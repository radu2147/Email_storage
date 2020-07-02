#pragma once
#include<string>

using namespace std;

class Email {
	string user;
	string email;
	string password;
	string platforma;
public:
	Email(string user, string email, string password, string platforma) :user{ user }, email{ email }, password{ password }, platforma{ platforma }{

	}
	string get_user() const;
	string get_email() const;
	string get_pass() const;
	string get_plat() const;
	void set_pass(string pass);
};