//https://atcoder.jp/contests/dp/tasks/dp_d
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

ll bag[100005][105];
ll knap(ll W,llv&arr,ll idx,llv& val){
    if(W==0){return 0;}
    if(idx<0){return 0;}
    if(bag[W][idx]!=-1){return bag[W][idx];}
    ll ans1=NINF,ans2=NINF;
    ans1=knap(W,arr,idx-1,val);
    if(W-arr[idx]>=0)ans2=knap(W-arr[idx],arr,idx-1,val)+val[idx];
    return bag[W][idx]=max(ans1,ans2);
}

void solve() {
    memset(bag,-1,sizeof(bag));
    ll n,W;
    cin>>n>>W;
    llv arr(n),val(n);
    for(int i=0;i<n;i++){
        cin>>arr[i]>>val[i];
    }
    cout<<knap(W,arr,n-1,val)<<endl;
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