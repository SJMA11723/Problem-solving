#include<iostream>
#include<vector>


#define MOD 1000000007
using namespace std;
#define DEBUG if(deb)
#define pb push_back
bool deb = false;
bool vis[2010];
int cnt[2010];
typedef long long ll;

int preffix[1010][1010];

int query(int x, int y, int i, int j){

    int ans = 0;

    ans+=preffix[i][j];

    if((x-1)>=0)ans-=preffix[x-1][j];
    if((y-1)>=0)ans-=preffix[i][y-1];
    if((x-1)>=0 && (y-1) >= 0) ans+=preffix[x-1][y-1];

    return ans;


}

void printv(vector<vector<int>>& v){

    for(int x = 0; x < v.size(); x++){
        for(int y = 0; y < v[x].size(); y++){
            cout<<v[x][y];
        }
        printf("\n");
    }
}


void printm(int ns, int ms){
    cout<<endl<<endl;
    for(int x = 0; x < ns; x++){
        for(int y = 0; y < ms; y++){
            cout<<preffix[x][y];
        }
        printf("\n");
    }
}


bool valid(int k, int ns, int ms){


    DEBUG printf("Checking for %d\n",k);
    for(int i = 0; (i+k-1)< ns; i++){
        for(int j = 0; (j+k-2)<ms; j++){


            DEBUG printf("Checking for %d %d %d %d\n", i,j, i+k-1, j+k-2);
            int val = query(i,j, i+k-1,j+k-2);
            DEBUG printf("Value %d\n", val);

            if(val == 0) return true;

        }
    }


    return false;


}





int main(){
    int n,m;


    cin>>n>>m;


    vector<string> matrix;
    for(int x = 0; x < n; x++){
        string s;

        cin>>s;
        matrix.pb(s);
    }


    if(n == 1 ||m == 1){
        printf("1");

        return 0;
    }

    vector<vector<int>> mat(n, vector<int>());
    for(int x = 0; x < n; x++){

        mat[x].pb(1);
        for(int i = 1; i < m; i++){
            if(matrix[x][i] == matrix[x][i-1])mat[x].pb(0);
            else mat[x].pb(1);
        }
        mat[x].pb(1);
    }

    DEBUG printv(mat);

    int ns = mat.size();
    int ms = mat[0].size();



    preffix[0][0] = mat[0][0];


    for(int i = 1; i < ms; i++){
        preffix[0][i] = preffix[0][i-1] + mat[0][i];
    }

    for(int i = 1; i < ns; i++ ){
        preffix[i][0] = preffix[i-1][0]+ mat[i][0];
    }


    for(int i = 1; i < ns; i++){
        for(int j = 1; j < ms; j++){

            preffix[i][j] = preffix[i-1][j]+preffix[i][j-1] - preffix[i-1][j-1] + mat[i][j];
        }
    }


    DEBUG printm(ns,ms);



    int ini = 0, fin = max(n,m);

    int ans = 1;
    while(ini <= fin){
        int mit = (ini+fin)/2;

        if(valid(mit, ns, ms)){
            ans = mit;
            ini = mit + 1;
        }
        else{
            fin = mit -1;
        }
    }


    cout<<(ans*ans);










}
