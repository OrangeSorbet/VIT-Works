print("This program calculates the roots of a quadratic equation ax² + bx + c = 0")
print("------------------------------------------------------------")

def quadraticRoots(a, b, c):
    # Calculate the discriminant
    d = (b**2) - (4*a*c)

    # If discriminant is less than 0, roots are imaginary
    if d < 0:
        return "Imaginary Roots"
    # If discriminant is 0, both roots are real and equal
    elif d == 0:
        r = -b / (2 * a)
        return r, -r
    # If discriminant is positive, roots are real and different
    else:
        r1 = (-b + d**0.5) / (2 * a)
        r2 = (-b - d**0.5) / (2 * a)
        return f"{r1:.2f}", f"{r2:.2f}"

# Take inputs from the user
a = int(input("Enter coefficient of x²: "))
b = int(input("Enter coefficient of x: "))
c = int(input("Enter constant: "))

# Display the quadratic equation
print(f"Equation is: {a}x² + {b}x + {c} = 0")

# Call the function and print the roots
print("Roots are:", quadraticRoots(a, b, c))
