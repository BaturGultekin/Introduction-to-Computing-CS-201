#include <iostream>
#include <string>
#include "strutils.h"
#include <fstream>
#include <sstream>
using namespace std;

void openInput(ifstream& input, string& fileName, string q)
{
	cout << "Please enter a filename which contains " << q;
	cin >> fileName;
	input.open(fileName);
	while (input.fail())
	{
		cout << "Error for opening " << fileName<< " Please enter filename again: ";
		cin >> fileName;
		input.open(fileName);
	}
}

bool couponCheck(ifstream& input)
{
	string line;
	int count = 0;
	while (getline(input, line))
	{
		count++;
	}

	if (count < 4)
	{
		return false;
	}
	return true;
}



string program(ifstream& cInput, ifstream& sInput, ifstream& pInput)
{
	string cLine, sLine, pLine, score, s, t, teams;
	double money, Money, lBet, dBet, wBet, odd = 1;
	int cCode, sCode, pCode, wdl;
	bool sCheck = true, pCheck = true, successCheck = true, couponValid = couponCheck(cInput);
	cInput.clear();
	cInput.seekg(0);

	while (getline(cInput, cLine))//coupon search
	{
		istringstream iss(cLine);
		if (cLine.substr(0, 5) == "STAKE")
		{
			string stake;
			iss >> stake >> money;
			Money = money;
		}
		else
		{
			iss >> cCode >> wdl;


			while (getline(sInput, sLine) && sCheck)//matchscores search
			{
				istringstream iss(sLine);
				iss >> sCode >> score;
				if (cCode == sCode)
				{
					string firstScore = score.substr(0, 1);
					int score1 = atoi(firstScore);
					string secondScore = score.substr(2, 1);
					int score2 = atoi(secondScore);
					sCheck = false;


					while (getline(pInput, pLine) && pCheck)//program search
					{
						istringstream iss(pLine);
						iss >> pCode;
						if (cCode == pCode)
						{
							int wordCount = 0;
							while (iss >> s)
							{
								wordCount++;
							}

							istringstream iss2(pLine);
							int c;
							iss2 >> c;

							for (int i = 0; i < wordCount - 3; i++)
							{
								iss2 >> t;
								teams += t + " ";
							}
							iss2 >> wBet >> dBet >> lBet;


							if (score1 > score2 && wdl == 1)
							{
								cout << cCode << " " << teams << wBet << " SUCCESS" << endl;
								money *= wBet;
								odd *= wBet;
							}
							else if (score1 == score2 && wdl == 0)
							{
								cout << cCode << " " << teams << dBet << " SUCCESS" << endl;
								money *= dBet;
								odd *= dBet;
							}
							else if (score1 < score2 && wdl == 2)
							{
								cout << cCode << " " << teams << lBet << " SUCCESS" << endl;
								money *= lBet;
								odd *= lBet;
							}
							else if (score1 >= score2 && wdl == 2)
							{
								cout << cCode << " " << teams << lBet << " FAILED" << endl;
								successCheck = false;
							}
							else if (score1 != score2 && wdl == 0)
							{
								cout << cCode << " " << teams << dBet << " FAILED" << endl;
								successCheck = false;
							}
							else if (score1 <= score2 && wdl == 1)
							{
								cout << cCode << " " << teams << wBet << " FAILED" << endl;
								successCheck = false;
							}
							sCheck = false;
							pCheck = false;
							pInput.clear();
							pInput.seekg(0);
							sInput.clear();
							sInput.seekg(0);
						}
						teams = "";
					}
				}
			}

			if (sCheck && pCheck)
			{
				pInput.clear();
				pInput.seekg(0);
				sInput.clear();
				sInput.seekg(0);
				couponValid = false;
			}
			sCheck = true;
			pCheck = true;
		}
	}

	if (couponValid)
	{
		if (successCheck)
		{
			return "\nTOTAL ODDS: " + tostring(odd) + "\n\nYou won " + tostring(money) + " TL\n";
			//cout << endl << "TOTAL ODDS: " << odd << endl;
			//cout << endl << "You won " << money << " TL" << endl;
		}
		else
		{
			return "\nYOU LOST, " + tostring(Money) + " TL HAS GONE\n";
			//cout << endl << "YOU LOST, " << Money << " TL HAS GONE" << endl;
		}
	}
	else
		return "\nINVALID COUPON\n";

	//cout << endl << "INVALID COUPON" << endl;
}


int main()
{
	string pFilename, cFilename, sFilename;
	ifstream pInput, cInput, sInput;

	cout << "This is a simple betting program." << endl << endl;

	openInput(pInput, pFilename, "whole betting program: ");
	openInput(cInput, cFilename, "the matches played by a user: ");
	openInput(sInput, sFilename, "the match scores of the week: ");
	cout << endl;

	string message = program(cInput, sInput, pInput);
	cout << message << endl << "!!! BET 'LEGALLY' AND 'RESPONSIBLY' !!!" << endl << endl;


	return 0;
}