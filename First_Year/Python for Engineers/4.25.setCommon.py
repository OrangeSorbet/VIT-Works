print("This program finds common elements between two sets.")
print("-------------------------------------------------------------")

# Original sets
set1 = {'Toyota', 'Honda', 'BMW', 'Audi', 'Mercedes'}
set2 = {'Toyota', 'Honda', 'BMW', 'Chevrolet', 'Nissan', 'Kia', 'Hyundai'}

# Display original sets
print("Original set1:", set1)
print("Original set2:", set2)

# Find and display the common elements
common_elements = set1.intersection(set2)
print("Common elements are:", common_elements)

# Display the count of common elements
print(f"There are {len(common_elements)} common elements between set1 and set2.")
