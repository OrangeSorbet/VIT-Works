print("This program concatenates two dictionaries by updating one with another.")
print("-------------------------------------------------------------")

# Initial dictionaries
salary = {
    'John': 700,
    'Alex': 800,
    'Richard': 750
}

cars = {
    'BMW': 20000,
    'Audi': 30000,
    'Mercedes': 40000
}

# Display the original dictionaries
print("Original dictionary:", salary)
print("Original dictionary:", cars)

# Concatenate the two dictionaries
print("\nNow, we will concatenate the two dictionaries.")
salary.update(cars)  # Update salary dictionary with cars dictionary

# Display the updated dictionary
print("Concatenated dictionary:", salary)
