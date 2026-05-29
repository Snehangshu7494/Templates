#include <bits/stdc++.h>
using namespace std;
int main()
{
     
   
 
        long long n, q;
        cin >> n >> q;
        char  arr[n + 1][n + 1];
        long long pre[n + 1][n + 1];
        
        
        for (long long i = 1; i <= n; i++)
        {
            // int cnt_1=1,cnt_0=0;
            for (long long j = 1; j <= n; j++){
          
                cin >> arr[i][j];
             if(arr[i][j]=='*')
              pre[i][j] = 1+ pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
              
            if(arr[i][j]=='.')
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
              
 
               
            }
            }
    
 
        while (q--)
        {
            long long a, b, c, d;
            cin >> a >> b >> c >> d;
            long long result = pre[c][d] - pre[a - 1][d] - pre[c][b - 1] + pre[a - 1][b - 1];
            cout << result <<endl;
        }
        cout << endl;
 
 
   
 
}