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

//const ll N=1e5+10;
//Time complexity O(V+E)
ll ans=0;
ll f=0;
void DFS(llv graph[],llv& visited,ll vertex,ll parent){

    //take action on vertex after entering it
    //if(visited[vertex]){return;} 
    //this line can be written if not used in the loop
    if(f){return;}
    visited[vertex]++;
    for(auto child:graph[vertex]){
        if(f){return;}
        //take action on child before entering it
        if(visited[child] && child!=parent){ans++;f=1;return;}
        if(child==parent){continue;}
        DFS(graph,visited,child,vertex);
        if(f){return;}
        //take action on child after exiting it

    }

    //take action on vertex before exiting it

}


void solve(){
    ll n,m;
    cin>>n>>m;
    llv graph1[n+5];
    llv visited(n+5);
    ans=0;
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        graph1[x].pb(y);
        graph1[y].pb(x);
    }
    
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            f=0;
            DFS(graph1,visited,i,0);
            
            
        }
    }
    cout<<ans<<endl;

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