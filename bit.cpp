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

//properties ot bit operations
/*
a&b<= min(a,b)
a|b>= max(a,b)
a + b = a|b + a&b
a|b|c|d= d|a|c|a
0^a= a            a^a=0
if a^b=c then a^c=b and b^c=a
odd number & 1=1   even&1=0

if(n&(n-1)==0) then n is a power of 2
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


//from c++14 and onwards   int a= 0b0101;   where a=0101 or 5


//bitwise ~    ~a= -a -1 for a>0   and ~(~a)=a

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




//sum of all pairs of Xors
/*
Consider i’th bit is set in m out of n numbers. Then we can say that i’th
bit will be set in m*(n-m) pairwise XORs. So the final sum due to this i’th
bit will be 2i * m * (n-m) (conversion of binary number to decimal)
All the elements are integers and we know that size of int is 32 bits, so if
we do the above for all the bits 0<=i<32 and sum all the results we will
have our final answer.
*/




//to calculate position of most significant bit
long long int msbPos(long long  n)
{
    long long int msb_p = -1;
    while (n)
    {
        n = n>>1;
        msb_p++;
    }
    return msb_p;
}



//count total setbits Brian Kernighan's algo
countsetbits(int n)
{
    int count=0;
    while(n){
        n=n&(n-1);
        count++;
    }
    return count;
}