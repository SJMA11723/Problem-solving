
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    map<string, int> cards;

    cards["Shadow"] = 6;
    cards["Gale"] = 5;
    cards["Ranger"] = 4;
    cards["Anvil"] = 7;
    cards["Vexia"] = 3;
    cards["Guardian"] = 8;
    cards["Thunderheart"] = 6;
    cards["Frostwhisper"] = 2;
    cards["Voidclaw"] = 3;
    cards["Ironwood"] = 3;
    cards["Zenith"] = 4;
    cards["Seraphina"] = 1;


    int lands[2][3];

    int p1, p2,totalp1,totalp2;
    p1=p2=0;
    totalp1=totalp2=0;
    for(int x = 0; x < 3; x++){

        int n1;

        cin>>n1;
        int power1 = 0;

        for(int i = 0; i < n1; i++){
            string s;
            cin>>s;
            power1+=cards[s];

            if(s == "Seraphina") power1+= (n1-1);
            if(s == "Zenith" && x == 1) power1+=5;
            if(s == "Thunderheart" && n1 == 4) power1+=6;
        }

        totalp1+=power1;


        int n2;
        cin>>n2;
        int power2 = 0;
        for(int i = 0; i < n2; i++){
            string s;
            cin>>s;
            power2+=cards[s];

            if(s == "Seraphina") power2+= (n2-1);
            if(s == "Zenith" && x == 1) power2+=5;
            if(s == "Thunderheart" && n2 == 4) power2+=6;
        }
        totalp2+=power2;

        if(power1 > power2){
            p1++;
        }
        else if(power1 < power2){
            p2++;
        }
    }


    if(p1 > p2){
        cout<<"Player 1\n";
    }
    else if(p1 < p2){
        cout<<"Player 2\n";
    }
    else{
        if(totalp1 > totalp2){
            cout<<"Player 1\n";
        }
        else if(totalp1 < totalp2){
            cout<<"Player 2\n";
        }
        else{
            cout<<"Tie\n";
        }
    }

}
