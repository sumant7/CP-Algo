//to find digits int the factorial of a number
int digitsInFactorial(int N)
    {
        double ans=0;
        for(int i=2;i<=N;++i)
        {
            ans = ans + log10(i);
        }
        return ceil(ans);
    }


    
//to search a number in an array with O(logN) complexity
int binarysearch(int a[], int n, int k)    //k is the number to search
{
        int l=0,r=n-1,mid;
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



//to find minimum no.of swaps to sort an array
int minSwaps(int arr[], int n)
{
	// Create an array of pairs where first element is array element and second element is position of first element
	pair<int, int> arrPos[n];
	for (int i = 0; i < n; i++)
	{
		arrPos[i].first = arr[i];
		arrPos[i].second = i;
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
		if (vis[i] || arrPos[i].second == i)
			continue;
        // find out the number of node in this cycle and add in ans
		int cycle_size = 0;
		int j = i;
		while (!vis[j])
		{
			vis[j] = 1;
            // move to next node
			j = arrPos[j].second;
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




//lcm
int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;
  
    // base case
    if (a == b)
        return a;
  
    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}






//no.of factors of a number
for(i=1;i<=sqrt(m);++i)
{
    if(m%i==0)
    {
        if(m/i==i)
        {
            count++;
        }
        else
        {
            count=count+2;
        }
    }
}




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

