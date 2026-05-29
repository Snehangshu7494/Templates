//https://codeforces.com/contest/329/problem/B

#include<bits/stdc++.h>
using namespace std;
#define EDA_PARI_NA_BHAI { ios_base::sync_with_stdio(false); cin.tie(0); }
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
ll visited[1005][1005];
ll level[1005][1005];
llv opponent(1e6+5);
void BFS(vector<string>&grid,ll i,ll j){
    queue<pair<ll,ll>>Q;
    Q.push({i,j});
    visited[i][j]++;
    while(!Q.empty()){
        ll curr_vx=Q.front().F;
        ll curr_vy=Q.front().S;
        //cout<<curr_vx<<spc<<curr_vy<<endl;
        Q.pop();
        vpll children={{curr_vx+1,curr_vy},{curr_vx-1,curr_vy},{curr_vx,curr_vy+1},{curr_vx,curr_vy-1}};
        for(auto child:children){
            //cout<<"Parent "<<curr_vx<<spc<<curr_vy<<endl;
            //cout<<"Child "<<child.F<<spc<<child.S<<endl;
            if (child.F < 0 || child.S < 0 || child.F >= grid.size() || child.S >= grid[0].size())
                continue;
            if(visited[child.F][child.S]){continue;}
            if(grid[child.F][child.S]=='T'){continue;}
            if(grid[child.F][child.S]=='S'){
                level[child.F][child.S]=level[curr_vx][curr_vy]+1;
                visited[child.F][child.S]++;
                continue;
            }
            Q.push(child);
            visited[child.F][child.S]++;
            level[child.F][child.S]=level[curr_vx][curr_vy]+1;
            opponent[level[child.F][child.S]]+=grid[child.F][child.S]-'0';
        }
    }



}


void solve(){

    ll n,m;
    cin>>n>>m;
    vector<string>grid(n+2);
    string s(m+2,'T');
    grid[0]=grid[n+1]=s;
    //vector<vector<ll>>visited(n+5),level(n+5);
    //llv v(m+2);
    //visited[0]=level[0]=level[n+1]=visited[n+1]=v;
    llv v(m+2);
    for(int i=1;i<=n;i++){
        cin>>s;
        s="T"+s+"T";
        grid[i]=s;
        //visited[i]=level[i]=v;
    }

    ll e=0,sp=0;
    ll spx,spy;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(grid[i][j]=='E'){
                BFS(grid,i,j);
                e=1;
                
            }
            if(grid[i][j]=='S'){
                spx=i;spy=j;
                sp=1;
            }
            if(sp && e){
                break;
            }
            
        }
            if(sp && e){
                break;
            }
    }
    ll lvl=level[spx][spy];
    ll ans=0;
    for(int i=0;i<=lvl;i++){
        ans+=opponent[i];
    }
    cout<<ans<<endl;



}

int main(){
    //EDA_PARI_NA_BHAI
    ll t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}