#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef vector<vector<int>> vvi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()
#define INF 10000000
#define lsb(S) ((S) & -(S))
#define DEBUG if (debb)
#define NO 10000000

bool debb = false;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.fi << ", " << p.se << ')'; }
template <typename C, typename T = typename enable_if<!is_same<C, string>::value, typename C::value_type>::type>
ostream &operator<<(ostream &os, const C &v)
{
    string sep;
    for (const T &xx : v)
        os << sep << xx, sep = " ";
    return os;
}
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args>
void logger(string vars, Args &&...values)
{
    cout << "[Debug]\n\t" << vars << " = ";
    string d = "[";
    (..., (cout << d << values, d = "] ["));
    cout << "]\n";
}

long long pow(int x, int n)
{
    long long ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans *= x;
    }
    return ans;
}
int main()
{
    if (!debb)
        ios_base::sync_with_stdio(false);
    if (!debb)
        cin.tie(0);
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int x = 0; x < n; x++)
        cin >> arr[x];

    int difff[n + 1];
    for (int x = 1; x < n; x++)
        difff[x] = arr[x] - arr[x - 1];

    int ll = 0;
    int rr = 1;
    int prev = difff[1];
    difff[n] = 10000000;
    pair<int, int> sp[n], ep[n];
    bool cs[n], ce[n];
    for (int x = 0; x < n; x++)
        cs[x] = ce[x] = false;
    vector<pair<pair<int, int>, int>> segs;
    for (int x = 1; x <= n; x++)
    {
        if (prev != difff[x])
        {
            segs.push_back({{ll, rr}, prev});
            cs[ll] = true;
            ce[rr] = true;
            sp[ll] = {rr, prev};
            ep[rr] = {ll, -prev};
            ll = rr;
            rr = x;
            prev = difff[x];
        }
        else
        {
            rr = x;
        }
    }

    int minerr = NO;
    int idx = -1;
    DEBUG deb(segs);
    for (int x = 0; x < segs.size(); x++)
    {
        auto [seg, diff] = segs[x];
        auto [l, r] = seg;
        int e = 0;
        int nxt = arr[l];
        bool flag = true;
        for (int i = l; i < n; i++)
        {
            DEBUG deb("f", i, e, nxt);
            if (arr[i] != nxt)
                e++;
            else
            {
                if (cs[i] && sp[i].second == diff)
                    i = sp[i].first;
                nxt = arr[i] + diff;
            }
            if (e > k)
            {
                flag = false;
                break;
            }
        }
        DEBUG deb("fh", seg, diff, e);
        if (!flag)
            continue;
        flag = true;

        // reverse
        diff = -diff;
        nxt = arr[r];

        for (int i = r; i >= 0; i--)
        {
            DEBUG deb("s", i, e, nxt, diff);
            if (arr[i] != nxt)
                e++;
            else
            {
                if (ce[i] && ep[i].second == diff)
                    i = ep[i].first;
                nxt = arr[i] + diff;
            }
            if (e > k)
            {
                flag = false;
                break;
            }
        }
        DEBUG deb("sh", seg, diff, e);
        if (!flag)
            continue;

        if (e < minerr)
        {
            minerr = e;
            idx = x;
        }
    }
    if (minerr == NO)
    {
        cout << "-1\n";
        return 0;
    }
    cout << minerr << "\n";

    //rebuild
    vector<int> ans;
    auto [seg, diff] = segs[idx];
    auto [l, r] = seg;
    int e = 0;
    int nxt = arr[l];
    bool flag = true;
    for (int i = l; i < n; i++)
    {
        if (arr[i] != nxt){
            e++;
            ans.push_back(i+1);
        }
        else
        {
            if (cs[i] && sp[i].second == diff)
            i = sp[i].first;
            nxt = arr[i] + diff;
        }
        if (e > k)
        {
            flag = false;
            break;
        }
    }
    DEBUG deb("fh", seg, diff, e);
    flag = true;
    // reverse
    diff = -diff;
    nxt = arr[r];
    for (int i = r; i >= 0; i--)
    {
        if (arr[i] != nxt){
            e++;
            ans.push_back(i+1);
        }
        else
        {
            if (ce[i] && ep[i].second == diff)i = ep[i].first;
            nxt = arr[i] + diff;
        }
        if (e > k)
        {
            flag = false;
            break;
        }
    }

    sort(ans.begin(), ans.end());

    for(auto x: ans){
        cout<<x<<" ";
    }
    cout<<"\n";
}