print("This program returns a set of elements present in Set A or B, but not both.")
print("-------------------------------------------------------------")

# Original sets
set1 = {'Toyota', 'Honda', 'BMW', 'Audi', 'Mercedes'}
set2 = {'Toyota', 'Honda', 'BMW', 'Chevrolet', 'Nissan', 'Kia', 'Hyundai'}

# Display original sets
print("Original set1:", set1)
print("Original set2:", set2)

# XOR operation to find elements present in either set1 or set2, but not both
set3 = set1 ^ set2

# Display the result
print("XOR set3 (elements in Set A or B, but not both):", set3)
