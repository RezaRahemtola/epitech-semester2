from sys import stderr

def check_param_is_int(string: str) -> None:
    try:
        int(string)
    except ValueError:
        stderr.write("bad argument: must be int.\n")
        exit(84)

def is_square(nb_args: int) -> None:
    i = 1

    while i ** 2 <= nb_args:
        if (nb_args % i == 0) and (nb_args / i == i):
            return True
        i += 1
    return False

def check_errors(argc: int, argv: list) -> None:
    if argc < 3:
        stderr.write("Incorrect number of arguments.\n")
        exit(84)
    if argv[1] not in ["EXP", "COS", "SIN", "COSH", "SINH"]:
        stderr.write("Incorrect function, try again with -h\n")
        exit(84)
    if not is_square(len(argv) - 2):
        stderr.write("Coeficients are not square.\n")
        exit(84)
    for arg in argv[2:]:
        check_param_is_int(arg)
