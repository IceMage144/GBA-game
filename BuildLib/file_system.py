import os
from posixpath import basename

from .debug import *

isfile = os.path.isfile
pjoin = os.path.join

def is_source(file_name):
    return file_name.endswith('.c')

def is_image(file_name):
    return file_name.endswith('.png')

def get_sources(base_dir):
    return get_files(base_dir, is_source)

def get_images(base_dir):
    return get_files(base_dir, is_image)

def get_files(base_dir: str, test_func):
    files = []
    for file_name in os.listdir(base_dir):
        file_path = pjoin(base_dir, file_name)
        if isfile(file_path):
            if test_func(file_name):
                files.append(file_path)
        else:
            files += get_sources(file_path)
    return files

def create_dir(dir_path: str):
    if dir_path == '':
        return
    os.makedirs(dir_path, exist_ok = True)

def change_dir(dir_path):
    print_warning(f'Changing directory to {dir_path}')
    os.chdir(dir_path)