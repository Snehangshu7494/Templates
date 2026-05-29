#include<bits/stdc++.h>
//#include<conio.h>
using namespace std;
#define EDA_PARI_NA_BHAI  { ios_base::sync_with_stdio(false); cin.tie(0); }
#define ll long long
#define lf double
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define endl "\n"
#define llv vector<ll>
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()
#define pdis(n) fixed<<setprecision(n)
#define spc " "
#define INF INT_MAX
#define NINF INT_MIN
#define bitcnt(x) __builtin_popcountll(x)
#define Check "Check "
#define trav(m,a) for(auto m:a){cout<<m<<" ";}cout<<"\n";
#define travP(m,a) for(auto m:a){cout<<m.first<<" "<<m.second<<"\n";}cout<<"\n";
#define vpll vector<pair<ll,ll>>

//POINT ASSIGN (SUM, MIN, MX, XOR):


struct Node
{
    long long sum;
    int mn, mx, xr;

    Node(long long s = 0, int mi = INT_MAX, int ma = INT_MIN, int x = 0)
        : sum(s), mn(mi), mx(ma), xr(x) {}
};

struct SegTree
{
    int n;
    vector<Node> tree;

    SegTree(const vector<int> &arr)
    {
        n = arr.size();
        tree.assign(4 * n, Node());
        build(arr, 1, 0, n - 1);
    }

    Node merge(const Node &a, const Node &b)
    {
        Node res;
        res.sum = a.sum + b.sum;
        res.mn = min(a.mn, b.mn);
        res.mx = max(a.mx, b.mx);
        res.xr = a.xr ^ b.xr;
        return res;
    }

    void build(const vector<int> &arr, int idx, int l, int r)
    {
        if (l == r)
        {
            int v = arr[l];
            tree[idx] = Node(v, v, v, v);
            return;
        }
        int mid = (l + r) >> 1;
        build(arr, idx << 1, l, mid);
        build(arr, idx << 1 | 1, mid + 1, r);
        tree[idx] = merge(tree[idx << 1], tree[idx << 1 | 1]);
    }

    void assign(int idx, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            tree[idx] = Node(val, val, val, val);
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            assign(idx << 1, l, mid, pos, val);
        else
            assign(idx << 1 | 1, mid + 1, r, pos, val);
        tree[idx] = merge(tree[idx << 1], tree[idx << 1 | 1]);
    }

    void assign(int pos, int val) { assign(1, 0, n - 1, pos, val); }

    Node query(int idx, int l, int r, int ql, int qr)
    {
        if (qr < l || r < ql)
            return Node(0, INT_MAX, INT_MIN, 0);
        if (ql <= l && r <= qr)
            return tree[idx];
        int mid = (l + r) >> 1;
        return merge(query(idx << 1, l, mid, ql, qr),
                     query(idx << 1 | 1, mid + 1, r, ql, qr));
    }

    Node query(int l, int r) { return query(1, 0, n - 1, l, r); }
};






void solve() {
    





}







int main(){
    EDA_PARI_NA_BHAI

   ll t=1;

    cin>>t;
   int test=1;

   while(t--){
    //cout<<"Case "<<test++<<": ";
    solve();

   }

}
