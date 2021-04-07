#include<iostream>
#include"tinyxml2.h"
#include<iomanip>
using namespace std;
using namespace tinyxml2;


/*

	We are going to do two things here in this code
		1) Read the records from the XMl file 
		2) Write records into an xml file
			
		2) Read the records from the XMl file after writing to check if the account is written into the file

	tinyXMl2 treats each entry of the XML document as an XML element 

	In this code, the XML elements are Account records.
	Each XMl element here contains Acc No, Account Type, Customer Name, Balance, Open Date

	1) For Reading from the XMl file, we use a while loop and get each XML element (or the account) and print its respective values (Acc No, Account Type, Customer Name, Balance, Open Date)
	
*/






int main() {
	XMLDocument doc;
	const char * path = "Accounts.xml";
	char amountText[100];
	// Load the XML file into the Doc instance
	doc.LoadFile(path);
	// Get root Element
	XMLElement * pRootElement = doc.RootElement();
	// Reading
	cout << '|' << setw(7) << "Reading From File Accounts.xml .........." << '|' << endl;
	// Print out the Table Header
	cout << '|' << setw(7) << "Acc No." << '|' << setw(12) << "Account Type" << '|' << setw(15) << "Customer Name" << '|' << setw(10) << "Balance" << '|' << setw(12) << "Open Date" <<
		endl << endl;
	if (NULL != pRootElement) {
		//Get 'Accounts' Child
		XMLElement * pAccounts = pRootElement->FirstChildElement("Accounts");
		if (NULL != pAccounts) {
			//Get 'Account' Child
			XMLElement * pAccount = pAccounts->FirstChildElement("Account");
			while (pAccount) {
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
					// Convert to *char
					strcpy(amountText, "$");
					strcat(amountText, balance->GetText());
					//Print out amount
					cout << '|' << setw(10) << amountText << '|';
				}
				// Get 'openDate' Child
				XMLElement * openDate = pAccount->FirstChildElement("openDate");
				if (NULL != openDate) {
					//Print out openDate
					cout << setw(12) << openDate->GetText() << '|';
				}
				cout << endl;
				return 0;
		}
	}
}
}
