//they operate on Last in First Out
//like chairs stacked on top of each other, to take out a chair you have to remove all chairs above it one by one
//size, push,empty,pop,top all occur in O(1)
#include <iostream>
#include <stack>
using namespace std;
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