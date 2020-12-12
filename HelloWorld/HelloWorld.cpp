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

#include <list>
#include <string>
#include <iostream>
using namespace std;

class Lampe {
public:
	bool isOn = false;
	float verbrauch;

	Lampe() {
		verbrauch = 0;
		isOn = false;
	}

	Lampe(float v, bool s) {
		verbrauch = v;
		isOn = s;
	}

	void setStatus(bool s) {
		isOn = s;
	}

	bool getStatus() {
		return isOn;
	}

	float getVerbrauch() {
		if (isOn) {
			return verbrauch;
		}
		else {
			return 0;
		}
	}
};

class Lichtschalter {
public:

	Lampe lamp;

	Lichtschalter(float v, bool s) {
		lamp = Lampe(v, s);
	}

	void umschalten() {
		if (lamp.isOn) {
			lamp.isOn = false;
		}
		else {
			lamp.isOn = true;
		}
	}

};

class Heizkoerper {
public:
	bool isOn;
	float verbrauch;

	Heizkoerper(float v, bool s) {
		isOn = s;
		verbrauch = v;
	}

	float getVerbrauch() {
		if (isOn) {
			return verbrauch;
		}
		else {
			return 0;
		}
	}

	bool getStatus() {
		return isOn;
	}

};

class Raum {
public:
	float laenge;
	float breite;
	float qm;
	float verbrauch_sonstiges;
	list<Heizkoerper> heizungen;
	list<Lichtschalter> lampen;

	Raum(float l, float b, float v_s) {
		laenge = l;
		breite = b;
		qm = l * b;
		verbrauch_sonstiges = v_s;
	}

	Raum(float l, float b, float v_s, list<Heizkoerper> l_hz, list<Lichtschalter> l_ls) {
		laenge = l;
		breite = b;
		qm = l * b;
		verbrauch_sonstiges = v_s;
		heizungen = l_hz;
		lampen = l_ls;
	}

	float getVerbrauch() {
		float total = 0;
		total += verbrauch_sonstiges;
		for (Heizkoerper i : heizungen) {
			total += i.getVerbrauch();
		}
		for (Lichtschalter i : lampen) {
			total += i.lamp.getVerbrauch();
		}
		return total;
	}

	float getQm() {
		return qm;
	}

};

class Gebaeude {
public:
	list<Raum> raeume;

	Gebaeude(list<Raum> r) {
		raeume = r;
	}

	float getVerbrauch() {
		float total = 0;
		for (Raum i : raeume) {
			 total+= i.getVerbrauch();
		}
		return total;
	}

};

auto createLichter() {
	list<Lichtschalter> lichtRaum1;
	list<Lichtschalter> lichtRaum2;
	list<Lichtschalter> lichtRaum3;

	Lichtschalter l1 = Lichtschalter(5.0, true);
	Lichtschalter l2 = Lichtschalter(3.0, true);
	Lichtschalter l3 = Lichtschalter(1.5, false);
	Lichtschalter l4 = Lichtschalter(4.8, false);
	Lichtschalter l5 = Lichtschalter(2.4, true);
	Lichtschalter l6 = Lichtschalter(4.20, true);
	Lichtschalter l7 = Lichtschalter(6.9, true);
	Lichtschalter l8 = Lichtschalter(8.8, true);
	Lichtschalter l9 = Lichtschalter(1.23, true);
	Lichtschalter l10 = Lichtschalter(5.0, false);

	lichtRaum1.push_back(l1);
	lichtRaum1.push_back(l2);
	lichtRaum1.push_back(l3);
	lichtRaum2.push_back(l4);
	lichtRaum2.push_back(l5);
	lichtRaum2.push_back(l6);
	lichtRaum3.push_back(l7);
	lichtRaum3.push_back(l8);
	lichtRaum3.push_back(l9);
	lichtRaum3.push_back(l10);
	struct result { list<Lichtschalter> a; list<Lichtschalter> b; list<Lichtschalter> c; };
	return result { lichtRaum1, lichtRaum2, lichtRaum3 };
}

auto createHeizung() {
	list<Heizkoerper> heizRaum1;
	list<Heizkoerper> heizRaum2;
	list<Heizkoerper> heizRaum3;

	Heizkoerper h1 = Heizkoerper(300.0, true);
	Heizkoerper h2 = Heizkoerper(250.0, true);
	Heizkoerper h3 = Heizkoerper(400.0, false);
	Heizkoerper h4 = Heizkoerper(410.0, true);
	Heizkoerper h5 = Heizkoerper(430.0, true);
	Heizkoerper h6 = Heizkoerper(520.0, false);
	Heizkoerper h7 = Heizkoerper(120.0, true);

	heizRaum1.push_back(h1);
	heizRaum1.push_back(h2);
	heizRaum2.push_back(h3);
	heizRaum2.push_back(h4);
	heizRaum3.push_back(h5);
	heizRaum3.push_back(h6);
	heizRaum3.push_back(h7);
	struct result { list<Heizkoerper> a; list<Heizkoerper> b; list<Heizkoerper> c; };
	return result{heizRaum1, heizRaum2, heizRaum3};
}

list<Raum> createSpace() {
	list<Raum> listR;
	auto l = createLichter();
	auto h = createHeizung();

	Raum r1 = Raum(3.5, 2.5, 0, h.a, l.a);
	Raum r2 = Raum(5.0, 4.0, 0, h.b, l.b);
	Raum r3 = Raum(8.75, 6.5, 0, h.c, l.c);
	
	listR.push_back(r1);
	listR.push_back(r2);
	listR.push_back(r3);

	return listR;
}

void printInfo(Gebaeude g) {
	cout << "Gebaeude gesamtverbrauch: " << g.getVerbrauch() << endl << endl;
	cout << "	Verbrauch Raeume:" << endl;
	int i = 1;
	for (Raum r : g.raeume) {
		cout << "	Raum NR " << i << ": " << r.getVerbrauch() << " Raumgroesse: " << r.getQm() << "qm" << endl;
		int j = 1;
		for (Lichtschalter l : r.lampen) {
			cout << "		Lampe NR " << j << ": " << l.lamp.getVerbrauch() << " Eingeschaltet: " << l.lamp.getStatus() << endl;
			j++;
		}
		int k = 1;
		for (Heizkoerper h : r.heizungen) {
			cout << "		Heizung NR " << k << ": " << h.getVerbrauch() << " Eingeschaltet: " << h.getStatus() << endl;
			k++;
		}
		i++;
	}
	
}

int main() {
	Gebaeude testgebaeude = Gebaeude(createSpace());
	printInfo(testgebaeude);
	system("pause");
}