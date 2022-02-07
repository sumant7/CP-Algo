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


//operators
/*  
x>>n  is basically x= x/2^n;
x<<n  is basically x= x*2^n;
*/

//properties
/*
a&b<= min(a,b)
a|b>= max(a,b)
a|b|c|d= d|a|c|a
0^a= a            a^a=0
odd number & 1=1   even&1=0
*/


//set and unset bits
/*
set bit=0 and unser bit=0

//check is ith bit is set in a number n
if((n&(1<<i))==0)   return false;
else return true;


//set ith bit
n= n | (~(1<<i))

//unset ith bit
n= n & (1<<i)

//toggle ith bit
n= n ^ (1<<i)
*/




//fint sum of all xor pairs in an array
/*
Consider ith bit is set in m out of n numbers.Then we can say that ith bit will be set in m*(n-m) pairwise XORs.So the final sum due to this ith bit will be 2^i*m*(n-m) (conversion of binary number to decimal)
*/

long long int sum(int a[],int n)
{
    long long int ans=0;
    for(int i=0;i<32;++i)  //integers are 32 bit numbers
    {
        int count=0;
        for(int j=0;j<n;++j)
        {
            if(a[j]&(1<<i)!=0)  count++;
        }
        ans=ans+ (1<<i)*count*(n-count);
    }
    return ans;
}