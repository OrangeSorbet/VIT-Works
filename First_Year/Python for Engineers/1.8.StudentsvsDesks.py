# Print what the code does
print("This program calculates the minimum number of desks needed for three classrooms.")
print("Each desk sits two students. The program will read the number of students in three classes and calculate the required desks.")

print("------------------------------------")

# Input the number of students in each class
a = int(input("Enter number of students in class 1: "))
b = int(input("Enter number of students in class 2: "))
c = int(input("Enter number of students in class 3: "))

# Calculate the number of desks needed for each class
d1 = a // 2 + a % 2  # Divide the number of students by 2, add 1 if there's an odd number of students
d2 = b // 2 + b % 2  # Similarly, calculate for class 2
d3 = c // 2 + c % 2  # Similarly, calculate for class 3

# Output the number of desks for each class
print("Number of desks in class 1 is", d1)
print("Number of desks in class 2 is", d2)
print("Number of desks in class 3 is", d3)

# Output the total number of desks needed
print("Total number of desks is", d1 + d2 + d3)
