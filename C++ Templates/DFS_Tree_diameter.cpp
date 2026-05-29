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

const ll N=1e5+10;
//Time complexity O(V+E)
llv height(N),depth(N);
void DFS(llv graph[],ll parent, ll vertex){

    //take action on vertex after entering it
    //if(visited[vertex]){return;} 
    //this line can be written if not used in the loop

    
    for(auto child:graph[vertex]){

        //take action on child before entering it
        if(child==parent){continue;}
        depth[child]=depth[vertex]+1;

        DFS(graph,vertex,child);
        //take action on child after exiting it
        height[vertex]=max(height[vertex],height[child]+1);

        

    }

    //take action on vertex before exiting it

}


void solve(){
    ll n,m;
    cin>>n;
    llv graph1[n+5];
    llv visited(n+5);
    //ll graph2[n][n];
    //valset(graph2,0);
    for(int i=0;i<n-1;i++){
        ll x,y;
        cin>>x>>y;
        graph1[x].pb(y);// use vpll if there is weight
        graph1[y].pb(x);
       // graph2[x][y]=1;//=w if there is weight
       // graph2[y][x]=1;


    }
    DFS(graph1,0LL,1LL);
    //for(int i=1;i<=n;i++){cout<<height[i]<<spc;}cout<<endl;
    //for(int i=1;i<=n;i++){cout<<depth[i]<<spc;}cout<<endl;
    ll max_depth=-1;
    ll end1;
    for(int i=1;i<=n;i++){
        if(max_depth<depth[i]){
            max_depth=depth[i];
            end1=i;
        }
    }
    for(int i=1;i<=n;i++){
        depth[i]=0;
    }
    
    DFS(graph1,0LL,end1);
    ll diameter=-1;
    ll end2;
    for(int i=1;i<=n;i++){
        if(diameter<depth[i]){
            diameter=depth[i];
            end2=i;
        }
    }
    cout<<diameter<<endl;//<<spc<<end1<<spc<<end2<<endl;

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