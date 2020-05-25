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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

class Stack{
    public:
    int top;
    Stack* next;
    Stack(int data){ //constructor
        this->top = data;
        this->next = NULL;
    }
    void push(Stack* &head, int data);
    int pop(Stack* &head);
    bool empty(Stack* &head);
};

void Stack::push(Stack* &head, int data){
    Stack* s = new Stack(data);
    s->next = head;
    head = s;
}

int Stack::pop(Stack* &head){
    int x = head->top;
    head = head->next;
    return x;
}

bool Stack::empty(Stack* &head){
    if(head == NULL)
        return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
	    class Stack* s = new Stack(1);
        s->push(s,2);
        s->push(s,3);
        cout << s->empty(s) << endl;
        cout << s->pop(s) << endl;
        cout << s->pop(s) << endl;
        cout << s->pop(s) << endl;
        cout << s->empty(s) << endl;
	}
}
