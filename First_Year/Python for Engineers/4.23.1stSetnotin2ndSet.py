print("This program updates the first set with items that don’t exist in the second set.")
print("-------------------------------------------------------------")

# Original sets
set1 = {'BMW', 'Audi', 'Mercedes', 'Toyota', 'Honda'}
set2 = {'Ford', 'Chevrolet', 'Nissan', 'Kia', 'Hyundai', 'Toyota', 'Honda'}

# Display original sets
print("Original set1:", set1)
print("Original set2:", set2)

# Use the difference_update method to remove elements from set1 that are present in set2
set1.difference_update(set2)

# Display the updated set1
print("Updated set1 with items that don’t exist in set2:", set1)
