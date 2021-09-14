#!python

# ---------------------------------------------------------------
# Script for building the project
#
# Long story short, make, cmake and scons sucks, so I made my
# own script for building.
# Plus, I had to create one anyway to convert data into c code.
# ---------------------------------------------------------------

import os
import shutil

import click

from BuildLib.file_system import *
from BuildLib.commands import *
from BuildLib.image import *

isdir = os.path.isdir
splitext = os.path.splitext
relpath = os.path.relpath

temp_files_dir = 'temp_files'
builds_dir = 'Builds'

@click.command()
@click.argument('base_folder', type=click.Path(exists=True, dir_okay=True, file_okay=False))
@click.option('--debug', is_flag=True)
@click.option('--verbose', is_flag=True)
def game(base_folder: str, debug: bool, verbose: bool):
    build_assets(base_folder, verbose)

    change_dir(base_folder)

    devkit_path = os.environ['DEVKITPRO']
    libgba_path = pjoin(devkit_path, 'libgba')
    libgba_include_path = pjoin(libgba_path, 'include')
    libgba_lib_path = pjoin(libgba_path, 'lib')
    compile_flags = {
        CFLAGS: {
            'specs': 'gba.specs',
            'Os': True
        },
        MFLAGS: {
            'cpu': 'arm7tdmi',
            'tune': 'arm7tdmi',
            'thumb': True,
            'thumb-interwork': True
        },
        WFLAGS: {
            'all': True
        },
        INCPATHS: ['include', libgba_include_path],
        LIBPATHS: [libgba_lib_path],
        LIBS: ['mm', 'gba']
    }
    if debug:
        compile_flags[CFLAGS]['g'] = True
        compile_flags[CFLAGS]['gdwarf-2'] = True

    sources_base_dir = 'source'
    sources = get_sources(sources_base_dir)
    obj_files = []
    for source in sources:
        target = pjoin(temp_files_dir, source[len(sources_base_dir) + 1:-2] + '.o')
        retcode = create_obj_file(source, target, compile_flags, True)
        if retcode != OK:
            return
        obj_files.append(target)

    elf_file = pjoin(temp_files_dir, base_folder + '.elf')
    retcode = create_executable_file(obj_files, elf_file, compile_flags, True)
    if retcode != OK:
        return
    
    change_dir('..')
    gba_file = pjoin(builds_dir, base_folder + '.gba')
    retcode = create_gba_file(pjoin(base_folder, elf_file), gba_file)
    if retcode != OK:
        return

@click.command()
@click.argument('base_folder', type=click.Path(exists=True, dir_okay=True, file_okay=False))
@click.option('--verbose', is_flag=True)
def assets(base_folder: str, verbose: bool):
    build_assets(base_folder, verbose)

def build_assets(base_folder: str, verbose: bool):
    change_dir(base_folder)
    images_base_dir = 'sprites'
    images = get_images(images_base_dir)
    for image_path in images:
        generate_header_from_sheet(splitext(relpath(image_path, images_base_dir))[0])
    change_dir('..')

@click.command()
@click.argument('base_folder', default='.', type=click.Path(exists=True, dir_okay=True, file_okay=False))
@click.option('--clean-build', is_flag=True)
def clean(base_folder, clean_build):
    if base_folder == '.':
        for dir_name in os.listdir(base_folder):
            temp_path = pjoin(dir_name, temp_files_dir)
            if isdir(temp_path):
                shutil.rmtree(temp_path)
        if clean_build:
            shutil.rmtree(builds_dir)
    else:
        shutil.rmtree(pjoin(base_folder, temp_files_dir))
        if clean_build:
            shutil.rmtree(pjoin(builds_dir, base_folder + '.gba'))

@click.group()
def main():
    pass

main.add_command(game)
main.add_command(assets)
main.add_command(clean)

if __name__ == '__main__':
    main()