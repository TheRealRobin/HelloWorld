#include "ArchitekturStuff.h"
#include <list>
#include <string>
#include <iostream>
using namespace std;

Lampe::Lampe() {
	verbrauch = 0;
	isOn = false;
}
Lampe::Lampe(float v, bool s) {
	verbrauch = v;
	isOn = s;
}
void Lampe::setStatus(bool s) {
	isOn = s;
}
bool Lampe::getStatus() {
	return isOn;
}
float Lampe::getVerbrauch() {
	if (isOn) {
		return verbrauch;
	}
	else {
		return 0;
	}
}

Lichtschalter::Lichtschalter(float v, bool s) {
	lamp = Lampe(v, s);
}
void Lichtschalter::umschalten() {
	if (lamp.getStatus()) {
		lamp.setStatus(false);
	}
	else {
		lamp.setStatus(true);
	}
}
Lampe Lichtschalter::getLampe() {
	return lamp;
}

Heizkoerper::Heizkoerper(float v, bool s) {
	isOn = s;
	verbrauch = v;
}
float Heizkoerper::getVerbrauch() {
	if (isOn) {
		return verbrauch;
	}
	else {
		return 0;
	}
}
void Heizkoerper::setStatus(bool s) {
	isOn = s;
}
bool Heizkoerper::getStatus() {
	return isOn;
}

Raum::Raum(float l, float b, float v_s) {
	laenge = l;
	breite = b;
	qm = l * b;
	verbrauch_sonstiges = v_s;
}
Raum::Raum(float l, float b, float v_s, std::list<Heizkoerper> l_hz, std::list<Lichtschalter> l_ls) {
	laenge = l;
	breite = b;
	qm = l * b;
	verbrauch_sonstiges = v_s;
	heizungen = l_hz;
	lampen = l_ls;
}
float Raum::getVerbrauch() {
	float total = 0;
	total += verbrauch_sonstiges;
	for (Heizkoerper i : heizungen) {
		total += i.getVerbrauch();
	}
	for (Lichtschalter i : lampen) {
		total += i.getLampe().getVerbrauch();
	}
	return total;
}
float Raum::getQm() {
	return qm;
}
std::list<Heizkoerper> Raum::getHeizungen() {
	return heizungen;
}
std::list<Lichtschalter> Raum::getLampen() {
	return lampen;
}

Gebaeude::Gebaeude(std::list<Raum> r) {
	raeume = r;
}
float Gebaeude::getVerbrauch() {
	float total = 0;
	for (Raum i : raeume) {
		total += i.getVerbrauch();
	}
	return total;
}
std::list<Raum> Gebaeude::getRaeume() {
	return raeume;
}

auto createLichter() {
	std::list<Lichtschalter> lichtRaum1;
	std::list<Lichtschalter> lichtRaum2;
	std::list<Lichtschalter> lichtRaum3;

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
	struct result { std::list<Lichtschalter> a; std::list<Lichtschalter> b; std::list<Lichtschalter> c; };
	return result{ lichtRaum1, lichtRaum2, lichtRaum3 };
}
auto createHeizung() {
	std::list<Heizkoerper> heizRaum1;
	std::list<Heizkoerper> heizRaum2;
	std::list<Heizkoerper> heizRaum3;

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
	struct result { std::list<Heizkoerper> a; std::list<Heizkoerper> b; std::list<Heizkoerper> c; };
	return result{ heizRaum1, heizRaum2, heizRaum3 };
}
std::list<Raum> createSpace() {
	std::list<Raum> listR;
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
	for (Raum r : g.getRaeume()) {
		cout << "	Raum NR " << i << ": " << r.getVerbrauch() << " Raumgroesse: " << r.getQm() << "qm" << endl;
		int j = 1;
		for (Lichtschalter l : r.getLampen()) {
			cout << "		Lampe NR " << j << ": " << l.getLampe().getVerbrauch() << " Eingeschaltet: " << l.getLampe().getStatus() << endl;
			j++;
		}
		int k = 1;
		for (Heizkoerper h : r.getHeizungen()) {
			cout << "		Heizung NR " << k << ": " << h.getVerbrauch() << " Eingeschaltet: " << h.getStatus() << endl;
			k++;
		}
		i++;
	}
}
void runArchitekturStuff() {
	Gebaeude testgebaeude = Gebaeude(createSpace());
	printInfo(testgebaeude);
	system("pause");
}