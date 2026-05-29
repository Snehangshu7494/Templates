//Question Link:
//Three Musketeers
//https://www.hackerearth.com/problem/algorithm/the-three-musketeers-6efd5f2d/

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

llv NGE(llv& arr){
    
    ll n=arr.size();
    llv ans(n);
    stack<ll>st;
    map<ll,ll>mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]=i;
        while(!st.empty()){
            ll fr=st.top();
            if(arr[i]>fr){
                ans[mp[fr]]=arr[i];
                st.pop();
            }
            else{
                break;
            }
        }
        st.push(arr[i]);
    }
    while(!st.empty()){
        ll fr=st.top();
    
        ans[mp[fr]]=-1;
        st.pop();
    
    }
    return ans;

}

void solve(){
    llv arr={4,5,2,25,7,8};
    llv ans=NGE(arr);
    for(auto x:ans){cout<<x<<spc;}cout<<endl;
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