#include <iostream>
#include "Practice.h"

using namespace std;

/*First solution for problem 1.1, referring to the anwswer*/
bool Practice::StringUnique(string input)
{
	bool value[256] = {false};		//Assuming that all character are under ASCII standard
	bool result = true;

	for(int i = 0; i < input.length(); ++i)
	{
		if(!value[input.at(i)])
		{
			value[input.at(i)] = true;
		}
		else
			result = false;
	}

	return result;
}
/*Second solution for problem 1.1, using STL map*/
bool Practice::StringUnique2(string input)
{
	bool result = true;
	map<char, int> strMap;

	for(int i = 0; i < input.length(); ++i)
	{
		if(strMap.find(input[i]) == strMap.end())
			strMap[input[i]] = input[i];
		else
			result = false;
	}

	return result;
}

void Practice::ReverseCString(char * input)
{
	char * end = input;
	char temp;

	if(input)
	{
		while(*end)
		{
			++end;
		}

		--end;

		while(input < end)
		{
			temp = *end;
			*end = *input;
			*input = temp;

			--end;
			++input;
		}
	}
}

void Practice::RemoveDuplication(string original)
{
	int len = original.length();

	if(len < 2)
		return;

	int tail = 1;
	bool findDuplicate = false;

	int i = 1;
	while(i < original.length())
	{
		findDuplicate = false;
		for(int j = 0; j < tail; ++j)
		{
			if(original[j] == original[i])
			{
				original.erase(tail, 1);
				findDuplicate = true;
				break;
			}
		}
		
		if(!findDuplicate)
		{
			++tail;
			++i;
		}
	}

	cout<<original<<endl;
}

bool Practice::DetectAnagram(string input)
{
	int len = input.length();
	bool result = true;
	if(len > 1)
	{
		int begin = 0;
		int end = len - 1;
		while(begin <= end)
		{
			if(input[begin] != input[end])
			{
				result = false;
				break;
			}
			else
			{
				++begin;
				--end;
			}
		}
		return result;
	}
	else
		return result;
}

bool Practice::DetectAnagramTwoStr(string s, string t)
{
	int lenS = s.length();
	int lenT = t.length();
	int result = true;

	if( lenS != lenT)
	{
		result = false;
	}
	else
	{
		int beginS = 0;
		int endT = lenS - 1;

		while(beginS < lenS && endT >= 0)
		{
			if(s[beginS] != t[endT])
			{
				result = false;
				break;
			}
			else
			{
				++beginS;
				--endT;
			}
		}
	}
	return result;
}

void Practice::ReplaceSpaces(string input)
{
	for(int i = 0; i < input.length(); ++i)
	{
		if(input[i] == ' ')
		{
			input.erase(i, 1);
			input.insert(i, "%20");
		}
	}
	cout<<input<<endl;
}

void Practice::ReplaceSpacesBack(char input[], int len)
{
	int spaceCount = 0;

	for (int i = 0; i < len; i++)
	{
		if (input[i] == ' ')
			spaceCount++;
	}

	int newLen = spaceCount * 2 + len;
	int endIndex = newLen - 1;
	input[newLen] = '\0';

	for (int i = len - 1; i > 0; i--)
	{
		if (input[i] != ' ')
		{
			input[endIndex] = input[i];
			endIndex--;
		}
		else
		{
			input[endIndex] = '%';
			input[endIndex - 1] = '0';
			input[endIndex - 2] = '2';
			endIndex -= 3;
		}
	}

	for (int i = 0; i < newLen; i++)
	{
		cout << input[i];
	}
	cout << endl;
}
void Practice::SetZeroOnMatrix(int m, int n, int** matrix)
{
	vector<pair<int, int> > index = GetZeroIndex(m, n, matrix);

	for(int count = 0; count < index.size(); ++count)
	{
		int column = index[count].first;
		int row = index[count].second;
		SetZero(m, n, column, row, matrix);
	}
	
	//Output the result
	for(int i = 0; i < m ;++i)
	{
		for(int j = 0; j < n; ++j)
			cout<<matrix[i][j]<<" ";
		cout<<endl;
	}

	cout<<endl;
}

void Practice::RotateMatrix(int n, int** matrix)
{
	for(int layerCount = 0; layerCount < n/2; ++layerCount)
	{
		int first = layerCount;
		int last = n - 1 - layerCount;
		for(int i = first; i < last; ++i)
		{
			int temp = matrix[first][i];
			int offset = i - first;
			//left -> top
			matrix[first][i] = matrix[last-offset][first];

			//bottom -> left
			matrix[last-offset][first] = matrix[last][last-offset];

			//right -> bottem
			matrix[last][last-offset] = matrix[i][last];

			//top -> right
			matrix[i][last] = temp;
		}
	}

	//Output the result
	for(int i = 0; i < n ;++i)
	{
		for(int j = 0; j < n; ++j)
			cout<<matrix[i][j]<<" ";
		cout<<endl;
	}

	cout<<endl;
}

int** Practice::InitializeMatrix(int m, int n, vector<int> list)
{
	int **matrix = new int*[m];
	
	if( (m*n) != list.size() )
		return nullptr;
	else
	{
		int count = 0;
		for(int i = 0; i < m; ++i)
		{
			matrix[i] = new int[n];
			for(int j = 0; j < n; ++j)
			{
				matrix[i][j] = list[count];
				++count;
			}
		}

		return matrix;
	}
}

vector<pair<int, int> > Practice::GetZeroIndex(int m, int n, int** matrix)
{
	int column = -1;
	int row = -1;

	vector<pair<int, int> > index;

	for(int i = 0; i < m; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if(matrix[i][j] == 0)
			{
				column = i;
				row = j;
				index.push_back(make_pair(column, row));
			}
		}
	}
	return index;
}

void Practice::SetZero(int m, int n, int column, int row, int** matrix)
{
	if( column != -1 && row != -1)
	{
		for(int i = 0; i < m; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				if( i == column || j == row )
					matrix[i][j] = 0;
			}
		}
	}
}
