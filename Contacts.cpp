#include "Contacts.h"

Contacts::Contacts()
{
	name = "james";
	number = 10;

}


Contacts::Contacts(string n, int num)
{
	n = "John";
	num = 88;
}

string Contacts::getName()
{
	return name;
}


void Contacts::setName()
{
	name = "newname";
}


int Contacts::getNumber()
{
	return number;
}


void Contacts::setNumber()
{
	number = 234;
}

ostream& operator<<(ostream& str, const Contacts myContact)
{
	str << myContact.name;
	str << myContact.number;
	return str;

}