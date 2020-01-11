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
	ifstream inFile;
	fstream file;
	inFile.open("invoice.txt");
	if (!inFile)
		cout << "invoice.txt cannot be opened\n";
	else
	{
		cout << left;
		cout << left << "Product Code" << setw(13) << "Unit Price" setw(13) << "Quantity" setw(13) << "Tag Colour" << setw(13) << "Disc Rate"
			<< "Amount Payable" << endl;
		while (!inFile.eof())
		{
			inFile >> productCode >> unitPrice >> quantity >> tagColour;
			if (inFile.fail()) break
			else
			{
				if (unitPrice > 70 && tagColour = "B") rate = 0.25;
				else if (unitPrice > 50 && tagColour = "G") rate = 0.15;
				else rate = 0.12;

				if (tagColour = "B") Bcounter++;
				else Gcounter++;

				amountPayable = unitPrice * quantity * (1 - rate);
				sum += amountPayable;

				cout << left;
				cout << setw(13) << productCode << setw(13) << unitPrice << setw(13) << quantity << setw(13) << tagColour << setw(13) << rate
					<< amountPayable << endl;
			}
			cout << "Number of green tag product is " << Gcounter << endl;
			cout << "Number of blue tag product is " << Bcounter << endl;
			cout << "Total amount payable is $" << sum << endl;
		}
	}
	inFile.close();

	file.open("summary.txt", fstream::app);
	if (!file)
		cout << "Error\n";
	else
	{
		file << "Number of green tag product is " << Gcounter << endl << "Number of blue tag product is " << Bcounter << endl << "Total amount payable is $" << sum << endl;
	}
	file.close();



	system("pause");
	return 0;
}
