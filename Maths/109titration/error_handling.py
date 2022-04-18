import os
from sys import stderr


def is_float(nbr: str) -> bool:
    try:
        float(nbr)
        return True
    except ValueError:
        return False


def error_handling(argv: list) -> bool:
    argc = len(argv)

    if argc != 2:
        stderr.write("Incorrect number of arguments.\n")
        return True
    path = argv[1]
    if not os.path.isfile(path) or not os.access(path, os.R_OK):
        stderr.write("File does not exist or is not readable.\n")
        return True
    keys = []
    with open(path, 'r') as file:
        for line in file.read().splitlines():
            content = line.split(';')
            if len(content) != 2:
                stderr.write(f"Incorrect number of elements per line\n")
                return True
            if not is_float(content[0]) or not is_float(content[1]):
                stderr.write("File contains non-numeric values.\n")
                return True
            keys.append(content[0])
    if len(keys) == 0:
        stderr.write("File is empty.\n")
        return True
    if len(keys) != len(set(keys)):
        stderr.write("File contains duplicate values.\n")
        return True
    if len(keys) < 3:
        stderr.write("File contains less than 3 values.\n")
        return True
    return False
