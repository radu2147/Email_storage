#pragma once
#include"model.h"
#include<vector>
#include<vector>
#include<map>
#include<fstream>
#include<algorithm>

class Repo {
	map<string, vector<Email>> vec;
	string filename;
	void load();
	void write();
public:
	Repo(string file) :filename{ file } {
		load();
	}
	void add(const Email& em);
	void update(const Email& em);
	vector<Email>& get_emails_from_user(const Email& em);

	~Repo() {
		write();
	}
};

class RepoUser {
	vector<string> vec;
	string filename;
	void load();
	void write();
public:
	RepoUser(string fil) :filename{ fil } {
		load();
	}
	const vector<string>& get_all() const;
	void add(string s);
	~RepoUser() {
		write();
	}
};