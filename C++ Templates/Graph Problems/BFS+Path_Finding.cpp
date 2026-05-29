#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define vpll vector<pair<ll,ll>>
#define F first
#define S second
#define spc " "

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (ll i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<ll, ll>>> parent(n, vector<pair<ll, ll>>(m, {-1, -1}));
    queue<pair<ll, ll>> q;
    pair<ll, ll> start, end;

    // Directions
    vpll dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    string move = "DURL";

    // Find 'A'
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                q.push({i, j});
                visited[i][j] = true;
                start = {i, j};
            }
        }
    }

    bool found = false;

    while (!q.empty()) {
        auto x = q.front().F; auto y=q.front().S; q.pop();

        if (grid[x][y] == 'B') {
            end = {x, y};
            found = true;
            break;
        }

        for (int k = 0; k < 4; k++) {
            ll ni = x + dir[k].F;
            ll nj = y + dir[k].S;

            if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
            if (visited[ni][nj] || grid[ni][nj] == '#') continue;

            visited[ni][nj] = true;
            parent[ni][nj] = {x, y};
            q.push({ni, nj});
        }
    }

    if (!found) {
        no;
        return;
    }

    // Reconstruct path
    string path;
    pair<ll, ll> cur = end;
    while (cur != start) {
        pair<ll, ll> par = parent[cur.F][cur.S];
        for (int k = 0; k < 4; k++) {
            if (par.F + dir[k].F == cur.F && par.S + dir[k].S == cur.S) {
                path += move[k];
                break;
            }
        }
        cur = par;
    }

    reverse(path.begin(), path.end());
    yes;
    cout << path.size() << endl;
    cout << path << endl;
}
int main() {
    ll t = 1;
    while (t--) {
        solve();
    }
}
