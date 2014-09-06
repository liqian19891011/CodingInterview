#ifndef HEADER_H
#define HEADER_H

#include <vector>
#include <string>
#include <map>
using namespace std;

class Moderate
{
public:
	void swap(int a, int b);
	void swapBitOpt(int a, int b);
	int zerosInFactorial(int number);
	int getMax(int a, int b);
	void getMasterMindResult(vector<char> solution, vector<char> guess);
	string translateNumber(int number);
	void getMaxContinuousSeq(vector<int> input);
private:
	string tranlateBase(int number);
};

#endif /*HEADER_H*/