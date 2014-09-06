
#include <iostream>
#include "TestClass.h"

using namespace std;

void TestClass::TestAdd()
{

}

void TestClass::TestShuffleCards()
{
	Hard h;

	int a[] = {1, 2, 3, 4, 5, 6};
	int n = 6;

	h.ShuffleCards(a, n);
	
	for(int i = 0; i < n; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void TestClass::TestGetMinDis()
{
	Hard h;
	vector<string> file;
	file.push_back("What");
	file.push_back("is");
	file.push_back("your");
	file.push_back("name");
	file.push_back("My");
	file.push_back("name");
	file.push_back("is");
	file.push_back("Li");
	file.push_back("Qian");

	cout<<h.getMinDis(file, "is", "name")<<endl;
}

void TestClass::TestMaxCompoundWord()
{
	Hard h;
	string init[] = {"test", "tester", "testertest", "testing", "apple", "seattle", "banana",  "batting", "ngcat", "batti","bat", "testingtester", "testbattingcat"};
	vector<string> input;
	input.assign(init, init + 13);
	cout<<h.findMaxCompound(input)<<endl;
}
