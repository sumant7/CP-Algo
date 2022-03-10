//they operate on Last in First Out
//like chairs stacked on top of each other, to take out a chair you have to remove all chairs above it one by one
//size, push,empty,pop,top all occur in O(1)
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
#include <queue>
#include <stack>
using namespace std;
#define prn(n) cout<<n<<"\n"
#define pr(n) cout<<n
#define ps(n) cout<<n<<" "
#define el <<'\n'
#define sp <<" "
#define ll long long int
#define pb push_back
#define cn continue
#define fr(i,n) for(i=0;i<n;++i)
int main() {
    stack <int> s;  //creating a stack of int
    //inserting elements into a stack one by one
    int i;
    for ( i = 0; i < 5; i++)
    {
        s.push(i);
    }
    cout<<s.size()<<'\n'; //returns 5
    //the stack is  4 3 2 1 0   , 4 is on top because it was inserted last
    cout<<s.top()<<'\n';  //output 4 which is the top element
    s.pop();  //removes top element which was 4
    cout<<s.top()<<'\n'; //output 3
    //to print all elements
    while(!s.empty())  //s.empty returns true is stack is empty
    {
        cout<<s.top()<<" ";  //outputs 3 2 1 0
        s.pop();
    }
    
}

//other functions
/*
stack1.swap(stack2)  will swap all values of both stacks
both stacks must be of same data type but can be of different size. Time O(n)
*/


/*
stack.emplace 
While push() function inserts a copy of the value or the parameter passed to the function into the container at the top, the emplace() function constructs a new element as the value of the parameter and then adds it to the top of the container. 
*/



//print next largest number, j>i && a[j]>a[i]
vector<pair<ll,ll>> solve(vector<ll> a)  //returns [{element,nextlargest}]  !!! not in correct order
{
    vector<pair<ll,ll>> v;
    stack <ll> s;
    s.push(a[0]);
    ll i;
    for(i=1;i<a.size();++i)
    {
        ll x=a[i];
        if(s.empty())
        {
            s.push(a[i]);
            cn;
        }
        while(!s.empty() && s.top()<a[i])
        {
            v.pb({s.top(),a[i]});
            s.pop();
        }
        s.push(a[i]);
    }
    while(!s.empty())
    {
        v.pb({s.top(),-1});
        s.pop();
    }
    return v;
}