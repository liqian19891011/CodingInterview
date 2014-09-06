#ifndef PRACTICE_H
#define PRACTICE_H

#include <string>
#include <map>		//Used by StringUnique(string input);
#include <vector>
#include <utility>
using namespace std;

class Practice
{
public:
	bool StringUnique(string input);
	bool StringUnique2(string input);

	void ReverseCString(char * input);

	void RemoveDuplication(string original);

	bool DetectAnagram(string input);
	bool DetectAnagramTwoStr(string s, string t);

	void ReplaceSpaces(string input);
	void ReplaceSpacesBack(char input[], int len);

	void RotateMatrix(int n, int** matrix);

	void SetZeroOnMatrix(int m, int n, int** matrix);

	friend class TestClass;

private:
	//Assistant method for SetZeroOnMatrix
	int** InitializeMatrix(int m, int n, vector<int> list);
	vector<pair<int, int> > GetZeroIndex(int m, int n, int** matrix);
	void SetZero(int m, int n, int col, int row, int** matrix);
};

#endif /*PRACTICE_H*/