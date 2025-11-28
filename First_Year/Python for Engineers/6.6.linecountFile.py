print("Counts the number of lines in a file")
file = open("6.6.zfile.txt", "r")
lineCount = 0
for line in file:
    lineCount += 1
print("Line count:", lineCount)
file.close()