#include <iostream>
#include <vector>
#include <string>
#include "user.h"
#include "teacher.h"

void do_something(User& user) {
	user.output();
}

int main() {
	// User me;
	// me.first_name = "Ankit";
	// me.last_name = "Mohanty";
	// // me.status = "Platinum";
	// // me.age = 21;

	// std::cout << "First Name :- " << me.first_name << std::endl;
	// std::cout << "Last Name :- " << me.last_name << std::endl;
	// std::cout << "Status :- " << me.get_status() << std::endl;
	// std::cout << "Age :- " << me.age << std::endl;
	// User user;
	// user.first_name = "Ankit";
	/*
		std::vector<User> users;

		User user1, user2, user3;

		user1.first_name = "Sally";
		user1.last_name = "Swan";

		user2.first_name = "Jake";
		user2.last_name = "Johnson";

		user3.first_name = "Curt";
		user3.last_name = "Angel";

		users.push_back(user1);
		users.push_back(user2);
		users.push_back(user3);

		User user;
		user.first_name = "Jakob";
		user.last_name = "Johnson";

		std::cout << add_user_if_not_exists(users, user) << "\n";
		std::cout << users.size() << "\n";
	*/
	// std::cout << users[0].first_name << "\n";
	// User user("Ankit", "Mohanty", "Diamond");
	// std:: cout << user.first_name << "\t" << user.last_name << "\t" << user.get_status() << "\n";
	// User user, user1, user2, user3, user4;
	// user.set_status("Tacos");
	// std::cout << user.get_status() << "\n";
	// std::cout << User::get_user_count() << "\n";
	// user.~User();
	// user1.~User();
	// std::cout << User::get_user_count() << "\n";
	// User user;
	// std::cin >> user;

	// // user.first_name = "Jakob";
	// // user.last_name = "Johnson";
	// // user.set_status("Gold");

	// std::cout << user << std::endl;
	// output_status(user);
	Teacher teacher;  // constructor chaining --> first User then Teacher constructor will run
	User& u = teacher; // as teacher inherits from User it should work. and u will be of type teacher. Polymorphism -->
	do_something(u);
	// teacher.first_name = "Ankit";
	// std::cout << teacher.first_name << std::endl;
	// teacher.output();
	return 0;
}