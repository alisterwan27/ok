#include <iostream>
#include <fstream>
//name
#include <iomanip>
#include <string>
using namespace std;
int main()
{

	string productCode;
	char tagColour;
	int quantity, Gcounter=0, Bcounter=0;
	double unitPrice, amountPayable, rate, sum=0;
	
	ifstream invoice;
	fstream summary;
	
	invoice.open("invoice.txt", ifstream::in);
	summary.open("summary.txt", ofstream::out);
	if (!invoice || !summary)	cout << "Error. Unable to open file." << endl;
	else
	{
		cout << left << fixed << setprecision(2);
		cout << setw(13) << "Product Code" << setw(13) << "Unit Price" << setw(13) << "Quantity" << setw(13) << "Tag Colour" << setw(13) << "Disc Rate" << setw(13) << "Amount Payable" << endl;
		while (!invoice.eof())
		{
			invoice >> productCode >> unitPrice >> quantity >> tagColour;
			if (invoice.fail()) break;
			else
			{
				if (unitPrice > 70 && tagColour == 'B')
				{
					rate = 0.25;
					Bcounter += quantity;
				}
				else if (unitPrice > 50 && tagColour == 'G')
				{
					rate = 0.15;
					Gcounter += quantity;
				}
				else
				{
					rate = 0.12;
				}

				amountPayable = unitPrice * quantity * (1 - rate);
				sum += amountPayable;
				cout << setw(13) << productCode << setw(13) << unitPrice << setw(13) << quantity << setw(13) << tagColour << setw(13) << rate << amountPayable << endl;
			}
			cout << "\nNumber of green tag product is " << Gcounter << endl;
			summary << "Number of green tag product is " << Gcounter << endl;
			cout << "Number of blue tag product is " << Bcounter << endl;
			summary << "Number of blue tag product is " << Bcounter<< endl;
			cout << "Total amount payable is $" << sum << endl;
			summary << "Total amount payable is $" << sum << endl;
			
			invoice.close();
			summary.close();
		}
	}
	system("pause");
	return 0;
}
