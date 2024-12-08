#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if(a < b) swap(a, b);
    
    while(a % b != 0){
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    
    return b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int q;
    
    cin >> q;
    
    
    while(q--){
        string a, b, str1 = "", str2 = "";
        
        cin >> a >> b;
        
        if(b < a) swap(a, b);
        
        int tam1 = a.size(), tam2 = b.size();
        
        int lcm = tam1 * tam2 / gcd(tam1, tam2);
        
        for(int i = 0; i < lcm / tam1; ++i) str1 += a;
        
        for(int i = 0; i < lcm / tam2; ++i) str2 += b;
        
        if(str1 != str2) str1 = "-1";
        
        str1 += "\n";
        
        cout << str1;
    }
}