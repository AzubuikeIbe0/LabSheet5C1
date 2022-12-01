#pragma once
#include "Contacts.h"
#include "NodeOfContacts.h"

class ListOfContacts
{
	friend class NodeOfContacts;
	friend ostream& operator<<(ostream& str, const ListOfContacts& myList);
private:
	NodeOfContacts* head;
public:
	ListOfContacts();

	bool insertFront(Contacts);
	void displayList();

	Contacts deleteFront();

	~ListOfContacts();

	bool insertBack(string, int);
	bool deleteBack();
	Contacts deleteContact(string nameToDelete);
	bool findContact(string nameToFind);
	bool isEmpty(); // return true if list empty
	/*ListOfContacts(const ListOfContacts* p1);*/ // Copy constructor
	ostream& displayList(ostream&) const;
};
