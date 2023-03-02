//March 2, 2023


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minCost(vector<vector<int>> &costs) {
        int n = costs.size();
        int k = costs[0].size();
        
        int dp[n][k];
        set<pair<int,int>> x, y;
        
        for(int i = 0; i < k; i++){
            dp[0][i] = costs[0][i];
            x.insert({dp[0][i], i});
        }
            
        for(int i = 1; i < n; i++){
            for(int j = 0; j < k; j++){
                dp[i][j] = 1e9;
                
                auto ptr = x.begin();
                if(*ptr == make_pair(dp[i - 1][j], j))
                    ++ptr;
            
                if(ptr != x.end())
                    dp[i][j] = costs[i][j] + (*ptr).first;
                
                y.insert({dp[i][j], j});
            }
            
            x = y;
            y.clear();
        }
        
        int ans = 1e9;
        
        for(int i = 0; i < k; i++)
            ans = min(ans, dp[n - 1][i]);
            
        return ((ans == 1e9) ? -1 : ans);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends
