#include <bits/stdc++.h>

using namespace std;

template<class TPriority, class TKey> class UpdatableHeap{
public:
    UpdatableHeap(){
        TPriority a;
        TKey b;
        nodes.clear();
        nodes.push_back( make_pair(a, b) );
    }

    pair<TPriority, TKey> top() {
        return nodes[1];
    }

    void pop(){
        if(nodes.size() == 1) return;
        TKey k = nodes[1].second;
        swapNodes(1, nodes.size() - 1);

        nodes.pop_back();
        position.erase(k);

        heapify(1);
    }

    void insertOrUpdate(const TPriority &p, const TKey &k){
        int pos;

        if(isInserted(k)){
            pos = position[k];
            nodes[pos].first += p;
        } else {
            position[k] = pos = nodes.size();
            nodes.push_back( make_pair(p, k) );
        }

        heapify(pos);
    }

    bool isInserted(const TKey &k) {
        return position.count(k);
    }

    int getSize() {
        return (int)nodes.size() - 1;
    }

    void erase(const TKey &k){
        if(!isInserted(k)) return;

        int pos = position[k];
        swapNodes(pos, nodes.size() - 1);

        nodes.pop_back();
        position.erase(k);

        heapify(pos);
    }

private:
    vector<pair<TPriority, TKey>> nodes;
    map<TKey, int> position;

    bool mayor(pair<TPriority, TKey> &a, pair<TPriority, TKey> &b){
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }

    void heapify(int pos){
        if(pos >= nodes.size()) return;

        while(1 < pos && !mayor(nodes[pos / 2], nodes[pos])){
            swapNodes(pos / 2, pos);
            pos /= 2;
        }

        int l = pos * 2,
            r = pos * 2 + 1,
            maxi = pos;
        if(l < nodes.size() && mayor(nodes[l], nodes[maxi]))
            maxi = l;
        if(r < nodes.size() && mayor(nodes[r], nodes[maxi]))
            maxi = r;
        if(maxi != pos){
            swapNodes(pos, maxi);
            heapify(maxi);
        }
    }

    void swapNodes(int a, int b){
        position[ nodes[a].second ] = b;
        position[ nodes[b].second ] = a;
        swap(nodes[a], nodes[b]);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    UpdatableHeap<int64_t, string> heap;

    int n, a; cin >> n >> a;
    for(int i = 0; i < n; ++i){
        string name;
        int64_t salary;
        cin >> name >> salary;
        heap.insertOrUpdate(salary, name);
    }

    while(a--){
        int t; cin >> t;
        if(t == 1){
            string name;
            int64_t salary;
            cin >> name >> salary;
            heap.insertOrUpdate(salary, name);
        } else {
            auto [salary, name] = heap.top();
            cout << name << ' ' << salary << '\n';
            heap.pop();
        }
    }
}
