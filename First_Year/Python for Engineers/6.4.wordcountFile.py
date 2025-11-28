print("Reads a text file, counts the number of words in it, and writes the word count to a new file")

file = open("6.4.zfile.txt", "r")
text = file.read()
words = text.split()
print(f"This file has {len(words)} words")

count = open("6.4.zcount.txt", "w")
count.write(f"This file has {len(words)} words")
file.close()
count.close()