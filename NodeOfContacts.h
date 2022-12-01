#pragma once
#include "Contacts.h"

class NodeOfContacts
{
	friend class ListOfContacts;
	friend ostream& operator<<(ostream& str, const ListOfContacts& myList);
private:
	Contacts theContact;
	NodeOfContacts* next;
public:
	NodeOfContacts();
	NodeOfContacts(string n, int num);
};