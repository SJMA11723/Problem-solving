#include<iostream>
#define MOD 1000000007
#define INV2 500000004
#define INV4 250000002
using namespace std;

int main(){


    string s;
    cin>>s;
    long long n;
    cin>>n;


    int len =s.length();
    long long mat[26][len];

    for(char c  = 'a'; c <= 'z'; c++){
        mat[c -'a'][0] = (s[0] > c);
        for(int i = 1; i < len; i++){
            if(s[i] > c) mat[c - 'a'][i] = mat[c - 'a'][i-1] +1;
            else mat[c - 'a'][i] = mat[c - 'a'][i-1]; 
        }
    }

    long long inv = 0;
    for(int i = 1; i < len; i++){
        inv+=mat[s[i] - 'a'][i-1];
    }

    long long ans = (inv * (n % MOD)) % MOD;


    long long left[27]{0};
    long long right[27]{0};
    for(char c = 'a' ; c <= 'z'; c++){
        for(auto si : s){
            if(c > si) left[c - 'a']++;
            else if( c < si) right[c - 'a']++;
        }
    }

    
    
    long long sum = 0;
    for(auto si : s){
        sum+= (left[si - 'a'] + right[si - 'a']);
        sum%=MOD;
    }

    ans += (((((n-1)%MOD * (n % MOD))% MOD )*sum )% MOD* INV4 % MOD);
    ans %=MOD;
    cout<<ans<<"\n";






}