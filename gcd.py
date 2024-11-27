import numpy as np
import math

def matrix_multiply(A, B):
    return np.dot(A, B)

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

# Example usage:
if __name__ == "__main__":
    # Matrix multiplication example
    A = np.array([[1, 2], [3, 4]])
    B = np.array([[5, 6], [7, 8]])
    print("Matrix A:")
    print(A)
    print("Matrix B:")
    print(B)
    print("A * B:")
    print(matrix_multiply(A, B))

    # GCD example
    num1 = 48
    num2 = 18
    print(f"GCD of {num1} and {num2} is {gcd(num1, num2)}")