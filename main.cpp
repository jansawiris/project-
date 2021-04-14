#include<iostream>
#include"tinyxml2.h"
#include<iomanip>
#include<string.h>
using namespace std;
using namespace tinyxml2;


/*

	We are doing two things here in sequence
		1) Read the records from the XMl file 
		2) Write two records into an xml file
		2) Read the records from the XMl file after writing to check if the account is written into the file

	tinyXMl2 treats each entry of the XML document as an XML element 

	In this code, the XML elements are Account records.
	Each XMl element here contains Acc No, Account Type, Customer Name, Balance, Open Date

	1) For Reading from the XMl file, we use a while loop and get each XML element (or the account) and print its respective values (Acc No, Account Type, Customer Name, Balance, Open Date)
	
*/


int main() {

	// Create an XML Document
	XMLDocument doc;
	const char * path = "Accounts.xml";//to look
	char amountText[100];

	// Load the XML file into the Doc instance
	doc.LoadFile(path);
	// Get root Element, root element is the first XML element or the first record in the file
	XMLElement * pRootElement = doc.RootElement();
	
	// Read the XML and print the results in a tabluar format
	// Note: setw(7) will print the string with fixed with of 7 characters wide 

cout << '|' << setw(7) << "Reading From File Accounts.xml .........." << '|' << endl;
	// Print out the Table Header
cout << '|' << setw(7) << "Acc No." << '|' << setw(12) << "Account Type" << '|' << setw(15) << "Customer Name" << '|' << setw(10) << "Balance" << '|' << setw(12) << "Open Date" <<
		endl << endl;

       // 
	if (NULL != pRootElement) {

		//Get 'Accounts' Child
XMLElement * pAccounts = pRootElement->FirstChildElement("Accounts"); // Creating the pointer
		if (NULL != pAccounts) {


			//Get 'Account' Child
	XMLElement * pAccount = pAccounts->FirstChildElement("Account");
			
			// Loop through all existing 
			while (pAccount) {

			// Get 'AccountNo' Child
	XMLElement * pAccountNo = pAccount->FirstChildElement("AccountNo");
				if (NULL != pAccountNo) {
			//Printing out the account number
			cout << '|' << setw(7) << pAccountNo->GetText();
				}
				//Get 'type' Child
		XMLElement * pType = pAccount->FirstChildElement("type");
				if (NULL != pType) {
					// Print out 'Tyoe'
			cout << '|' << setw(12) << pType->GetText();
				}
				// Get 'customer' Child
	XMLElement * pname = pAccount->FirstChildElement("customer");
				if (NULL != pname) {
					//Print out name of the account 
				cout << '|' << setw(15) << pname->GetText();
				}
				// Get 'balance' Child
	XMLElement * pbalance = pAccount->FirstChildElement("balance");
				if (NULL != pbalance) {
			
		cout << '|' << setw(10) <<"$"<< pbalance->GetText() << '|';
				}
				// Get 'openDate' Child
	XMLElement * popenDate = pAccount->FirstChildElement("openDate");
				if (NULL != popenDate) {
					// to Print out openDate of the account 
			cout << setw(12) << popenDate->GetText() << '|';
				}
				cout << endl;
cout << "------------------------------------------------------------";
				std::cout << std::endl;
				// Next Account
			pAccount = pAccount->NextSiblingElement("Account");
			}
			cout << "\n";
		}
	}
}
