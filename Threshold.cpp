
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char **argv)
{
	ifstream inFile;
	ofstream outFile;

	if (!inFile)
	{
		cout << "ERROR to open file";
		exit(1);
	}

	inFile.open(argv[1]);

	int numRows;
	int numCols;
	int minVal;
	int maxVal;


	inFile >> numRows >> numCols >> minVal >> maxVal;

	int thrValue;
	cout << "Enter a threshold value: " << endl;
	cin >> thrValue;

	string StringthrValue=to_string(thrValue);
	string Argvalue(argv[2]);
	string shortenstring = Argvalue.substr(0, Argvalue.length() - 4);
	string outFileName = shortenstring + "_thr_" + StringthrValue;

	outFile.open(outFileName);
	outFile << numRows << "  " << numCols << "  " << 0  << "  "<< 1 << endl;

	int** picture;

	picture = new int*[numRows];
	for(int l = 0; l < numCols; l++)
	{
		picture[l] = new int[numCols];
	}

	for(int m = 0; m < numRows; m++)
	{
		for(int n = 0; n < numCols; n++)
		{
			picture[m][n] = 0;
		}
	}

	int value;

	while(!inFile.eof())
	{
		for(int m = 0; m < numRows; m++)
		{
			for(int n = 0; n < numCols; n++)
			{
				inFile >> value;

				if(value >= thrValue)
				{
					outFile << 1 << "  ";
				}
				else
				{
					outFile  << 0 << "  ";
				}
			}
			outFile << endl;
		}
	}

		inFile.close();
		outFile.close();
	return 0;
}
