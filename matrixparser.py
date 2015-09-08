#!/usr/bin/python3
import numpy

#csv_file = '/mnt/data/homedir/Documents/UT/Embedded_Computer_Architectures/MatrixValues.csv'
csv_file = '20MatrixValues.csv'


## A
matrix_rows = []
with open(csv_file, 'r') as csv:
    for row, line in enumerate(csv.readlines()):
        line = line.replace('\n', '')
        matrix_lines = ['\t{']
        for column, item in enumerate(line.split(',')):
            item = "{0:b}".format(int(item)).zfill(16)
            output = "0b%s, " % (item)
            matrix_lines.append(output)

        matrix_lines.append('},\n')
        matrix_rows.append("".join(matrix_lines))

    matrix_rows = "".join(matrix_rows)

row += 1
column += 1

with open('ecamatrix.h', 'w') as header:
    code = "#ifndef ECAMATRIX_H\n\
#define ECAMATRIX_H\n\
#ifdef ARDUINO_TARGET\n\
const PROGMEM unsigned char A[%d][%d] = {\n\
#else\n\
const unsigned char A[%d][%d] = {\n\
#endif\n\
%s\n\
};\n\
#endif" % (row, column, row, column, matrix_rows)
    print(code)
    header.write(code)

print('\n')

## C
matrix_rows = []
A = numpy.loadtxt(open(csv_file, 'rb'), delimiter=',')
C = numpy.dot(A, A)
for i, row in enumerate(C):
    matrix_lines = ['\t{']
    for j, col in enumerate(C[i]):
        item = "{0:b}".format(int(C[i][j])).zfill(32)
        output = "0b%s, " % (item)
        matrix_lines.append(output)

    matrix_lines.append('},\n')
    matrix_rows.append("".join(matrix_lines))

matrix_rows = "".join(matrix_rows)

i += 1
j += 1

with open('ansmatrix.h', 'w') as header:
    code = "#ifndef ANSMATRIX_H\n\
#define ANSMATRIX_H\n\
#ifdef ARDUINO_TARGET\n\
const PROGMEM unsigned long C[%d][%d] = {\n\
#else\n\
const unsigned long C[%d][%d] = {\n\
#endif\n\
%s\n\
};\n\
#endif" % (i, j, i, j, matrix_rows)
    print(code)
    header.write(code)

print(C)
