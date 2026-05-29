//https://leetcode.com/problems/longest-increasing-subsequence/description/
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
#define vpll vector<pair<ll,ll>>

ll seq[200005];
    
ll jump(vector<int> &arr, ll id) {
    if(seq[id] != -1) return seq[id];
    ll ans = 1;
    for(int i = 0; i < id; i++) {
        if(arr[i] < arr[id]) {
            ll ans1 = jump(arr, i) + 1;
            ans = max(ans, ans1);
        }
    }
    return seq[id] = ans;
}

int lengthOfLIS(vector<int>& nums) {
    vector<int> arr = nums;
    ll n = arr.size();
    memset(seq, -1, sizeof(seq));
    for(int i = 0; i < n; i++) {
        jump(arr, i);
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, seq[i]);
    }
    return ans;
}
void solve() {




}







int main(){
    EDA_PARI_NA_BHAI
    
   ll t=1;
   
    //cin>>t;
   int test=1;
   
   while(t--){
    //cout<<"Case "<<test++<<": ";
    solve();
    
   }

}