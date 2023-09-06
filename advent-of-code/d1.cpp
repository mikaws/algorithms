#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ifstream in("calories.txt");
		if (!in) std::cerr << "no file\n";
	std::string endline = "\n";
	int sum = 0;
	int highest = 0;
	for(std::string line; std::getline(in,line);)
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
	std::cout << "the highest: " << highest << "\n";
	return 0;
}
