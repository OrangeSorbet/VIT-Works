import random
import time

# Function to generate a random number without using 'random' library
def rand_num(min_value, max_value):
    # Get the current time in seconds since the epoch and multiply by 1000 to use milliseconds
    current_time = time.time()
    # Use modulus operation to ensure the generated value falls within the range
    random_value = int(current_time * 1000) % (max_value - min_value + 1) + min_value
    return random_value

# Display the introduction message for the user
print("Random number generator")
print("Enter the range of random numbers")

# Input range from the user
start = int(input("Start: "))
end = int(input("End: "))

# Generate and display a random number using the 'random' library
print(f"Generating random number using 'random' library between {start} and {end}")
print("Random number:", random.randint(start, end))

print("----------------------------------------------------------------------------")

# Generate and display a random number without using the 'random' library
print(f"Generating random number without using 'random' library between {start} and {end}")
print("Random number:", rand_num(start, end))
