#include <iostream> // std::cout, std:cin
#include <vector> // std::vector
#include <algorithm> // std::reverse
#include <unordered_map> // std::unordered_map
#include <iomanip> // std::setw


// Functions
std::vector<int> get_digits(int number);
void print_header(std::vector<int>& nums, int rows_amount, bool second_number = false);
void print_line(int amount);

int main()
{
	// Vars
	int first_number, second_number;
	first_number, second_number = 0, 0;

	// Start
	std::cout << "Multi-digit multiplication calculator." << std::endl;
	
	// Inputs
	std::cout << "Please input the first number: " << std::endl;
	std::cin >> first_number;

	std::cout << "Please input the second number: " << std::endl;
	std::cin >> second_number;

	// Math start
	std::vector<int> first_number_split = get_digits(first_number);
	std::vector<int> second_number_split = get_digits(second_number);

	// Hash map
	int rows_amount = second_number_split.size();
	std::unordered_map<int, std::vector<int>> rows_data;

	// Multiplication

	for (int num2 = 0; num2 < second_number_split.size(); num2++) // Row 1 (first number)
	{
		int carry_amount = 0;
		for (int num1 = 0; num1 < first_number_split.size(); num1++) // Row 2 (second number)
		{
			int result = second_number_split[num2] * first_number_split[num1];


			if (carry_amount > 0) // If number previous was > 10, add 1 to account for carrying digit
			{
				result += carry_amount;
				carry_amount = 0;
			}
			
			if (result >= 10 && num2 != second_number_split.size()) // Add new carrying digit
			{
				carry_amount = result / 10;
			}

			if (result > 10)
			{
				result = result % 10;
			}

			rows_data[num2].push_back(result);

		}
	}




	// Display Header
	print_header(first_number_split, rows_amount);
	print_header(second_number_split, rows_amount, true);
	
	print_line(rows_amount);

	// Display Rows

	for (int row = 0; row < rows_amount; row++) 
	{
		// Reverse row to display properly
		std::reverse(rows_data[row].begin(), rows_data[row].end());
		
		// Add zeros to account for offset

		for (int zero = 0; zero < row && row != 0; zero++)
		{
			rows_data[row].push_back(0);
		}

		// Formatting
		std::cout << std::setw((rows_amount * 2) - (row * 2)); // Algorithm to display offsets properly

		for (int number = 0; number < rows_data[row].size(); number++)
		{
			std::cout << rows_data[row][number] << " ";

		}
		std::cout << std::endl; // Separate row
	}

	// Print Result
	
	print_line(rows_amount);


	for (int digit = 0; digit < rows_data[rows_amount - 1].size(); digit++) // Uses last element in map because it's the largest one
	{
		int sum = 0;
		for (int row = 0; row < rows_amount; row++)
		{
			int index = (rows_data[row].size() - 1) - digit;

			if (index < 0)
			{
				continue; // Account for out of range vectors;
			}

			sum += rows_data[row][index];

			std::cout << rows_data[row][index] << " ";
		}
		std::cout << " = " << sum << std::endl;
		sum = 0;
	}

	return 0;
}

std::vector<int> get_digits(int number)
{	
	int digit_place = number;
	std::vector<int> digits;

	while (digit_place != 0)
	{
		digits.push_back(digit_place % 10); // Get rightmost digit
		digit_place /= 10; // Moves one digit to the left
	}

	return digits;
}


void print_header(std::vector<int>& nums, int rows_amount, bool second_number)
{
	std::cout << std::setw((rows_amount * 2));
	for (int digit = nums.size() - 1; digit >= 0; digit--)
	{
		std::cout << nums[digit] << " ";
	}

	if (second_number)
	{
		std::cout << " x"; // Add Multiplication sign
	}

	std::cout << std::endl;
}

void print_line(int amount)
{
	for (int i = 0; i < amount * 5; i++)
	{
		std::cout << "-";
	}
	std::cout << std::endl;
}
