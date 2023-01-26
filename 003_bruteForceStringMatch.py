def findSubstring(text, subString):
    sizeText = len(text)
    sizesubString = len(subString)
    for i in range(0, sizeText - sizesubString):
        j = 0
        while j < sizesubString and subString[j] == text[i + j]:
            j = j + 1

        if j == sizeText:
            return i

    return -1


string = "Hello, World!"
substring = "World"

print(findSubstring(string, substring))
