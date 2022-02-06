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
    
//no.of digits in n
//floor(log10(n)+1)=ceil(log10(n))


//no.of bits in binary form in n
//floor(log2(n)+1)=ceil(log2(n))


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



//no.of factors of a number
int numoffac(int m){
int count=0;
for(int i=1;i<=sqrt(m);++i)
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
//sum of factors is similar
return count;
}





//gcd
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

// lcm(a,b)*gcd(a,b)=a*b




/*Modular Inverse
if M%(a*x)=1 then x is modular inverse and x<M and x>=0*/
int minv(int m,int a)
{
    for (int i = 0; i < m; i++)
    {
        if(m%(a*i)==1)  return i;
    }
}


/*Mod rules
(a+b)%m= (a%m +b%m)%m
(a*b)%m= (a%m *b%m)%m*/




//Fermat's Little Theorem         if m is prime then  (a^m -a)%m=0  for all a


// sum of all proper divisiors of n= (sum of reciprocal of all proper divisors)*n



/*if we have 2 numbers a and b
let z= a + (b*n)   now   z%n=a and z/n=b    #a should be greater than n
*/