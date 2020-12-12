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

void runStrukturen() {

	struct PersonWithAddress mustermann;

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
	cout << mustermann.person.id << endl;
	cout << mustermann.person.alter << endl;
	cout << mustermann.person.first_name << endl;
	cout << mustermann.person.last_name << endl;
	cout << mustermann.person.job << endl;
	cout << mustermann.address.city << endl;
	cout << mustermann.address.street << endl;
	cout << mustermann.address.zipcode << endl;
	cout << mustermann.address.mailnumber << endl;
	system("pause");
}