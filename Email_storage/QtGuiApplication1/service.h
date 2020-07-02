#pragma once
#include"repo.h"
#include"observer.h"
#include"validator.h"
#include<functional>

class Service : public Observable{
	Repo& r;
	Validator& v;
	bool substr(string str1, string str2) const;
public:
	Service(Repo& r, Validator& v) :r{ r }, v{ v }{

	}
	void serv_add(string u, string em, string pass, string plat);

	void serv_upd(string u, string em, string pass, string plat);

	vector<Email>& get_emails_of_user(string u) const;

	vector<Email> filter(string s1, string user) const;
};

class ServiceUser {
	RepoUser& r;
	ValidUser& val;
public:
	ServiceUser(RepoUser& r, ValidUser& v) :r{ r }, val{ v }{

	}
	const vector<string>& all() const;
	void login(const string& el);
	void serv_add(const string& a);
};