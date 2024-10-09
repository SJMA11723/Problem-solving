#include<iostream>


using namespace std;
int main(){

    int h, m;

    cin>>h>>m;


    int curr = h*60+m;


    int n;
    cin>>n;

    int tax[n];
    int time[n];

    for(int x = 0; x < n; x++){
        cin>>time[x]>>tax[x];
    }
    int i = 0;
    int cost = 0;
    while(i < n && curr>0){
        int t = min(curr, time[i]);
        //printf("%d %d %d\n", curr, time[i], tax[i]);

        curr-= t;
        cost+= tax[i]*t;
        i++;
    }

    cout<<cost<<"\n";

    

    






}