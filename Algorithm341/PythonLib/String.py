# STRING is a sequence of characters
# This file will explore some common problems with string

s = "aba"

# RETURN TRUE if a given string is palindrome
# :: operator --> https://stackoverflow.com/questions/17331290/how-to-check-for-palindrome-using-python-logic
def is_palindrome(s):
	return s == s[::-1]
print(is_palindrome(s))

# RETURN MINIMUM CHANGES convert a given string to anagram
# hackerrank --> https://www.hackerrank.com/challenges/anagram/problem
def len_convert_to_anagram(s):
	l = list(s)
	if not len(l) % 2 == 0: # base case
		return -1
	# other case
	mid = int(len(l) / 2)
	d = {}
	# runtime optimization
	for i in range(mid, len(l)):
		if l[i] not in d.keys():
			d[l[i]] = 1
		else:
			d[l[i]] += 1
	# algorithm
	c = 0 
	for i in range(0, mid):
		if l[i] in d.keys():
			if d[l[i]] > 0:
					d[l[i]] -= 1
					c += 1
			else:
				del d[l[i]]
	return mid - c
print(len_convert_to_anagram("xaxbbbxx"))