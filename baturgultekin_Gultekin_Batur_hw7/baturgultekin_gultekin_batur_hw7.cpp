#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

struct team
{
	int rank;
	string name;
	int gamePlayed;
	int points;
	int numWins;
	int numLosses;
	int numDraws;
	int goalsS;
	int goalsC;
	int average;
};

void SelectSort(vector<team> & a)
	// pre: a contains a.size() elements
	// post: elements of a are sorted in non-decreasing order
{
	int j, k, minIndex, numElts = a.size();
	team temp;

	for(k=0; k < numElts - 1; k++)
	{   minIndex = k;             // minimal element index
		for(j=k+1; j < numElts; j++)
		{  
			if (a[j].points > a[minIndex].points)
			{  
				minIndex = j;     // new min, store index
			}

			else if ((a[j].points == a[minIndex].points) && (a[j].average >  a[minIndex].average))
			{
				minIndex = j;
			}

			else if ((a[j].points == a[minIndex].points) && (a[j].average == a[minIndex].average) && (a[j].name < a[minIndex].name) )
			{
				minIndex = j;
			}
		}
		temp = a[k];         // swap min and k-th elements
		a[k] = a[minIndex];
		a[minIndex] = temp;
	}
}

void InsertionSort(vector<team> & rank) 
{
	int i, j;
	team key;

	for (int i = 1; i < rank.size(); i++)
	{
		key = rank[i];
		j= i-1;

		bool check= true;
		while(j>=0 && rank[j].points <= key.points && check)
		{
			if(rank[j].points == key.points)
			{
				if(rank[j].average <= key.average)
				{
					rank[j+1] = rank[j];
					j= j-1;
				}
				else
				{
					if(rank[j].average == key.average)
					{
						if(rank[j].name > key.name)
						{
							rank[j+1] = rank[j];
							j= j-1;
						}
						else
						{
							check=false;
						}
					}
					else
					{
						check=false;
					}
				}
			}
			else
			{
				rank[j+1] = rank[j];
				j= j-1;
			}
		}
		rank[j+1]= key;
	}
}

void changePosition(team & team1, team & team2)
{
	team teamP;
	teamP= team1;
	team1= team2;
	team2=teamP;
}

int isThereAny (vector<team> & a, string & s)
	// post: returns the index of occurrence of s in a, -1 
	// otherwise
{
	int k;
	for (k=0; k < a.size(); k++)
	{   
		if (a[k].name == s)
		{  
			return k;
		}
	}
	return -1;
}

int SetRank(vector<team> & r, string & teamname)
{
	return isThereAny(r,teamname)+1;
}


int main()
{
	ifstream input;
	string filename;
	string s;


	cout << "Please enter a filename: ";
	cin >> filename;

	input.open(filename.c_str());

	for (int x = 0; x < 1;)
	{
		if (input.fail())
		{
			cout << "Program cannot open " << filename << endl;
			cout << "Please enter a filename: ";
			cin >> filename;
			input.open(filename.c_str());
		}
		else
		{
			x+=1;
		}
	}

	vector<team> matches;
	string FirstTeam,SecondTeam;
	int score1, score2, check1, check2;

	while (getline(input,s))
	{
		istringstream str(s);
		team team1, team2;
		str >> FirstTeam >> score1 >> score2 >> SecondTeam;  
		check1 = isThereAny(matches, FirstTeam);
		check2 = isThereAny(matches, SecondTeam);

		if (check1 !=-1) // takim daha öceden yaratilmis ise
		{
			int k;
			k= isThereAny(matches, FirstTeam);
			matches[k].goalsS += score1;
			matches[k].goalsC += score2;
			matches[k].gamePlayed++;
			matches[k].average=team1.goalsS-team1.goalsC;



			if (check2 !=-1) // takim daha öceden yaratilmis ise
			{
				int j;
				j= isThereAny(matches, SecondTeam);
				matches[j].goalsS += score2;
				matches[j].goalsC += score1;
				matches[j].gamePlayed++;
				matches[j].average=team2.goalsS-team2.goalsC;
			}

			else // takim ilk kez yaratiliyorsa
			{
				team2.name=SecondTeam;
				team2.gamePlayed=0;
				team2.rank=0;
				team2.points=0;
				team2.numWins=0;
				team2.numLosses=0;
				team2.numDraws=0;
				team2.goalsS=0;
				team2.goalsC=0;
				team2.average=0;
				team2.goalsS=score2;
				team2.goalsC= score1;
				team2.gamePlayed++;
				team2.average= team2.goalsS-team2.goalsC;
				matches.push_back(team2);
			} 
		}
		else // takim ilk kez yaratiliyorsa
		{
			team1.name=FirstTeam;
			team1.gamePlayed=0;
			team1.rank=0;
			team1.points=0;
			team1.numWins=0;
			team1.numLosses=0;
			team1.numDraws=0;
			team1.goalsS=0;
			team1.goalsC=0;
			team1.average=0;
			team1.goalsS=score1;
			team1.goalsC= score2;
			team1.gamePlayed++;
			team1.average= team1.goalsS-team1.goalsC;
			matches.push_back(team1);


			if (check2 !=-1)// takim daha öceden yaratilmis ise
			{
				int l;
				l= isThereAny(matches, SecondTeam);
				matches[l].goalsS += score2;
				matches[l].goalsC += score1;
				matches[l].gamePlayed++;
				matches[l].average=team2.goalsS-team2.goalsC;
			}

			else // takim ilk kez yaratiliyorsa
			{
				team2.name=SecondTeam;
				team2.gamePlayed=0;
				team2.rank=0;
				team2.points=0;
				team2.numWins=0;
				team2.numLosses=0;
				team2.numDraws=0;
				team2.goalsS=0;
				team2.goalsC=0;
				team2.average=0;
				team2.goalsS=score2;
				team2.goalsC= score1;
				team2.gamePlayed++;
				team2.average= team1.goalsS-team1.goalsC;
				matches.push_back(team2);
			} 
		}

		check1 = isThereAny(matches, FirstTeam);
		check2 = isThereAny(matches, SecondTeam);

		if (score1> score2)
		{
			matches[check1].numWins++;
			matches[check2].numLosses++;
			matches[check1].points += 3;
		}
		else if (score1 < score2)
		{
			matches[check2].numWins++;
			matches[check1].numLosses++;
			matches[check2].points += 3;
		}

		else if (score1 == score2)
		{
			matches[check1].numDraws++;
			matches[check2].numDraws++;
			matches[check1].points ++;
			matches[check2].points ++;
		}

	}

	
		cout<< "Please enter a team name: ";
		string tn;
		cin >> tn;

		int checkTeam = isThereAny(matches, tn);

		if (checkTeam == -1)
		{
			cout << "There is no such team!" << endl;
		}
		else
		{
			SelectSort(matches);
			

			for (int i=0; i < matches.size(); i++)
			{
				if (matches[i].name == tn)// tn = input takım adı 
				{
					cout << "Rank: "<< SetRank(matches, tn) << endl;
					cout << "Matches played: "<< matches[i].gamePlayed<< endl;
					cout << "Wins: "<< matches[i].numWins<< endl;
					cout << "Draws: "<< matches[i].numDraws<< endl;
					cout << "Losts: "<< matches[i].numLosses<< endl;
					cout << "Goals scored: "<< matches[i].goalsS<< endl;
					cout << "Goals conceded: "<< matches[i].goalsC<< endl;
					cout << "Goal difference: "<< matches[i].goalsS - matches[i].goalsC << endl;
					cout << "Points: "<< matches[i].points<< endl;
				}
			}

		}
	return 0;
}
