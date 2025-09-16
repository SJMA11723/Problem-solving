#include<iostream>
#include<bitset>
#include<vector>

using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n,m;

    cin>>n>>m;

    bitset<1010> bs;



    int l;
    cin>>l;
    for(int x = 0; x < l; x++){
        int t;
        cin>>t;
        bs[t] = true;
    }
    vector<vector<int> > adyl(n+1);

    for(int x = 1; x <= n; x++){
        int c;
        cin>>c;
        for(int i = 0; i < c; i++){
            int e;
            cin>>e;
            adyl[x].push_back(e);
        }
    }
    //cout<<bs.to_string()<<endl;
    for(int sw = 0; sw < 2*n; sw++){
        
        int i = (sw % n)+1;
        
        for(auto edge : adyl[i]){
            bs.flip(edge);
        }
        //cout<<bs.to_string()<<endl;

        if(!bs.count()){
            cout<<(sw+1)<<"\n";
            return 0;
            
        }
    }

    cout<<"-1\n";



}