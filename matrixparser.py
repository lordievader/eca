#!/usr/bin/python3
import numpy

#csv_file = '/mnt/data/homedir/Documents/UT/Embedded_Computer_Architectures/MatrixValues.csv'
csv_file = '20MatrixValues.csv'

matrix_rows = []
A = numpy.loadtxt(open(csv_file, 'rb'), delimiter=',')
n = numpy.amin(A)
m = numpy.amax(A)

c_rows = []
for row, data in enumerate(A):
    c_columns = ['\t{']
    for column, value in enumerate(data):
        output = "%d, " % int(value)
        c_columns.append(output)

    c_columns.append('},\n')
    c_rows.append("".join(c_columns))

c_rows = "".join(c_rows)

row += 1
column += 1

code = "#ifndef ECAMATRIX_H\n\
#define ECAMATRIX_H\n\
#ifdef ARDUINO_TARGET\n\
const PROGMEM char A[%d][%d] = {\n\
#else\n\
const char A[%d][%d] = {\n\
#endif\n\
%s\n\
};\n\
#endif" % (row, column, row, column, c_rows)
print(code)
print('\n')
with open('ecamatrix.h', 'w') as header:
    header.write(code)

C = numpy.dot(A, A)
x = numpy.amin(C)
y = numpy.amax(C)

c_rows = []
for row, data in enumerate(C):
    c_columns = ['\t{']
    for column, value in enumerate(data):
        output = "%d, " % int(value)
        c_columns.append(output)

    c_columns.append('},\n')
    c_rows.append("".join(c_columns))

c_rows = "".join(c_rows)

row += 1
column += 1

code = "#ifndef ANSMATRIX_H\n\
#define ANSAMATRIX_H\n\
#ifdef ARDUINO_TARGET\n\
const PROGMEM int C[%d][%d] = {\n\
#else\n\
const int C[%d][%d] = {\n\
#endif\n\
%s\n\
};\n\
#endif" % (row, column, row, column, c_rows)
print(code)
print('\n')
with open('ansmatrix.h', 'w') as header:
    header.write(code)

print("range: %d -- %d --> %d -- %d" % (n, m, x, y))
