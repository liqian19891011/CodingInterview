//#define BOOST_TEST_MODULE DEMO

#include <iostream>
#include <string>
#include "TestClass.h"

using namespace std;

int main()
{
	TestClass testClass;

	//testClass.TestShuffleCards();
	//testClass.TestGetMinDis();
	testClass.TestMaxCompoundWord();

	int tt;
	cin>>tt;
	return 0;
}

//TestClass testClass;
//
//BOOST_AUTO_TEST_SUITE(test)
//
//BOOST_AUTO_TEST_CASE(testAdd)
//{
//	testClass.TestAdd();
//}
//
//BOOST_AUTO_TEST_SUITE_END()