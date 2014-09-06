#include "Moderate.h"
#include <iostream>
#include <string>
#include <map>
#include <math.h>

using namespace std;

void Moderate::swap(int a, int b)
{
	cout<<"Before swap, a: "<<a<<" b: "<<b<<endl;
	a = b - a;
	b = b - a;
	a = a + b;

	cout<<"After swap, a: "<<a<<" b: "<<b<<endl;
}

void Moderate::swapBitOpt(int a, int b)
{
	cout<<"Before swap, a: "<<a<<" b: "<<b<<endl;
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;

	cout<<"After swap, a: "<<a<<" b: "<<b<<endl;
}

int Moderate::zerosInFactorial(int number)
{
	int count = 0;

	if( number < 0)
		return -1;

	for(int i = number; i > 0; i--)
	{
		if( (i % 5) == 0)
		{
			count ++;
			int temp = i / 5;
			while( (temp % 5) == 0)
			{
				count ++;
				temp = temp / 5;
			}
		}
	}

	return count;
}

int Moderate::getMax(int a, int b)
{
	int c = a - b;

	//K stands for the most significant bit of c
	int k = (c >> 31) & (0x1);

	return a - k * c;
}

void Moderate::getMasterMindResult(vector<char> solution, vector<char> guess)
{
	int hits = 0;
	int pseuHits = 0;
	vector<bool> positionGuess, positionSolution;
	positionGuess.assign(4, false);
	positionSolution.assign(4, false);

	for(int i = 0; i < 4; i++)
	{
		if(guess[i] == solution[i])
		{
			hits++;
			positionGuess[i] = true;
			positionSolution[i] = true;
		}
	}

	for(int i = 0; i < 4; i++)
	{
		if(!positionGuess[i])
		{
			for(int j = 0; j < 4; j++)
			{
				if((!positionSolution[j]) && (!positionGuess[i]))
				{
					if(guess[i] == solution[j])
					{
						pseuHits++;
						positionSolution[j] = true;
						positionGuess[i] = true;
					}
				}
			}
		}
	}

	cout<<hits<<" hit and "<<pseuHits<<" pseudo hits!"<<endl;
}

string Moderate::translateNumber(int number)
{
	string result = "";
	string hundreds[] = {"", "Hundred", "Thousand"};

	//Calculte the number of digits
	int len = 0;
	while(pow(10, len) < number)
		len++;

	if(len > 3)
	{
		result += tranlateBase(number / 1000);
		result = result + "Thousand ";
		result = result + tranlateBase(number % 1000);
	}
	else
		result += tranlateBase(number);

	return result;
}

string Moderate::tranlateBase(int number)
{
	string result = "";
	
	string ones[] = {"", "One","Two", "Three","Four", "Five","Six", "Seven","Eight", "Nine"};
	string teens[] = {"", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
	string tens[] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
	string hundreds[] = {"", "Hundred", "Thousand"};

	int len = 0;
	while(pow(10, len) < number)
		len++;
	
	int temp = number / 100;
	if(temp != 0)
	{
		result = result + ones[temp] + " ";
		result = result + hundreds[len - 2] + "  and ";
	}

	temp = number % 100;
	if(temp / 10 == 1 && temp % 10 != 0)
	{
		result = result + teens[temp % 10] + " ";
	}
	else
	{
		result = result + tens[temp / 10] + " ";
		result = result + ones[temp % 10] + " ";
	}

	return result;
}

void Moderate::getMaxContinuousSeq(vector<int> input)
{
	vector<int> result;
	vector<int> temp;
	int sum = 0;
	int maxsum = 0;
	int flag = 0;

	//Compute the sum
	for(int i = 0; i < input.size(); i++)
	{
		sum = sum + input[i];
		temp.push_back(i);
		if(maxsum < sum)
		{
			maxsum = sum;
			flag = i;
		}
		else if(sum < 0)
		{
			sum = 0;
			temp.pop_back();
		}
	}

	//Get the subseq with the max sum
	int beginIndex = flag;
	int endIndex = temp.size() - 1;
	for(int i = 0; i < temp.size(); i++)
	{
		if(temp[i] == flag)
		{
			endIndex = i;
			break;
		}
	}
	for(int i = endIndex; i > 0; i--)
	{
		if(temp[i] - temp[i-1] != 1)
		{
			beginIndex = i;
			break;
		}
	}
	result.assign(temp.begin() + beginIndex, temp.begin() + endIndex + 1);
	for(int i = 0; i < result.size(); i++)
	{
		cout<<input[result[i]]<<" ";
	}
	cout<<endl;

	cout<<maxsum<<endl;
}