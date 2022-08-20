#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <array>
#include <fstream>

void save_score(int guess_count) {
	std::ifstream input("best_score.txt");
	if (!input.is_open()) {
		std::cout << "Unable to read the file!\n";
		return;
	}

	int best_score;
	input >> best_score;

	std::ofstream output("best_score.txt");
	if (!output.is_open()) {
		std::cout << "Unable to read the file!\n";
		return;
	}

	if (guess_count < best_score) {
		output << guess_count;
	} else {
		output << best_score;
	}
}

void print_stl_array(std::array<int, 251> array, int count) {
	for (int i = 0; i < count; ++i) {
		std:: cout << array[i] << "\t";
	}
	std::cout << "\n";
}

void print_array(int array[], int count) {
	for (int i = 0; i < count; i++) {
		std::cout << array[i] << "\t";
	}
	std::cout << "\n";
}

void print_vector(std::vector<int> vector) {
	for (int i = 0; i < vector.size(); i++) {
		std::cout << vector[i] << "\t";
	}
	std::cout << "\n";
}

void play_game() {
	std::cout << "Game is being played!\n";
	// int guesses[251];
	// int guess_count = 0;
	std::vector<int> guesses;
	// std::array<int, 251> guesses;

	int random = rand() % 251;
	std::cout << random << std::endl;
	while (true) {
		std::cout << "Guess a number : ";
		int guess;
		std::cin >> guess;
		guesses.push_back(guess);
		// guesses[guess_count++] = guess;
		// guess_count++;
		if (guess == random) {
			std::cout << "You win! Woohoo!\n";
			break;
		}
		else if (guess < random) {
			std::cout << "Guess is less than the number!\n";
		}
		else {
			std::cout << "Guess is greater than the number!\n";
		}
	}
	int guess_count = guesses.size();
	save_score(guess_count);
	// print_array(guesses, guess_count);
	print_vector(guesses);
	// print_stl_array(guesses, guess_count);
}

int main() {
	srand(time(NULL));   //Generating random number
	int choice;
	do {
		std::cout << "0.Quit\n1.Play Game\n";
		std::cin >> choice;

		switch (choice) {
		case 0:
			std::cout << "Thanks!\n";
			return 0;
		case 1:
			std::cout << "Yeah Let's Play!\n";
			play_game();
			break;
		}
	}
	while (choice != 0);
}