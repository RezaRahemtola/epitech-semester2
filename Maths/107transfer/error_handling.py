from sys import stderr

def check_param_is_polynomial(string: str) -> None:
    try:
        [int(nb) for nb in string.split("*")]
    except ValueError:
        stderr.write("bad argument: must be int.\n")
        exit(84)

def check_errors(argc: int, argv: list) -> None:
    if argc < 3 or argc % 2 == 0:
        exit(84)
    for arg in argv[1:]:
        check_param_is_polynomial(arg)