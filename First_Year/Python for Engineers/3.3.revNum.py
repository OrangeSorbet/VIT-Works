# This program reverses a number entered by the user.
print("This program reverses the number you enter.")
print("-------------------------------------------------------------")

num = int(input("Enter a number to get reverse: "))  # Take number input from user
num = str(num)  # Convert the number to string to reverse it easily

# Print the reversed number using string slicing
print(f"Reverse of {num} is {num[::-1]}")
