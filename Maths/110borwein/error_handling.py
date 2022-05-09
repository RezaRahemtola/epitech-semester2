from sys import stderr


def error_handling(argv: list[str]) -> bool:
    argc = len(argv)

    if argc != 2:
        stderr.write("Incorrect number of arguments.\n")
        return True
    if not argv[1].isdigit():
        stderr.write("n must be an integer.\n")
        return True
    if int(argv[1]) > 5000:
        stderr.write("n must be between 0 and 5000.\n")
        return True
    return False
