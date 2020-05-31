#include <iostream>
#include <string>

using namespace std;

void totalBill  ( string fullname, double totalPrice){
// totalBill= fuction to show total bill at the end of the application

	if (totalPrice <= 49){
		cout << fullname << ", total cost of your phone usage is " << totalPrice <<" TL. You did not exceed your base package." <<endl;
	}
	else if (totalPrice < 100) {
		cout << fullname << ", total cost of your phone usage is "<< totalPrice <<" TL. You exceeded your base package."<<endl;
	}
	else {
		cout << fullname << ", total cost of your phone usage is "<< totalPrice<< " TL. You exceeded your base package too much. We suggest you to change your base package."<<endl;
	}
}

bool inputcheck (int number, string name, string writing){
// inputcheck= a function to check imputs is has a true value or false

	if (number >= 0){
	return true;}

	else
	{
		cout << name << ", " << writing << " cannot be smaller than 0."<<endl ;
		return false;
	}
}

void priceCalculator (string fullname, int numberMTTM, int numberSMS, int numberMB, int addCall, int addSMS, int addMB ){
//priceCalculator = a function to calculate total price in terms of usage data

	double totalPrice = 49;

	if (addCall+addSMS+addMB >= 1 ){
		totalPrice += 12*(addCall+addSMS+addMB);
	}

	if (numberMTTM - 250*addCall > 500){
		totalPrice += 0.66*(numberMTTM - 250*addCall - 500);
		}
	
	if (numberSMS - 250*addSMS > 1000){
		totalPrice += 0.55*(numberSMS - 250*addSMS - 1000);
		}	

	if (numberMB - 1024*addMB > 3072){
		totalPrice += 10.24*(numberMB - 1024*addMB - 3072);
		}

	totalBill (fullname, totalPrice);

}

void usageInfo (string fullname){
int numberMTTM;
	// numberMTTM = number of minutes talked this month
	
	cout << fullname << ", please enter how many minutes you used this month: ";
	cin >> numberMTTM;
	if (inputcheck(numberMTTM, fullname, "number of minutes"))
	{
		int numberSMS;
		// numberSMS= number of SMSs send this month
	
		cout << fullname << ", please enter how many SMSs you sent this month: ";
		cin >> numberSMS;
		if (inputcheck(numberSMS, fullname, "number of SMSs"))
		{
			int numberMB;
			// numberMB = number of MBs used this month
	
			cout << fullname << ", please enter how many MBs you used this month: ";
			cin >> numberMB;
			if (inputcheck(numberMB, fullname, "internet usage"))
			{
				int addCall, addSMS, addMB;
				// addCall, addSMS, addMB = number of additional pacakes bought (call, SMS, internet)

				cout << fullname << ", please specify how many additional packages you bought for calls, SMS and internet in this order: ";
				cin >> addCall >> addSMS >> addMB;

				priceCalculator(fullname, numberMTTM, numberSMS, numberMB, addCall, addSMS, addMB);
			}
		}
	}
}


int main(){
	string name, lname;

	cout << "Please enter your name: ";
	cin >> name >> lname;

	string fullname = name + " " + lname;
	
	usageInfo(fullname);

	string name2, lname2;

	cout << "Please enter your name: ";
	cin >> name2 >> lname2;

	fullname = name2 + " " + lname2;
	
	usageInfo(fullname);

	cin.get ();
	cin.ignore ();

	return 0;
}