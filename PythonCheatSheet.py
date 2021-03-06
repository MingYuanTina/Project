# REFERENCE:
#		1. http://blog.teamtreehouse.com/python-single-line-loops
# 	2. 
import sys
import string
from collections import deque
from functools import reduce

#**************** Split String by Keyword ***********
line = "TEST1,TEST2,TEST3,TEST4,TEST5"
line = string.split(line, ",")

for i in range(0, len(line)):					# ANOTHER WAY: for keyword in line:
	print("Item %d: %s" % (i, line[i])) # print WITH new line

#***************** Convert String to Floating/Integer ************
str_ = "3.14159"
float_ = string.atof(str_)						# STRING -> FLOAT
str_ = "3"
int_ = string.atoi(str_)							# STRING -> INTEGER

#******************************** LIST/STACK ***************************
a = [1,2,3,4,5]
a.append(6)						# append(val)
a.insert(len(a), 7)		# insert(index, val), where index starts wiht 0
a.remove(7)						# remove(val)
a.pop(5)							# pop(index)
print(a)
print(a.index(5))			# position of given value
print(a.count(5))  		# number of occurrences of given value
a.reverse()
# LIST COMPREHENSION
b = [(x, y) for x in [1,2,3] for y in [4,5,6] if x != y]
print(b)

#****************************** QUEUE *****************************
q = deque(a)
q.append(0)
q.popleft()
print(q)

#************************ FUNCTIONAL PROGRAMMING *******************
# FILTER
def f(x):
	return x % 3 == 0
sys.stdout.write("FILTER: ")
print(filter(f, range(0, 20)))			# List where f = true

# MAP
def square(x):
	return x * x
sys.stdout.write("MAP: ")
print(map(square, range(0, 4)))			# List that applies f

def add(x, y):
	return x + y
sys.stdout.write("MAP: ")
print(map(add, range(0, 4), range(0, 4))) # MULTIPLE SEQUENCE MAP

# REDUCE
sys.stdout.write("REDUCE: ")
print(reduce(add, range(0, 4)))				# Return value applies f from list

#************************ FUNCTIONAL PROGRAMMING *******************








