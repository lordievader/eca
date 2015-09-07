#!/usr/bin/python3
#csv_file = '/mnt/data/homedir/Documents/UT/Embedded_Computer_Architectures/MatrixValues.csv'
csv_file = '20MatrixValues.csv'

matrix_lines = []
with open(csv_file, 'r') as csv:
    for row, line in enumerate(csv.readlines()):
        line = line.replace('\n', '')
        for column, item in enumerate(line.split(',')):
            item = "{0:b}".format(int(item)).zfill(8)
            output = "\tA[%2d][%2d] = 0b%s;" % (row, column, item)
            matrix_lines.append(output)

with open('ecamatrix.h', 'w') as header:
    code = "#ifndef ECAMATRIX_H\n\
#define ECAMATRIX_H\n\
void matrix(unsigned char A[%d][%d]);\n\
#endif" % (row + 1, column + 1)
    print(code)
    header.write(code)

print()

with open('ecamatrix.cpp', 'w') as matrix:
    code = "void matrix(unsigned char A[%d][%d])\n\
{\n\
%s\n\
}\n" %(row + 1, column + 1, "\n".join(matrix_lines))
    print(code)
    matrix.write(code)

