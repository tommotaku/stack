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

void sortStack(stack<int> &s){
    stack<int> s1 = s;
    s = stack<int>(); //emptying stack
    while(!s1.empty()){
        if(s.empty() || s.top() > s1.top()){ //for decending change > to <=
            s.push(s1.top());
            s1.pop();
        }
        else{
            int temp = s1.top();
            s1.pop();
            while(s.top() <= temp){ //for descending change <= to >
                s1.push(s.top());
                s.pop();
            }
            s.push(temp);
        }
    }
}

int main(){
    stack<int> s;
    int n;
    cin >> n;
    loop(i,n){
        int a;
        cin >> a;
        s.push(a);
    }
    sortStack(s);
     loop(i,n){
        cout << s.top();
        s.pop();
    }
}