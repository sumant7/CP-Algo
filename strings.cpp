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


//add 2 strings of same size like numbers s1="25678" and s2="12345"
string add(string s1,string s2){
    string s="";
    int i,sum,carry=0;
    char c;
    for(i=s1.size();i>=0;--i)
    {
        sum= (s1[i]-'0') + (s2[i]-'0') + carry;
        if(sum<=9)
        {
            c=((char)(sum)+48);
            s=c+s;   //adding the digit to end of s
            carry=0;
        }
        if(sum>9)
        {
            sum=sum%10;
            c=((char)(sum)+48);
            carry=1;
            s=c+s;
        }
        if(i==0 && carry==1)
        {
            s=(char)(1+48)+ s;
        }
    }
    s.pop_back();
    return s;
}

//convert a number to roman         1 to 3999
string printRoman(int number)
{
    int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    string s="";
    int i=12;   
    while(number>0)
    {
      int div = number/num[i];
      number = number%num[i];
      while(div--)
      {
        s=s+sym[i];
      }
      i--;
    }
    return s;
}