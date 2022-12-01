#include "Contacts.h"
#include "NodeOfContacts.h"
#include "ListOfContacts.h"

int main()
{

	Contacts C;
	cout << C;

	ListOfContacts L;
	L.insertFront(C);
	L.insertFront(C);
	L.insertFront(C);
	
	cout << L;

	L.insertBack(C.getName(), C.getNumber());
	L.insertBack(C.getName(), C.getNumber());
	L.insertBack(C.getName(), C.getNumber());

	cout << L;

	L.deleteBack();
	L.deleteContact(C.getName());
	L.findContact(C.getName());
	L.isEmpty(); // return true if list empty

	cout << L;

	/*
	L.insertFront();
	L.displayList();
	L.deleteFront();
	L.operator<<(ostream & str, const ListOfContacts &mList);
	L.~ListOfContacts();
	*/
	return 0;
}