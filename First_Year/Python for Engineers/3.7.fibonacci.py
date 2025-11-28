print("This program prints the first 'n' numbers of the Fibonacci series.")
print("-------------------------------------------------------------")

rng = int(input("How many numbers of Fibonacci series you want?: "))  # Take user input for how many numbers to display
a = 0  # First Fibonacci number
b = 1  # Second Fibonacci number
print(f"First {rng} numbers of Fibonacci series are:")  # Display the header for Fibonacci series

i = 0
while i < rng:  # Loop until the required number of Fibonacci numbers are printed
    print(a)  # Print the current Fibonacci number
    a, b = b, a + b  # Update 'a' and 'b' to the next Fibonacci numbers
    i += 1  # Increment the counter to keep track of how many numbers have been printed
