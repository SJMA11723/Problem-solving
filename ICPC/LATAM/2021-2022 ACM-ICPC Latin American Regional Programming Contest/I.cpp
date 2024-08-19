#include <bits\stdc++.h>
#define MUCHO 100005

using namespace std;

string day;
int today;
int n;
int act;
int actDate;
int mini=50;
//int inversion[MUCHO];
string dayToInt[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
int timeTillMonday[] = {91, 62, 61, 32, 31};

int simula(int howLongAgo, int date){
    while(howLongAgo > 0){
        howLongAgo-=30;
        date+=2;
        date%=7;
        if(date >= 5){
            howLongAgo-=7-date;
            date = 0;
        }
    }
    return howLongAgo*-1;
}

void getToMonday(int howLongAgo, int date){
    howLongAgo-=timeTillMonday[date];
    howLongAgo%=91;
    actDate = 0;
    act = howLongAgo;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> day >> n;
    for(int c=0; c < 7; c++){
        if(day == dayToInt[c])
            today = c;
    }
    for(int c =0; c < n; c++){
        //cin >> inversion[c];
        cin >> act;
        actDate = (today-(act%7)+7)%7;
        if(act == 0){
            int aux = 30;
            if(actDate+2 >= 5)
                aux+=7-(actDate+2);
            mini = min(mini, aux);
            continue;
        }
        if(act > 91){
            getToMonday(act, actDate);
        }
        mini = min(simula(act, actDate), mini);
        //solo falta un ciclo para ver que onda
    }
    cout << mini << endl;
}
