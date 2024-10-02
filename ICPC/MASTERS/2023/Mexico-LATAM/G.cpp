#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int x;
    cin>>x;

    int i = 1;
    vector<int> ans;
    while(i*i <= x){
        if(i*i == x){
            i++;
            continue;
        }

        if(x%i != 0) {
            i++;
            continue;
        }

        int sum = i + x/i;

        if(sum % 2  == 0){
            ans.push_back(sum/2);
        }
        i++;
    }

    cout<<ans.size()<<"\n";
    sort(ans.begin(), ans.end());
    for(int x = 0; x < ans.size(); x++){
        if(x!= ans.size()-1)cout<<ans[x]<<" ";
        else cout<<ans[x]<<"\n";
    }
    
}