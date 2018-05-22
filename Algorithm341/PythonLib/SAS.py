# This module contains a list of searching and sorting algorithms
# Reference: 
#	1. https://en.wikipedia.org/wiki/Counting_sort
import sys

l = [1,2,3,4,5,6,7,8,9,10]
l2 = l
l2.reverse()

#****************************** BINARY SEARCH *****************************
# binary_search(l, k): takes a sorted list of input and a searched value
# 	and returns true if the element is in the list, otherwise returns false
def binary_search(l, k):
	if len(l) == 1 and l[0] != k:
		return False
	else:
		mid = len(l) / 2
		if l[mid] == k:
			return True
		elif k < l[mid]:
			return binary_search(l[0 : mid], k)
		else:
			return binary_search(l[mid: len(l)], k)

print(binary_search(l, 4))
print(binary_search(l, 11))

#****************************** INSERTION SORT *****************************
# variable:
#			l -- list of items to be sorted
# 		cur -- current value of item for each iteration
#			pos -- index postion for each iteration
def insertion_sort(l):
	for i in range(len(l)):
		cur = l[i]
		pos = i
		while pos > 0 and l[pos-1] > cur:
			l[pos] = l[pos-1]
			pos -= 1
		l[pos] = cur
# EXAMPLE
insertion_sort(l2)
print("INSERTION SORT", l2)

#****************************** SELECTION SORT *****************************
# variables:
# 		l -- list of items to be sorted
# 		m -- minimum number each iteration to be selected
# 		c -- a copy of original as the result of sorted list
def selection_sort(l):
	c = []
	while len(l) != 0:
		m = min(l)
		c.append(m)
		l.remove(m)
	return c
# EXAMPLE
l2.reverse()
l2 = selection_sort(l2)
print("SELECTION SORT", l2)

#****************************** QUICK SORT *****************************
# variable:
# 		low -- lowest starting index 
#			high -- highest ending index
#			l -- list of items to be sorted
def partition(l,low,high):
    i = low-1
    pivot = l[high]
    for j in range(low , high+1):
        if   l[j] <= pivot:
            i = i+1
            l[i],l[j] = l[j],l[i]
    return is
 
# Function to do Quick sort
def quick_sort(l,low,high):
    if low < high:
        pi = partition(l,low,high)
        quick_sort(l, low, pi-1)
        quick_sort(l, pi+1, high)
    return l

l2.reverse()
l2 = quick_sort(l2, 0, len(l2)-1)
print("QUICK SORT", l2)

#****************************** MERGE SORT *****************************
# merge_sort(l): takes a list of input and increasingly sort the list
def merge(left, right):
	res = []
	while len(left) != 0 and len(right) != 0:
		if left[0] < right[0]:
			res.append(left[0])
			left.remove(left[0])
		else:
			res.append(right[0])
			right.remove(right[0])
	if len(left) == 0:
		res += right
	else:
		res += left
	return res

def merge_sort(l):
	if len(l) == 1 or len(l) == 0:
		return l
	else:
		mid = len(l) / 2
		left = merge_sort(l[:mid])
		right = merge_sort(l[mid:])
		return merge(left, right)
# EXAMPLE
l2.reverse()
l2 = merge_sort(l2)
print("MERGE SORT", l2)						# SORTED

#****************************** QUICK SORT *****************************
