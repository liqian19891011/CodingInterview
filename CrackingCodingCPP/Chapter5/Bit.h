#ifndef BIT_H
#define BIT_H

#include <string>
#include <vector>
using namespace std;

class Bit
{
public:
	int UpdateBit(int n, int m, int i, int j);
	void DecimalToBinary(string decimal);
	int BitDistance(int m, int n);
	int SwapBits(int m);
private:
	vector<int> IntToBinary(int value);
	vector<int> FloatToBinary(double value, int size);
};

#endif