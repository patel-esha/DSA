#include <iostream>
#include <string>
using namespace std;

int suffixCount(std::string S, int L) {
	string suffix;
	int count = 0;
	for (int i = 1; i <= L; i++)
	{
		suffix += S[S.size() - i];
	}
	for (int j = 0; j <= S.size() - L; j++)
	{
		if (S.substr(j, L) == suffix)
		{
			count +=1;
		}
	}
	return count;
	
}
