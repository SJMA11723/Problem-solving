#include<iostream>
#include<vector>
#define pb push_back

using namespace std;

class Wave{
    public:
    int ini;
    int fin;
    int h;
     Wave(int ini,int fin,int h){
        this->ini = ini;
        this->fin = fin;
        this->h = h;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, w;
    cin>>n>>w;

    vector<Wave> waves;

    while(n--){

        char c;
        cin>>c;

        if(c == '!'){
            //update

            int ini, l, h;
            cin>>ini>>l>>h;
            waves.pb(Wave(ini, ini+l-1, h));
        }
        else{
            int eval;
            cin>>eval;
            long long ans = 0;
            for(auto wave : waves){
                if(eval >= wave.ini && eval <= wave.fin){
                    
                    if(wave.ini % 2 == 0){
                       // printf("p\n");
                        //inipar
                        if(eval%2 == 1){
                            //printf("plus 0\n");
                            ans+=0;
                        }
                        else{
                            if((eval - wave.ini) % 4 == 0){
                                //printf("plus +h\n");
                                ans+=wave.h;
                            }
                            else{
                                ans-=wave.h;
                                //printf("plus -h\n");
                            }
                        }
                    }
                    else{
                        //ini es impar
                        if(eval%2 == 0){
                            //eval es par

                            //printf("plus 0\n");
                            ans+=0;
                        }
                        else{
                            if((eval - wave.ini) % 4 == 0){
                                //printf("plus +h\n");
                                ans+=wave.h;
                            }
                            else{
                                ans-=wave.h;
                                //printf("plus -h\n");
                            }
                        }
                    }
                }
            }

            cout<<ans<<"\n";


        }
    }
}