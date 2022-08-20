#include <iostream>
#include <vector>

int main() {
//  multi dimensional array --> we have to mention the second size i.e the number of 1-D arrays.
	std::vector<std::vector<int>> grades = {
		{1, 2, 3, 5},
		{4, 5, 6},
		{7, 8, 9}
	};
	std::cout << grades.size() << "\n";
	for (int i = 0; i < grades.size(); i++)
	{
		for (int j = 0; j < grades[i].size(); j++)
		{
			std::cout << grades[i][j] << "\t";
		}
		std::cout << "\n";
	}

	/*

	int grades[][3] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			std::cout << grades[r][c] << "\t";
		}
		std::cout << "\n";
	}
	*/
	return 0;
}