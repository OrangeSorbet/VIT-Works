print("This program finds perfect squares in a given range and finds if the sum of their digits is less than 10.")
print("-------------------------------------------------------------")

rng = int(input("Enter range to get perfect squares and sum of their digits: "))  # Prompt for the range
print(f"Perfect squares in range 1 to {rng} are:")

# Loop to find perfect squares within the range
for i in range(1, rng + 1):
    if (i**0.5).is_integer():  # Check if the number is a perfect square
        print(f"{i} is perfect square of {int(i**0.5)}")  # Print the perfect square and its square root

print(f"Now, perfect square numbers with sum of their digits less than 10 are: ")

# Loop to find perfect squares with a sum of digits less than 10
for i in range(1, rng + 1):
    if (i**0.5).is_integer():  # Check if the number is a perfect square
        sum_of_digits = 0
        for j in str(i):  # Iterate over the digits of the perfect square
            sum_of_digits += int(j)  # Calculate the sum of the digits
        if sum_of_digits < 10:  # Check if the sum of digits is less than 10
            print(f"{i} with sum of digits {sum_of_digits}, which is the perfect square of {int(i**0.5)}")  # Print the result
