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


//time complexity O(2^n)
vector<llv>subsets;
void Subset_Gen(llv& subset,ll i,llv& num){
    
    if(i==num.size()){
        subsets.pb(subset);
        return;
    }
    // i not in subset
    Subset_Gen(subset,i+1,num);

    // i in subset
    subset.pb(num[i]);
    Subset_Gen(subset,i+1,num);
    subset.pop_back();
}


void solve(){
    ll n;
    cin>>n;
    llv arr(n);
    for(auto &x:arr){cin>>x;}
    llv subset;
    Subset_Gen(subset,0,arr);
    for(auto x:subsets){
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