#include <iostream>
#include <unordered_map>
#include <algorithm>
// geeks for geeks insertion sort utilized: https://www.geeksforgeeks.org/insertion-sort/

using namespace std;

string findTheDigits(string x, string y) 
{
    unordered_map<char, int> digitCounter;
	for (int i = 0; i < x.length(); i++) 
	{
	{
		char integer = x[i];
        digitCounter[integer]++;
    }
	}
    string returning;
	for (int j = 0; j < y.length(); j++) 
	{
		char integer = y[j];
        if (digitCounter.count(integer) > 0) 
		{
			if (digitCounter[integer] > 0)
			{
				digitCounter[integer]--;
			}
			else 
			{
            returning.push_back(integer);
			}

        } 
		else 
		{
            returning.push_back(integer);
        }
    }

    for (int i = 0; i < returning.length() - 1; i++) 
	{
        for (int j = 0; j < returning.length() - i - 1; j++) 
		{
            if (returning[j] > returning[j + 1]) 
			{
                char sorted = returning[j];
                returning[j] = returning[j + 1];
                returning[j + 1] = sorted;
            }
        }
    }
	return returning;
}

