# This program prints all numbers from 1 up to the number entered by the user.
print("This program prints all numbers from 1 up to the number you enter.")
print("------------------------------------------------------------------")

# Loop from 1 to the entered number (inclusive)
for i in range(1, int(input("Enter a number: ")) + 1):
    print(i)
