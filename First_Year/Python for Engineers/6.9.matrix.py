import numpy as np
import math

# Function to multiply two matrices
def matrix_multiply(a, b):
    return np.dot(a, b)

# Function to add two matrices
def matrix_addition(a, b):
    return np.add(a, b)

# Function to subtract one matrix from another
def matrix_subtraction(a, b):
    return np.subtract(a, b)

# Function to generate a random 3x3 matrix with integers from 1 to 10
def random_matrix():
    return np.random.randint(1, 11, size=(3, 3))

# Function to display matrix properties and values
def display_matrix_info(matrix, operation_name):
    print(f"\n{operation_name} Result:")
    print(f"Matrix Shape: {matrix.shape}")               # Shape (rows, columns)
    print(f"Matrix Dimensions: {matrix.ndim}")           # Number of dimensions
    print(f"Matrix Dtype: {matrix.dtype}")               # Data type of matrix elements
    print(f"Matrix Rank: {np.linalg.matrix_rank(matrix)}") # Matrix rank
    print(f"Flattened Output: {matrix.flatten()}")       # Flattened 1D version of matrix
    print(matrix)                                        # Display the matrix

# Main function to execute the operations
def main():
    print("Matrix Operations for 2 Random Matrices")
    print("-------------------------------------")
    
    # Generate two random 3x3 matrices
    matrix1 = random_matrix()
    matrix2 = random_matrix()
    
    print("\nMatrix 1:")
    print(matrix1)
    
    print("\nMatrix 2:")
    print(matrix2)
    
    # Perform and display addition of the two matrices
    result_add = matrix_addition(matrix1, matrix2)
    display_matrix_info(result_add, "Addition")

    # Perform and display subtraction of the two matrices
    result_sub = matrix_subtraction(matrix1, matrix2)
    display_matrix_info(result_sub, "Subtraction")

    # Perform and display multiplication of the two matrices
    result_mul = matrix_multiply(matrix1, matrix2)
    display_matrix_info(result_mul, "Multiplication")

# Run the main function when the script is executed
if __name__ == "__main__":
    main()
