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
#define INF LONG_MAX
#define NINF INT_MIN
#define bitcnt(x) __builtin_popcountll(x)
#define Check "Check "
#define trav(m,a) for(auto m:a){cout<<m<<" ";}cout<<"\n";
#define travP(m,a) for(auto m:a){cout<<m.first<<" "<<m.second<<"\n";}cout<<"\n";
#define vpll vector<pair<ll,ll>>

bool val(pair<ll,ll>&a,pair<ll,ll>&b,pair<ll,ll>&c){
    ll area = (b.F - a.F) * (c.S - a.S) - (c.F - a.F) * (b.S - a.S);
    return (area != 0);  
}


void solve(){
    ll ans=0;
    ll n;
    cin>>n;
    vpll arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].F>>arr[i].S;
    }
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                //cout<<"CHECK "<<i<<spc<<j<<spc<<k<<endl;
                if(val(arr[i],arr[j],arr[k])){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
}

int main(){
    EDA_PARI_NA_BHAI;
    int t=1;
    //cin >> t;
    while(t--){
        solve();
    }
}