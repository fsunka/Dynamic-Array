/*******************************************************************************
*	Fahim Sunka 	4-12-2019
*	Spring 2019		COSC 1437-58000		   DevC++ 5.11
*	Dynamic Array Attempt
* Summary:
*           Appeared to be successful
*           Dynamic array starts at size 1, doubles whenever limit is reached
*           Double size increase was arbitrary/is basic for understanding
*           Minor formatting - Grades 90+ Green, <60 Red, Else White
*           5 grades per row print out along with average and total # of grades
*******************************************************************************/

#include <iostream>
#include <iomanip>
#include "Color_In_CPP.h"
#include "Input_Validation_Plus_Ultra.h"

using namespace std;



int main()
{
	changeColor(G);
	cout << "\nDynamic Array Program\n";
	changeColor();
	int gradeSize = 1; // start with array size 1 but can grow!
	double* gradesArray = new double[gradeSize];    // allocate a double array of size 1
	int index = 0;                                  // current index of my dynamic gradesArray
	double total = 0.0, average = 0.0;              // grades total/average
	while(1)
	{   // Runs until user enters -1 ("sentinel") as a grade

		double grade;   // hold the current grade (user input)

		/* If we reach the end of our dynamic array
		 	Then this code runs and makes a new one that is twice as big
		 	Copies values over from our previous array and deletes that one */
		if (index >= gradeSize)
		{
	        gradeSize *= 2;            			// double previous size
	        double* temp = new double[gradeSize]; // create new bigger array.
	        for (int i = 0; i < index; i++)
			{
	            temp[i] = gradesArray[i];       // copy values to new array.
	        }
	        delete [] gradesArray;              // free old array memory.
	        gradesArray = temp;                 // point to new array and continue as usual
		}
		
		cout << "\nPlease enter grade #" << index+1 << " (or -1 when done): ";
		changeColor(C);
		validate(grade, 1, -1.0, 150.0); // uses my input validation - forces a double between -1 and 150.0
		changeColor();
		if(grade == -1.0)
		{
			break;  // exit condition met
		}
		
		gradesArray[index] = grade; // Add the grade to the array
		total += grade;             // Add to total
		index++;                    // Increment index for next run
		average = total / index;    // Incremented index useful here and below
		
		// Print some data
		cout << "\n#\tValue\t   Max Size\tTotal\tAverage";
		cout << "\n" << index << "\t" << grade << "\t    " << gradeSize
			 << "\t\t" << total << "\t" << average;
		
	}
		// Print all the grades
		cout << "\nGrades Entered: ";
		for(int i = 0; i < index; i++)
		{
			changeColor(W);
			if(i % 5 == 0) cout << "\n"; 				// for formatting - 5 per row
			if(gradesArray[i] >= 90) changeColor(G);    // Green for 90+ grades
			if(gradesArray[i] < 60) changeColor(R);     // Red for grades below 60

			cout << setw(5) << gradesArray[i];          // print out the grade
		}
		changeColor(W);
		cout << "\n\nAverage Grade: " << average << endl;
		cout << "Number of Grades: " << index << endl;
	
	
	
// Regular way - guess an upper limit on the array and waste space/not be able to exceed the arbitrary maximum
// Or ask the user how many grades but then they have to count and wont always know how many entries of something
//	double gradesArray[100];
//	int count;
//	for(int i = 0; i < 100; i++)
//	{
//		double grade;
//		cout << "Please enter grade #" << i+1 << " (or -1 when done): ";
//		cin >> grade;
//		if(grade == -1.0)
//		{
//			break;
//		}
//		gradesArray[i] = grade;
//		count++;
//	}
//	
//	for(int i = 0; i < count; i++)
//	{
//		cout << gradesArray[i] << " ";
//	}
	
	
 	return 0;
}

