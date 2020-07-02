#include "QtGuiApplication1.h"
#include "ActivGUI.h"
#include "tests.h"
#include <QtWidgets/QApplication>


using namespace std;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Validator v;
	ValidUser va;
	string filename{ "act.txt" };
	Repo u{ filename };
	filename = "users.txt";
	RepoUser r{ filename };
	Service s{ u, v };

	ServiceUser aux{ r, va };
	LoginWidget g{ aux, s };

	g.main.show();
	a.exec();

	return 0;
}
