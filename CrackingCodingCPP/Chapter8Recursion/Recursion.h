#ifndef RECURSION_H
#define RECURSION_H

#include <vector>
#include <string>
#include <set>

using namespace std;

class Recursion
{
public:
	vector<vector<int>> GetSubsetRecursion(vector<int> originalSet);		//We just accept positive number in the set and 0 means empty here
	void GetSubsetBinary(vector<int> originalSet);
	vector<string> GetPerm(string str);
	void GetParis(int count);
	void MakeChange(int cents);
	
	friend class TestClass;
private:
	vector<vector<int> > resultSubSet;
	void PrintPair(int r, int l, vector<char> str, int count);
};

#endif /*RECURSION_H*/