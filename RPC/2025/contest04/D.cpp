#include <bits/stdc++.h>
#define DEBUG if (deb)
#define pb push_back
#define no cout << "NO\n"
#define yes cout << "YES\n"
#define MAXC 28
#define MAXN 300000

using namespace std;
typedef long long ll;

int ps[MAXC][MAXN];
bool deb = true;
string s;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   
    int n;
    cin>>n;

    bool arr[2*n+1]{false};

    for(int x = 0; x < n; x++){
        int t;
        cin>>t;
        arr[t] = true;
    }

    int max = 0;
    int bc = 0;

    for(int x = 1; x <= 2*n; x++){
        if(!arr[x]) bc++;
        else if(bc) {
            bc--;
            max++;
        }
    }

    int min = 0;
    bc = 0;
    for(int x = 1; x <= 2*n; x++){
        if(arr[x]) bc++;
        else if(bc) {
            bc--;
            min++;
        }
    }
    min = n - min;

    cout<<min<<" "<<max<<"\n";
}