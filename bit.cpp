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
