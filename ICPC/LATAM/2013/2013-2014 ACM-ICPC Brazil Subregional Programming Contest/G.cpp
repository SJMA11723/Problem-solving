// Source: https://usaco.guide/general/io
 
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <map>
#define DEBUG if (deb)
#define INF 2000000000
#define LINF 2000000000000000000
bool deb = true;
using namespace std;
#define pb push_back
typedef long long ll;
 
 
int main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int r,c;
    cin>>r>>c;
    int i0, j0;
    vector<vector<int>> mrows(r, vector<int>(c, 0));
    vector<vector<int>> mcols(c, vector<int>(r, 0));
    for(int i = 0; i < r; i ++){
        for(int j = 0; j < c; j++){
            cin>>mrows[i][j];

            
            mcols[j][i] = mrows[i][j];

            mrows[i][j]--;
            mcols[j][i]--;

            if(mrows[i][j] == 0){
                i0 = i;
                j0 = j;
            }
        }
    }
    //validating rows

    
    set<int> prows;
    for(int i = 0; i < r*c; i+=c) prows.insert(i);
    for(auto row: mrows){
        sort(row.begin(), row.end());
        int id = row[0];

        if(prows.count(id) == 0){
            cout<<"*\n";
            return 0;
        }
        for(int i = 1; i < row.size(); i++){
            if(row[i] - row[i-1]!=1){
                cout<<"*\n";
                return 0;
            }
        }
        prows.erase(id);
    }

    if(prows.size() != 0){
        cout<<"*\n";
        return 0;
    }


    //validating columns
    set<int> pcols;
    for(int x = 0; x < c; x++) pcols.insert(x);

    for(auto col: mcols){
        sort(col.begin(), col.end());
        int id = col[0];

        if(pcols.count(id) == 0){
            cout<<"*\n";
            return 0;
        }

        for(int i = 1; i < col.size(); i++){
            if(col[i] - col[i-1] != c){
                cout<<"*\n";
                return 0;
            }
        }
        pcols.erase(id);
    }

    if(pcols.size() != 0){
        cout<<"*\n";
        return 0;
    }
    

    //counting hswaps
    int steps = 0;
    bool marked[c]{false};
    for(int x = 0; x < c; x++){

        if(marked[x]) continue;
        int i = x;
        int cnt = -1;
        do{ 
            cnt++;
            marked[i] = true;
            i = mrows[i0][i];
        }while(!marked[i]);
        steps+=cnt;
    }

    //counting vswaps
   

    vector<int> perm;
    for(auto x : mcols[j0]){
        perm.pb(x/c);
    }
    
    bool marked2[r]{false};
    
    for(int x = 0; x < r; x++){
        if(marked2[x]) continue;
        int i = x;
        int cnt = -1;
        do{ 
            cnt++;
            marked2[i] = true;
            i = perm[i];
        }while(!marked2[i]);
        steps+=cnt;
    }
    cout<<steps<<"\n";
}   