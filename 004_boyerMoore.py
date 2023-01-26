# The Boyer-Moore algorithm is a string matching algorithm that can be used to efficiently search for a substring within a larger string

# I apologize for the previous confusion, pyxDamerauLevenshtein is not a python library. Boyer-Moore algorithm can be implemented manually in python, The basic idea behind the algorithm is to preprocess the substring to create a "bad character" rule and a "good suffix" rule, which can be used to quickly skip over parts of the larger string that are unlikely to contain the substring.

# However, python's re library has an implementation of Boyer-Moore algorithm, you can use re.search(pattern, string, flags=re.S) to find the substring in the given string.

# It's also possible to use python's str.find() or str.index() method to find the substring in a given string, but Boyer-Moore algorithm is more efficient when the substring is long and the string is large.

import re
string = "Hello, World!"
substring = "World"
result = re.search(substring, string)
print(result.start())
