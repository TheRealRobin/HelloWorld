/*include <iostream>
using namespace std;

//Definition der Mehrwertsteuer als globale Variable
float mwst = 0.16;

//Einstiegspunkt des Programms
int main()
{
	//Definition und Eingabe Nettopreis
	
	float nettopreis;

	cout << "Preis eingeben: ";
	cin >> nettopreis;
	
	//Berechnung und Ausgabe des Ergebnisses

	float preisMitMwst = nettopreis+(nettopreis*mwst);
	
	cout << "Preis mit Mehrwertsteuer: " << preisMitMwst << "\n";

	system("pause");
}
*/
/*
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float a, b, c, x, y;
	cout << "y = ax^2+bx+c:\n";
	cout << "input a: ";
	cin >> a;
	cout << "\ninput b: ";
	cin >> b;
	cout << "\ninput c: ";
	cin >> c;
	cout << "\ninput x: ";
	cin >> x;
	
	y = a * pow(x, 2) + b * x + c;
	cout << "\n" << a << " * " << x << " ^2 + " << b << " * " << x << " + " << c << " = " << y << "\n";
	system("pause");
}
*/
/*
//Ein Tresor hat Zahlenkombi 5397 -> öffnet sich bei richtiger eingabe
#include <iostream>
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

int main() {
	int pin;
	do {
		cout << "[ TRESOR ]\n" << "[  INPUT ]\n" << "[PASSWORD]\n\n";
		cout << "[____]\r[";
		cin >> pin;
	} while (checkPin(pin) == false);
	system("pause");
}*/
/*
//Eingabe: Zahl zw. 1. und 10
//Ausgabe: alle Zahlen zw 1 und wert mit Quadrat und Kubik
//Zeug dass es geht
#include <cmath>
#include <iostream>
using namespace std;

//Hauptmethode
int main() {

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
}*/
/*
#include <string>
#include <iostream>
using namespace std;

//Strukturen sind eine Art Datenbündel, um Daten zu bündeln
struct Person {
	string last_name;
	string first_name;
	int alter;
	int id;
	string job;
};

struct Address {
	string street;
	string city;
	int zipcode;
	int mailnumber;
};

//Man kann auch Datenbündel bündeln
struct PersonWithAddress {
	struct Person person;
	struct Address address;
};

int main() {
		
	struct PersonWithAddress mustermann;

	struct Gruppe test1[3];

	//structOber.structUnter.Var
	mustermann.person.id = 3;
	mustermann.person.alter = 42;
	mustermann.person.first_name = "Max";
	mustermann.person.last_name = "Mustermann";
	mustermann.person.job = "Arbeitsloser Hartzer";
	mustermann.address.city = "Hannover";
	mustermann.address.street = "Brandenburgerstraße";
	mustermann.address.zipcode = 12345;
	mustermann.address.mailnumber = 126;
	
	cout << mustermann.address.city << endl;
	system("pause");
}*/
/*
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

fstream file;
//DAS IST IRGENDWIE BROKEN UND ICH VERSTEH NICHT WIESO
string fileToString()
{
	string s = "";
	char line[100];
	while (!file.eof())
	{
		file.getline(line, 100);
		for (int i = 0; i < 100; i++)
		{
			cout << line[i];
		}
	}
	return s;
}

int main() 
{
	file.open("file.txt", ios::out);
	fileToString();
	system("pause");
}
*/

#include <iostream>
#include <cstring>
using namespace std;

class stadt
{
public:
	float x, y;
	char  name[20];
};

class kurort : public stadt // abgeleitete Klasse 1
{
public:
	float kurtaxe;
};

class kurklinik : public kurort // abgeleitete Klasse 2
{
public:
	int anzahl_betten;
};

int main()
{

	float min, temp;
	char ort;
	class stadt hannover;
	class stadt hildesheim;
	class kurort bad_salzdetfurth;
	class kurklinik rehaklinik;

	hannover.x = 9.74; hannover.y = 52.37;   //km ost nord
	hildesheim.x = 9.95; hildesheim.y = 52.15;
	bad_salzdetfurth.x = 10.01; bad_salzdetfurth.y = 52.07;
	bad_salzdetfurth.x = 10.02; bad_salzdetfurth.y = 52.07;

	temp = sqrt((hannover.x - hildesheim.x) * (hannover.x - hildesheim.x)
		+ (hannover.y - hildesheim.y) * (hannover.y - hildesheim.y));

	cout << " km " << temp << endl;

	temp = sqrt((hannover.x - bad_salzdetfurth.x) * (hannover.x - bad_salzdetfurth.x)
		+ (hannover.y - bad_salzdetfurth.y) * (hannover.y - bad_salzdetfurth.y));

	cout << " km (real ca. 40 km) " << temp << endl;

	bad_salzdetfurth.kurtaxe = 5.0;
	rehaklinik.kurtaxe = 4.50;
	rehaklinik.anzahl_betten = 146;
	//  TEST  hannover.kurtaxe = 2.0; // Fehler!!
	//  TEST  hannover.kurtaxe = 2.0; // Fehler!!


}

