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
}

void alternatingDiskSort(int n)
{
    for (int i = 0; i < n; i++)
    {
        //Left to Right
        for (int j = i; j < n-1; j++) // goes to n-1 because don't want to swap with empty
            {
                if(i > 0 && unsortedArray[j] == unsortedArray[0]) //if the current elem is the same as the initial, skip it as long as this isn't the first run
                    j++;
                if (unsortedArray[j] != unsortedArray[j + 1])
                {
                    swap(unsortedArray[j], unsortedArray[j + 1]);
                    stepNum++;
                }
            }
            //Right to Left
            for (int j = n-i-2; j > i+1; j--) //starts at n-i-2 because far right is already right and stops before gets to 1st place
            {
                if(unsortedArray[j] == unsortedArray[n-1])
                    j--;
                if (unsortedArray[j] != unsortedArray[j - 1] )
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
    cout << "Enter the number of light and dark disks (up to 50): ";
    cin >> n;
    while (n > 50 || n < 0)
    {
        cout << "Please keep the number between 0 and 50: ";
        cin >> n;
    }

    n *=2;

    // Indexing disk colors into unsortedArray
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0) //even index
        {
            unsortedArray[i] = 'l';
        }
        else //odd index
        {
            unsortedArray[i] = 'd';
        }

    }

    // Print disk starting order
    cout << "\nDisk starting order: " << endl;
    printDisks(n);

    // Call alternatingDiskSort function
    alternatingDiskSort(n);

    // Print disk ending order
    cout << "\nDisk ending order: " << endl;
    printDisks(n);

    // Print number of steps and runs 
    cout << "\nThis took " << stepNum << " step(s) and " << runNum << " run(s)." << endl;

    return 0;
}
