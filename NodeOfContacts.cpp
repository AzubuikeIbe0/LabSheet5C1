#include "NodeOfContacts.h"



NodeOfContacts::NodeOfContacts()
{
	theContact.name = 'John';
	theContact.number = 128373463;
	next = nullptr;
}

NodeOfContacts::NodeOfContacts(string n, int num)
{

	theContact.name = n;
	theContact.number = num;
}