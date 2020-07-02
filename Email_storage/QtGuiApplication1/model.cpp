#include "model.h"

string Email::get_user() const
{
	return user;
}

string Email::get_email() const
{
	return email;
}

string Email::get_pass() const
{
	return password;
}

string Email::get_plat() const
{
	return platforma;
}

void Email::set_pass(string pass)
{
	password = pass;
}
