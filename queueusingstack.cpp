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

class Queue{
    stack<int> s1, s2;
    public:
    void enqueue(int x);
    int dequeue();
};

void Queue::enqueue(int x){
    s1.push(x);
}

int Queue::dequeue(){
    if(s1.empty() && s2.empty()) return -1;
    if(s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
    int x = s2.top();
    s2.pop();
    return x;
}

int main(){
    Queue q;
    q.enqueue(1); q.enqueue(2); q.enqueue(3);
    cout << q.dequeue()<< endl << q.dequeue();
}