#include<bits/stdc++.h>
#include<iostream>
#include<map>
#include<vector>
#include<climits>
#include<queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
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
#define Check "Check "
#define vpll vector<pair<ll,ll>>


//time complexity O(n*(2^n))
vector<llv>Subset_Gen(llv& num){
    ll n=num.size();
    ll sub_cnt= (1<<n);
    vector<llv>subset;
    for(ll mask=0;mask<=sub_cnt;mask++){
        llv subs;
        for(int i=0;i<n;i++){
            if(mask&(1<<i)){//checks if the i bit is on
                subs.pb(num[i]);
            }
        }
        subset.pb(subs);
    }
    return subset;
}


void solve(){
    ll n;
    cin>>n;
    llv arr(n);
    for(auto &x:arr){cin>>x;}
    vector<llv>sub=Subset_Gen(arr);
    for(auto x:sub){
        for(auto z:x){
            cout<<z<<spc;
        }
        cout<<endl;
    }
    


}







int main(){
    //EDA_PARI_NA_BHAI
    
   ll t=1;
   
  //cin>>t;
   int test=1;
   
   while(t--){
    //cout<<"Case "<<test++<<": ";
    solve();
    
   }

}