#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream in("calories.txt");
		if (!in) cerr << "no file\n";
	string endline = "\n";
	int sum = 0;
	int highest = 0;
	for(string line; getline(in,line);)
	{
		if(line.empty())
		{
			if(sum > highest)
			{
				highest = sum;
			}
			sum = 0;
		} else
		{
			sum = sum + stoi(line);
		}
	}
	in.close();
	cout << "the highest: " << highest << "\n";
	return 0;
}
