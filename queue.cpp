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


//queue is basically stack just element is accessed from front and pushed from back
int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    // queue is 1 2 3 4 5, 1 is front
    prn(q.front()); //1
    prn(q.back()); //5
    prn(q.size()); //5
    q.pop();
    prn(q.size()); //4
    while(!q.empty())
    {
        ps(q.front());  // 2 3 4 5
        q.pop();
    }
    return 0;
}