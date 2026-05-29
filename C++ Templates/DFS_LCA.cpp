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
/*
13
1 2
1 3
1 13
2 5
5 6
5 7
5 8
8 12
3 4
4 9
4 10
10 11

*/
//const ll N=1e5+10;
//Time complexity O(V+E)

void DFS(llv graph[],ll vertex,llv& parent,ll par){

    //take action on vertex after entering it
    //if(visited[vertex]){return;} 
    //this line can be written if not used in the loop

    parent[vertex]=par;
    for(auto child:graph[vertex]){ 

        //take action on child before entering it
        if(child==par){continue;}
        DFS(graph,child,parent,vertex);

        //take action on child after exiting it

    }

    //take action on vertex before exiting it

}

llv path(ll vertex,llv& parent){
    llv ans;
    while(vertex!=-1){
        ans.pb(vertex);
        vertex=parent[vertex];
    }
    reverse(all(ans));
    return ans;
}


void solve(){
    ll n,m;
    cin>>n;
    m=n-1;
    llv graph1[n+5];

    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        graph1[x].pb(y);// use vpll if there is weight
        graph1[y].pb(x);


    }
    llv parent(n+5);
    DFS(graph1,1,parent,-1);
    ll v1,v2;
    cin>>v1>>v2;
    llv path1=path(v1,parent);
    llv path2=path(v2,parent);
    ll sz=min(path1.size(),path2.size());
    ll ans=0;
    for(int i=0;i<sz;i++){
        if(path1[i]!=path2[i]){break;}
        else{
            ans=path1[i];
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