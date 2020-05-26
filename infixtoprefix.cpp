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
    public:
    char top;
    char a[10000];
    Stack() { //for new stack
        top = -1;
    }
    bool push(char data);
    bool pop();
    char peek();
    bool empty();
};

bool Stack::push(char data){
    // if(top >= max-1)
    //     return false; //stack overflow
    a[++top] = data;
    return true;
}

bool Stack::pop(){
    if(top < 0)
        return false;
    top--;
    return true;
}

char Stack::peek(){
    return a[top];
    
}

bool Stack::empty(){
    if(top < 0)
        return true;
    return false;
}


bool isOperand(char c){
    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return true;
    return false;
}

int precedence(char c){
    switch(c){
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default:return 0;
    }
}

string infixToPostfix(string s)
{
    class Stack stk;
    string str= "";
    for(int i = 0; i < s.length(); i++){
        if(isOperand(s[i]))
            str+=s[i];
        else{
            if(s[i] == '(')
                stk.push(s[i]);
            else if(s[i] == ')'){
                while(stk.peek() != '('){
                    str+=stk.peek();
                    stk.pop();
                }
                if(stk.peek() == '(')
                stk.pop();
            }
            else{
            
                    while(!stk.empty() && precedence(s[i]) <= precedence(stk.peek())){
                        str+=stk.peek();
                        stk.pop();
                    }
                
                stk.push(s[i]);
            }
        }
        //cout << str << endl;
    }
    while(!stk.empty()){
        str+=stk.peek();
        stk.pop();
    }
    return str;
}

string infixToPrefix(string s){
    reverse(s.begin(), s.end());
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(')
            s[i] = ')';
        else if(s[i] == ')')
            s[i] = '(';
    }
    s = infixToPostfix(s);
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    string s = "(A-B/C)*(A/K-L)";
    cout << infixToPrefix(s);
}
