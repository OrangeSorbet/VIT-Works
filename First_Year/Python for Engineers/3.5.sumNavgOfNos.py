print("This program calculates the sum and average of the first 'n' numbers.")
print("-------------------------------------------------------------")

size = int(input("I want to take the first 'n' numbers: "))  # Take user input for the value of 'n'
sum = 0  # Initialize sum variable to 0

for i in range(1, size+1):  # Loop through numbers from 1 to 'n'
    sum += i  # Add the current number to the sum

print(f"Sum of first {size} numbers is {sum}")  # Output the sum of the first 'n' numbers

avg = 0  # Initialize avg variable to 0
for i in range(1, size+1):  # Loop again to calculate the average
    avg = sum / size  # Divide the sum by 'n' to get the average

print(f"Average of first {size} numbers is {avg}")  # Output the average of the first 'n' numbers
