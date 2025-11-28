print("This program demonstrates how to concatenate two dictionaries into a new one.")
print("-------------------------------------------------------------")

# Initialize two dictionaries: salary and cars
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
print("Original dictionary (salary):", salary)
print("Original dictionary (cars):", cars)

# Concatenate the two dictionaries into a new one
print("\nNow, we will concatenate the two dictionaries into a new dictionary.")

concatenated_dict = salary.copy()  # Create a copy of the 'salary' dictionary
concatenated_dict.update(cars)  # Use the update method to add items from 'cars' dictionary

# Display the concatenated dictionary
print("Concatenated dictionary:", concatenated_dict)
