#include <iostream>
#include <vector>
#include <string>
#include "user.h"
// structs follow POD :- Plain Old Data, generally we don't put any
// functionality in structs. Structs are used for smaller objects and classes
// are used for larger objects. Access modifiers :-
// public,private,protected :- In structs by deafult the access is public,
// but in classes it's by default private.
/*
struct User {
	std::string first_name;
	std::string last_name;
	std::string get_status() {
		return status;
	}
private:  /// can't access private members outside the class or struct
	std::string status = "Platinum";
	// int age;
};  //end the struct with ;
*/
// class User {
// 	std::string status = "Platinum";
// 	static int user_count;   // associated with Class instead of each object.

// public:
/*static*/ int User::get_user_count() {   // can only access other static memebers.
	return user_count;
}
// std::string first_name;
// std::string last_name;
std::string User::get_status() {
	return status;
}
void User::set_status(std::string status) {
	if (status == "Gold" || status == "Diamond") {
		this->status = status;
	}
	else {
		this-> status = "No status";
	}
}
User::User() {
	std::cout << "User created\n";
	user_count ++;
}
User::User(std::string first_name, std::string last_name, std::string status) {
	this-> first_name = first_name;
	this-> last_name = last_name;
	this-> status = status;
	user_count++;
}
User::~User() {
	// std::cout << "Destructor" << "\n";
	user_count--;
}
void User::output() {
	std::cout << "I am a user\n";
}
// Friend function operator overload.
/*friend*/ std::ostream& operator << (std::ostream& output, const User user);
/*friend*/ std::istream& operator >> (std::istream &input, User &user);
// friend void output_status(User user); //friend function to get access of private members in methods outside class.
// };

int User::user_count = 0; // class is just a structure so we can't assign static values inline, instead assign values outside. Class is not usable until we define some memory for the class. So we need to define a variable and assign some memory to it, so that we can use static stuff.

// void output_status(User user) { // standalone function to get private member status, it is not a part of class. It can be called independently.
// 	std::cout << user.status << "\n";
// }

int add_user_if_not_exists(std::vector<User> &users, User user) {
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].first_name == user.first_name && users[i].last_name == user.last_name) {
			return i;
		}
	}
	users.push_back(user);
	return users.size() - 1;
}

std::ostream& operator << (std::ostream& output, const User user) {  // cout is of type std::ostream and to reference it Add & after it, so that the change is reflected.
	output << "First Name: " << user.first_name << "\nLast Name: " << user.last_name << "\nStatus: " << user.status << "\n";
	return output;
}

std::istream& operator >> (std::istream &input, User &user) {
	input >> user.first_name >> user.last_name >> user.status;
	return input;
}