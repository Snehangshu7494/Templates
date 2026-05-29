
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

string LCS(string &s, string &t) {
    ll n = s.size(), m = t.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));

    // Build DP table
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Trace back to find the actual LCS string
    ll i = n, j = m;
    string ans = "";
    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            ans += s[i - 1];
            i--; j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

string dp[3005][3005],s,t;
string ans="";
string fun(ll idx1,ll idx2){
    if(idx1<0 || idx2<0){
        return "";
    }
    if(dp[idx1][idx2]!="1"){return dp[idx1][idx2]; }
    string a="",ss1="",ss2="",ss3="",ss4="";

    if(s[idx1]==t[idx2]){
        //a+=s[idx1];
        ss1=fun(idx1-1,idx2-1)+s[idx1];
        //if(ans.size()<ss.size()){ans=ss;}
    }
    else{
        ss2=fun(idx1-1,idx2-1);
        ss3=fun(idx1-1,idx2);
        ss4=fun(idx1,idx2-1);
    }
    if(a.size()<=ss1.size() && ss1.size()>=ss2.size() && ss1.size()>=ss3.size() && ss1.size()>=ss4.size()){
        a=ss1;
    }
    else if(a.size()<=ss2.size() && ss1.size()<=ss2.size() && ss2.size()>=ss3.size() && ss2.size()>=ss4.size()){
        a=ss2;
    }
    else if(a.size()<=ss2.size() && ss3.size()>=ss2.size() && ss1.size()<=ss3.size() && ss3.size()>=ss4.size()){
        a=ss3;
    }
    else if(a.size()<=ss2.size() && ss4.size()>=ss1.size() && ss2.size()<=ss4.size() && ss3.size()<=ss4.size()){
        a=ss4;
    }

    //if(a!=""){cout<<a<<endl;}
    //if(ans.size()<a.size()){ans=a;}
    return dp[idx1][idx2]=a;

}


void solve(){
    cin>>s>>t;
    for(int i=0;i<=s.size();i++){
        for(int j=0;j<=t.size();j++){
            dp[i][j]="1";
        }
    }
    //memset(dp,0,sizeof(dp));
    
    cout<<LCS(s,t)<<endl;
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