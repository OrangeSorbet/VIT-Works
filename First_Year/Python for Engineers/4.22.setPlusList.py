print("This program updates a set with a list of new cars provided by the user.")
print("-------------------------------------------------------------")

# Original set of car names
cars = {'BMW', 'Audi', 'Mercedes', 'Toyota', 'Honda', 'Ford', 'Chevrolet', 'Nissan', 'Kia', 'Hyundai'}

# Display the original set
print("Original set:", cars)

# Taking input from the user for new cars to add to the set
print("Now, give me a list to update to the set.")
car_string = str(input("Enter the list of cars (separated with spaces): \n").title())  # User inputs a string
new_cars = list(car_string.split())  # Split the input string into a list of car names

# Update the set with the new cars
cars.update(new_cars)

# Display the updated set
print("Updated set (set doesn't contain duplicates by default): \n", cars)
