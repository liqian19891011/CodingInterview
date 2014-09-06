#ifndef HARD_H
#define HARD_H

#include <vector>
#include <string>
using namespace std;

class Hard
{
public:
	int addWithoutPlus(int a, int b);
	void ShuffleCards(int a[], int n);
	int getMinDis(vector<string> contents, string a, string b);
	string findMaxCompound(vector<string> input);
private:
	void swap(int &a, int &b);
	bool isCompoundWord(vector<string> input, string word, int wordLen);
	bool hasMatch(vector<string> input, string word);
};

#endif /*HARD_H*/