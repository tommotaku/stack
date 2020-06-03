#include <bits/stdc++.h>
using namespace std;
#define pb push_back  
#define loop(i,n) for(int i = 0; i < n; i++)
#define mp make_pair
#define F first
#define S second
#define asort(a) sort(a,a+n)
#define vsort(v) sort(v.begin(), v.end())
#define remdup(v) v.erase(unique(v.begin(), v.end()), v.end())
#define iter(m) for(auto it = m.begin(); it != m.end(); it++)
#define max 10000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

class Stack{
    queue<int> q1, q2;
    public:
    void push(int x);
    void pop();
    int top();
};

void Stack::push(int x){
    q1.push(x);
}

void Stack::pop(){
    if(q1.empty()) return;
    while(q1.size() != 1){
        q2.push(q1.front());
        q1.pop();
    }
    q1.pop();
    queue<int> tempq = q1;
    q1 = q2;
    q2 = tempq;
}

int Stack::top(){
    if(q1.empty()) return -1;
    while(q1.size() != 1){
        q2.push(q1.front());
        q1.pop();
    }
    int x = q1.front();
    q1.pop();
    q2.push(x);
    queue<int> tempq = q1;
    q1 = q2;
    q2 = tempq;
    return x;
}

int main(){
    Stack s;
    s.push(1); s.push(2); s.push(3);
    s.pop();
    cout << s.top();
}