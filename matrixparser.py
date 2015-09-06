#!/usr/bin/python3
csv_file = '/mnt/data/homedir/Documents/UT/Embedded_Computer_Architectures/MatrixValues.csv'

matrix_lines = []
with open(csv_file, 'r') as csv:
    for row, line in enumerate(csv.readlines()):
        line = line.replace('\n', '')
        for column, item in enumerate(line.split(',')):
            item = "{0:b}".format(int(item)).zfill(8)
            output = "\tA[%2d][%2d] = 0b%s;" % (row, column, item)
            matrix_lines.append(output)

with open('ecamatrix.cpp', 'w') as matrix:
    code = "void matrix(unsigned char A[20][20])\n\
{\n\
%s\n\
}\n" %"\n".join(matrix_lines)
    print(code)
    matrix.write(code)
