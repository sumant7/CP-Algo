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




//smallest number on left
vector<int> leftSmaller(int n, int a[]){
        vector<int> v(n);
        stack <int> s;
        s.push(-1);
        int i;
        for(i=0;i<n;++i)
        {
            while(a[i]<=s.top() && s.top()!=-1) s.pop();
            v[i]=s.top();
            s.push(a[i]);
        }
        return v;
    }



//next smaller
vector<int> help_classmate(vector<int> a, int n) 
    { 
        stack <int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--)
        {
            while(s.top()>=a[i])
            {
                s.pop();
            }
            ans[i]=s.top();
            s.push(a[i]);
        }
        return ans;
    } 


//find minimum value in a stack in O(1)
/*
we actually make stack os pairs
stack<pair<int, int>> st;
int new_min = st.empty() ? new_elem : min(new_elem, st.top().second);
st.push({new_elem, new_min});


each element = {element, minimum of all elemtnts not above it}
*/





//convert infix to postfix
// Function to return precedence of operators
int prec(char c)
{
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// The main function to convert infix 
// expression to postfix expression
void infixToPostfix(string s)
{
    stack<char> st;
    st.push('N');
    
    int l = s.length();
    
    string ns;
    
    for(int i = 0; i < l; i++)
    {
        // If the scanned character is an operand, 
        // add it to output string.
        if((s[i] >= 'a' && s[i] <= 'z')||
                (s[i] >= 'A' && s[i] <= 'Z'))
            ns+=s[i];
        // If the scanned character is an ‘(‘,
        // push it to the stack.
        else if(s[i] == '(')
        
        st.push('(');
        
        // If the scanned character is an ‘)’, 
        // pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if(s[i] == ')')
        {
            while(st.top() != 'N' && st.top() != '(')
            {
                char c = st.top();
                st.pop();
                
                ns += c;
            }
            if(st.top() == '(')
            {
                char c = st.top();
                st.pop();
            }
        }
        
        // If an operator is scanned
        else{
            while(st.top() != 'N' && prec(s[i]) <= prec(st.top()))
            {
                char c = st.top();
                st.pop();
                ns += c;
            }
            
            st.push(s[i]);
        }
    }
    
    // Pop all the remaining elements from the stack
    while(st.top() != 'N')
    {
        char c = st.top();
        st.pop();
        ns += c;
    }
    
    cout << ns << endl;
}


//evaluating postfix
int evaluatePostfix(char* exp) //or string
{ 
    // Create a stack 
    stack<int> st;
    
    int i; 

    // Scan all characters one by one 
    for (i = 0; exp[i]; ++i) 
    { 
        // If the scanned character is an operand (number here), 
        // push it to the stack. 
        if (isdigit(exp[i])) 
            st.push(exp[i] - '0'); 

        // If the scanned character is an operator, pop two 
        // elements from stack apply the operator 
        else
        { 
            int val1 = st.top();
            st.pop();
            
            int val2 = st.top();
            st.pop();
            
            switch (exp[i]) 
            { 
                case '+': st.push(val2 + val1); break; 
                case '-': st.push(val2 - val1); break; 
                case '*': st.push(val2 * val1); break; 
                case '/': st.push(val2/val1); break; 
            } 
        } 
    } 
    
    return st.top(); 
}



//implement stack using array
#define MAX 1000

class Stack
{
    int top;
public:
    int a[MAX];    //Maximum size of Stack

    Stack()  { top = -1; }
    bool push(int x);
    int pop();
    bool isEmpty();
};

bool Stack::push(int x)
{
    if (top >= (MAX-1))
    {
        cout << "Stack Overflow";
        return false;
    }
    else
    {
        a[++top] = x;
        cout<<x <<" pushed into stack\n";
        return true;
    }
}

int Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow";
        return 0;
    }
    else
    {
        int x = a[top--];
        return x;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}
/*
int main()
{
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout<<s.pop() << " Popped from stack\n";

    return 0;
}
10 pushed into stack

20 pushed into stack

30 pushed into stack

30 popped from stack
*/