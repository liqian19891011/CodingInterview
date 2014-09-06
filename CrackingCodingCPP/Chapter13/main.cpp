#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void printLines(string filePath, int k)
{
	vector<string> fileLines;

	ifstream inFile(filePath);
	if(inFile.good())
	{
		while(!inFile.eof())
		{
			string temp;
			getline(inFile, temp);
			fileLines.push_back(temp);
		}
	}

	int size = fileLines.size();
	for(int i = size - k; i < size; i++)
	{
		cout<<fileLines[i]<<endl;
	}
}

void printLinesV2(string filePath, int k)
{
	string * fileLines = new string[k];
	int lines = 0;

	ifstream inFile(filePath);
	if(inFile.good())
	{
		while(!inFile.eof())
		{
			getline(inFile, fileLines[lines % k]);
			lines ++;
		}
	}

	int flag = lines % k;
	int start = flag;
	if(flag == k )
		start = 0;
	for(int i = start; i < k; i++)
	{
		cout<<fileLines[i]<<endl;
	}
	for(int j = 0; j < start; j++)
	{
		cout<<fileLines[j]<<endl;
	}
}

int main()
{
	printLines("file.txt", 4);
	//printLinesV2("file.txt", 2);

	int test;
	cin>>test;

	return 0;
}

