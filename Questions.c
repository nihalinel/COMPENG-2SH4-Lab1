
#include "Questions.h"



int Q1_for(int num){
	int sum = 0;
	int i;
	
	// calculate your sum below..this has to use for loop
	for (i=1; i<=1000; i++){
		if (i % num == 0) {
            sum += i;
        }
	}

	// here, we return the calcualted sum:
	return sum;
}
int Q1_while(int num){
	int sum = 0;
	int counter = 1;

	// calculate your sum below..this has to use while loop
	while (counter <= 1000){
		if (counter % num == 0) {
            sum += counter;
        }
		counter++;
	}
	
	// here, we return the calcualted sum:
	return sum;
}
int Q1_dowhile(int num){
	int sum = 0;
	int counter = 1;
	
	// calculate your sum below..this has to use do-while loop
	do{
		if (counter % num == 0) {
            sum += counter;
        }
		counter++;
	} while(counter <= 1000);	  
	
	// here, we return the calcualted sum:
	return sum;
}
//===============================================================================================
int Q2_FPN(float Q2_input, float Q2_threshold){

	//function explanation:
	//Returns 0 if input falls in the range of [-2*threshold, -1*threshold)
	//Returns 1 if input falls in the range of [-1*threshold, 0)
	//Returns 2 if input falls in the range of [0, 1*threshold)
	//Returns 3 if input falls in the range of [1*threshold, 2*threshold]
	//Returns -999 otherwise
	
	int result;
	// Determine which range does Q2_input fall into.  Keep in mind the floating point number range.
	// Assign the correct output to the result.

	if ((Q2_input >= Q2_threshold*(-2)) && (Q2_input < Q2_threshold*(-1)))
	{
		result = 0;
	}
	else if ((Q2_input >= Q2_threshold*(-1)) && (Q2_input < 0))
	{
		result = 1;
	}
	else if ((Q2_input >= 0) && (Q2_input < Q2_threshold))
	{
		result = 2;
	}
	else if ((Q2_input >= Q2_threshold) && (Q2_input <= Q2_threshold*2))
	{
		result = 3;
	}
	else
	{
		result = -999;
	}
	
	// Finally, return the result.
	return result;
}
//===============================================================================================
int Q3(int Q3_input, int perfect[]){	
	
	
		//counts is the variable that should hold the total number of found perfect numbers
		//you should update it within your code and return it at the end
	    int counts=0;
		int i, j, sum_factors;
		
		for (i=2; i<=Q3_input; i++) //go through all the numbers up until the given number
		{
			sum_factors = 1; //1 is always a factor so start with 1

			for (j=2; j<i; j++)
			{
				if (i % j == 0)
				{
					sum_factors += j;
				}
			}

			if (sum_factors == i)
			{
				perfect[counts] = i;
				counts++;
			}
		}

		/*
		*
		*perfect is an array that you need to add into it any perfect number you find
		*which means at the end of this function, the perfect[] array should hold all the found perfect numbers in the range
		*you do not need to return perfect because as stated in lectures arrays are already passed by reference. so, modifying them will 
		*autmoatically reflect in the main calling function.
		*/
	    
	   return counts;

}
//===============================================================================================
int Q4_Bubble(int array[], int size){ //hint for q4: keep checking the numbers and if its smaller u have to swap
	
	// This variable tracks the number of passes done on the array to sort the array.
	int passes = 0;

	// Pseudocode
	// 	1. Given an array and its size, visit every single element in the array up to size-2 (i.e. up to the second last element, omit the last element)
	//  2. For every visited element (current element), check its subsequent element (next element).  
	//     If the next element is smaller, swap the current element and the next element. 
	//  3. Continue until reaching size-2 element.  This is considered One Pass => increment pass count by one.
	//  4. Repeat 1-3 until encountering a pass in which no swapping was done.
	//   -> Sorting Completed.

	int i;
	int temp; //the place holder variable
	int swapped = 1; //var that determines whether there were any swaps in one pass or not
					//0 if no swaps and 1 if yes

	while (swapped == 1)
	{
		swapped = 0;

		for (i = 0; i <= (size-2); i++)
		{
			if (array[i+1] < array[i])
			{
				temp = array[i+1];
				array[i+1] = array[i];
				array[i] = temp;

				swapped = 1;
			}
		}

		passes++; //one pass is complete - increase pass count by 1
	}
	
	// Finally, return the number of passes used to complete the Bubble Sort
	return passes;	
}