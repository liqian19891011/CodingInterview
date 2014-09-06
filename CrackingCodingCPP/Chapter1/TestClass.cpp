#include <iostream>
#include <assert.h>
#include "TestClass.h"

using namespace std;

void TestClass::TestStringUnique()
{
	string uniqueString = "abcd";
	string normalString1 = "abca";
	string normalString2 = "abac";
	string normalString3 = "ababcd";

	Practice * practice = new Practice();
	assert(practice->StringUnique(uniqueString) == true);
	assert(practice->StringUnique(normalString1) == false);
	assert(practice->StringUnique(normalString2) == false);
	assert(practice->StringUnique(normalString3) == false);

	assert(practice->StringUnique2(uniqueString) == true);
	assert(practice->StringUnique2(normalString1) == false);
	assert(practice->StringUnique2(normalString2) == false);
	assert(practice->StringUnique2(normalString3) == false);
	
	delete practice;
}

void TestClass::TestReverseCString()
{
	Practice * practice = new Practice();
	char * input = new char();
	strcpy(input, "abcd");
	practice->ReverseCString(input);
	
	while(*input)
	{
		cout<<*input;
		++input;
	}
	cout<<endl;

	delete practice;
}

void TestClass::TestRemoveDuplicate()
{
	Practice * practice = new Practice();
	practice->RemoveDuplication("hello");
	practice->RemoveDuplication("abcbc");
	practice->RemoveDuplication("abcd");
	practice->RemoveDuplication("aaaaaa");
	practice->RemoveDuplication("aaabb");
	practice->RemoveDuplication("");

	delete practice;
}

void TestClass::TestAnagram()
{
	Practice * practice = new Practice();

	assert(practice->DetectAnagram("") == true);
	assert(practice->DetectAnagram("a") == true);
	assert(practice->DetectAnagram("abcba") == true);
	assert(practice->DetectAnagram("abccba") == true);
	assert(practice->DetectAnagram("abcda") == false);

	assert(practice->DetectAnagramTwoStr("", "") == true);
	assert(practice->DetectAnagramTwoStr("a", "a") == true);
	assert(practice->DetectAnagramTwoStr("abc", "cba") == true);
	assert(practice->DetectAnagramTwoStr("abc", "cb") == false);
	assert(practice->DetectAnagramTwoStr("abc","cca") == false);


	delete practice;
}

void TestClass::TestReplaceSpaces()
{
	Practice * practice = new Practice();

	string str1 = "hello world!";
	string str2 = "helloworld!";
	string str3 = "hello world !";
	string str4 = "hello%20world !";

	practice->ReplaceSpaces(str1);
	practice->ReplaceSpaces(str2);
	practice->ReplaceSpaces(str3);
	practice->ReplaceSpaces(str4);

	char c1[] = { "hello world!" };
	char c2[] = { "helloworld!" };
	char c3[] = { "hello world !" };
	char c4[] = { "hello%20world !" };
	practice->ReplaceSpacesBack(c1, 12);
	practice->ReplaceSpacesBack(c2, 11);
	practice->ReplaceSpacesBack(c3, 13);
	practice->ReplaceSpacesBack(c4, 15);

	delete practice;
}

void TestClass::TestSetZero()
{
	Practice * practice = new Practice();

	vector<int> list;
	list.push_back(3);
	list.push_back(2);
	list.push_back(0);
	list.push_back(1);
	list.push_back(6);
	list.push_back(4);
	list.push_back(9);
	list.push_back(0);
	list.push_back(8);

	int m = 3;
	int n = 3;

	int** matrix = practice->InitializeMatrix(m, n, list);

	practice -> SetZeroOnMatrix(m, n, matrix);

	delete practice;
}

void TestClass::TestRotateMatrix()
{
	Practice * practice = new Practice();

	vector<int> list;
	list.push_back(0);
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);
	list.push_back(8);
	list.push_back(9);
	list.push_back(10);
	list.push_back(11);
	list.push_back(12);
	list.push_back(13);
	list.push_back(14);
	list.push_back(15);

	int m = 4;
	int n = 4;

	int** matrix = practice->InitializeMatrix(m, n, list);
	practice->RotateMatrix(n, matrix);

	delete practice;
}