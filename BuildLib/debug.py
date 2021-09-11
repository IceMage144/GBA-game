def print_success(text):
    print(f'\033[92m{text}\033[0m', flush=True)

def print_warning(text):
    print(f'\033[93m{text}\033[0m', flush=True)

def print_fail(text):
    print(f'\033[91m{text}\033[0m', flush=True)