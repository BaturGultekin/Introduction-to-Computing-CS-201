#include <iostream>
#include <string>
#include "strutils.h"

using namespace std;

bool letterCheck (string exp){

	bool check = true;
	for(int index=0; index < exp.length(); index++){
		if (((exp.at(index) == '+')||(exp.at(index) =='-')||(exp.at(index) =='*')||(exp.at(index) =='/')) ||( ((exp.at(index)) >= '0') && (exp.at(index) <= '9'))) {
		check = true;
		}
		else {
			check= false;
			break;
		}
	}
	return check;
}

bool operationInputCheck (string exp, int& L){

	if (((exp.find("+")!= string::npos) || (exp.find("-")!= string::npos))  && (((exp.find("*")!= string::npos) || (exp.find("/")!= string::npos)))){
		L-=1;
		cout<< "Invalid entry"<< endl << endl;
		return false;
	}
	else if ((exp.find("++")!= string::npos)||(exp.find("--")!= string::npos)||(exp.find("+-")!= string::npos)||(exp.find("-+")!= string::npos)||(exp.find("**")!= string::npos)||(exp.find("//")!= string::npos)||(exp.find("*/")!= string::npos)||(exp.find("/*")!= string::npos)){
		L-=1;
		cout<< "Invalid entry"<< endl << endl;
		return false;
	}
	else if (exp.find("/0")!= string::npos){
		L-=1;
		cout<< "You cannot divide by 0"<< endl << endl;
		return false;
	}
	else if ((exp.at(0) == '+')||(exp.at(0) =='-')||(exp.at(0) =='*')||(exp.at(0) =='/')||( exp.at(exp.length()-1) == '+')||(exp.at(exp.length()-1) =='-')||(exp.at(exp.length()-1) =='*')||(exp.at(exp.length()-1) =='/')){
		L-=1;
		cout<< "Invalid entry"<< endl << endl;
		return false;
	}
	else if (letterCheck(exp) == false){
		L-=1;
		cout<< "Invalid entry"<< endl << endl;
		return false;
	}
	else if (((exp.find("+") == string::npos) && (exp.find("-") == string::npos)) &&  (((exp.find("*")== string::npos) && (exp.find("/")== string::npos)))){
		L-=1;
		cout << exp << endl << endl;
		return false;
	}
		return true;
}

double calculation(string exp){
	int i=0; 
	double sum= 0;

	while (i< exp.length()){
		int count = 0;

			while(exp.at(i)== '+' || exp.at(i)=='-'){

				if(exp.at(i)== '-'){
				count+= 1;
				i++;
				}

				else 
					i++;
			}
			int j=i;
			int p=0;

			while(exp.at(i)!= '+' && exp.at(i)!='-'){
				p+=1;
			i++;

			if(i==exp.length())
				break;
			}
			if (count == 1)
				sum+= atoi(exp.substr(j,p))* -1.0;
			else 
				sum+=atoi(exp.substr(j,p))* 1.0;
	}
	return sum;
}

double calculation2(string exp){
	int i=0,j,p,s;
	double sum;
	int check = 0;

	while (i< exp.length()){
		int count = 0;

			while(exp.at(i)== '*' || exp.at(i)=='/'){

				if(exp.at(i)== '/'){
				count+= 1;
				i++;
				}

				else 
					i++;
			}
			
			j=i;
			p=0;
			
			while(exp.at(i)!= '*' && exp.at(i)!='/'){
			p+=1;
			i++;

			if(i==exp.length())
				break;
			}
			check+=1;
			if(check == 1)
			{
				
				sum = atoi(exp.substr(0,p));
				if(sum == 0)
					return 0;
				s = sum;
			
			}
			if (count == 1)
			{
				sum = sum/atoi(exp.substr(j,p))* 1.0;
			}
			else if(count!=1)
			{
				sum =sum*atoi(exp.substr(j,p))* 1.0 ;
			}
	}
	return sum/s;
}

bool endOfProgram(string exp, int& finisher){
	if ((exp=="QUIT") || (exp=="quit")|| (exp=="EXIT")|| (exp=="exit")|| (exp=="END")|| (exp=="end")){
		cout<< "GOOD BYE" <<endl;
		finisher-=1;
		return false;
	}
	return true;
}

void mainFunc(string exp, int finisher, int L){

	endOfProgram(exp, finisher);

	while(finisher!=0){

		operationInputCheck(exp, L);

		if ((exp.find("+")!= string::npos || exp.find("-")!= string::npos) && (L!=0)){
			cout << calculation(exp)<< endl<< endl;
		}
		else if ((exp.find("*")!= string::npos || exp.find("/")!= string::npos) && (L!=0)){
			cout << calculation2(exp)<< endl<< endl;
		}
		cout << "Please enter the expression to calculate: ";
		cin>> exp;
		endOfProgram(exp, finisher);
		L = 1;
	}
}

int main(){
	string exp;
	int finisher= 1;
	int L=1;

	cout << "Please enter the expression to calculate: ";
	cin>> exp;

	mainFunc(exp, finisher, L);
	return 0;
}