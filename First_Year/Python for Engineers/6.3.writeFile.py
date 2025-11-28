print("Takes string from user and writes it on document")
file = open("6.3.zfile.txt", "w")
str = input("Enter the string to be written in the file: ")
file.write(str)
file.close()


