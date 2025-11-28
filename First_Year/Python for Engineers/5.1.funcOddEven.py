# This program defines a function to check if a number is even or odd.
print("This program checks if a number is even or odd.")
print("-------------------------------------------------------------")

# Function to check if a number is even or odd
def calc(num):
    if num % 2 == 0:
        print(num, "is even")
    else:
        print(num, "is odd")

# Get the number from the user
num = int(input("Enter a number to find if it's odd or even: "))
# Call the function to check the number
calc(num)
