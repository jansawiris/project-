#include<iostream>
#include"tinyxml2.h"
#include<iomanip>
#include<cstring>
using namespace std;
using namespace tinyxml2;

/*

	We are doing three things here in sequence
		1) Read the records from the XMl file 
		2) Write records into an xml file
		3) Search for records in the xml file
		2) Read the records from the XMl file after writing to check if the account is written into the file

	tinyXMl2 treats each entry of the XML document as an XML element 

	In this code, the XML elements are Account records.
	Each XMl element here contains Acc No, Account Type, Customer Name, Balance, Open Date

	1) For Reading from the XMl file, we use a while loop and get each XML element (or the account) and print its respective values (Acc No, Account Type, Customer Name, Balance, Open Date)
	
*/


// Create an XML Document
XMLDocument doc;
const char * path = "Accounts.xml";
char amountText[100];


// Get root Element, root element is the first XML element or the first record in the file
XMLElement * pRootElement;


void printOneRecord(XMLElement * pAccount) {

	// Get 'AccountNo' Child
	XMLElement * pAccountNo = pAccount->FirstChildElement("AccountNo");
	if (NULL != pAccountNo) {
		//Print out AccountNo
		cout << '|' << setw(7) << pAccountNo->GetText();
	}
	//Get 'type' Child
	XMLElement * pType = pAccount->FirstChildElement("type");
	if (NULL != pType) {
		// Print out 'Tyoe'
		cout << '|' << setw(12) << pType->GetText();
	}
	// Get 'customer' Child
	XMLElement * name = pAccount->FirstChildElement("customer");
	if (NULL != name) {
		//Print out name
		cout << '|' << setw(15) << name->GetText();
	}
	// Get 'balance' Child
	XMLElement * balance = pAccount->FirstChildElement("balance");
	if (NULL != balance) {
		//Print out amount
		cout << '|' << setw(10) <<"$"<< balance->GetText() << '|';
	}
	// Get 'openDate' Child
	XMLElement * openDate = pAccount->FirstChildElement("openDate");
	if (NULL != openDate) {
		//Print out openDate
		cout << setw(12) << openDate->GetText() << '|';
	}
	cout << endl;
cout << "------------------------------------------------------------";
	cout << endl;


}
