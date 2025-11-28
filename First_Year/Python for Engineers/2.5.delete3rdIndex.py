print("This program removes characters at indices divisible by 3 from the input string.")
print("------------------------------------------------------------")

str = input("Enter a string to remove the indices divisible by 3: ")
str2 = []  # This list will store characters not at positions divisible by 3

# Loop through the string using index
for i in range(len(str)):
    if i % 3 != 0:  # Skip characters at indices divisible by 3 (like 0, 3, 6, ...)
        str2.append(str[i])  # Append valid characters to the new list

# Join the list back into a string and print
print("".join(str2))
