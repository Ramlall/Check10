// Check10Numbers_IBMAug.cpp : Defines the entry point for the console application.
//

// Program that, given 10 numbers, checks if any 1, 2, or 3 numbers adds up to any combination of the rest.

// TO-DO: Change int set[] to vector
// In the Checkset add a 0 for 2 numbers
// In Checkset add another 0 to check the 3 numbers (so that no 3 numbers adds up to 1 other number)

#include <iostream>
using namespace std;

// Given an array of 10 numbers, check if any 3 of the 10 add up to any of the others.
bool CheckSet(int set[10])
	{
    // 1 number: Check that no two numbers are the same.
	for (int i = 0; i < 9; i++)
		{
		for (int j = i + 1; j < 10; j++)
			{
			if(set[i] == set[j])
				{
				cout << "Set failed because " << set[i] << " at spot " << i << " is the same number as spot" << j << endl;
				return false;
				}
			}
		}

	// 2 numbers: No 2 numbers add up to the addition of any other two numbers.
        // Scroll through 2 numbers at a time
        for(int i = 0; i < 10-1-1; i++)
        {
            for(int j = i+1; j < 10-1; j++)
            {
                
                    // Now scroll through 2 numbers at a time in the same way.
                    for(int x = 0; x < 10-1-1; x++)
                    {
                        for(int y = x+1; y < 10-1; y++)
                        {
                            
                                // If the numbers are the same, there's no need to check.
                                if(i == x && j == y) { continue; }
                                
                                // If the three numbers add up to each other then it's bad.
                                if(set[i] + set[j] == set[x] + set[y])
                                {
                                    cout << "Failed because " << set[i] << " and " << set[j]  << " adds up too " << set[i] + set[j]<< ". That's the same as "  << set[x] << " + "  << set[y] << endl;
                                    return false;
                                }
                                
                            
                        
                    }
                    
                }
            }
        }

	// 3 numbers:
        
        // Scroll through 3 numbers at a time
        for(int i = 0; i < 10-1-1; i++)
        {
            for(int j = i+1; j < 10-1; j++)
            {
                for(int k = j+1; k < 10; k++)
                {
                    // Now scroll through 3 numbers at a time in the same way.
                    for(int x = 0; x < 10-1-1; x++)
                    {
                        for(int y = x+1; y < 10-1; y++)
                        {
                            for(int z = y+1; z < 10; z++)
                            {
                                // If the numbers are the same, there's no need to check.
                                if(i == x && j == y && k == z) { continue; }
                                
                                // If the three numbers add up to each other then it's bad.
                                if(set[i] + set[j] + set[k] == set[x] + set[y] + set[z])
                                {
                                    cout << "Failed because " << set[i] << " and " << set[j] << " and " << set[k] << " adds up too " << set[i] + set[j] + set[k] << ". That's the same as "  << set[x] << " + "  << set[y] << " + " << set[z] << endl;
                                    return false;
                                }
                                
                            }
                        }
                    }
                    
                }
            }
        }
        
    // It must have passed all the cases so return true, that the set works.
	return true;
	}

int main()
	{
	// Get 10 numbers from user input
	cout << "Enter your 10 numbers loser: " << endl;
	int set[11] = { 0 };

	for (int i = 0; i < 10; i++)
		{ cin >> set[i]; }
       
        
    // Check if this set is good.
	bool isgood = CheckSet(set);

    // If it's good output that it's good.
    if(isgood == true) { cout << "This set is good."; }
        
	cout << "Program ended." << endl;

	char zzz;
	cin >> zzz;
    return 0;
	}
