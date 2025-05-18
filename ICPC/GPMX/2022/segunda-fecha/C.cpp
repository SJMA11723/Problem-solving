#include <bits/stdc++.h>

using namespace std;

struct student{
    int id;
    set<int> req;

    const bool operator<(const student &b) const {
        return id < b.id;
    }
};

struct studentAns{
    int id;
    vector<pair<int, char>> req;

    const bool operator<(const studentAns &b) const {
        return id < b.id;
    }
};

int n, m;
vector<student> arr, arr2;
vector<studentAns> ans;

int binId(int x, vector<student> &vec){
    int ini = 0;
    int fin = vec.size();
    while(ini < fin){
        int mitad = (ini + fin) / 2;
        if(vec[mitad].id < x) ini = mitad + 1;
        else fin = mitad;
    }

    if(ini < vec.size() && vec[ini].id == x) return ini;
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        int id, b;
        cin >> id >> b;
        student st;
        st.id = id;
        while(b--){
            int x; cin >> x;
            st.req.insert(x);
        }
        arr.push_back(st);
    }

    for(int i = 0; i < m; ++i){
        int id, b;
        cin >> id >> b;
        student st;
        st.id = id;
        while(b--){
            int x; cin >> x;
            st.req.insert(x);
        }
        arr2.push_back(st);
    }

    sort(arr.begin(), arr.end());
    sort(arr2.begin(), arr2.end());

    for(int i = 0; i < n; ++i){
        int id = arr[i].id;
        int posId = binId(id, arr2);

        ///Si no esta
        if(posId == -1){
            studentAns st;
            st.id = id;
            for(int it : arr[i].req){
                st.req.push_back({it, '+'});
            }
            sort(st.req.begin(), st.req.end());
            ans.push_back(st);
            continue;
        }

        ///Creo interseccion
        set<int> inter;
        for(int it : arr[i].req){
            if(arr2[posId].req.count(it))
                inter.insert(it);
        }

        /// Quito interseccion
        for(int it : inter){
            arr[i].req.erase(it);
            arr2[posId].req.erase(it);
        }

        ///Si todo OK
        if(arr[i].req.size() == 0 && arr2[posId].req.size() == 0)
            continue;

        ///union del complemento de la interseccion
        studentAns st;
        st.id = id;
        for(int it : arr[i].req){
            st.req.push_back({it, '+'});
        }

        for(int it : arr2[posId].req){
            st.req.push_back({it, '-'});
        }

        sort(st.req.begin(), st.req.end());
        ans.push_back(st);
    }

    for(int i = 0; i < m; ++i){
        int id = arr2[i].id;
        int posId = binId(id, arr);

        if(posId != -1) continue;

        studentAns st;
        st.id = id;
        for(int it : arr2[i].req){
            st.req.push_back({it, '-'});
        }
        sort(st.req.begin(), st.req.end());
        ans.push_back(st);
    }

    sort(ans.begin(), ans.end());

    int missed = 0, notreq = 0;
    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i].id << ' ';
        for(int j = 0; j < ans[i].req.size(); ++j){
            auto it = ans[i].req[j];
            cout << it.second << it.first;

            if(it.second == '+') missed++;
            else notreq++;

            if(j < ans[i].req.size() - 1) cout << ' ';
        }
        cout << '\n';
    }

    if(ans.size() == 0){
        cout << "GREAT WORK! NO MISTAKES FOUND!\n";
    } else {
        cout << "MISTAKES IN " << ans.size() << " STUDENTS: " << notreq << " NOT REQUESTED, " << missed << " MISSED\n";
    }

}