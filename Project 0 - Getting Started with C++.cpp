/*	EECS 2510 Non-Linear Data Structures
	Project 0 Getting Started
	Nadine Mansour
	Due January 31, 2019
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() 
{
	double  currBal, rate, newBal, intEarned;
	int     periods;
	
	cout << "Amount of money: $";
	cin  >> currBal;
	
	cout << "Interest Rate: ";
	cin  >> rate;
	
	cout << "Number of Periods: ";
	cin  >> periods;
	
	cout << "Period " << "Beginning Balance " << "Interest Earned " << "New Balance " << endl;
	
	for (int i = 0; i < periods; i++) {
		intEarned = currBal * rate / 100;
		newBal    = currBal + intEarned;
	 
	    cout << fixed;
		cout << setprecision(2);
		
		cout << setw(4) << (i+1) << setw(10) << "$" << currBal << setw(11) << "$" << intEarned << setw(7) << "$" << newBal << endl;
		currBal = newBal;
	
	}
	
	System("pause");
	return 0;

}

