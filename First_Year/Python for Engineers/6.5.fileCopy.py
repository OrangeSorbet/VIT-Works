print("Reads content of one file and copies it to another file")
file1 = open("6.5.zfile1.txt", "r")
file2 = open("6.5.zfile2.txt", "w")
for line in file1:
    file2.write(line)
print("Done")
file2.close()
file1.close()