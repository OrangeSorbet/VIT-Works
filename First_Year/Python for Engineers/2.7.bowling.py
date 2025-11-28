print("This program simulates a bowling game. Given the number of pins and balls rolled, it will determine which pins remain standing after all the rolls.")
print("------------------------------------------------------------")

# Take the number of pins and balls rolled as input
N = int(input("Enter the number of pins to display: "))
K = int(input("Enter the number of balls rolled: "))
print("----------------------------------------------------------------------------")
print("Bowling pins are represented as 'I'")  # 'I' for pins standing
print("Knocked pins are represented as '.'")  # '.' for pins knocked down
print("----------------------------------------------------------------------------")
print("Initial pin state:")
print("".join(["I"] * N))  # Print the initial state of all pins standing
print("----------------------------------------------------------------------------")

# Create a list representing the state of each pin ('I' means standing)
pins = ["I"] * N
# A holder to compare if any pin is knocked down
holder = ["I"] * N
# A reference for all pins knocked down (if all are knocked down, it's a strike)
strike = ["."] * N

# Loop for each ball rolled
j = 1
for _ in range(K):
    while True:
        # Ask user to input the range of knocked pins
        start, end = map(int, input("Enter range of knocked pins (start end): ").split())
        # Check if the range is valid
        if start < 1 or end > N or start > end:
            print("Invalid range. Please enter valid pin numbers.")  # Prompt for valid input
        else:
            break  # Exit the loop if the range is valid
    
    # Knock down the pins within the specified range
    for i in range(start - 1, end):
        pins[i] = "."  # Set the pin as knocked down ('.')
    
    # Print the pin state after each roll
    print(f"Pins after rolling the ball {j}: {''.join(pins)}")
    j += 1
    print("----------------------------------------------------------------------------")

# Print the final pin state after all balls have been rolled
print("Final pin state:")
print("".join(pins))

# Check if no pins were knocked down
if pins == holder:
    print("No pins were knocked down!!")

# Check if all pins are knocked down (strike condition)
if pins == strike:
    print("STRIKE!")

print("----------------------------------------------------------------------------")
