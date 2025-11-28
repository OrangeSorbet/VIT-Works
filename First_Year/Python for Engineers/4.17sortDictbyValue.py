print("This program sorts a dictionary by its values (salaries) in ascending and descending order.")
print("-------------------------------------------------------------------------------------------")

# Initialize a dictionary with names and their corresponding salaries
salary = {
    'John': 7500,
    'Alex': 4700,
    'Richard': 3400
}

# Display the original dictionary
print("Original dictionary:", salary)

# Sort the dictionary by values in ascending order
sorted_asc = dict(sorted(salary.items(), key=lambda x: x[1]))
print("\nSorted dictionary by values (Ascending):", sorted_asc)

# Sort the dictionary by values in descending order
sorted_desc = dict(sorted(salary.items(), key=lambda x: x[1], reverse=True))
print("Sorted dictionary by values (Descending):", sorted_desc)