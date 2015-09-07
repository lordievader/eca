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
unsigned char A[%d][%d] = {\n\
#endif\n\
%s\n\
};\n\
#endif" % (row, column, row, column, matrix_rows)
    print(code)
    header.write(code)

print()
raise SystemExit()

with open('ecamatrix.cpp', 'w') as matrix:
    code = "void matrix(unsigned char A[%d][%d])\n\
{\n\
%s\n\
}\n" %(row + 1, column + 1, "\n".join(matrix_lines))
    print(code)
    matrix.write(code)

print('\n')

raise SystemExit()

## B
matrix_lines = []
A = numpy.loadtxt(open(csv_file, 'rb'), delimiter=',')
B = numpy.dot(A, A)
for i, row in enumerate(B):
    for j, col in enumerate(B[i]):
        print(int(B[i][j]))
        item = "{0:b}".format(int(B[i][j])).zfill(32)
        output = "\tB[%2d][%2d] = 0b%s;" % (i, j, item)
        print(output)
        matrix_lines.append(output)

with open('ansmatrix.h', 'w') as header:
    code = "#ifndef ANSMATRIX_H\n\
#define ANSMATRIX_H\n\
void ansmatrix(unsigned long B[%d][%d]);\n\
#endif" % (i + 1, j + 1)
    print(code)
    header.write(code)

print()

with open('ansmatrix.cpp', 'w') as matrix:
    code = "void ansmatrix(unsigned long B[%d][%d])\n\
{\n\
%s\n\
}\n" %(i + 1, j + 1, "\n".join(matrix_lines))
    print(code)
    matrix.write(code)

#print(B)
