def load_data_from_file(path: str) -> dict:
    result = {}

    with open(path, 'r') as file:
        for line in file.read().split('\n'):
            if line == '':
                continue
            content = line.split(';')
            result[str(float(content[0]))] = content[1]
    keys = sorted(list([float(key) for key in result.keys()]))
    values = [float(result[str(key)]) for key in keys]
    return keys, values
