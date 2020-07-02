#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_QtGuiApplication1.h"
#include"service.h"
#include"tableview.h"
#include<QListWidget>
#include<QLineEdit>
#include<QLabel>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QFormLayout>
#include<QPushButton>
#include<QMessageBox>
#include<QTableView>

class QtGuiApplication1 : public QWidget, public Observer
{
	Q_OBJECT

public:
	QtGuiApplication1(Service& s, string user);
	QWidget main;
private:
	Service& s;
	string user;
	void init();
	void load(vector<Email>& ot);
	void connect();
	void update() {
		load(s.get_emails_of_user(user));
	}

	TableView* model;
	QTableView* dis = new QTableView;
	QPushButton* add = new QPushButton("&Add");
	QPushButton* upd = new QPushButton("&Update");
	QPushButton* clear = new QPushButton("&Clear");
	
	QLineEdit* email = new QLineEdit;
	QLineEdit* pass = new QLineEdit;
	QLineEdit* plat = new QLineEdit;

};

class LoginWidget : public QWidget {
	ServiceUser& s;
	Service& mn;
	void init();
	void connect();
	QLineEdit* user = new QLineEdit;
	QPushButton* login = new QPushButton("&Login");
	QPushButton* reg = new QPushButton("&Register");
public:
	QWidget main;
	LoginWidget(ServiceUser& s, Service& m) :s{ s }, mn{ m } {
		init();
		connect();
	}
};

class RegisterWidget : public QWidget {
	ServiceUser& s;
	void init();
	void connect();
	QLineEdit* user = new QLineEdit;
	QPushButton* create = new QPushButton("&Create");
public:
	QWidget main;
	RegisterWidget(ServiceUser& s) : s{ s } {
		init();
		connect();
	}
};