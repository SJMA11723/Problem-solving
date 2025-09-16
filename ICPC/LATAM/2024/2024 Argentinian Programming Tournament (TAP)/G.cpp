#include<iostream>


using namespace std;



int main(){
    string s;


    cin>>s;

    int t,p,a,u;

    t = p = a = u = 0;
    for(auto x : s){
        switch(x){
        case 'T':
            t++;
            break;
        case 'P':
            p++;
            break;
        case 'U':
            u++;
            break;
        case 'A':
            a++;
            break;
        }
    }

    int ans = min(t,p);
    ans = min(ans, u+a);

    cout<<ans<<"\n";


}