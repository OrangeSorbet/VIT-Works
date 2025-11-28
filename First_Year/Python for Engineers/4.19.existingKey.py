print("This program checks if a key exists in the dictionary.")
print("-------------------------------------------------------------")

# Initialize the cars dictionary
cars = {
    'Mclaren': 20000,
    'Audi': 30000,
    'Mercedes': 40000
}

# Display the original dictionary
print("Original dictionary:", cars)

# Ask the user for a key to check
key = input("Enter key to check if it exists in the dictionary: ").strip().capitalize()

# Check if the key exists in the dictionary
if key in cars:
    print("Key exists in the dictionary.")
else:
    print("Key does not exist in the dictionary.")
