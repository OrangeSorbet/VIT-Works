print("This program finds the car with the minimum and maximum price from the dictionary.")
print("-------------------------------------------------------------")

# Original dictionary with cars and their prices
cars = {
    'BMW': 20000,
    'Audi': 30000,
    'Mercedes': 40000,
    'Toyota': 15000,
    'Honda': 12000,
    'Ford': 10000,
    'Chevrolet': 11000,
    'Nissan': 13000,
    'Kia': 14000,
    'Hyundai': 16000
}

# Display the original dictionary
print("Original dictionary:", cars)

# Finding the key with the minimum and maximum value
min_key = min(cars, key=cars.get)
max_key = max(cars, key=cars.get)

# Display the key with minimum and maximum values
print("\nKey with minimum value:", min_key)
print("Key with maximum value:", max_key)

# Display the minimum and maximum values
print("\nMinimum value:", cars[min_key])
print("Maximum value:", cars[max_key])

# Sort the dictionary by values in ascending order
min_item = min(cars.items(), key=lambda x: x[1])
max_item = max(cars.items(), key=lambda x: x[1])
# Display the minimum and maximum items
print("\nMinimum item:", min_item)
print("Maximum item:", max_item)
