/*
A simple solution is to generate all subsets, find product of every subset and return maximum product.

GFG approach: 

A better solution is to use the below facts.

>> If there are even number of negative numbers and no zeros, result is simply product of all

>> If there are odd number of negative numbers and no zeros, result is product of all except the negative integer with 
   the least absolute value.
   
>> If there are zeros, result is product of all except these zeros with one exceptional case. The exceptional case is when 
   there is one negative number and all other elements are 0. In this case, result is 0.

Time Complexity: O(n) 
Auxiliary Space: O(1) 
*/

#include <bits/stdc++.h>
using namespace std;

int maxProductSubset(int a[], int n)
{
	//corner case
	if (n == 1)
	{
		return a[0];
	}
	
	// Find count of negative numbers, count of zeros, negative number with least absolute value and product of non-zero numbers
    int max_neg = INT_MIN;
    int count_neg = 0, count_zero = 0;
    int prod = 1;
    
    for (int i = 0; i < n; i++) 
	{
 
        // If number is 0, we don't
        // multiply it with product.
        if (a[i] == 0) {
            count_zero++;
            continue;
        }
 
        // Count negatives and keep
        // track of negative number
        // with least absolute value
        if (a[i] < 0) {
            count_neg++;
            max_neg = max(max_neg, a[i]);
        }
 
        prod = prod * a[i];
    }
    
    // If there are all zeros
    if (count_zero == n)
    {
    	return 0;
	}
	else if(count_zero == n-1)
	{
		return prod;
	}
	// If there are odd number of
    // negative numbers
    if (count_neg & 1) {
 
        // Exceptional case: There is only
        // negative and all other are zeros
        if (count_neg == 1 &&
            count_zero > 0 &&
            count_zero + count_neg == n)
            return 0;
 
        // Otherwise result is product of
        // all non-zeros divided by
        //negative number with
        // least absolute value
        prod = prod / max_neg;
    }
 
    return prod;
	
	


}

// Driver Code
int main()
{
    int a[] = {  -1, -1, -2, 4, 3  };
    int n = sizeof(a) / sizeof(a[0]);
    cout << maxProductSubset(a, n);
    return 0;
}
