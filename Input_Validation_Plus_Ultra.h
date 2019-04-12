//From: http://stackoverflow.com/questions/514420/how-to-validate-numeric-input-c 
// Modified Further by Fahim Sunka
// This version allows usage of just one function - validate() with all data types
#include <ios>  // Provides ios_base::failure
#include <iostream>  // Provides cin
#include<string> //for string manipulation
#include<sstream> //for string manipulation and comparison
#include<typeinfo> // for the T data type comparisons
#include<cfloat> // for maximum double value
using namespace std; 


template <typename T>
T validate(T &input, bool requirePositive = 0, double min = 0, double max = DBL_MAX)
{
	int counter = 0; // display messages only after first pass
    while (true)
    {
    	if(counter > 0)
    	{
	     	if (typeid(T) == typeid(int) || typeid(T) == typeid(short))
	    	{
	    		cout << "Enter a whole number only: ";
			}
	    	else if (typeid(T) == typeid(double) || typeid(T) == typeid(float))
	    	{
	    		cout << "Enter a number only: ";
			}
	     	else if (typeid(T) == typeid(char))
	    	{
	        	cout << "Enter a single letter or 1-digit number: ";
			}
	     	else if (typeid(T) == typeid(string))
	    	{
	    		cout << "Enter a single word only: ";
			}
	      	else if (typeid(T) == typeid(bool))
	    	{
	    		cout << "Enter 0 (False) or 1 (True): ";
			}
		}
        try
        {
			do
			{
			    // Get input of type T
					cin >> input;

			    // Check if the failbit has been set, meaning the beginning of the input
			    // was not type T. Also make sure the result is the only thing in the input
			    // stream, otherwise things like 2b would be a valid int.
			    if (cin.fail() || cin.get() != '\n')
			    {
			        // Set the error state flag back to goodbit. If you need to get the input
			        // again (e.g. this is in a while loop), this is essential. Otherwise, the
			        // failbit will stay set.
			        cin.clear();

			        // Clear the input stream using and empty while loop.
			        while (cin.get() != '\n')
			            ;

			        // Throw an exception. Allows the caller to handle it any way you see fit
			        // (exit, ask for input again, etc.)
			        throw ios_base::failure("Invalid input.");
			    }
			    if(requirePositive && min == 0 && input < min)   			// when we require a positive value
			    {
			    	cout << "No negative values. Try again: ";
				}
				else if(requirePositive && input < min && max == DBL_MAX)   // when we require any other minimum value (with no max set)
				{
					cout << "Enter a value greater or equal to " << (T)min << ": ";
				}
			    else if(requirePositive && (input < min || input > max))     // when we require the value to be in a range
			    {
			    	cout << "Out of range. Enter a value between "
						 << (T)min << " and " << (T)max << ": ";
				}
				else
				{   														// breaks out of the loop when all conditions are met
					requirePositive = false;
				}
			}while(requirePositive);
		}
        catch (exception e)
        {
            cerr << e.what() << ": Invalid input."<< endl;
            counter++;
            continue;
        }
        break;
    }
    
    return input;
}

string validate(string &input, bool oneWord = false)
{
	int counter = 0;
    while (true)
    {
	    if(counter > 0 && oneWord)
    	{
        	cout << "Enter a word (no spaces): ";
		}

        try
        {
			    if(oneWord)
			    {
			    	//cout << "\noneword running\n";
			    	cin >> input;
				}
				else
				{
					//cout << "\ngetline running\n";
					getline(cin, input);
					break;                  // necessary
				}

			    // Check if the failbit has been set, meaning the beginning of the input
			    // was not type T. Also make sure the result is the only thing in the input
			    // stream, otherwise things like 2b would be a valid int.
			    if (cin.fail() || cin.get() != '\n')
			    {
			        // Set the error state flag back to goodbit. If you need to get the input
			        // again (e.g. this is in a while loop), this is essential. Otherwise, the
			        // failbit will stay set.
			        cin.clear();

			        // Clear the input stream using and empty while loop.
			        while (cin.get() != '\n')
			            ;

			        // Throw an exception. Allows the caller to handle it any way you see fit
			        // (exit, ask for input again, etc.)
			        throw ios_base::failure("Invalid input.");
			    }
		}
        catch (exception e)
        {
            cerr << e.what() << ": Invalid input."<< endl;
            counter++;
            continue;
        }
        break;
    }
    return input;
}
