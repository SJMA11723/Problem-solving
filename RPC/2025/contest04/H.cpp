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
   
    int a,b;
    cin>>a>>b;

    ll ans = min(a,b)*10;
    a-=min(a,b);

    ans += (a/3)*10;

    if(a%3 == 2) ans+=3;
    else if(a% 3 == 1) ans+=1;

    cout<<ans<<"\n";
    return 0;
}