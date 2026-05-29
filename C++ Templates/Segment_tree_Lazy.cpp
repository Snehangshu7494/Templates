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

//LAZY SEGMENT TREE WITH RANGE ASSIGN AND RANGE ADD(MAX, MIN, SUM):




struct Node {
    long long sum;
    int mn, mx;
    Node(long long _sum = 0, int _mn = INT_MAX, int _mx = INT_MIN)
        : sum(_sum), mn(_mn), mx(_mx) {}
};

struct SegTree {
    int n;
    vector<Node> tree;
    vector<long long> lazyAdd;
    vector<long long> lazyAssign;
    vector<bool> hasAssign;

    SegTree(int _n) : n(_n) {
        tree.resize(4 * n + 5);
        lazyAdd.assign(4 * n + 5, 0);
        lazyAssign.assign(4 * n + 5, 0);
        hasAssign.assign(4 * n + 5, false);
    }

    SegTree(const vector<int> &a) {
        n = a.size();
        tree.resize(4 * n + 5);
        lazyAdd.assign(4 * n + 5, 0);
        lazyAssign.assign(4 * n + 5, 0);
        hasAssign.assign(4 * n + 5, false);
        build(1, 0, n - 1, a);
    }

    // --------- MERGE FUNCTION (Change this to modify tree behavior) ----------
    Node merge(const Node &left, const Node &right) {
        Node res;
        res.sum = left.sum + right.sum;
        res.mn = min(left.mn, right.mn);
        res.mx = max(left.mx, right.mx);
        return res;
    }

    // --------------------- BUILD ---------------------
    void build(int node, int l, int r, const vector<int> &a) {
        if (l == r) {
            tree[node] = Node(a[l], a[l], a[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(node * 2, l, mid, a);
        build(node * 2 + 1, mid + 1, r, a);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    // --------------------- APPLY ASSIGN ---------------------
    void applyAssign(int node, int l, int r, long long val) {
        tree[node].sum = val * (r - l + 1);
        tree[node].mn = val;
        tree[node].mx = val;
        lazyAssign[node] = val;
        hasAssign[node] = true;
        lazyAdd[node] = 0; // clear pending adds since assign overrides them
    }

    // --------------------- APPLY ADD ---------------------
    void applyAdd(int node, int l, int r, long long val) {
        tree[node].sum += val * (r - l + 1);
        tree[node].mn += val;
        tree[node].mx += val;
        if (hasAssign[node])
            lazyAssign[node] += val; // add over assign
        else
            lazyAdd[node] += val;
    }

    // --------------------- PUSH DOWN ---------------------
    void pushDown(int node, int l, int r) {
        int mid = (l + r) / 2;
        int left = node * 2, right = node * 2 + 1;

        if (hasAssign[node]) {
            applyAssign(left, l, mid, lazyAssign[node]);
            applyAssign(right, mid + 1, r, lazyAssign[node]);
            hasAssign[node] = false;
        }

        if (lazyAdd[node] != 0) {
            applyAdd(left, l, mid, lazyAdd[node]);
            applyAdd(right, mid + 1, r, lazyAdd[node]);
            lazyAdd[node] = 0;
        }
    }

    // --------------------- RANGE ASSIGN ---------------------
    void rangeAssign(int node, int l, int r, int ql, int qr, long long val) {
        if (qr < l || ql > r) return;
        if (ql <= l && r <= qr) {
            applyAssign(node, l, r, val);
            return;
        }
        pushDown(node, l, r);
        int mid = (l + r) / 2;
        rangeAssign(node * 2, l, mid, ql, qr, val);
        rangeAssign(node * 2 + 1, mid + 1, r, ql, qr, val);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void rangeAssign(int l, int r, long long val) {
        rangeAssign(1, 0, n - 1, l, r, val);
    }

    // --------------------- RANGE ADD ---------------------
    void rangeAdd(int node, int l, int r, int ql, int qr, long long val) {
        if (qr < l || ql > r) return;
        if (ql <= l && r <= qr) {
            applyAdd(node, l, r, val);
            return;
        }
        pushDown(node, l, r);
        int mid = (l + r) / 2;
        rangeAdd(node * 2, l, mid, ql, qr, val);
        rangeAdd(node * 2 + 1, mid + 1, r, ql, qr, val);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void rangeAdd(int l, int r, long long val) {
        rangeAdd(1, 0, n - 1, l, r, val);
    }

    // --------------------- RANGE QUERY ---------------------
    Node query(int node, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return Node(0, INT_MAX, INT_MIN);
        if (ql <= l && r <= qr) return tree[node];
        pushDown(node, l, r);
        int mid = (l + r) / 2;
        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);
        return merge(left, right);
    }

    Node query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
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
