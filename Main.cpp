#include <iostream> // std::cout, std:cin
#include <vector> // std::vector
//#include <algorithm> // std::reverse
#include <unordered_map> // std::unordered_map


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

	// Hash map
	int rows_amount = second_number_split.size();
	std::unordered_map<int, std::vector<int>> rows_data;

	// Multiplication
	bool carry_number = false;

	for (int num2 = 0; num2 < second_number_split.size(); num2++) // Row 1 (first number)
	{
		for (int num1 = 0; num1 < first_number_split.size(); num1++) // Row 2 (second number)
		{
			int result = second_number_split[num2] * first_number_split[num1];
			
			if (carry_number) // If number previous was > 10, add 1 to account for carrying digit
			{
				result++;
				carry_number = false;
			}
			else if (result >= 10)
			{
				carry_number = true;
			}

			rows_data[num2].push_back(result);

		}
	}

	// Display
	for (int row = 0; row < rows_amount; row++)
	{
		for (int number = 0; number < rows_data[row].size(); number++)
		{
			std::cout << rows_data[row][number] << " ";

		}
		std::endl;
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

	//std::reverse(digits.begin(), digits.end()); // digits are in reverse (3, 2, 1), this sets them back to the original splitted int)

	return digits;
}