#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n,k;
    cin>>n>>k;
    if(n%k==0){
    	cout<<k<<endl;
    	return 0;
	}
    else if(n<k){
    	cout<<n<<endl;
    	return 0;
	}
    else{
    	long long c=n/k + 1;
    	cout<<n/c<<endl;
    	return 0;
	}

}

