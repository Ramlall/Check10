// Check10Numbers_IBMAug.cpp : Defines the entry point for the console application.
//

// Program that, given 10 numbers, checks if any 1, 2, or 3 numbers adds up to any combination of the rest.

// TO-DO: Change int set[] to vector
// In the Checkset add a 0 for 2 numbers
// In Checkset add another 0 to check the 3 numbers (so that no 3 numbers adds up to 1 other number)

#include <iostream>
#include <vector>
using namespace std;

// Given an array of 10 numbers, check if any 3 of the 10 add up to any of the others.
bool CheckSet(vector<int> set)
	{
    // 1 number: Check that no two numbers are the same.
	for (int i = 0; i < 9; i++)
		{
		for (int j = i + 1; j < 10; j++)
			{
			if(set[i] == set[j])
				{
//				cout << "Set failed because " << set[i] << " at spot " << i << " is the same number as spot" << j << endl;
				return false;
				}
			}
		}

	// 2 numbers: No 2 numbers add up to the addition of any other two numbers.
	// Add a 0 to the vector set so we check if 2 numbers adds up to any 1
	set.push_back(0);
        // Scroll through 2 numbers at a time
        for(int i = 0; i < 11-1; i++)
        {
            for(int j = i+1; j < 11; j++)
            {
                
                    // Now scroll through 2 numbers at a time in the same way.
                    for(int x = 0; x < 11-1; x++)
                    {
                        for(int y = x+1; y < 11; y++)
                        {
                            
                                // If the numbers are the same index, there's no need to check.
                                if(i == x && j == y) { continue; }
                                
                                // If the two numbers add up to each other then it's bad.
                                if(set[i] + set[j] == set[x] + set[y])
                                {
  //                                  cout << "Failed because " << set[i] << " and " << set[j]  << " adds up too " << set[i] + set[j]<< ". That's the same as "  << set[x] << " + "  << set[y] << endl;
                                    return false;
                                }
                                
                            
                        
                    }
                    
                }
            }
        }

	// 3 numbers:
       	// Add a 0 to the vector set so we check if 3 numbers adds up to any 1
	set.push_back(0);
        // Scroll through 3 numbers at a time
        for(int i = 0; i < 12-1-1; i++)
        {
            for(int j = i+1; j < 12-1; j++)
            {
                for(int k = j+1; k < 12; k++)
                {
                    // Now scroll through 3 numbers at a time in the same way.
                    for(int x = 0; x < 12-1-1; x++)
                    {
                        for(int y = x+1; y < 12-1; y++)
                        {
                            for(int z = y+1; z < 12; z++)
                            {
                                // If the numbers are the same, there's no need to check.
                                if(i == x && j == y && k == z) { continue; }
                                
                                // If the three numbers add up to each other then it's bad.
                                if(set[i] + set[j] + set[k] == set[x] + set[y] + set[z])
                                {
    //                                cout << "Failed because " << set[i] << " and " << set[j] << " and " << set[k] << " adds up too " << set[i] + set[j] + set[k] << ". That's the same as "  << set[x] << " + "  << set[y] << " + " << set[z] << endl;
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
//	cout << "Enter your 10 numbers loser: " << endl;
	vector<int> set;
//	int set[11] = { 0 };
//	int temp;
//	for (int i = 0; i < 10; i++)
//		{ cin >> set[i]; }
  	//	{ cin >> temp; set.push_back(temp);}     

/*
1 3 5 12 21 37 65 68 71 174 FAILED
2 4 6 13 22 38 66 69 72 174 FAILED
1 3 5 20 35 61 67 68 73 174 FAILED
4 5 6 29 38 54 67 70 73 174 FAILED

1 5 6 19 34 37 62 68 74 174 FAILED
5 6 7 30 39 55 68 71 74 174 FAILED
1 2 6 34 53 62 68 71 74 174 FAILED

1 4 7 13 22 40 63 73 74 174
*/

set.push_back(1);
set.push_back(4);
set.push_back(7);
set.push_back(13);
set.push_back(22);
set.push_back(40);
set.push_back(63);
set.push_back(73);
set.push_back(74);
set.push_back(174);  

for(int i = 1; i <= 174; i++)      
{
set[9] = i;
    // Check if this set is good.
	bool isgood = CheckSet(set);

    // If it's good output that it's good.
    if(isgood == true) { cout << "This set is good using " << i << endl; }
 }

       
	cout << "Program ended." << endl;

	//char zzz;
	//cin >> zzz;
    return 0;
	}
