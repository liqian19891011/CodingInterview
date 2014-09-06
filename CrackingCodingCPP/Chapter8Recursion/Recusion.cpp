#include <iostream>
#include "Recursion.h"

using namespace std;

vector<vector<int>> Recursion::GetSubsetRecursion(vector<int> originalSet)
{
	vector<vector<int>> result;

	if(originalSet.size() == 0)
	{
		result.push_back(originalSet);
	}
	else
	{
		vector<int> start(originalSet.begin(), originalSet.begin() + 1);
		vector<int> remainder(originalSet.begin() + 1, originalSet.end());

		vector<vector<int>> subsets = GetSubsetRecursion(remainder);

		for(int i = 0; i < subsets.size(); ++i)
		{
			result.push_back(subsets[i]);
			vector<int> temp = subsets[i];
			temp.push_back(*(start.begin()));
			result.push_back(temp);
		}
	}

	return result;
}

void Recursion::GetSubsetBinary(vector<int> originalSet)
{
	int max = 1 << originalSet.size();
	for(int i = 0; i < max; ++i)
	{
		vector<int> temp;
		int k = i;
		int index = 0;
		while(k > 0)
		{
			if( (k & 1) > 0)
				temp.push_back(originalSet[index]);
			k = k>>1;
			index++;
		}
		resultSubSet.push_back(temp);
	}

	for(int i = 0; i < resultSubSet.size(); ++i)
	{
		vector<int> temp = resultSubSet[i];
		for(int j = 0; j < temp.size(); ++j)
			cout<<temp[j]<<"  ";
		cout<<endl;
	}
}

vector<string> Recursion::GetPerm(string str)
{
	vector<string> perList;
	if(str.length() == 0)
	{
		perList.push_back("");
		return perList;
	}

	for(int i = 0; i < str.length(); ++i)
	{
		string firstChar = str.substr(i, 1);
		string remainder = str.substr(0, i) + str.substr(i + 1);
		vector<string> words = GetPerm(remainder);
		for(int j = 0; j < words.size(); ++j)
		{
			perList.push_back(firstChar + words[j]);
		}
	}

	return perList;
}

void Recursion::GetParis(int count)
{
	vector<char> str;
	str.assign(count * 2, ' ');
	PrintPair(count, count, str, 0);
}

void Recursion::PrintPair(int l, int r, vector<char> str, int count)
{
	if(l < 0 || r < l)
		return;
	if(l == 0 && r == 0)
	{
		for(int i = 0; i < str.size(); ++i)
			cout<<str[i];
		cout<<endl;
	}
	else
	{
		if(l > 0)
		{
			str[count] = '(';
			PrintPair(l - 1, r, str, count + 1);
		}
		if(r > l)
		{
			str[count] = ')';
			PrintPair(l, r - 1, str, count + 1);
		}
	}
}

void Recursion::MakeChange(int cents)
{
}