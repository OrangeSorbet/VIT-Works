print("This program prints the first 'n' multiples of a given number.")
print("-------------------------------------------------------------")

num = int(input("Enter a number to get multiples: "))  # Take user input for the number whose multiples are needed
rng = int(input("Enter total multiples to get: "))  # Take user input for how many multiples to display

print(f"Multiples of {num} are:")  # Display the header for the multiples
for i in range(1, rng+1):  # Loop from 1 to the total number of multiples
    print(f"{num} x {i} = {num*i}")  # Display each multiple in the format "num x i = result"
