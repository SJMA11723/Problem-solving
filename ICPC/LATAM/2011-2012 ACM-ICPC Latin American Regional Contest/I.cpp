#include <bits/stdc++.h>

using namespace std;

typedef string str;

str toBraile[]={".*","**","*.","..", "*.","*.", "**","..","**",".*","*.",".*","**","*.","**","**","*.","**",".*","*.",};
//str two[]={"*.","*."};
//str three[]={};
//str four[]={} ;
//str five[]={};
//str six[]={};
//str seven[]={};
//str ocho[]={};
//str nine[]={};
//str cero[]={};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int d;
    char mode;
    string nums;

    do{
        cin >> d;
        if(!d) break;
        cin >> mode;
        if(mode == 'S'){
            vector <int> toPrint;
            cin >> nums;
            for(int c=0; c < d; c++){
                toPrint.push_back(nums[c]-'0');
            }
            for(int c=0; c < d; c++){
                cout << toBraile[toPrint[c]*2] <<" ";
            }
            cout << "\n";
            for(int c=0; c < d; c++){
                cout << toBraile[toPrint[c]*2+1] <<" ";
            }
            cout << "\n";
            for(int c=0; c < d; c++){
                cout << ".." <<" ";
            }
            cout << "\n";
        }
        else{
            string braile[3][105];
            vector <int> toPrint;
            for(int k=0; k < 3; k++){
                for(int c=0; c < d; c++){
                    cin >> braile[k][c];
                }
            }
            for(int c=0; c < d; c++){
                for(int k=0; k < 10; k++){
                    if(braile[0][c]==toBraile[k*2] && braile[1][c]==toBraile[k*2+1]){
                        toPrint.push_back(k);
                        break;
                    }
                }
            }
//            cout << toPrint.size();
            for(int c=0; c < d; c++){
                cout << toPrint[c];
            }
            cout << endl;
        }
    }while(d);

}
