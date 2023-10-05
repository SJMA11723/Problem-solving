#include <bits/stdc++.h>

using namespace std;

stack<int> pila;
string str, res = "";

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    getline(cin, str);
    for(int i = 0; i < str.size(); ++i){
        if(str[i] == '('){
            pila.push(i);
        } else if(str[i] == ')'){
            reverse(str.begin() + pila.top() + 1, str.begin() + i);
            pila.pop();
        }
    }
    for(char it : str){
        if(it != '(' && it != ')') cout << it;
    }
}