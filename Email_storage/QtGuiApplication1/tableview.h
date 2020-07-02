#pragma once
#include<QAbstractTableModel>
#include"model.h"

class TableView : public QAbstractTableModel {
	vector<Email> el;
public:
	TableView(vector<Email>& ot) :el{ ot } {

	}
	int rowCount(const QModelIndex& parent = QModelIndex()) const override {
		parent;
		return el.size() + 1;
	}
	int columnCount(const QModelIndex& parent = QModelIndex()) const override {
		parent;
		return 3;
	}
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
		
		if (role == Qt::DisplayRole) {
			if (index.row() == 0) {
				if (index.column() == 0)
					return "Cont";
				if (index.column() == 1)
					return "Parola";
				if (index.column() == 2)
					return "Platforma";
			}
			if (index.column() == 0) {
				return QString::fromStdString(el[index.row() - 1].get_email());
			}
			if (index.column() == 1) {
				return QString::fromStdString(el[index.row() - 1].get_pass());
			}
			if (index.column() == 2) {
				return QString::fromStdString(el[index.row() - 1].get_plat());
			}
		}
		return QVariant();
	}
	void change(vector<Email>& ot) {
		el = ot;
		emit layoutChanged();
	}
};