#include "resonator.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Resonator w;
	w.setWindowIcon(QIcon("pic/ava.ico"));
	w.show();
	return a.exec();
}
