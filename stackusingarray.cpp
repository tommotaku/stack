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
#define max 1000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

class Stack{
    public:
    int top;
    int a[max];
    Stack() { //for new stack
        top = -1;
    }
    bool push(int data);
    int pop();
    bool empty();
};

bool Stack::push(int data){
    if(top >= max-1)
        return false; //stack overflow
    a[++top] = data;
    return true;
}

int Stack::pop(){
    if(top < 0)
        return false;
    return a[top--];
}

bool Stack::empty(){
    if(top < 0)
        return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
	    class Stack s;
        s.push(1);
        s.push(2);
        s.push(3);
        cout << s.empty() << endl;
        cout << s.pop() << endl;
        cout << s.pop() << endl;
        cout << s.pop() << endl;
        cout << s.empty() << endl;
	}
}
