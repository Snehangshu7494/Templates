//https://codeforces.com/contest/2027/problem/B
#include<bits/stdc++.h>
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
#define vpll vector<pair<ll,ll>>
#define valset(arr,val) memset(arr,val,sizeof(arr));


llv countNextGreater(const llv& nums) {
    int n = nums.size();
    llv result(n);
    multiset<ll> seen;

    for (int i = n - 1; i >= 0; --i) {
        // Count elements strictly greater than nums[i]
        auto it = seen.upper_bound(nums[i]);
        result[i] = distance(it, seen.end());
        seen.insert(nums[i]);
    }

    return result;
}

void solve(){
    
    ll n;cin>>n;
    llv arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    llv great=countNextGreater(arr);
    llv rem(n);
    for(int i=0;i<n;i++){
        rem[i]=i+great[i];
    }
    ll ans=*min_element(all(rem));
    cout<<ans<<endl;
    



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