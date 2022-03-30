class Matrix:
    def __init__(self, values: list):
        last_value = len(values[0])
        for row in values:
            if last_value != len(row):
                raise Exception("Error: Matrix with uncoherent rows length.")
            else:
                last_value = len(row)
        self.values = values
        self.rows = len(values)
        self.columns = len(values[0])

    def __mul__(self, factor):
        if self.columns != factor.rows:
            raise Exception("Error: Matrices with different rows and columns.")
        result = []
        for row in self.values:
            line_result = []
            for col_nbr in range(factor.columns):
                col = factor.get_column(col_nbr)
                value = sum([row[i] * col[i] for i in range(len(row))])
                line_result.append(value)
            result.append(line_result)
        return Matrix(result)

    def __add__(self, other):
        if self.rows != other.rows or self.columns != other.columns:
            raise Exception("Error: Matrices with different rows and columns.")
        result = []
        for row in range(self.rows):
            line_result = []
            for col in range(self.columns):
                line_result.append(self.values[row][col] + other.values[row][col])
            result.append(line_result)
        return Matrix(result)

    def __sub__(self, other):
        if self.rows != other.rows or self.columns != other.columns:
            raise Exception("Error: Matrices with different rows and columns.")
        result = []
        for row in range(self.rows):
            line_result = []
            for col in range(self.columns):
                line_result.append(self.values[row][col] - other.values[row][col])
            result.append(line_result)
        return Matrix(result)

    def divide_by(self, nb: int):
        result = []
        for row in self.values:
            line_result = []
            for col in row:
                line_result.append(col / nb)
            result.append(line_result)
        return Matrix(result)

    def power_of(self, nb: int):
        result = Matrix(self.values)
        for i in range(nb - 1):
            result *= self
        return result

    def get_column(self, col_index):
        result = []
        for i, value in enumerate(self.values):
            result.append(self.values[i][col_index])
        return result


    def __str__(self) -> str:
        result = ""
        for row in self.values:
            for value in row:
                result += f"{value:.2f}\t"
            result = result[:-1] + "\n"
        return result[:-1]
