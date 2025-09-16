#include<iostream>


using namespace std;



int main(){
    int n;


    cin>>n;


    int arr[n];
    int p = 0;
    for(int x = 0; x < n; x++){
        cin>>arr[x];
        if(arr[x]) p++;
        else p--;
    }

    for(int x = 2; x < n;x++ ){

        if((arr[x]+arr[x-1]+arr[x-2]) == 3)p++;
    }


    cout<<p<<"\n";

    return 0;
}