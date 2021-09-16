def print_success(text: str):
    print(f'\033[92m{text}\033[0m', flush=True)

def print_warning(text: str):
    print(f'\033[93m{text}\033[0m', flush=True)

def print_fail(text: str):
    print(f'\033[91m{text}\033[0m', flush=True)

def print_log(text: str):
    print(text, flush=True)