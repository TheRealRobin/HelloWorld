#include "Nettopreis.h"
#include <iostream>
using namespace std;

//Definition der Mehrwertsteuer als globale Variable
float mwst = 0.16;

//Einstiegspunkt des Programms
void nettopreis()
{
	//Definition und Eingabe Nettopreis

	float nettopreis;

	cout << "Preis eingeben: ";
	cin >> nettopreis;

	//Berechnung und Ausgabe des Ergebnisses

	float preisMitMwst = nettopreis + (nettopreis * mwst);

	cout << "Preis mit Mehrwertsteuer: " << preisMitMwst << "\n";

	system("pause");
}