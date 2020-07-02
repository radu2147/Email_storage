#include "QtGuiApplication1.h"

QtGuiApplication1::QtGuiApplication1(Service& s, string user) :s{ s }, user{ user } {
	model = new TableView(s.get_emails_of_user(user));
	dis->setModel(model);
	init();
	load(s.get_emails_of_user(user));
	connect();
}

void QtGuiApplication1::init()
{
	auto mainly = new QHBoxLayout;
	main.setLayout(mainly);
	main.setWindowTitle(QString::fromStdString(user));
	mainly->addWidget(dis);
	auto dr = new QVBoxLayout;
	mainly->addLayout(dr);
	auto form = new QFormLayout;
	form->addRow(new QLabel("Cont:"), email);
	form->addRow(new QLabel("Parola:"), pass);
	form->addRow(new QLabel("Platforma:"), plat);

	dr->addLayout(form);

	auto but = new QHBoxLayout;
	but->addWidget(add);
	but->addWidget(upd);
	but->addWidget(clear);

	dr->addLayout(but);
}

void QtGuiApplication1::load(vector<Email>& ot)
{
	model->change(ot);
}

void QtGuiApplication1::connect()
{
	QObject::connect(add, &QPushButton::clicked, [&]() {
		try {
			s.serv_add(user, email->text().toStdString(), pass->text().toStdString(), plat->text().toStdString());
			load(s.get_emails_of_user(user));
		}
		catch (exception& e) {
			QMessageBox::information(nullptr, "ERROR", QString::fromStdString(e.what()));
		}
	});
	QObject::connect(clear, &QPushButton::clicked, [&]() {
		try {
			email->setText("");
			pass->setText("");
			plat->setText("");
		}
		catch (exception& e) {
			QMessageBox::information(nullptr, "ERROR", QString::fromStdString(e.what()));
		}
		});
	QObject::connect(upd, &QPushButton::clicked, [&]() {
		try {
			s.serv_upd(user, email->text().toStdString(), pass->text().toStdString(), plat->text().toStdString());
			load(s.get_emails_of_user(user));
		}
		catch (exception& e) {
			QMessageBox::information(nullptr, "ERROR", QString::fromStdString(e.what()));
		}
		});
	QObject::connect(plat, &QLineEdit::textChanged, [&]() {
		auto vec = s.filter(plat->text().toStdString(), user);
		load(vec);
	});
	QObject::connect(dis->selectionModel(), &QItemSelectionModel::selectionChanged, [this]() {
		if (dis->selectionModel()->selectedIndexes().isEmpty()) {
			plat->setText("");
			email->setText("");
			pass->setText("");
			return;
		}
		int selRow = dis->selectionModel()->selectedIndexes().at(0).row();
		auto cel0Index = dis->model()->index(selRow, 0);
		auto cel1Index = dis->model()->index(selRow, 1);
		auto cel2Index = dis->model()->index(selRow, 2);
		auto cellValue = dis->model()->data(cel0Index, Qt::DisplayRole).toString();
		email->setText(cellValue);
		auto cel1Value = dis->model()->data(cel1Index, Qt::DisplayRole).toString();
		pass->setText(cel1Value);
		auto cel2Value = dis->model()->data(cel2Index, Qt::DisplayRole).toString();
		plat->setText(cel2Value);
			
	});
}

void LoginWidget::init()
{
	auto mainly = new QVBoxLayout;
	main.setLayout(mainly);
	auto form = new QFormLayout;
	form->addRow(new QLabel("Username:"), user);
	mainly->addLayout(form);

	auto but = new QHBoxLayout;
	mainly->addLayout(but);
	but->addWidget(login);
	but->addWidget(reg);
}

void LoginWidget::connect()
{
QObject::connect(login, &QPushButton::clicked, [&]() {
	try {
		s.login(user->text().toStdString());
		auto main = new QtGuiApplication1(mn, user->text().toStdString());
		main->main.show();
		this->main.close();
	}
	catch (exception& e) {
		QMessageBox::critical(nullptr, "Eroare", QString::fromStdString(e.what()));
	}
	
});
QObject::connect(reg, &QPushButton::clicked, [&]() {
	try {
		auto main = new RegisterWidget(s);
		main->main.show();
	}
	catch (exception& e) {
		QMessageBox::critical(nullptr, "Eroare", QString::fromStdString(e.what()));
	}

	});
}

void RegisterWidget::init()
{
	auto mainly = new QVBoxLayout;
	main.setLayout(mainly);
	auto form = new QFormLayout;
	form->addRow(new QLabel("Username:"), user);
	mainly->addLayout(form);
	mainly->addWidget(create);
}

void RegisterWidget::connect()
{
	QObject::connect(create, &QPushButton::clicked, [&]() {
		try {
			s.serv_add(user->text().toStdString());
			main.close();
		}
		catch (exception& e) {
			QMessageBox::critical(nullptr, "Eroare", QString::fromStdString(e.what()));
		}

		});
}
