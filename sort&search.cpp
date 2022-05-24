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
#define ll long long int

using namespace std;
    
//to search a number in an array with O(logN) complexity
ll binarysearch(ll a[], ll n, ll k)    //k is the number to search
{
    ll l=0,r=n-1,mid;
    while(r>=l)
    {
        mid= l+(r-l)/2;
        if(a[mid]==k)
        {
            return mid;
        }
        if(a[mid]>k)
        {
            r=mid-1;
        }
        if(a[mid]<k)
        {
            l=mid+1;
        }
    }
    return -1;
}



//find sqaure root with precision
double bsqrt(int key){
	double l=0,r=key;   //l=left and r=right
	double mid= l+ (r-l)/2,p=0.01;   //p is precision with which we need to find
	while((r-l)>p){
		mid = l+ (r-l)/2;
		if(mid*mid<key)    l=mid;
		else r=key;
	}
	return mid;
}


//to find minimum no.of swaps to sort an array
int minSwaps(int arr[], int n)
{
	// Create an array of pairs where first element is array element and second element is position of first element
	pair<int, int> arrPos[n];
	for (int i = 0; i < n; i++)
	{
		arrPos[i].first = arr[i];     //storing original array
		arrPos[i].second = i;    //original index
	}

	// Sort the array by array element values to get right position of every element as second element of pair.
	sort(arrPos, arrPos + n);
    // To keep track of visited elements. Initialize all elements as not visited or false.
	vector<bool> vis(n, false);
    // Initialize result
	int ans = 0;
    // Traverse array elements
	for (int i = 0; i < n; i++)
	{
		// already swapped and corrected or already present at correct pos
		if (vis[i] || arrPos[i].second == i)      //vis[i] is already swapped and  arrPos[i].second == i already at correct position
			continue;
        // find out the number of node in this cycle and add in ans
		int cycle_size = 0;
		int j = i;
		while (!vis[j])
		{
			vis[j] = 1;    //already swapped
            // move to next node
			j = arrPos[j].second;   //j is sorted position  and arrPos[j].second is original position
			cycle_size++;
		}
        // Update answer by adding current cycle.
		if (cycle_size > 0)
		{
			ans += (cycle_size - 1);
		}
	}
	// Return result
	return ans;
}



//sorting with cmp function
//Given a vector of string, Sort the vector elements on the basis of size of strings in descending order. If sizes are equal, sort them in lexicographically smallest order

/*
bool cmp(string a, string b)
{
    if(a.size()!=b.size())  return(a.size()>b.size());     //for descending order of size
    else return a<b;    //lexiographically inceasing
}
int main(){
    vector<string> v={"abc", "o", "tdc", "zx", "d", "za"};
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();++i)
    {
        cout<<v[i]<<" ";
    }
}
*/







