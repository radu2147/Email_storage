#include "service.h"

void Service::serv_add(string u, string em, string pass, string plat)
{
	auto e = Email(u, em, pass, plat);
	v.validate(e);
	r.add(e);
	notify();
}

bool Service::substr(string str1, string str2) const
{
	bool ok = false;
	for (unsigned int i = 0; i < str1.size(); i++) {
		if (str1[i] == str2[0])
		{
			ok = true;
			for (unsigned int j = i; j < i + str2.size(); j++)
			{
				if (j < str1.size()) {
					if (str1[j] != str2[j - i]) {
						ok = false;
						break;
					}
				}
				else {
					ok = false;
					break;
				}
			}
			if (ok == true)
				return true;
		}
	}
	return ok;
}

void Service::serv_upd(string u, string em, string pass, string plat)
{
	auto e = Email(u, em, pass, plat);
	v.validate(e);
	r.update(e);
	notify();
}

vector<Email>& Service::get_emails_of_user(string u) const
{
	return r.get_emails_from_user(Email(u, "doesn't_matter", "doesn't_matter", "doesn't_matter"));
}

vector<Email> Service::filter(string s1, string user) const {
	
	if (s1 == "") return get_emails_of_user(user);
	vector<Email> vs;
	for (const auto& el : get_emails_of_user(user)) {
		if (substr(el.get_plat(), s1)) {
			vs.push_back(el);
		}
	}
	return vs;
}

const vector<string>& ServiceUser::all() const
{
	// TODO: insert return statement here
	return r.get_all();
}

void ServiceUser::login(const string& el)
{
	auto it = find_if(r.get_all().begin(), r.get_all().end(), [&el](const string& ot) {return ot == el; });
	if (it == r.get_all().end())
		throw exception("User inexistent");

}

void ServiceUser::serv_add(const string& a)
{
	if (a == "") throw exception("invalid");
	r.add(a);
}
