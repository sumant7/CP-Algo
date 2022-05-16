// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <map>
#include <list>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;
#define prn(n) cout << n << "\n"
#define pr(n) cout << n
#define ps(n) cout << n << " "
#define el << '\n'
#define sp << " "
#define ll long long int
#define pb push_back
#define cn continue
#define fr(i, n) for (i = 0; i < n; ++i)

class Employee
{
private:
    int a, b, c; // these variables can only used by functions inside class
public:
    int d, e ,test;
    void setData(int a1, int b1, int c1); // declaration of a function
    void getData()
    { // an example of full function inside class only
        cout << "Value of a is: " << a el;
        cout << "Value of b is: " << b el;
        cout << "Value of c is: " << c el;
        cout << "Value of d is: " << d el;
        cout << "Value of e is: " << e el;
        cout << "Value of test is: " << test el;
    }
    Employee(){   //default constructor, is called when onject is created without any paramter
        test =0;
    }
    Employee(int x){
        test =x; //Parameterized constructor is called when object is created with a paramter
    }
};

void Employee ::setData(int a1, int b1, int c1)
{
    // this is another way to define function
    a = a1; // we can use 'a' because setData is a function inside class
    b = b1;
    c = c1;
}

int main()
{
    Employee sumant;
    sumant.setData(1, 2, 3);
    // sumant.a = 56; this will give error as it is private
    sumant.d = 4;
    sumant.e = 5;
    sumant.getData();
    cout el el;
    Employee harry(69);
    harry.d =34;
    harry.e =96;
    harry.setData(1,2,3);
    harry.getData();
    return 0;
}


/*
Output:
Value of a is: 1
Value of b is: 2
Value of c is: 3
Value of d is: 4
Value of e is: 5
Value of test is: 0


Value of a is: 1
Value of b is: 2
Value of c is: 3
Value of d is: 34
Value of e is: 96
Value of test is: 69
*/