#include "ListOfContacts.h"
#include "ListOfContacts.h"
#include "Contacts.h"



ListOfContacts::ListOfContacts()
{
	head = nullptr;
}

bool ListOfContacts::insertFront(Contacts newContact)
{
	// STEP 1
	NodeOfContacts* newNode = new NodeOfContacts(); // Create a new NodeOfContacts

	// STEP 2
	newNode->theContact = newContact; // Assign a contact data

	// STEP 3
	newNode->next = head; // Make the next node of the newNode as head

	// STEP 4
	head = newNode; // Set newNode as head

	return true;
}



void ListOfContacts::displayList()
{

	NodeOfContacts* temp = head;
	if (head != nullptr)
	{
		while (temp != nullptr)
		{
			std::cout << temp->theContact << endl;
			temp = temp->next;
		}
	}

}




Contacts ListOfContacts::deleteFront()
{
	Contacts tempName;

	// STEP 1
	if (head == nullptr) { // Check if there is not node
		 
		return tempName;
	}

	// STEP 2
	NodeOfContacts* temp = head; // Create a pointer to the head

	// STEP 3
	head = head->next; // Move the head pointer to the next node

	// STEP 4
	tempName = temp->theContact;
	delete temp; // Delete the first node

	// STEP 5

	return tempName; // Return the value of the deleted node
}


ListOfContacts::~ListOfContacts()
{
	while (head) // While the list is not empty
	{

		NodeOfContacts* temp = head; //Set a temporary pointer to point to the first item on the list

		head = head->next; // Move the head pointer to the next node in the list

		delete temp; // Delete the first node, ie the one the temp pointer is pointed to

	} // End while
}

ostream& operator<<(ostream& str, const ListOfContacts& myList)
{


	NodeOfContacts* temp = myList.head;
	while (temp != nullptr)
	{
		str << temp->theContact.getName() << endl;
		temp = temp->next;
	}


	return str;

}


bool ListOfContacts::insertBack(string s, int n)
{
	NodeOfContacts* newNode = new NodeOfContacts;
	NodeOfContacts* nodePtr = head;
	//bool result;

	newNode->next = nullptr;
	newNode->theContact.name = s;
	newNode->theContact.number = n;

	if (head != nullptr)
	{
		while (nodePtr->next != nullptr)
		{
			nodePtr = nodePtr->next;
		}
		nodePtr->next = newNode;
		cout << "A new node was inserted!" << endl;

	}
	else
	{
		head = newNode;
		cout << "A new node was inserted at the head!" << endl;
	}

	return true;
}

bool ListOfContacts::deleteBack()
{
	NodeOfContacts* temp = new NodeOfContacts;
	NodeOfContacts* nodePtr = nullptr;

	if (head != nullptr)
	{
		while (nodePtr != nullptr)
		{
			nodePtr = nodePtr->next;
			temp = nodePtr;
		}
		cout << temp->theContact << " has been deleted!" << endl;
		delete temp;

		
	}
	else
	{
		cout << "The list is empty!" << endl;
		
	}

	return true;
}

Contacts ListOfContacts::deleteContact(string nameToDelete)
{
	// Initialize 3 pointer to track the name to delete
	NodeOfContacts* delPtr = nullptr; // point at the contact to delete;
	NodeOfContacts* temp = head;
	NodeOfContacts* nodePtr = head;
	Contacts tempName;


	while (nodePtr != nullptr && nodePtr->theContact.name != nameToDelete) //loop through the nodes
	{
		temp = nodePtr;
		nodePtr = nodePtr->next;
	}
	if (nodePtr == nullptr) //Means the name was not found
	{
		cout << "This Contact with " << nameToDelete << " is not in the list" << endl;
		delete delPtr; // delete delPtr since there are no nodes
	}
	else // Continue looping
	{
		delPtr = nodePtr;
		nodePtr = nodePtr->next;

		if (delPtr == head) // head Contact contains name to be deleted
		{
			head = head->next; // move the head pointer to the next node
			temp = nullptr;
		}

		tempName = delPtr->theContact;

		delete delPtr;
		cout << "The contact " << tempName << " was deleted succesfully!" << endl;
	}

	return tempName;

}

bool ListOfContacts::findContact(string nameToFind)
{
	NodeOfContacts* findPtr = new NodeOfContacts;
	NodeOfContacts* nodePtr = head;
	NodeOfContacts* tempPtr = head;
	Contacts tempName;
	bool result;

	while (nodePtr != nullptr && nodePtr->theContact.name != nameToFind)
	{
		tempPtr = nodePtr;
		nodePtr = nodePtr->next;
	}
	if (nodePtr == nullptr)
	{
		cout << "The Contact " << findPtr->theContact << " is not in this list" << endl;
		delete findPtr;
		result = false;
	}
	else
	{
		findPtr = nodePtr;
		nodePtr = nodePtr->next;

		if (findPtr == head)
		{
			head = head->next;
			tempPtr = nullptr;
		}

		tempName = findPtr->theContact;

		cout << "The Contact with name " << findPtr->theContact << " was found" << endl;
		delete findPtr;
		result = true;
	}

	return result;
}

bool ListOfContacts::isEmpty()
{
	NodeOfContacts* nodePtr = head;
	bool result;

	if (head != nullptr)
	{
		cout << "The list is not Empty" << endl;
		result = true;
	}
	else
	{
		cout << "The list is Empty" << endl;
		result = false;
	}

	return result;
}


ostream& ListOfContacts::displayList(ostream& str) const
{
	NodeOfContacts* temp = head;
	while (temp != nullptr)
	{
		str << temp->theContact.getName() << endl;
		temp = temp->next;
	}

	return str;
}


//ListOfContacts & ListOfContacts::operator=(const ListOfContacts& rhs)
//{
//	if (this != &rhs) // Check for self assignment aka the lhs and rhs the same object
//	{
//		if (head != nullptr) // free memory of lhs
//		{
//			while (head)
//				deleteBack();
//		}//end if
//
//		NodeOfContacts* copyPtr = nullptr;
//		NodeOfContacts* orgPtr = rhs.head;
//
//		while (orgPtr != nullptr)
//		{
//			if (head == nullptr)
//			{
//				head = copyPtr = new NodeOfContacts((orgPtr->theContact).name, (orgPtr->theContact).number);
//			}
//			else
//			{
//				copyPtr->next = new NodeOfContacts((orgPtr->theContact).name, (orgPtr->theContact).number);
//				copyPtr = copyPtr->next;
//			}//end if
//
//			orgPtr = orgPtr->next;
//		}//end while
//	 }// end if
//
//	return *this;
//}




ListOfContacts::ListOfContacts(const ListOfContacts& source)
{
	head = nullptr;
	NodeOfContacts* newNode = source.head;
	while (newNode != nullptr)
	{
		insertBack((newNode->theContact).getName(), (newNode->theContact).getNumber());
		newNode=newNode->next;  // Simple but inefficient
	}

}

// this takes advantage of move construction on the
// passed-in parameter with pass-by-value.
// therefore pass by value performs the copy
ListOfContacts ListOfContacts::operator=(ListOfContacts rhs)
{
	std::swap(rhs.head, head); // now just swap the head of the copy for the head of the source
	return *this; // destructor fires for rhs and cleans up all the nodes that were on this list
}

//ostream& operator<<(ostream& str, const ListOfContacts& myList)
//{
//
//	str << myList.head;
//	return str;
//
//}