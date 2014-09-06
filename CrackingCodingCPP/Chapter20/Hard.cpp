#include <cstdlib>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include "Hard.h"

using namespace std;

inline bool cmp(string a, string b)
{
	return a.length() > b.length();
}

int Hard::addWithoutPlus(int a, int b)
{
	if(b == 0)
		return a;
	int sum = a ^ b;
	int carry = (a & b) << 1;
	return addWithoutPlus(sum, carry);
}

void Hard::swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

void Hard::ShuffleCards(int a[], int n)
{
	srand((unsigned)time(0));
	for(int i = 0; i < n; i++)
	{
		int j = rand() % (n-i) + i;
		swap(a[i], a[j]);
	}
}

int Hard::getMinDis(vector<string> contents, string a, string b)
{
	int posA = -1;
	int posB = contents.size();
	int dis = abs(posA - posB);

	for(int i = 0; i < contents.size(); i++)
	{
		if(contents[i] == a)
			posA = i;
		else if(contents[i] == b)
			posB = i;

		int newDis = abs(posA - posB);
		if(newDis < dis)
			dis = newDis;
	}

	return dis;
}

string Hard::findMaxCompound(vector<string> input)
{
	sort(input.begin(), input.begin() + input.size(), cmp);

	for(int i = 0; i < input.size(); i++)
	{
		if(isCompoundWord(input, input[i], input[i].length()))
			return input[i];
	}
}

bool Hard::isCompoundWord(vector<string> input, string word, int wordLen)
{
	int len = word.length();

	if(0 == len)
		return true;

	for(int i = 1; i <= len; i++)
	{
		if(i == wordLen)
			return false;
		string str = word.substr(0, i);
		if(hasMatch(input, str))
		{
			if(isCompoundWord(input, word.substr(i), wordLen))
			{
				string t = word.substr(i);
				return true;
			}
		}

	}

	return false;
}

bool Hard::hasMatch(vector<string> input, string word)
{
	bool result = false;
	for(int i = 0; i < input.size(); i++)
	{
		if(input[i] == word)
		{
			result = true;
			break;
		}
	}
	
	return result;
}