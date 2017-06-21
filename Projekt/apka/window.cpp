#include "window.h"
#include "ui_window.h"

QString Start;
QString Stop;
QString Wyswietl;

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
}

Window::~Window()
{
    delete ui;
}

void Window::on_findButton_clicked()
{
    Wykonaj();
}

void Window::UstawSiec(Siec &MPK) {
    siec = MPK;
}

void Window::Wykonaj() {

    std::string Poczatek;
    std::string Koniec;
    std::string display;
    Poczatek = Start.toStdString();
    Koniec = Stop.toStdString();


    auto lista = siec.ZnajdzNajkrotszaDroge(Poczatek, Koniec);
    MojaTrasa* trasa = new MojaTrasa(lista);
    ParaLiniaPrzystanek* tablica = trasa->WytyczTrase(siec);

    if(tablica!= nullptr) {
            for (int i = 0; i < trasa->getLiczbaPrzystankowDoPrzejechania(); ++i) {
                if (tablica->liniaznak == ';' && tablica->linia!=1111) {
                    ostringstream temp;
                    display += "Linia ";
                    temp << tablica[i].linia;
                    display += temp.str();
                    display += " Przystanek ";
                    display += tablica[i].przystanek;
                    display += "\n";
                }
                else if (tablica->linia == 1111) {
                    display += "Linia ";
                    display += tablica[i].liniaznak;
                    display += " Przystanek ";
                    display += tablica[i].przystanek;
                    display += "\n";
                }
                else {
                    display += "Linia ";
                    display += tablica[i].linia;
                    display += tablica[i].liniaznak;
                    display += " Przystanek ";
                    display += tablica[i].przystanek;
                    display += "\n";
                }
            }
        }
        else {
            display += "Brak trasy";
            display += "\n";
    }

    Wyswietl = QString::fromStdString(display);
    ui->textEdit->setText(Wyswietl);

}

void Window::on_lineStart_editingFinished()
{
    Start = ui->lineStart->text();
}

void Window::on_lineStop_editingFinished()
{
    Stop = ui->lineStop->text();
}
