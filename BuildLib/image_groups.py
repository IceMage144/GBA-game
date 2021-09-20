import os

from .file_system import *
from .debug import *

basename = os.path.basename
dirname = os.path.dirname
splitext = os.path.splitext
pjoin = os.path.join

sheet_group_header_model = '''#ifndef __{group_name}_SHEET_GROUP_H__
#define __{group_name}_SHEET_GROUP_H__

{includes}

{defines}

void load_{group_name}_sheet(volatile OBJATTR* objattr, u8 sheet_id, u16* start_tile,
    u8* palette_pos)
{{
    switch (sheet_id)
    {{
        {load_cases}
    }}
}}

void assign_{group_name}_sheet_attrs(volatile OBJATTR* objattr, u8 sheet_id, u16 start_tile,
    u8 palette_pos)
{{
    switch (sheet_id)
    {{
        {assign_cases}
    }}
}}

#endif'''
include_model = '#include "sprites/{group_name}/{file_name}.h"'
define_model = '#define {file_name}_SHEET {value}'
load_case_model = '''case {file_name}_SHEET:
            load_{file_name}_sheet(objattr, start_tile, palette_pos);
            break;'''
assign_case_model = '''case {file_name}_SHEET:
            assign_{file_name}_sheet_attrs(objattr, start_tile, palette_pos);
            break;'''

def generate_sheet_group_header(base_path: str):
    group_name = basename(base_path)
    print_log(f'Creating sheet group header from folder {group_name}')
    sheet_id = 0
    includes = []
    defines = []
    load_cases = []
    assign_cases = []
    for sheet_path in get_images(base_path):
        sheet_name = splitext(basename(sheet_path))[0]
        includes.append(include_model.format(group_name=group_name, file_name=sheet_name))
        defines.append(define_model.format(file_name=sheet_name, value=sheet_id))
        load_cases.append(load_case_model.format(file_name=sheet_name))
        assign_cases.append(assign_case_model.format(file_name=sheet_name))
        sheet_id += 1
    includes = '\n'.join(includes)
    defines = '\n'.join(defines)
    load_cases = '\n        '.join(load_cases)
    assign_cases = '\n        '.join(assign_cases)

    header_str = sheet_group_header_model.format(
        group_name = group_name,
        includes=includes,
        defines=defines,
        load_cases=load_cases,
        assign_cases=assign_cases
    )

    header_path = pjoin('include', dirname(base_path), group_name + '.h')
    with open(header_path, 'w+') as f:
        f.write(header_str)

    print_success('SUCCESS')