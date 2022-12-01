#pragma once
#include "Contacts.h"

class NodeOfContacts
{
	friend class ListOfContacts;
private:
	Contacts theContact;
	NodeOfContacts* next;
public:
	NodeOfContacts();
	NodeOfContacts(string n, int num);
};