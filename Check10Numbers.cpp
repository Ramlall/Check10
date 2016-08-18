// Program that, given 10 numbers, checks if any 1, 2, or 3 numbers adds up to any combination of the rest.



#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Given an array of 10 numbers, check if any 3 of the 10 add up to any of the others.
bool CheckCoinsTaken(vector<int> set)
	{
    // 1 number: Check that no two numbers are the same.
	for (int i = 0; i < 10-1; i++)
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
				// We don't need to check two zeroes.
				if(j == 12-2 && k == 12-1) { continue; }
				if(y == 12-2 && z == 12-1) { continue; }
                                
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
	// Say the program started and open the file we're writing too.
	cout << "Program started." << endl << endl;
	ofstream file;
	file.open ("answers.txt");
	file << "Program started.\n\n" << flush;
	

	/*
	//// JUST TEST A USER'S 10 NUMBERS
	 
	// Get 10 numbers from user input
	cout << "Enter your 10 numbers loser: " << endl;
	vector<int> set;
	int temp;
	for (int i = 0; i < 10; i++)
		{ cin >> temp; set.push_back(temp);}     

	// Check if this set is good.
	bool isgood = CheckCoinsTaken(set);

	// If it's good output that it's good.
	if(isgood == true) { cout << "This set is good." << endl; }
 	*/
	
       

	//// TEST ALL POSSIBLE NUMBERS

	// Create a vector to hold how many coins we're taking from each bag and fill it with 10 dummy numbers.
	vector<int> coinsTakenVector;
	for(int i = 0; i < 10; i++)
		{ coinsTakenVector.push_back(0); }
	
	// Guess how many coins to take from each bag.
	for(int coinsTakenFromBag0 = 174; coinsTakenFromBag0 > 0; coinsTakenFromBag0--) { // Start with 174 since it's an obvious guess
	for(int coinsTakenFromBag1 = 50; coinsTakenFromBag1 <= 173; coinsTakenFromBag1++) { if(coinsTakenFromBag1 == coinsTakenFromBag0) { continue; }
	for(int coinsTakenFromBag2 = 20; coinsTakenFromBag2 <= 173; coinsTakenFromBag2++) { if(coinsTakenFromBag2 == coinsTakenFromBag0 || coinsTakenFromBag2 == coinsTakenFromBag1) { continue; }
	for(int coinsTakenFromBag3 = 15; coinsTakenFromBag3 <= 173; coinsTakenFromBag3++) { if(coinsTakenFromBag3 == coinsTakenFromBag0 || coinsTakenFromBag3 == coinsTakenFromBag1 || coinsTakenFromBag3 == coinsTakenFromBag2) { continue; }
	for(int coinsTakenFromBag4 = 10; coinsTakenFromBag4 <= 173; coinsTakenFromBag4++) { if(coinsTakenFromBag4 == coinsTakenFromBag0 || coinsTakenFromBag4 == coinsTakenFromBag1 || coinsTakenFromBag4 == coinsTakenFromBag2 || coinsTakenFromBag4 == coinsTakenFromBag3) { continue; }
	for(int coinsTakenFromBag5 = 10; coinsTakenFromBag5 <= 173; coinsTakenFromBag5++) { if(coinsTakenFromBag5 == coinsTakenFromBag0 || coinsTakenFromBag5 == coinsTakenFromBag1 || coinsTakenFromBag5 == coinsTakenFromBag2 || coinsTakenFromBag5 == coinsTakenFromBag3 || coinsTakenFromBag5 == coinsTakenFromBag4) { continue; }
	for(int coinsTakenFromBag6 = 4; coinsTakenFromBag6 <= 100; coinsTakenFromBag6++) { if(coinsTakenFromBag6 == coinsTakenFromBag0 || coinsTakenFromBag6 == coinsTakenFromBag1 || coinsTakenFromBag6 == coinsTakenFromBag2 || coinsTakenFromBag6 == coinsTakenFromBag3 || coinsTakenFromBag6 == coinsTakenFromBag4 || coinsTakenFromBag6 == coinsTakenFromBag5) { continue; }
	for(int coinsTakenFromBag7 = 3; coinsTakenFromBag7 <= 100; coinsTakenFromBag7++) { if(coinsTakenFromBag7 == coinsTakenFromBag0 || coinsTakenFromBag7 == coinsTakenFromBag1 || coinsTakenFromBag7 == coinsTakenFromBag2 || coinsTakenFromBag7 == coinsTakenFromBag3 || coinsTakenFromBag7 == coinsTakenFromBag4 || coinsTakenFromBag7 == coinsTakenFromBag5 || coinsTakenFromBag7 == coinsTakenFromBag6) { continue; }
	for(int coinsTakenFromBag8 = 2; coinsTakenFromBag8 <= 50; coinsTakenFromBag8++) { if(coinsTakenFromBag8 == coinsTakenFromBag0 || coinsTakenFromBag8 == coinsTakenFromBag1 || coinsTakenFromBag8 == coinsTakenFromBag2 || coinsTakenFromBag8 == coinsTakenFromBag3 || coinsTakenFromBag8 == coinsTakenFromBag4 || coinsTakenFromBag8 == coinsTakenFromBag5 || coinsTakenFromBag8 == coinsTakenFromBag6 || coinsTakenFromBag8 == coinsTakenFromBag7) { continue; }
	for(int coinsTakenFromBag9 = 1; coinsTakenFromBag9 <= 50; coinsTakenFromBag9++) { if(coinsTakenFromBag9 == coinsTakenFromBag0 || coinsTakenFromBag9 == coinsTakenFromBag1 || coinsTakenFromBag9 == coinsTakenFromBag2 || coinsTakenFromBag9 == coinsTakenFromBag3 || coinsTakenFromBag9 == coinsTakenFromBag4 || coinsTakenFromBag9 == coinsTakenFromBag5 || coinsTakenFromBag9 == coinsTakenFromBag6 || coinsTakenFromBag9 == coinsTakenFromBag7 || coinsTakenFromBag9 == coinsTakenFromBag8) { continue; }
	
	// Edit our vector to what the guess is.
	coinsTakenVector[0] = coinsTakenFromBag0;
	coinsTakenVector[1] = coinsTakenFromBag1;
	coinsTakenVector[2] = coinsTakenFromBag2;
	coinsTakenVector[3] = coinsTakenFromBag3;
	coinsTakenVector[4] = coinsTakenFromBag4;
	coinsTakenVector[5] = coinsTakenFromBag5;
	coinsTakenVector[6] = coinsTakenFromBag6;
	coinsTakenVector[7] = coinsTakenFromBag7;
	coinsTakenVector[8] = coinsTakenFromBag8;
	coinsTakenVector[9] = coinsTakenFromBag9;

	// Call our Check function to check this set of coins taken.		
	bool setWorked = CheckCoinsTaken(coinsTakenVector);

	// If setWorked is True then its a good set, output the set.
	if(setWorked == true)
		{
		// Output the answer to console.
		cout << "Found a working set! The set is: " << endl;
		cout << coinsTakenVector[9] << " " << coinsTakenVector[8] << " " << coinsTakenVector[7] << " " << coinsTakenVector[6] << " " << coinsTakenVector[5] << " " << coinsTakenVector[4] << " " << coinsTakenVector[3] << " " << coinsTakenVector[2] << " " << coinsTakenVector[1] << " " << coinsTakenVector[0] << endl << endl;

		// Output the answer to file.
		file << "Found a working set! The set is: \n" << flush;
		file << coinsTakenVector[9] << " " << coinsTakenVector[8] << " " << coinsTakenVector[7] << " " << coinsTakenVector[6] << " " << coinsTakenVector[5] << " " << coinsTakenVector[4] << " " << coinsTakenVector[3] << " " << coinsTakenVector[2] << " " << coinsTakenVector[1] << " " << coinsTakenVector[0] << "\n\n" << flush;
		}

	}}}}}}}}}}
	


	// Program is over.
	file.close();
	cout << "Program ended." << endl;
	char zzz;
	cin >> zzz;
	return 0;
	}
