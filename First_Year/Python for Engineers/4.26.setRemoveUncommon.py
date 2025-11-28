print("This program removes items from set1 that are not common to both set1 and set2.")
print("-------------------------------------------------------------")

# Original sets
set1 = {'BMW', 'Audi', 'Mercedes', 'Toyota', 'Honda'}
set2 = {'Ford', 'Chevrolet', 'Nissan', 'Kia', 'Hyundai', 'Toyota', 'Honda'}

# Display original sets
print("Original set1:", set1)
print("Original set2:", set2)

# Remove items from set1 that are not common to both set1 and set2
set1.intersection_update(set2)

# Display updated set1
print("Updated set1:", set1)
