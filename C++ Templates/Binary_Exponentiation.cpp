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

//3^13=3^(8+4+0+1) 13s binary representation
//3^8*3^4*3^1
const ll M=1e18+7;
ll Bin_Exp(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1){//checks if 0th bit is 1
            ans=(ans*a)%M;//%M if modulo is needed
        }
        a=(a*a)%M;//%M if modulo is needed  //increasing power
        b/=2;//just doing right shift
    }
    return ans;
}

ll Bin_Mult(ll a,ll b){
    ll ans=0;
    while(b){
        if(b&1){//checks if 0th bit is 1
            ans=(ans+a)%M;
             //%M  modulo is needed
        }
        a=(a+a)%M;//%M if modulo is needed  //increasing power
        
        b/=2;//just doing right shift
    }
    return ans;    
}

//if M=1e18 or so
ll LLM_Bin_Exp(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1){//checks if 0th bit is 1
            ans=Bin_Mult(ans,a);//%M is done in function
        }
        a=Bin_Mult(a,a);//%M is done   //increasing power
        b/=2;//just doing right shift
    }
    return ans;
}
// if (a^b)%M here b is extremely large then
// (a^b)%M = ( a^(b% (M-1) ) )%M
///(a^-1)%M=(a^M-2)%M

void solve(){
    cout<<LLM_Bin_Exp(3,13)<<endl;
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