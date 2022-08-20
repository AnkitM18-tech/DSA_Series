#include <iostream>
#include <fstream>
#include <vector>

int main() {
	/* Saving in output file
	std::string filename;
	std:: cin >> filename;

	std::ofstream file (filename.c_str(), std::ios::app);  //instance of ofstream called file
	// file.open("hello.txt"); --------> std::ios::app for appending
	if (file.is_open()) {
		std::cout << "success Noob" << std::endl;
	}
	std::vector<std::string> names;
	names.push_back("Ankit");
	names.push_back("Dristi");
	names.push_back("Kiara");
	// file << "hey humans!";
	for (std::string name : names) {
		file << name << std::endl;
	}

	file.close();*/

	/*
	//getting info from files
	std::ifstream file ("chicken.txt");
	std::vector<std::string> names; // std::vector<char> names
	std::string input;  // char input
	while (file >> input) {  // return true if read is successful. reads each string as one, doesn't consider entire line, space acts the end character. if we change it from string to char, then each character will be read sequentially.
		names.push_back(input);
	}
	for (std::string name : names) {    // char name
		std::cout << name << std::endl;
	}
	file.close();
	*/

	std::ifstream file ("chicken.txt");

	// char temp = file.get(); std::cout << temp << std::endl; only gets the very first character.
	std::string line;
	getline(file, line);  // get single line from file.
	std::cout << line << "\n";
	return 0;
}