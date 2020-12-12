#pragma once
#include <list>
#include <string>
#include <iostream>

class Lampe {
private:
	bool isOn = false;
	float verbrauch;
public:
	Lampe();
	Lampe(float v, bool s);
	void setStatus(bool s);
	bool getStatus();
	float getVerbrauch();
};

class Lichtschalter {
private:
	Lampe lamp;
public:
	Lichtschalter(float v, bool s);
	Lampe getLampe();
	void umschalten();
};

class Heizkoerper {
private:
	bool isOn;
	float verbrauch;
public:
	Heizkoerper(float v, bool s);
	float getVerbrauch();
	void setStatus(bool s);
	bool getStatus();
};

class Raum {
private:
	float laenge;
	float breite;
	float qm;
	float verbrauch_sonstiges;
	std::list<Heizkoerper> heizungen;
	std::list<Lichtschalter> lampen;
public:
	Raum(float l, float b, float v_s);
	Raum(float l, float b, float v_s, std::list<Heizkoerper> l_hz, std::list<Lichtschalter> l_ls);
	float getVerbrauch();
	float getQm();
	std::list<Heizkoerper> getHeizungen();
	std::list<Lichtschalter> getLampen();
};

class Gebaeude {
private:
	std::list<Raum> raeume;
public:
	Gebaeude(std::list<Raum> r);
	float getVerbrauch();
	std::list<Raum> getRaeume();
};

auto createLichter();
auto createHeizung();
std::list<Raum> createSpace();
void printInfo(Gebaeude g);
void runArchitekturStuff();