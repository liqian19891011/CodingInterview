#include <iostream>
#include <string>
#include <vector>
#include <utility>

#include "TestClass.h"
#include "Sorting.h"

using namespace std;

void TestClass::TestMerge()
{
	vector<int> a;
	vector<int> b;
	Sorting s;

	a.push_back(1);
	a.push_back(2);
	a.push_back(5);
	a.push_back(8);
	a.push_back(9);
	a.push_back(15);

	b.push_back(3);
	b.push_back(4);
	b.push_back(7);
	b.push_back(10);
	b.push_back(12);

	int sizeA = a.size();
	int sizeB = b.size();

	for(int i = 0; i < b.size(); ++i)
	{
		a.push_back(0);
	}

	vector<int> result = s.Merge(a, b, sizeA, sizeB);
	cout<<"Merge Result: "<<endl;
	for(int i = 0; i < result.size(); ++i)
	{
		cout<<result[i]<<" ";
	}
	cout<<endl;
}

void TestClass::TestMergeBack()
{
	vector<int> a;
	vector<int> b;
	Sorting s;

	a.push_back(1);
	a.push_back(2);
	a.push_back(5);
	a.push_back(8);
	a.push_back(9);
	a.push_back(15);

	b.push_back(0);
	b.push_back(3);
	b.push_back(4);
	b.push_back(7);
	b.push_back(10);
	b.push_back(12);

	int sizeA = a.size();
	int sizeB = b.size();

	for(int i = 0; i < b.size(); ++i)
	{
		a.push_back(0);
	}

	vector<int> result = s.MergeBack(a, b, sizeA, sizeB);
	cout<<"Merge backwards result: "<<endl;
	for(int i = 0; i < result.size(); ++i)
	{
		cout<<result[i]<<" ";
	}
	cout<<endl;
}

void TestClass::TestFindAnagrams()
{
	vector<string> strList;
	strList.push_back("abc");
	strList.push_back("axyz");
	strList.push_back("zyxa");
	strList.push_back("cba");
	strList.push_back("gf");
	strList.push_back("fg");
	strList.push_back("abcd");
	strList.push_back("bc");
	
	Sorting s;
	s.SortAnagrams(strList);
}

void TestClass::TestSearchStringEmpty()
{
	vector<string> strList;
	strList.push_back("a");
	strList.push_back("");
	strList.push_back("");
	strList.push_back("");
	strList.push_back("b");
	strList.push_back("c");
	strList.push_back("");
	strList.push_back("");
	strList.push_back("d");
	strList.push_back("e");
	strList.push_back("f");
	strList.push_back("g");
	strList.push_back("");
	strList.push_back("");
	strList.push_back("");

	Sorting s;
	string str;
	cout<<"Please enter the string you want to search: "<<endl;
    cin>>str;
	int index = s.SearchStringEmpty(strList, str);
	cout<<"The index of "<<str<<" is: "<<index<<endl;
}

void TestClass::TestRotatedSearch()
{
	int intList[] = {19,20,25,1,3,4,5,7,10,14,15,16};
	vector<int> list(intList, intList + 12);

	Sorting s;
	int target;
	cout<<"Please enter the string you want to search: "<<endl;
    cin>>target;
	int index = s.RotatedSearch(list, target);
	cout<<"The index of "<<target<<" is: "<<index<<endl;

}

void TestClass::TestMatrixSearch()
{
	int M = 3;
	int N = 4;
	int** matrix = new int*[M];

	for(int i = 0; i < M; i++)
		matrix[i] = new int[N];
	int a[] = {1,2,6,7};
	int b[] = {5,8,9,12};
	int c[] = {10,11,16,17};

	matrix[0] = a;
	matrix[1] = b;
	matrix[2] = c;

	Sorting s;
	int target;
	cout<<"Please enter the string you want to search: "<<endl;
    cin>>target;
	int * result = s.MatrixSearch(matrix, M, N, target);

	if(result[0] == -1)
		cout<<"Cannot find the element in the matrix"<<endl;
	else
		cout<<"Row: "<<result[0]<<" Col: "<<result[1]<<endl;
}

void TestClass::TestCircusTower()
{
	vector<pair<int, int>> input;
	input.push_back(make_pair(65, 100));
	input.push_back(make_pair(70, 150));
	input.push_back(make_pair(56, 90));
	input.push_back(make_pair(75, 190));
	input.push_back(make_pair(60, 95));
	input.push_back(make_pair(50, 110));
	input.push_back(make_pair(68, 110));

	Sorting s;
	s.CircusTower(input);
}