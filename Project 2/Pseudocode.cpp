/*
Christopher Katnic
894-68-7516
Project 2

function to check inventory to see if the item is available and if so, get the price, quantity available, and description
utilizing arrays and c-type strings.

May have done a little too much. Pretty much copy-paste from assignment one



struct itemStruct
{
	int ID, quantityAvailable;
	double price, subtotal, total;
	string description;
}
itemStruct item;


void checkInventory(itemStruct &item, int IDchosen, int amountRequested, int &grandTotal)
{	
	//create ifstring locally, to be closed when everything is done
	ifstring inventory;
	inventory.open("Inventory.txt");

	//create ID number to hold value of current item
	int ID;
	inventory >> ID;

	//while loop to search through the inventory till the new one is found
	//go to the next line, read in the new ID
	while(inventory && ID != IDchosen)
	{
		inventory.ignore(1000, '\n');
		inventory >> ID;
	}

	//if the loop reached the end of the file, and could not find the item
	//print out an apology
	if(!inventory)
	{
		cout << "I'm sorry, I couldn't find that item!";
	}


	//if the loop found the file (inventory is still good)
	//the information can be read in from the file
	//formatted as such:
	//	IDnumber	IDprice		amountAvailable		IDdescription
	//the ID number will have already been read in.
	if(inventory)
	{
		inventory >> item.price >> item.quantity available;
		getline(inventory, item.description);


		//Then, while in the same conditional, check against amount available
		if(amountRequested <= item.amountAvailable)
		{
			//If we have enough to sell, calculate and print the order to the screen, and to order.txt
			//then update the grand total
			item.subtotal = item.price * amountRequested;
			item.total = item.subtotal * 1.075 + 5.00     //tax = 7.5%, so to create the total with tax 1 + .075, and shipping
			grandTotal += item.total;					  //increment grandTotal with the total from the item found and calculated

		}
		else if(amountRequested < item.amountAvailable)
		{
			//If we don't have enough to sell, print out yet another apology
			cout << "I'm sorry, I don't have enough of that item to sell to you, please select another amount.";
		}
	}

	
}


