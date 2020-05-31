#include<iostream>
#include<string>

using namespace std;

	int mafdin(){
		string name;

		cout << "Please enter your name: ";
    cin >> name;
	cout << endl;

	double priceOGC;
	// priceOGC = price of out going call per minute in TL
	
	cout << name << ", please enter the price for outgoing call per minute: ";
	cin >> priceOGC;

	int numberMTOGC;
	// numberMTOGC = numbers of minutes talked out going call

	cout << name << ", please enter how many minutes you have talked in outgoing calls: ";
	cin >> numberMTOGC;

	double	tPriceOGC = numberMTOGC * priceOGC;
	// tPriceOGC = money spend for out going calls

	cout << name << ", you have spent "<< tPriceOGC << " TL for outgoing calls you made while you are abroad." << endl << endl;
	
	double priceICC; 
	// priceICC = price of incoming call per minute in TL

	cout << name << ", please enter the price for incoming call per minute: ";
	cin >> priceICC;
	
	int numberICC;
	// numberICC = numbers of minutes talked incoming call
	cout << name << ", please enter how many minutes you have talked in incoming calls: ";
	cin >> numberICC;

	double tPriceICC = numberICC * priceICC;
	// tPriceICC = money spend for incoming calls

	cout << name << ", you have spent "<< tPriceICC << " TL for incoming calls you made while you are abroad."<< endl << endl;

	double priceIUMB;
	// priceIUMB = price of internet usage per MB in TL

	cout << name << ", please enter the price for internet usage per MB: ";
	cin >> priceIUMB;

	double numberIUGB;
	// numberIUGB = GBs of internet used 

	cout << name << ", please enter how many GBs you have used: ";
	cin >> numberIUGB;

	double tPriceInternet = numberIUGB * priceIUMB * 1024;
	// tPriceInternet = money spend for internet

	cout << name << ", you have spent "<< tPriceInternet <<" TL for the internet while you are abroad." << endl << endl;

	double priceSMS;
	// priceSMS = price of one international SMS in TL 

	cout << name << ", please enter the price for one SMS: ";
	cin >> priceSMS;

	int numberSMS;
	// numberSMS = number of SMS's sent

	cout << name << ", please enter the number of SMS you have sent: ";
	cin >> numberSMS;

	double tPriceSMS = numberSMS * priceSMS;
	// tPriceSMS = money spend for SMS

	cout << name << ", you have spent "<< tPriceSMS <<" TL for the SMS while you are abroad."<< endl << endl;

	double totalC = tPriceOGC + tPriceICC + tPriceInternet + tPriceSMS;
	// totalC = total cost for all roaming services

	cout << name << ", total cost for all roaming services is " << totalC << " TL." << endl;

	double tax = totalC * 18 / 100;
	// tax = tax

	cout << name << ", tax is "<< tax <<" TL." << endl;

	double totalFee = totalC + tax;
	// totalFee = total roaming bill fee with tax

	cout << name << ", total roaming bill fee with tax is " << totalFee << " TL."  << endl << endl;

    return 0;}
