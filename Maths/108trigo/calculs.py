from matrix import Matrix
from math import factorial


def get_base(matrix: Matrix) -> Matrix:
    base_values = []

    for i in range(matrix.rows):
        tmp = []
        for j in range(matrix.columns):
            tmp.append(1 if i == j else 0)
        base_values.append(tmp)
    return Matrix(base_values)


def calc_exp(matrix: Matrix) -> Matrix:
    base = get_base(matrix)
    i = 1
    end = False
    while not end:
        try:
            base += matrix.power_of(i).divide_by(factorial(i))
            i += 1
        except:
            end = True
    return base


def calc_cos(matrix: Matrix) -> Matrix:
    base = get_base(matrix)
    i = 1
    end = False
    while not end:
        try:
            if i % 2 == 0:
                base += matrix.power_of(2 * i).divide_by(factorial(2 * i))
            else:
                base -= matrix.power_of(2 * i).divide_by(factorial(2 * i))
            i += 1
        except:
            end = True
    return base


def calc_sin(matrix: Matrix) -> Matrix:
    result = Matrix(matrix.values)
    i = 1
    end = False
    while not end:
        try:
            if i % 2 == 0:
                result += matrix.power_of(2 * i + 1).divide_by(factorial(2 * i + 1))
            else:
                result -= matrix.power_of(2 * i + 1).divide_by(factorial(2 * i + 1))
            i += 1
        except:
            end = True
    return result


def calc_cosh(matrix: Matrix) -> Matrix:
    base = get_base(matrix)
    i = 1
    end = False
    while not end:
        try:
            base += matrix.power_of(2 * i).divide_by(factorial(2 * i))
            i += 1
        except:
            end = True
    return base


def calc_sinh(matrix: Matrix) -> Matrix:
    result = Matrix(matrix.values)
    i = 1
    end = False
    while not end:
        try:
            result += matrix.power_of(2 * i + 1).divide_by(factorial(2 * i + 1))
            i += 1
        except:
            end = True
    return result
