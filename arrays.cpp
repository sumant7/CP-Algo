#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <list>

using namespace std;
    
//to put all negative numbers on left in an array
//time O(n), space O(1)
void rearrange(int arr[], int n)     //n is size of arr
{
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (i != j)
                swap(arr[i], arr[j]);
            j++;
        }
    }
}




//largest sum subarray    or Kadane's Algorithm
/*The simple idea of Kadane’s algorithm is to look for all positive contiguous segments of the array (max_ending_here is used for this). And keep track of maximum sum contiguous segment among all positive segments (max_so_far is used for this). Each time we get a positive-sum compare it with max_so_far and update max_so_far if it is greater than max_so_far*/
int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
 
    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}



//Merge two sorted Arrays
/*The idea is to traverse both the arrays simultaneously and compare the current numbers from both the Arrays. Pick the smaller element and copy it to arr3[ ] and advance the current index of the array from where the smaller element is picked. When we reach at the end of one of the arrays, copy the remaining elements of another array to arr3[ ].*/
// input arrays - arr1(size m), arr2(size n)
void merge_sorted(int arr1[],int arr2[],int m, int n)     //O(m+n)
{
    int arr3[m+n]; // merged array
    int i=0,j=0,k=0;
    while(i < m && j < n)   //may perform less tha m+n steps
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k] = arr1[i];
            k++;
            i++;
        }
        else
        { 
            arr3[k] = arr2[j];
            k++;
            j++;
        }
    }
    while(i < m)   //rest steps
    {
        arr3[k] = arr1[i];
        k++;
        i++;
    }
    while(j < n)
    { 
        arr3[k] = arr2[j];
        k++;
        j++;
    }
}




//rearrange an array such that a[i]=a[a[i]] without extra space
void rearr(int a[],int n)
{
    int i;
    for(i=0;i<n;++i)    // a=> a+ b*n     a=a[i]    b=a[a[i]]
    {
        a[i]= a[i]%n + (a[a[i]%n]%n)*n;       //%n is neccesary beacuse this a[i] will get changed and later in the loop we need original a[i] yo convert some other a[i]
    }
    for(i=0;i<n;++i)
    {
        a[i]= a[i]/n;   // (a+b*n)/n = b
    }
}