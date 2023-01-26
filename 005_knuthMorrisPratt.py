# The Knuth-Morris-Pratt (KMP) algorithm is a string matching algorithm that can be used to efficiently search for a substring within a larger string. It's based on the observation that when a mismatch occurs, the substring and the larger string share a common prefix, so it's possible to skip over some of the characters in the larger string by making use of this information.

# In Python, the KMP algorithm can be implemented manually using the standard Python libraries. Here is an example of how you can implement the KMP algorithm in Python

def KMPSearch(string, substring):
    m = len(substring)
    n = len(string)

    # Create lps[] that will hold the longest prefix suffix values for substring
    lps = [0]*m
    j = 0 # index for substring

    # Preprocess the substring
    computeLPSArray(substring, m, lps)

    i = 0 # index for string
    while i < n:
        if substring[j] == string[i]:
            i += 1
            j += 1

        if j == m:
            print("Found substring at index " + str(i-j))
            j = lps[j-1]

        # mismatch after j matches
        elif i < n and substring[j] != string[i]:
            # Do not match lps[0..lps[j-1]] characters, they will match anyway
            if j != 0:
                j = lps[j-1]
            else:
                i += 1

def computeLPSArray(substring, m, lps):
    len = 0 # length of the previous longest prefix suffix
    lps[0] = 0 # lps[0] is always 0
    i = 1

    # the loop calculates lps[i] for i = 1 to m-1
    while i < m:
        if substring[i] == substring[len]:
            len += 1
            lps[i] = len
            i += 1
        else:
            if len != 0:
                len = lps[len-1]
            else:
                lps[i] = 0
                i += 1

string = "Hello, World!"
substring = "World"
KMPSearch(string, substring)
