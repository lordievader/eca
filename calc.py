#!/usr/bin/python3

code = []
for column in range(20):
    code.append("temp = cache[row][0] * cache[0][%d];" % (column))
    for i in range(1, 20):
        output = "temp += cache[row][%d] * cache[%d][%d];" % (i, i, column)
        code.append(output)

    code.append('B[row][%d] = temp;\n' % (column))


code = "\n".join(code)
print(code)
print('\n')
with open('calc.h', 'w') as calc:
    calc.write(code)
