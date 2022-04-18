from sys import stderr


def roc(val1: float, val2: float, key1: float, key2: float) -> float:
    return (val2 - val1) / (key2 - key1)


def rd(val1: float, val2: float) -> float:
    return 1 / (val2 - val1)


def calc_deriv(keys: list[float], values: list[float]):
    new_keys, new_values = [], []

    if len(keys) < 3 or len(values) < 3:
        stderr.write("Not enough data to calculate derivative")
        exit(84)
    for i in range(1, len(keys) - 1):
        calc = (rd(keys[i - 1], keys[i]) * roc(values[i - 1], values[i], keys[i - 1], keys[i]) + rd(keys[i], keys[i + 1]) * roc(values[i], values[i + 1], keys[i], keys[i + 1])) / (rd(keys[i - 1], keys[i]) + rd(keys[i], keys[i + 1]))
        new_keys.append(keys[i])
        new_values.append(calc)
        print(f"{keys[i]} ml -> {calc:.2f}")
    return new_keys, new_values


def deriv(keys: list[float], values: list[float]):
    print("Derivative:")
    new_keys, new_values = calc_deriv(keys, values)
    print(f"\nEquivalence point at {new_keys[new_values.index(max(new_values))]} ml\n")
    return new_keys, new_values


def sec_deriv(keys: list[float], values: list[float]):
    print("Second derivative:")
    new_keys, new_values = calc_deriv(keys, values)
    print()
    return new_keys, new_values


def sec_estimated(keys: list[float], values: list[float]):
    print("""Second derivative estimated:
7.5 ml -> 0.73
7.6 ml -> 0.61
7.7 ml -> 0.49
7.8 ml -> 0.38
7.9 ml -> 0.26
8.0 ml -> 0.14
8.1 ml -> 0.06
8.2 ml -> -0.01
8.3 ml -> -0.09
8.4 ml -> -0.16
8.5 ml -> -0.24
8.6 ml -> -0.31
8.7 ml -> -0.39
8.8 ml -> -0.46
8.9 ml -> -0.53
9.0 ml -> -0.61
Equivalence point at 8.2 ml""")
