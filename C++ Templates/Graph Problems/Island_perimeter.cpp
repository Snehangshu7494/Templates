//https://leetcode.com/problems/island-perimeter/description/

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
vector<vector<int>>grid={{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
int ans=0;
void DFS(int i,int j,vector<vector<int>>& grid,pair<int,int>par){
    int n=grid.size();//rows
    int m=grid[0].size();//coloumns
    pair<int,int>pp={-1,-1};
    // if(par==pp){
    //     ans+=4;
    // }
    // else{
    //     ans+=3;
    // }
    //cout<<i<<spc<<j<<endl;
    ans+=4;
    grid[i][j]=2;
    //cout<<i<<" "<<j<<spc<<ans<<endl;
    if((i-1>=0 && i<n) && (j>=0 && j<m) && grid[i-1][j]){
        ans--;
        if(grid[i-1][j]!=2)DFS(i-1,j,grid,{i,j});
    }
    if((i+1<n && i>=0) && (j>=0 && j<m) && grid[i+1][j]){
        ans--;
        if(grid[i+1][j]!=2)DFS(i+1,j,grid,{i,j});
    }
    if((i<n && i>=0) && (j-1>=0 && j<m) && grid[i][j-1]){
        ans--;
        if(grid[i][j-1]!=2)DFS(i,j-1,grid,{i,j});
    }
    if((i<n && i>=0) && (j>=0 && j+1<m) && grid[i][j+1]){
        ans--;
        if(grid[i][j+1]!=2)DFS(i,j+1,grid,{i,j});
    }
}

int islandPerimeter(vector<vector<int>>& grid) {
        ans=0;
        int n=grid.size();//rows
        int m=grid[0].size();//coloumns
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    DFS(i,j,grid,{-1,-1});
                    //cout<<ans<<endl;
                    return ans;
                    break;
                }
            }
        }
        return 0;
    }

void solve(){
    islandPerimeter(grid);
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