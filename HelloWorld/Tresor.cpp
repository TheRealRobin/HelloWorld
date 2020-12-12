#include "Tresor.h"
#include <iostream>
//Ein Tresor hat Zahlenkombi 5397 -> öffnet sich bei richtiger eingabe

using namespace std;

const int pass = 5397;

bool checkPin(int pin) {
	if (pin == pass) {
		cout << "\n\n[SUCCESS YOU ARE RICH NOW]\n\n";
		return true;
	}
	else {
		cout << "\n\n[SORRY WRONG PIN]\n\n";
		return false;
	}
}

void runTresor() {
	int pin;
	do {
		cout << "[ TRESOR ]\n" << "[  INPUT ]\n" << "[PASSWORD]\n\n";
		cout << "[____]\r[";
		cin >> pin;
	} while (checkPin(pin) == false);
	system("pause");
}