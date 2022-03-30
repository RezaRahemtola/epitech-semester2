from matrix import Matrix

def get_square_size(nb_args: int) -> int:
    i = 1

    while i ** 2 <= nb_args:
        if (nb_args % i == 0) and (nb_args / i == i):
            return i
        i += 1

def create_matrix_from_args(argv: list) -> Matrix:
    argc = len(argv)
    square_size = get_square_size(argc)
    values = []
    line = []
    for elem in argv:
        line.append(float(elem))
        if len(line) == square_size:
            values.append(line)
            line = []
    return Matrix(values)
