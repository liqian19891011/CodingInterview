#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>

#include "Sorting.h"

using namespace std;

bool cmp(string s1, string s2)
{
	sort(&s1[0], &s1[0]+s1.length());
	sort(&s2[0], &s2[0]+s2.length());

	return (s1 < s2);
}

bool pairCmp(pair<int, int> pairA, pair<int, int> pairB)
{
	return pairA.first < pairB.first;
}

vector<int> Sorting::Merge(vector<int> a, vector<int> b, int sizeA, int sizeB)
{
	int count = 0;
	int index = 0;

	while(count < sizeB)
	{
		while(a[index] < b[count])
		{
			index ++;
		}

		for(int i = sizeA; i > index; i--)
		{
			a[i] = a[i - 1];
		}

		a[index] = b[count];

		++count;
		++sizeA;
	}

	return a;
}

vector<int> Sorting::MergeBack(vector<int> a, vector<int> b, int sizeA, int sizeB)
{
	int index = sizeA + sizeB - 1;
	int i = sizeA - 1;
	int j = sizeB - 1;

	while(i >= 0  && j >= 0)
	{
		if(a[i] > b[j])
		{
			a[index] = a[i];
			i--;
			index--;
		}
		else
		{
			a[index] = b[j];
			j--;
			index--;
		}
	}

	while(j >= 0)
	{
		a[index] = b[j];
		index--;
		j--;
	}

	return a;
}

void Sorting::SortAnagrams(vector<string> strList)
{
	std::sort(strList.begin(), strList.end(), cmp);
	for(int i = 0; i < strList.size(); i++)
	{
		cout<<strList[i]<<"   ";
	}

	cout<<endl;
}

int Sorting::SearchStringEmpty(vector<string> strList, string value)
{
	int index = BinarySearch(strList, value, 0, strList.size() - 1);
	return index;
}

int Sorting::BinarySearch(vector<string> strList, string target, int low, int high)
{
	if(low < high)
	{
		int mid = (low + high)/2;
		while(strList[mid] == "" && mid < high)
		{
				mid = mid + 1;
		}
		if(strList[mid] == target)
			return mid;
		else if(strList[mid] > target)
			return BinarySearch(strList, target, low, mid - 1);
		else
			return BinarySearch(strList, target, mid + 1, high);
	}
	else if(low == high)
	{
		if(strList[low] == target)
			return low;
		else 
			return -1;
	}
	else
		return -1;
}

int Sorting::RotatedSearch(vector<int> list, int value)
{
	return RotatedBinarySearch(list, value, 0, list.size() - 1);
}

int Sorting::RotatedBinarySearch(vector<int> list, int target, int low, int high)
{
	while(low <= high){
        int mid = (low+high)/2;
        if(list[mid] == target) 
			return mid;
        if(list[mid] < target){
            if(list[mid] < list[low])
			{
                if(list[low] <= target) 
					high = mid - 1;
                else 
					low = mid + 1;
            }
            else
			{
                low = mid + 1;
            }
        }
        else{

            if(list[mid] < list[low])
			{
                high = mid - 1;
            }
            else{
                if(list[low] <= target) 
					high = mid - 1;
                else 
					low = mid + 1;
            }
        }
	}
	return -1;
}

int * Sorting::MatrixSearch(int **matrix, int M, int N, int value)
{
	int row = 0;
	int col = N - 1;
	int result[] = {-1, -1};

	while(row < M && col >= 0)
	{
		if(matrix[row][col] == value)
		{
			result[0] = row;
			result[1] = col;
			return result;
		}
		else if(value > matrix[row][col])
		{
			row = row + 1;
		}
		else
		{
			col = col -1;
		}
	}

	return result;
}

void Sorting::CircusTower(vector<pair<int, int> > input)
{
	sort(input.begin(), input.end(), pairCmp);

	//计算最长递增子序列
	vector<int> seq;
	seq.assign(input.size(), 1);
	for(int i = 1; i < input.size(); i++)
	{
		int temp = false;
		for(int j = 0; j < i; j++)
		{
			if(input[j].second < input[i].second )
			{
				if(seq[i] <= seq[j])
					seq[i] = seq[j] + 1;
			}
		}
	}

	int count = 1;
	for(int i = 0; i < seq.size(); i++)
	{
		if(seq[i] > count)
		{
			count = seq[i];
		}
	}
	cout<<count<<endl;
}