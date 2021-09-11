from .command_builder import *

CC = 'arm-none-eabi-gcc'

INCPATHS = 'I'
LIBPATHS = 'L'
WFLAGS = 'W'
MFLAGS = 'm'
LIBS = 'l'

def create_obj_file(source: str, target: str, flags: Dict,
                    verbose: bool = False) -> int:
    command = create_build_obj_command(CC, source, target, flags)
    return execute_command(command, verbose)

def create_executable_file(sources: list, target: str, flags: Dict,
                           verbose: bool = False) -> int:
    command = create_build_executable_command(CC, sources, target, flags)
    return execute_command(command, verbose)

def create_gba_file(source: str, target: str, verbose: bool = True) -> int:
    create_dir(dirname(target))
    convert_command = f'arm-none-eabi-objcopy -v -O binary {source} {target}'
    retcode = execute_command(convert_command, verbose)
    if retcode != OK:
        return retcode
    
    fix_command = f'gbafix {target}'
    return execute_command(fix_command, verbose)
