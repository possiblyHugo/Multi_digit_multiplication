# Multi-Digit Multiplication Visualizer

This project is a multi-digit multiplication visualizer, created to demonstrate the step-by-step process of multiplying two multi-digit numbers and visualize the intermediate results.

## Overview

The code is written in C++ and consists of the following main functions:

### `get_digits(int number)`

This function takes an integer `number` as input and returns a vector of its individual digits. It separates the digits of the given number and stores them in reverse order in the vector. For example, if `number` is 123, the function will return a vector containing {3, 2, 1}.

### `print_header(std::vector<int>& nums, int rows_amount, bool second_number)`

This function prints the header for the multiplication visualization. It takes a vector of integers `nums` representing the individual digits of the number to be printed, the `rows_amount` indicating the number of rows in the multiplication process, and a boolean flag `second_number` that indicates whether the header is for the second number in the multiplication.

### `print_line(int amount)`

This function prints a horizontal line to separate different rows in the multiplication visualization. It takes the `amount` of rows as input and prints a line accordingly.

### `main()`

The main function handles user input and performs the multi-digit multiplication. It takes two integers as input, multiplies them step-by-step, and then displays the visual representation of the multiplication process.

## Points of Interest

The following points could be highlighted when showcasing this project:

1. **Algorithmic Approach**: An algorithm is implemented to perform multi-digit multiplication without relying on language-specific or built-in multiplication functions. This demonstrates a problem-solving and algorithmic skills.

2. **Data Manipulation**: The use of vectors and unordered maps to store and manipulate intermediate results shows an ability to work with complex data structures.

3. **Visual Representation**: The program provides a visual representation of the multiplication process, making it easy to understand and follow.

4. **Code Organization**: The code is divided into functions, each with a specific purpose, making it more readable, modular, and maintainable.

5. **Input Handling**: The program handles user input for two multi-digit numbers, demonstrating consideration for user experience and error handling.

## How to Use

1. Clone this repository to your local machine.

2. Compile the C++ code using your preferred C++ compiler.

3. Run the compiled executable.

4. Follow the on-screen instructions to input the two multi-digit numbers you want to multiply.

5. The program will display the step-by-step visual representation of the multiplication process along with the final result.

Enjoy exploring the world of multi-digit multiplication!
