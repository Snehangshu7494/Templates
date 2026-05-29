#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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

// =================== Example Usage ======================
int main() {
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

    return 0;
}
