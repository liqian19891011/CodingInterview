#include <vector>
#include <iostream>
#include "TestClass.h"
#include "Recursion.h"

using namespace std;

void TestClass::TestGetSubsetBinary()
{
	vector<int> set;
	set.push_back(1);
	set.push_back(2);
	set.push_back(3);
	set.push_back(4);

	Recursion re;
	cout<<"Below is the non-recursion solution result: "<<endl;
	re.GetSubsetBinary(set);
}

void TestClass::TestGetSubsetRecursion()
{
	vector<int> set;
	set.push_back(1);
	set.push_back(2);
	set.push_back(3);
	set.push_back(4);

	Recursion re;
	auto result = re.GetSubsetRecursion(set);

	for(int i = 0; i < result.size(); ++i)
	{
		cout<<"{ ";
		for(int j = 0; j < result[i].size(); ++j)
		{
			if(result[i][j] != 0)
				cout<<result[i][j]<<" "; 
		}
		cout<<"}"<<endl;
	}
}

void TestClass::TestGetPerm()
{
	vector<string> strList;
	Recursion re;
	strList = re.GetPerm("abc");

	for(int i = 0; i < strList.size(); ++i)
	{
		cout<<strList[i]<<endl;
	}
}

void TestClass::TestGetPair()
{
	Recursion re;
	re.GetParis(3);
}