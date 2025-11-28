# Displaying the menu to the user
print("------------------")
print("Find area of circle or triangle")
print("------------------")
print("1. Circle")
print("2. Triangle")
print("3. Exit")
print("------------------")

# Get the user's choice for the shape
option = int(input("Enter your choice: "))

# Infinite loop to keep asking the user for input until they choose to exit
while True:
    print("------------------")  # Separator for each loop iteration
    if option == 1:  # If user selects option 1 for Circle
        # Get the radius of the circle from the user
        radius = float(input("Enter radius of circle: "))
        # Calculate the area of the circle using the formula: Area = π * r^2
        area = 3.14 * radius * radius
        print(f"Area of circle is {area}")  # Print the area of the circle
        break  # Exit the loop after calculating area of circle
    elif option == 2:  # If user selects option 2 for Triangle
        # Get the base and height of the triangle from the user
        base = float(input("Enter base of triangle: "))
        height = float(input("Enter height of triangle: "))
        # Calculate the area of the triangle using the formula: Area = 0.5 * base * height
        area = 0.5 * base * height
        print(f"Area of triangle is {area}")  # Print the area of the triangle
        break # Exit the loop after calculating area of triangle
    elif option == 3:  # If user selects option 3, exit the program
        print("------------------")
        print("Exiting program. Goodbye!")
        print("------------------")
        exit()
    else:  # If user enters an invalid option
        print("Invalid option. Please enter 1, 2, or 3.")
    
    # Ask for the user's choice again for the next calculation
    option = int(input("Enter your choice: "))