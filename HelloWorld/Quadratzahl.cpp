//Eingabe: Zahl zw. 1. und 10
//Ausgabe: alle Zahlen zw 1 und wert mit Quadrat und Kubik
//Zeug dass es geht
#include <cmath>
#include <iostream>
#include "Quadratzahl.h"
using namespace std;

//Hauptmethode
void squareAndStuff() {

	//Wenn eine Zahl <1 oder >10 eingegeben wird, soll nochmal gefragt werden.
	int inputNumber;
	bool runAgain = true;
	while (runAgain) {

		//Eingabe der Zahl
		cout << "Zahl zwischen 1 und 10 eingeben: ";
		cin >> inputNumber;

		//Wenn die Zahl richtigerweise zw. 1 und 10 liegt, wird das ganze ausgeführt und danach beendet.
		if (inputNumber <= 10 && inputNumber >= 1) {
			runAgain = false;

			//Eigentliches Berechnen und Ausgeben
			for (int i = 1; i <= inputNumber; i++) {
				cout << "Aktuelle Zahl: " << i << endl;
				cout << "Quadratzahl:   " << pow(i, 2) << endl;
				cout << "Kubikzahl:     " << pow(i, 3) << endl;
				cout << endl;
			}
			system("pause");
		}

		//Wenn die Zahl nicht richtig eingegeben wurde, wird man nochmal gefragt
		else {
			runAgain = true;
		}
	}
}