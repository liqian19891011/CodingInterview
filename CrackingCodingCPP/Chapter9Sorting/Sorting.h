#ifndef SORTING_H
#define SORTING_H

#include <vector>
#include <utility>

using namespace std;

class Sorting
{
public:
	vector<int> Merge(vector<int>, vector<int>, int, int);
	vector<int> MergeBack(vector<int>, vector<int>, int, int);
	void SortAnagrams(vector<string>);
	int RotatedSearch(vector<int>, int);
	int SearchStringEmpty(vector<string>, string);
	int* MatrixSearch(int **matrix, int M, int N, int value);
	void CircusTower(vector<pair<int, int> >);
private:
	int BinarySearch(vector<string> strList, string target, int low, int high);
	int RotatedBinarySearch(vector<int> list, int target, int low, int high);

};
#endif /*SORTING_H*/