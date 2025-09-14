#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    string s; cin >> s;

    int n = s.size();
    bool todoIgual = true;
    vector<int64_t> raices;
    for( int i=0; i<s.size()-1; i++ ){
        int64_t id = 1ll*(i+1)*2;

        if( s[i] != s[i+1]  ) raices.push_back( id+1);
        if( s[i] != s[i+1]  ) todoIgual = false;
    }

//    for( int x: raices ) cout << x << ' ';
//    cout << '\n';

    if( todoIgual ){
        if( s[0] == 'H' ) cout << "0\n1\n";
        else cout <<" 0\n-1\n";

//        while(true);
        return  0;
    }

    vector<int64_t> cof;


    //par empeiza positivo
    if( raices.size() %2==0   ){
        // x -r //HUMANO
        if( s[0] == 'H' ){
            cof.push_back(1);
            cof.push_back( -1*raices[0] );
        }
        // -(x-r) //ALINE: multiplciar por -1 para que empeize negaitvo
        else{
            cof.push_back(-1);
            cof.push_back( raices[0] );
        }
    }
    //impar empeiza negativo
    else{
        // (x -r) ALIEN
        if( s[0] == 'A' ){
            cof.push_back(1);
            cof.push_back( -1*raices[0] );
        }
        // -(x-r) HUMANO: multiplicar por -1 para uqe empoeize psoitvo
        else{
            cof.push_back(-1);
            cof.push_back( raices[0] );
        }
    }


//    cout <<"coeficeintes\n";
//     for( int i=0; i<cof.size(); i++ )
//        cout << cof[i] << " \n"[i == cof.size()-1];

    //por cada binomio multiplicar
    for( int i=1; i< raices.size(); i++ ){
        //mutilplicar por (x + r)

        int64_t r = -raices[i];
        cof.push_back(0);

        int64_t anterior = cof[0];
        for( int i=1; i<cof.size(); i++ ){
            int64_t tmp=cof[i];
            cof[i]+= r*anterior;
            anterior = tmp;

        }

//         for( int i=0; i<cof.size(); i++ )
//                cout << cof[i] << " \n"[i == cof.size()-1];

    }

    cout << cof.size()-1 << '\n';

     for( int i=0; i<cof.size(); i++ )
        cout << cof[i] << " \n"[i == cof.size()-1];


}

