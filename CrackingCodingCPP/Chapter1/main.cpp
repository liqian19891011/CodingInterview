#include "Practice.h"
#include "TestClass.h"
#include <iostream>

using namespace std;

/*This chapter is about stacks and queues*/
int main()
{
	TestClass * test = new TestClass();

	/*test->TestStringUnique();
	test->TestReverseCString();
	test->TestRemoveDuplicate();
	test->TestAnagram();
	test->TestReplaceSpaces();
	test->TestSetZero();
	test->TestRotateMatrix();*/
	test->TestReplaceSpaces();

	int i;
	cin>>i;

	delete test;

	return 0;
}