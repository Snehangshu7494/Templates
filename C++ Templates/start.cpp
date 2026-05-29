#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace std;
//#include<conio.h>
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
#define pll pair<ll,ll>
#define bitcnt(x) __builtin_popcountll(x)
#define Check "Check "
#define trav(m,a) for(auto m:a){cout<<m<<" ";}cout<<"\n";
#define travP(m,a) for(auto m:a){cout<<m.first<<" "<<m.second<<"\n";}cout<<"\n";
#define vpll vector<pair<ll,ll>>
#define print(a) cout<<a<<"\n"
#define MAX 9000000000000000000
#define MIN -9000000000000000000

// ================= Ordered Set Template ==================
// Standard ordered set (no duplicates)
template<typename T, typename Compare = less<T>>
using ordered_set = tree<
    T,
    null_type,
    Compare,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

// ================= Ordered Multiset Template ==============
// Trick to allow duplicates: store pair<value, index>
// Index ensures uniqueness
template<typename T>
struct ordered_multiset {
    int idx = 0;
    using pair_t = pair<T,int>;
    tree<pair_t, null_type, less<pair_t>, rb_tree_tag, tree_order_statistics_node_update> os;

    void insert(T x) { os.insert({x, idx++}); }
    void erase(T x) {
        auto it = os.lower_bound({x, 0});
        if(it != os.end() && it->first == x) os.erase(it);
    }
    int size() { return os.size(); }
    T find_by_order(int k) { return os.find_by_order(k)->first; }
    int order_of_key(T x) { return os.order_of_key({x, 0}); }
};

void sample(){
    // ---------- Ordered Set ----------
    ordered_set<int> os;
    os.insert(5);
    os.insert(1);
    os.insert(10);

    cout << "Ordered Set size: " << os.size() << "\n";
    cout << "0-th element: " << *os.find_by_order(0) << "\n"; // 1
    cout << "Elements < 7: " << os.order_of_key(7) << "\n";  // 2

    // ---------- Ordered Multiset ----------
    ordered_multiset<int> oms;
    oms.insert(5);
    oms.insert(1);
    oms.insert(5); // duplicate allowed

    cout << "Ordered Multiset size: " << oms.size() << "\n"; // 3
    cout << "0-th element: " << oms.find_by_order(0) << "\n"; // 1
    cout << "Elements < 5: " << oms.order_of_key(5) << "\n"; // 1

    oms.erase(5); // removes one occurrence
    cout << "Size after erase 5: " << oms.size() << "\n";   // 2

    // ---------- Custom comparator example ----------
    // Descending ordered set
    ordered_set<int, greater<int>> os_desc;
    os_desc.insert(2);
    os_desc.insert(8);
    cout << "Descending 0-th: " << *os_desc.find_by_order(0) << "\n"; // 8

}

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
