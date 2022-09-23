#include <iostream>
using namespace std;

int stepNum = 0;
int runNum = 0;
char unsortedArray[100];

void printDisks(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << unsortedArray[i] << " ";
	}
	cout << endl;
}

void alternatingDiskSort(int n)
{
	for (int i = 0; i < n; i++)
	{
		//Left to Right
		for (int j = 0; j < n; j++)
		{
			if (unsortedArray[j] == 'd' && unsortedArray[j + 1] == 'l')
			{
				swap(unsortedArray[j], unsortedArray[j + 1]);
				stepNum++;
			}
		}
		//Right to Left
		for (int j = n - 1; j > 0; j--)
		{
			if (unsortedArray[j] == 'l' && unsortedArray[j - 1] == 'd')
			{
				swap(unsortedArray[j], unsortedArray[j - 1]);
				stepNum++;
			}
		}
		runNum++;
	}
}

int main()
{
	// Initializing variables
	int n = 0;

	// User inputs n value
	cout << "Enter the number of total disks (up to 100): ";
	cin >> n;
	cout << endl;
	
	// Indexing disk colors into unsortedArray
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0) //even index
		{
			unsortedArray[i] = 'd';
		}
		else //odd index
		{
			unsortedArray[i] = 'l';
		}

	}

	// Print disk starting order
	cout << "Disk starting order: " << endl;
	printDisks(n);

	// Call alternatingDiskSort function
	alternatingDiskSort(n);

	// Print disk ending order
	cout << "Disk ending order: " << endl;
	printDisks(n);

	// Print number of steps and runs 
	cout << "This took " << stepNum << " step(s) and " << runNum << " run(s)." << endl;

	return 0;
}
