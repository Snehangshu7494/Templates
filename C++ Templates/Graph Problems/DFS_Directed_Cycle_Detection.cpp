//https://codeforces.com/contest/1931/problem/F

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

ll f=0;
ll acvi[200005];
ll ans[200005];
void DFS(vector<set<ll>>&graph,llv& visited,ll vertex){

    //take action on vertex after entering it
    //if(visited[vertex]){return;} 
    //this line can be written if not used in the loop
    if(acvi[vertex]){return;}
    visited[vertex]++;
    
    acvi[vertex]++;
    
    for(auto child:graph[vertex]){
        
        //take action on child before entering it
        if(visited[child] ){f=1;return;}
        
        DFS(graph,visited,child);
        
        //take action on child after exiting it

    }
    visited[vertex]--;

    //take action on vertex before exiting it

}


void solve(){
    valset(acvi,0);
    valset(ans,-1);
    ll n,k;
    cin>>n>>k;
    vector<set<ll>>graph(n+5);
    ll pre=-1;
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            ll x;
            cin>>x;
            if(j>1){graph[pre].insert(x);}
            pre=x;
        }
    }
    llv visited(n+5);
    f=0;
    
    //DFS(graph,visited,1);
    for(int i=1;i<=n;i++){
        if(!acvi[i] && !f){
            llv visited2(n+5);
            //cout<<i<<endl;
            //for(int i=0;i<n+5;i++){visited[i]=0;}
            DFS(graph,visited2,i);
            ans[i]=f;
        }
    }
    //for(int i=0;i<n+5;i++){visited[i]=0;}

    if(f){no;}
    else{yes;}


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