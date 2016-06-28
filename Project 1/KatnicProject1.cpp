//Christopher Katnic
//894-68-7516
//Project 1 - utilizing an array of structs to create an E-store

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

//struct to hold values for the user
struct userProfile
{
	string fName, lName;
	int itemSelection, amountRequested;
};

//struct to hold values for items chosen
struct itemChoice
	{
		string itemName;
		double itemPrice, subtotal, tax, total;
		int amountAvailable, ID;
	};
void getStore(itemChoice[], int&);
//Function getStore: takes all values out of inventory.txt and puts them into an array of structs
//and gets the amount of items in the inventory for later use
//Parameters: itemChoice[] is the array of values that hold data from inventory.txt; int is the amount of items in inventory

void printOrder(userProfile, itemChoice, ofstream&);
//Function printOrder: creates the order.txt based on what the user has chosen
//Parameters: userProfile is the struct containing information that the user has inputted;
//itemChoice is the item currently found, containing all information to be printed
//ofstream& is the order.txt that is passed by reference to keep the order updated.

void storeWelcome(userProfile&);
//Function storeWelcome: prints out a welcome page to the user and prompts them to type in pertinent information
//Parameters: userProfile is a struct containing all information for the user, to be used later

void getSelection(userProfile&);
//Function getSelection: prompts user to enter in an item ID and request a certain amount
//Parameters: userProfile is a struct containing information about what item was requested and how much

void findItem(itemChoice[], userProfile, double&, int&, int);
//Function findItem: search algorithm through the array of structs to find the item requested by the user
//Parameters: itemChoice[] is the array of structs that hold all of the inventory items;
//userProfile is a struct with information collected in previous functions that the algorithm searches for;
//double& is the grand total, which is calculated with each new item found;
//int& is the index value of the item in the inventory array, found by the algorithm to be used later;
//int is the maximum number of items in the inventory, utilized to shorten algorithm search time.

void calculateTotal(itemChoice&, userProfile);
//Function calculateTotal: Takes information pulled from inventory item chosen and the amount requested by the user to 
//get subtotal and grand total values
//Parameters: itemChoice& contains the values for the item found by search algorithm findItem;
//userProfile contains the values inputted by the user, namely the amount requested.


int main()
{
//user and item profiles
	itemChoice item[10];
	userProfile user1;
//placeholders and grandTotal of order
	int n, numOfItems = 0;
	double grandTotal = 0;

//create array of structs for the store
	getStore(item, numOfItems);
	storeWelcome(user1);

//open up order
	ofstream order;
	order.open("Order.txt");
//loop to create order
	char flag = 'y';
	while(flag == 'y' || flag == 'Y')
	{

		getSelection(user1);
		findItem(item, user1, grandTotal, n, numOfItems);
		if(n!=numOfItems) printOrder(user1, item[n], order);
		cout << "\nWould you like to continue? (y/n): ";
		cin >> flag;
		cout << endl;
	}

//finally, write grand total and close
	order << "\n" << setw(80) << "Grand Total: " << setw(20) << grandTotal << "\n";
	order.close();
	return 0;
}

void printOrder(userProfile user1, itemChoice item, ofstream &order)
{	
	order << left;
	order << user1.lName << ", " << user1.fName << "\n";
	order << fixed << showpoint << setprecision(2);
	order << setw(20) << "ID" << setw(20) << "Item" << setw(20) << "Price"
		  << setw(20) << "Amount" << setw(20) << "Cost" << "\n";
    order << setw(15) << user1.itemSelection << setw(25) << item.itemName << setw(20) << item.itemPrice
		<< setw(20) << user1.amountRequested << setw(20) << (user1.amountRequested * item.itemPrice) << "\n";
	order << setw(80) << "Sales Tax: " << setw(20) << item.tax << "\n";
	order << setw(80) << "Shipping: " << setw(20) << "5.00" << "\n";
	order << "\n" << setw(80) << "Total: " << setw(20) << item.total << "\n";

	cout << fixed << showpoint << setprecision(2);
	cout << "Item ID:\t" << item.ID << "\nItem Name: " << item.itemName << "\nAmount: \t" << user1.amountRequested << "\nsubtotal:\t" << item.subtotal << "\nTotal Cost:\t" << item.total << endl;
}

void storeWelcome(userProfile &user)
{
	cout << "Welcome to the store!!!! \n";
	cout << "Please enter your first name\nand your last name separated by a space: ";
	cin >> user.fName >> user.lName;
}

void getSelection(userProfile &user)
{
	cout << "Enter the ID of the item that you would like: ";
	cin >> user.itemSelection;
	cout << "Please enter the amount of that item that you would like: ";
	cin >> user.amountRequested;
	cout << endl;
}

void calculateTotal(itemChoice &item, userProfile user)
{
	item.subtotal = (item.itemPrice * user.amountRequested);
	item.tax = (item.subtotal * 0.075);
	item.total = item.subtotal + item.tax + 5;
}


void getStore(itemChoice item[10], int &n)
{
	//open up the inventory.txt
	ifstream inventory;
	inventory.open("Inventory.txt");
	n = 0;
	inventory >> item[n].ID;
	while(inventory)
	{
		inventory >> item[n].itemPrice >> item[n].amountAvailable;
		getline(inventory, item[n].itemName);
		n++;
		inventory >> item[n].ID;
	}
	inventory.close();
}


void findItem(itemChoice item[10], userProfile user, double &grandTotal, int &n, int cap)
{
	n = 0;
	while(n < cap && item[n].ID != user.itemSelection)
	{
		n++;
	}
	//if the loop found the item
	if(item[n].ID == user.itemSelection)
	{
			//if the item is not in stock
			if(user.amountRequested > item[n].amountAvailable)
			{
				cout << "\nThere is not enough of that item available in the inventory. \nPlease adjust amount requested and try again" << endl;
				n = cap;
			}
			//if the item is in stock
			else if(user.amountRequested <= item[n].amountAvailable)
			{
					calculateTotal(item[n], user);
					grandTotal += item[n].total;
			}
		
	}
	//if the loop didn't find the item
	else if(n==cap)
	{
		cout << "\nCould not find the item requested. Please check the item and try again" << endl;
	}

}
