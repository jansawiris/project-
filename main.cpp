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
void printXML()
{
	// Load the XML file into the Doc instance
	doc.LoadFile(path);
	pRootElement = doc.RootElement();
	
	// Read the XML and print the results in a tabluar format
	// Note: setw(7) will print the string with fixed with of 7 characters wide 

cout << '|' << setw(7) << "Reading From File Accounts.xml .........." << '|' << endl;
	// Print out the Table Header
cout << '|' << setw(7) << "Acc No." << '|' << setw(12) << "Account Type" << '|' << setw(15) << "Customer Name" << '|' << setw(10) << "Balance" << '|' << setw(12) << "Open Date" <<
		endl << endl;

	// 
	if (NULL != pRootElement) {
		//Get 'Accounts' Child
XMLElement * pAccounts = pRootElement->FirstChildElement("Accounts");
		if (NULL != pAccounts) {

			//Get 'Account' Child
	XMLElement * pAccount = pAccounts->FirstChildElement("Account");
			
			// Loop through all existing 
			while (pAccount) {
				printOneRecord(pAccount);
				// Next Account
		pAccount = pAccount->NextSiblingElement("Account");
			}
			cout << "\n";
		}
	}

}

void insertRecord()
{
	string input;

	// Load the XML file into the Doc instance
	doc.LoadFile(path);
	//Get root Element
	XMLElement * pTop = doc.RootElement();
	// Get 'Accounts' Child
	XMLElement * pAccounts = pTop -> FirstChildElement("Accounts");

	//Create new Element
	XMLNode * pRoot = doc.NewElement("Account");
	//Insert new Element
	pAccounts -> InsertEndChild(pRoot);
	//Create new Element
	XMLElement * pElement = doc.NewElement("AccountNo");

	cout << "Enter Account Number: ";
	cin >> input;
	// Set new Element Text
	pElement -> SetText(input.c_str()); // AccountNo

	// Insert new Element
	pRoot -> InsertEndChild(pElement);
	//Create new Element
	pElement = doc.NewElement("type");
	// Set new Element Text
	cout << "Enter Account Type: ";
	cin >> input;
	pElement -> SetText(input.c_str()); // type
	// Insert new Element
	pRoot -> InsertEndChild(pElement);
	//Create new Element
	pElement = doc.NewElement("customer");
	cout << "Enter Customer Name: ";
	cin >> input;
	// Set new element Text
	pElement -> SetText(input.c_str()); // customer
 	// Insert new Element
	pRoot -> InsertEndChild(pElement);
	//Create new Element
	pElement = doc.NewElement("balance");
	cout << "Enter Account Balance: ";
	cin >> input;
	// Set new Element Text
	pElement -> SetText(input.c_str()); // balance
	// Insert new Element
	pRoot -> InsertEndChild(pElement);
	//Create new Element
	pElement = doc.NewElement("openDate");
	// Set new Element Text
	cout << "Enter OpenDate: ";
	cin >> input;
	pElement -> SetText(input.c_str()); // openDate
	//Insert new Element
	pRoot -> InsertEndChild(pElement);
	//Save the changes into the XML file
	doc.SaveFile(path);

	cout << "Record Inserted into the XML" << endl << endl;
}
