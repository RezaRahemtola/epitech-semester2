from sys import exit, stderr

def check_str_is_int(string: str):
    try:
        int(string)
    except ValueError:
        stderr.write("bad argument: must be int.\n")
        exit(84)

def check_str_is_float(string: str):
    try:
        float(string)
    except ValueError:
        stderr.write("bad argument: must be float.\n")
        exit(84)

def check_errors(argv: list):
    argc = len(argv)
    if argc != 3 and argc != 4:
        stderr.write("Incorrect number of arguments.\n")
        exit(84)
    check_str_is_int(argv[1])
    if int(argv[1]) < 0:
        stderr.write("n should be a positive integer.\n")
        exit(84)
    if argc == 3:
        check_str_is_float(argv[2])
        if float(argv[2]) < 1 or float(argv[2]) > 4:
            stderr.write("bad argument: k must be between 1 and 4.\n")
            exit(84)
    if argc == 4:
        check_str_is_int(argv[2])
        check_str_is_int(argv[3])
        if int(argv[2]) > int(argv[3]):
            stderr.write("bad argument: i0 must be smaller or equal to i1.\n")
            exit(84)
        if int(argv[2]) < 1:
            stderr.write("bad argument: i0 must be greater or equal to 1.\n")
            exit(84)
