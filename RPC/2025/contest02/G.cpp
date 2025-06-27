#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>

#define DEBUG if (deb)
#define pb push_back
#define forn(i, a, b) for (int i = int(a); i < int(b); i++)
#define LLINF 9223372036854775807
#define INF 2000000000
#define MOD 998244353
#define MAX 10000000
typedef long long int ll;
bool deb = false;
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin>>n;

  int arr[n];
  for(int x = 0; x < n; x++) {
    int in, dec;
    char point;
    cin>>in>>point>>dec;
    arr[x]= in*100+dec;
  }

  int tot = 0;
  int freq3, freq4;
  freq3=freq4=0;
  for(auto x : arr){
    if(x%5 == 1 || x%5 == 2){
        tot+= (x - x%5);
    }
    else {
        tot+=x;
        if(x%5 == 3) freq3++;
        if(x%5 == 4) freq4++;
    }
  }
  if(freq4 >= freq3){
    tot-= 2*freq3;
    tot-= 2*((freq4-freq3)/3);
  }
  else{
    tot-=2*freq4 + (freq3-freq4)/2;
  }
  int ic,dc;
  ic = tot/100;
  dc = tot%100;
  if(dc < 10)cout<<ic<<".0"<<dc<<"\n";
  else cout<<ic<<"."<<dc<<"\n";
  

}