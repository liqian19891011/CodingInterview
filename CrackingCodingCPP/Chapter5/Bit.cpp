#include "Bit.h"
#include <math.h>
#include <iostream>

using namespace std;

int Bit::UpdateBit(int n, int m, int i, int j)
{
	/*if (i >= j)
		return n;

	int outerMask = ((1 << i) - 1) | (~0 << (j + 1));
	int mask = m << i;

	n &= outerMask;
	n |= mask;

	return n;*/
	int max = ~0;

	int left = max - ((1<<j )- 1);   //right????
	int right = (1<<i)-1;

	int mask = left | right;

	n = (n & mask) | (m<<i);

	return n;
}

void Bit::DecimalToBinary(string decimal)
{
	unsigned index = decimal.find('.');

	//Get the int and float part in string mode
	string intString = decimal.substr(0, index);
	string floatString = decimal.substr(index + 1, decimal.size()-index);

	//Get the int and float value
	int intValue = 0;
	for(int i = 0; i < intString.size(); ++i)
	{
		int base = (intString[intString.size() - i - 1] - '0');
		intValue += base * pow(10, i);
	}
	double floadValue = 0;
	for(int i = 0; i < floatString.size(); ++i)
	{
		int base = (floatString[i] - '0');
		int c = pow(10, -(i+1));
		floadValue +=  base * pow(10, -(i+1));
	}
	vector<int> v1 = IntToBinary(intValue);
	vector<int> v2 = FloatToBinary(floadValue, 10);

	for(int i = 0; i < v1.size(); ++i)
	{
		cout<<v1[v1.size() - i -1];
	}
	cout<<".";
	for(int i = 0; i < v2.size(); ++i)
	{
		cout<<v2[i];
	}
}

int Bit::BitDistance(int m, int n)
{
	int result = 0;

	int mask = m^n;
	
	//Count the number of '1' in mask
	while(mask > 0)
	{
		if(mask & 1 == 1)
			result++;
		mask = mask >> 1;
	}
	return result;
}

int Bit::SwapBits(int m)
{
	int temp = m;
	int count = 0;
	while(temp > 0)
	{
		//Get the even and odd number
		int even = (m >> count) & 1;
		int odd = (m >> (count + 1)) & 1;

		//Swap the even and odd number
		if(odd == 1)
			m = m | (1<<count);
		else
			m = m &~ (1<<count);

		if(even == 1)
			m = m | (1<<(count + 1));
		else
			m = m &~ (1<< (count + 1));

		temp = temp>>1;
		count = count + 2;
	}

	return m;
	/* There is a more simple way*/
	/*
	 * return (((m & 0xaaaaaaaa) >> 1) | ((m & 0x55555555) << 1));
	 */
}

vector<int> Bit::IntToBinary(int value)
{
	vector<int> result;
	while(value != 0)
	{
		result.push_back(value % 2);
		value = value/2;
	}

	return result;
}

vector<int> Bit::FloatToBinary(double value, int size)
{
	vector<int> result;

	int count = 0;
	while((value - 0 > 0.0000000001) && count < size)
	{
		result.push_back(floor(value * 2));
		if(value * 2 >= 1)
			value = value*2 - 1;
		else
			value = value * 2;
		count++;
	}

	return result;
}