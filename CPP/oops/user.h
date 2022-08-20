#ifndef USER_H // for protection from including it twice we use this.
#define USER_H

class User {
	std::string status = "Platinum";
	static int user_count;   // associated with Class instead of each object.
public:
	static int get_user_count();  // can only access other static memebers.
	std::string first_name;
	std::string last_name;
	std::string get_status();
	void set_status(std::string status);
	User();
	User(std::string first_name, std::string last_name, std::string status);
	~User();
	virtual void output();  // virtual means it can be overridden in sub classes. otherwise it can't be overridden
	// Friend function operator overload.
	friend std::ostream& operator << (std::ostream& output, const User user);
	friend std::istream& operator >> (std::istream &input, User &user);
	// friend void output_status(User user); //friend function to get access of private members in methods outside class.
};
#endif