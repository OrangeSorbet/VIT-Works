print("This program separates even and odd numbers from a list.")
print("-------------------------------------------------------------")

size = int(input("Enter size of list: "))  # Prompt user to enter the size of the list
print("Enter numbers in list: ")
lst = []  # Initialize an empty list to store the numbers

# Collect the list elements from user input
for i in range(size):
    lst.append(int(input(f"Enter number {i+1}: ")))  # Append numbers to the list

print(f"List is: {lst}")

even = []  # Initialize an empty list for even numbers
odd = []   # Initialize an empty list for odd numbers

# Iterate through the list and separate even and odd numbers
for num in lst:
    if num % 2 == 0:
        even.append(num)  # If the number is even, append it to the even list
    else:
        odd.append(num)   # If the number is odd, append it to the odd list

# Output the results
print(f"Even numbers in list are: {even}")
print(f"Odd numbers in list are: {odd}")
