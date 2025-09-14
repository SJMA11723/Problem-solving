#include <bits\stdc++.h>
#define MUCHO 100005

using namespace std;

int arr1[MUCHO];
int arr2[MUCHO];
int n;
int maxl, maxr;
int min1l, min1r, min2l, min2r;

long long int maxsum;
long long int minsum;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    maxl=0;
    maxr=n-1;
    min1l=0;
    min2l=0;
    min1r=n-1;
    min2r=n-1;
    for(int c=0; c < n; c++){
        cin >> arr1[c];
    }
    for(int c=0; c < n; c++){
        cin >> arr2[c];
    }
    sort(arr1, arr1+n);
    sort(arr2, arr2+n);
    for(int c=1; c <= n; c++){
        //getmin
        if(arr1[min1l]*arr2[min2r] < arr1[min1r]*arr2[min2l]){
            minsum+=arr1[min1l]*arr2[min2r];
            min1l++;
            min2r--;
        }
        else{
            minsum+=arr1[min1r]*arr2[min2l];
            min1r--;
            min2l++;
        }
        //getmax
        if(arr1[maxr]*arr2[maxr] > arr1[maxl]*arr2[maxl]){
            maxsum+=arr1[maxr]*arr2[maxr];
            maxr--;
        }
        else{
            maxsum+=arr1[maxl]*arr2[maxl];
            maxl++;
        }
        cout << minsum << " " << maxsum << endl;
    }
}
