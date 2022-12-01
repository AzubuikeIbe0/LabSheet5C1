#include "Contacts.h"
#include "NodeOfContacts.h"
#include "ListOfContacts.h"

int main()
{

	Contacts C("name", 14);
	cout << C <<endl;

	ListOfContacts L;
	L.insertFront(C);

	//ListOfContacts L2(L);

	ListOfContacts L3;

	L3 = L;

	L3.displayList(cout);
	//cout << L3;


	//L.insertFront(C);
	//L.insertFront(C);
	//
	//cout << L;

	//L.insertBack(C.getName(), C.getNumber());
	//L.insertBack(C.getName(), C.getNumber());
	//L.insertBack(C.getName(), C.getNumber());

	//cout << L;

	//L.deleteBack();
	//L.deleteContact(C.getName());
	//L.findContact(C.getName());
	//L.isEmpty(); // return true if list empty
	/*L.displayList(C);*/



	/*
	L.insertFront();
	L.displayList();
	L.deleteFront();
	L.operator<<(ostream & str, const ListOfContacts &mList);
	L.~ListOfContacts();
	*/
	return 0;
}