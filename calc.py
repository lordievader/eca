#!/usr/bin/python3

adds = []
for column in range(20):
    for i in range(20):
        output = "temp += cache[row][%d] * cache[%d][%d];" % (i, i, column)
        adds.append(output)

    adds.append('B[row][%d] = temp;\ntemp = 0;' % column)


adds = "\n".join(adds)
print(adds)
print('\n')
with open('calc.tmp', 'w') as calc:
    calc.write(adds)

#adds = []
#for i in range(10):
    #output = "cache[row][%d] * cache[%d][column]" % (i, i)
    #adds.append(output)

#adds = " + ".join(adds)
#output = "item1 = %s;" % adds
#print(output)

#adds = []
#for i in range(10, 20):
    #output = "cache[row][%d] * cache[%d][column]" % (i, i)
    #adds.append(output)

#adds = " + ".join(adds)
#output = "item2 = %s;" % adds
#print(output)


#adds = []
#for i in range(10):
    #output = "item1 += cache[row][%d] * cache[%d][column];\n" % (i, i)
    #adds.append(output)

#adds = "".join(adds)
#print(adds)
#print('\n')

#adds = []
#for i in range(10, 20):
    #output = "item2 += cache[row][%d] * cache[%d][column];\n" % (i, i)
    #adds.append(output)

#adds = "".join(adds)
#print(adds)
#print('\n')
