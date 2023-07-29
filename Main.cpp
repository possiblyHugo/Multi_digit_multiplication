#include <iostream> // std::cout, std:cin
#include <vector> // std::vector
#include <algorithm> // std::reverse

// Functions
std::vector<int> get_digits(int number);

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

	// Multiply first row

	for (int second_number_digit = second_number_split.size(); second_number_digit > 0; second_number_digit--) // Number is taken from left to right, so it must read from right to left
	{
		for (int first_number_digit = first_number_split.size(); first_number_split > 0; first_number_split--)
		{
			// Multiply first digit with each number in the row
			int result = second_number_digit * first_number_digit;
			std::cout << second_number_digit << " " << first_number_digit << std::endl;
		}

	}

	// Display



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

	std::reverse(digits.begin(), digits.end()); // digits are in reverse (3, 2, 1), this sets them back to the original splitted int)

	return digits;
}