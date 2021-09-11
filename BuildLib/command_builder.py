import os
import copy
import subprocess as sp
from typing import Dict

from .file_system import *

dirname = os.path.dirname

flag_indicator = '-'

OK = 0
CFLAGS = ''

def create_flag(prefix: str, name: str, value, bind_char: str = '=') -> str:
    if (value == True):
        return f'{flag_indicator}{prefix}{name}'
    return f'{flag_indicator}{prefix}{name}{bind_char}{value}'

def create_flags_group(prefix: str, flags_dict) -> str:
    flags_list = []
    if type(flags_dict) == dict:
        for name, value in flags_dict.items():
            flags_list.append(create_flag(prefix, name, value))
    elif type(flags_dict) == list:
        for name in flags_dict:
            flags_list.append(create_flag(prefix, name, True))
    return ' '.join(flags_list)

def create_flags_string(flag_groups_dict: Dict) -> str:
    flag_groups_list = []
    for prefix, flags_dict in flag_groups_dict.items():
        flag_groups_list.append(create_flags_group(prefix, flags_dict))
    return ' '.join(flag_groups_list)

def create_build_c_target_command(compiler: str, source: str, target: str,
                                  flags: Dict) -> str:
    flags_string = create_flags_string(flags)
    create_dir(dirname(target))
    return f'{compiler} {source} -o {target} {flags_string}'

def create_build_obj_command(compiler: str, source: str, target: str, flags: Dict) -> str:
    flags = copy.deepcopy(flags)
    if flags.get(CFLAGS) is None:
        flags[CFLAGS] = {}
    flags[CFLAGS]['c'] = True
    return create_build_c_target_command(compiler, source, target, flags)

def create_build_executable_command(compiler: str, sources: list,
                                    target: str, flags: Dict) -> str:
    joined_sources = ' '.join(sources)
    return create_build_c_target_command(compiler, joined_sources, target, flags)

def execute_command(command: str, verbose: bool = False) -> int:
    if verbose:
        print(f'Executing: {command}', flush=True)

    pipe = sp.Popen(
        command,
        env=os.environ,
        shell=True,
        stdout=sp.PIPE,
        stderr=sp.PIPE
    )

    _, stderr = pipe.communicate()
    retcode = pipe.returncode
    if retcode == OK:
        if verbose:
            print_success('SUCCESS')
    else:
        if verbose:
            print_fail('FAILED')
        print(stderr.decode('utf-8'), flush=True)

    return retcode