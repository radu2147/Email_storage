#include "repo.h"

void Repo::load()
{
	ifstream f(filename);
	string u, e, p, plat;
	while (f >> u >> e >> p >> plat) {
		vec[u].push_back(Email(u, e, p, plat));
	}
	f.close();
}

void Repo::write()
{
	ofstream f(filename);
	for (const auto& el : vec) {
		for (const auto& cv : el.second) {
			f << cv.get_user() << " " << cv.get_email() << " " << cv.get_pass() <<  " " << cv.get_plat() << "\n";
		}
	}
	f.close();
}

void Repo::add(const Email& em)
{
	auto it = find_if(vec[em.get_user()].begin(), vec[em.get_user()].end(), [&](const Email& a) {return a.get_email() == em.get_email(); });
	if (it != vec[em.get_user()].end())
		throw exception("Nu exista");
	vec[em.get_user()].push_back(em);
}

void Repo::update(const Email& em)
{
	for (auto& el : vec[em.get_user()]) {
		if (el.get_email() == em.get_email())
		{
			el.set_pass(em.get_pass());
			return;
		}
	}
	throw exception("Emailul nu exista");
}

vector<Email>& Repo::get_emails_from_user(const Email& em)
{
	return vec[em.get_user()];
}

void RepoUser::load()
{
	ifstream f(filename);
	string s;
	while (f >> s) {
		vec.push_back(s);
	}
	f.close();
}

void RepoUser::write()
{
	ofstream g(filename);
	for (const auto& el : vec) {
		g << el << "\n";
	}
	g.close();
}

const vector<string>& RepoUser::get_all() const
{
	// TODO: insert return statement here
	return vec;
}

void RepoUser::add(string s)
{
	auto it = find_if(vec.begin(), vec.end(), [&](const string& a) {return a == s; });
	if (it != vec.end())
		throw exception("Nu exista");
	vec.push_back(s);
}
