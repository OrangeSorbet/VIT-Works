# Print what the code does
print("This program calculates the coordinates of the fourth vertex of a rectangle given three vertices.")
print("It assumes that the rectangle's sides are parallel to the coordinate axes.")
print("The program will output the coordinates of the fourth vertex based on the given three.")

# Print the separator line
print("------------------------------------")

# Function to split input coordinates into x and y
def split(coor):
    coor = coor.split(",")
    coorx = int(coor[0])
    coory = int(coor[1])
    return coorx, coory

# Prompt user to enter coordinates of the three vertices
print("Enter the coordinates of three vertices of a rectangle to find the fourth vertex")
coor1 = input("Enter the coordinates of the first vertex (x,y): ")
coor1x, coor1y = split(coor1)
coor2 = input("Enter the coordinates of the second vertex (x,y): ")
coor2x, coor2y = split(coor2)
coor3 = input("Enter the coordinates of the third vertex (x,y): ")
coor3x, coor3y = split(coor3)

# Determine the fourth vertex's coordinates
if(coor1x == coor2x or coor2x == coor3x or coor3x == coor1x):
    if(coor1x == coor2x):
        coor4x = coor3x
    elif(coor2x == coor3x):
        coor4x = coor1x
    else:
        coor4x = coor2x
else:
    print("This doesn't form a rectangle")
    exit()

if(coor1y == coor2y or coor2y == coor3y or coor3y == coor1y):
    if(coor1y == coor2y):
        coor4y = coor3y
    elif(coor2y == coor3y):
        coor4y = coor1y
    else:
        coor4y = coor2y
else:
    print("This doesn't form a rectangle")
    exit()

# Output the coordinates of the fourth vertex
print("The fourth vertex is at", coor4x, ",", coor4y)
