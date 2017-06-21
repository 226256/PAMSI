#include "window.h"
#include "pracownikmpk.h"
#include "mojatrasa.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window w;
    w.setWindowTitle("Jak dojadę");
    w.setGeometry(100, 100, 500, 400);
    w.show();

    Siec MPK;
    PracownikMPK::TworzTablicePrzystankow(MPK);
    PracownikMPK::StworzLinie(MPK);
    MPK.OrganizujSiec();

    w.UstawSiec(MPK);

    return a.exec();
}
