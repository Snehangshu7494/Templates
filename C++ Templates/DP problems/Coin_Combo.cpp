
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

//ll cons[200005];
   
// ll coin(ll num,vector<int>& arr) {
//     if(num==0){return cons[num]= 1;}
//     if(num<0){return 0;}
//     if(cons[num]!=-1){return cons[num];}
//     ll ways=0;
//     for(auto x:arr){
//         //ll ans1=coin(num-x,arr)+1;
//         //ans=min(ans,ans1);
//         ways+=coin(num-x,arr);
//     }
//     cout<<num<<spc<<ways<<endl;
//     return cons[num]=ways;
// }
ll cons1[305][5005]; 
ll coin1(ll idx,ll num,vector<int>& arr) {
    
    if(num==0){return cons1[idx][num]= 1;}
    if(idx<0){return 0;}
    if(num<0){return 0;}
    if(cons1[idx][num]!=-1){return cons1[idx][num];}
    ll ways=0;
    for(ll c_amount=0;c_amount<=num;c_amount+=arr[idx]){
        ways+=coin1(idx-1,num-c_amount,arr);
    }
    return cons1[idx][num]=ways;
}
int change(int amount, vector<int>& coins) {
    memset(cons1,-1,sizeof(cons1));
    return coin1(coins.size()-1,amount,coins); 
}

void solve() {
    vector<int> coins={1,2,5};
    int amount =5;
    cout<<change(amount,coins)<<endl;

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