#include <iostream>
#include "TestClass.h"

using namespace std;

void TestClass::TestSwap()
{
	Moderate m;
	cout<<"Below is the simple swap test"<<endl;
	m.swap(3, 7);
	m.swap(7, 2);
	m.swap(5, 5);

	cout<<"Below is the bit version swap test"<<endl;
	m.swapBitOpt(3, 7);
	m.swapBitOpt(7, 2);
	m.swapBitOpt(5, 5);
}

void TestClass::TestFactorialZeros()
{
	Moderate m;

	int number = -10;
	int result = m.zerosInFactorial(number);
	cout<<"0 numbers of "<<number<<" is "<<result<<endl;

	number = 5;
	result = m.zerosInFactorial(number);
	cout<<"0 numbers of "<<number<<" is "<<result<<endl;

	number = 10;
	result = m.zerosInFactorial(number);
	cout<<"0 numbers of "<<number<<" is "<<result<<endl;

	number = 15;
	result = m.zerosInFactorial(number);
	cout<<"0 numbers of "<<number<<" is "<<result<<endl;

	number = 28;
	result = m.zerosInFactorial(number);
	cout<<"0 numbers of "<<number<<" is "<<result<<endl;

	number = 127;
	result = m.zerosInFactorial(number);
	cout<<"0 numbers of "<<number<<" is "<<result<<endl;
}

void TestClass::TestGetMax()
{
	Moderate m;
	int a, b, result;

	a = 4;
	b = 6;
	result = m.getMax(a, b);
	cout<<"The max of "<<a<<" and "<<b<<" is "<<result<<endl;

	a = 6;
	b = 4;
	result = m.getMax(a, b);
	cout<<"The max of "<<a<<" and "<<b<<" is "<<result<<endl;

	a = -4;
	b = -6;
	result = m.getMax(a, b);
	cout<<"The max of "<<a<<" and "<<b<<" is "<<result<<endl;

	a = -4;
	b = 6;
	result = m.getMax(a, b);
	cout<<"The max of "<<a<<" and "<<b<<" is "<<result<<endl;
}

void TestClass::TestMasterMind()
{
	Moderate m;
	vector<char> solution, guess;

	char solu[4] = {'R', 'G', 'G', 'B'};
	char gue[4] = {'Y', 'R', 'G', 'B'};
	solution.assign(solu, solu + 4);
	guess.assign(gue, gue + 4);
	cout<<"Solution is "<<solution[0]<<" "<<solution[1]<<" "<<solution[2]<<" "<<solution[3]<<" "<<endl;
	cout<<"User Guess is "<<guess[0]<<" "<<guess[1]<<" "<<guess[2]<<" "<<guess[3]<<" "<<endl;
	m.getMasterMindResult(solution, guess);

	char gue1[4] = {'R', 'R', 'G', 'G'};
	guess.assign(gue1, gue1 + 4);
	cout<<"Solution is "<<solution[0]<<" "<<solution[1]<<" "<<solution[2]<<" "<<solution[3]<<" "<<endl;
	cout<<"User Guess is "<<guess[0]<<" "<<guess[1]<<" "<<guess[2]<<" "<<guess[3]<<" "<<endl;
	m.getMasterMindResult(solution, guess);

	char gue2[4] = {'Y', 'Y', 'Y', 'G'};
	guess.assign(gue2, gue2 + 4);
	cout<<"Solution is "<<solution[0]<<" "<<solution[1]<<" "<<solution[2]<<" "<<solution[3]<<" "<<endl;
	cout<<"User Guess is "<<guess[0]<<" "<<guess[1]<<" "<<guess[2]<<" "<<guess[3]<<" "<<endl;
	m.getMasterMindResult(solution, guess);
}

void TestClass::TestTranslateNumber()
{
	Moderate m;
	
	int number = 1627;
	cout<<"Input is "<<number<<endl;
	cout<<"Result is: "<<m.translateNumber(number)<<endl;
}

void TestClass::TestSubMax()
{
	Moderate m;
	int temp[] = {2, -8, 3, -2, 4, -10, 1};
	vector<int> input;
	input.assign(temp, temp + 7);
	m.getMaxContinuousSeq(input);
}