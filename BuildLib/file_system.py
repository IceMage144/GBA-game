import os

from .debug import *

isfile = os.path.isfile
pjoin = os.path.join

def is_source(file_name):
    return file_name.endswith('.c')

def get_sources(base_dir):
    files = []
    for file_name in os.listdir(base_dir):
        file_path = pjoin(base_dir, file_name)
        if isfile(file_path):
            if is_source(file_name):
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