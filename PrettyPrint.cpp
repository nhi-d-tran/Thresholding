
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc,char** argv)
{
	ifstream inFile;
	ofstream outFile;

	if (!inFile)
	{
		cout << "ERROR to open file";
		exit(1);
	}

	inFile.open(argv[1]);
	outFile.open(argv[2]);

	int numRows;
	int numCols;
	int minVal;
	int maxVal;

	inFile >> numRows >> numCols >> minVal >> maxVal;


	int value;
	outFile << numRows << " " << numCols << " " << minVal << " " << maxVal << " " << endl;
	while(!inFile.eof())
	{
		for(int m = 0; m < numRows; m++)
		{
			for(int n = 0; n < numCols; n++)
			{
				inFile >> value;

				if(value > 0)
				{
					outFile << value << " ";
				}
				else
				{
					outFile  << "  ";
				}
			}
			outFile << endl;
		}
	}

	inFile.close();
	outFile.close();

	return 0;
}
