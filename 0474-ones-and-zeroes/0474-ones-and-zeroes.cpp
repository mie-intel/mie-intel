class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        int c[600][2];
        memset(c, 0, sizeof c);
        for(int i = 0; i < len; ++i){
            for(char p : strs[i]){
                c[i][p-'0']++;
            }
        }
        // for(int i = 0; i < len; ++i){
        //     cout << c[i][0] << " " << c[i][1] << '\n';
        // }
        const int maxn = 101;
        int dp[len][maxn][maxn]; // kita ambil kalo m sekian, n terkecil berapa
        // m = 0, n = 1
        for(int i = 0; i < len; ++i)
            for(int j = 0; j < maxn; ++j)
                for(int k = 0; k < maxn; ++k)
                    dp[i][j][k] = -1;
        
        dp[0][0][0] = 0;
        dp[0][c[0][0]][c[0][1]] = 1;
        for(int i = 1; i < len; ++i){
            for(int j = 0; j < maxn; ++j)
                for(int k = 0; k < maxn; ++k)
                     dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);

            for(int j = c[i][0]; j < maxn; ++j)
                for(int k = c[i][1]; k < maxn; ++k){
                    if(dp[i-1][j-c[i][0]][k-c[i][1]] != -1)
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-c[i][0]][k-c[i][1]] + 1);
                }
        }

        int ans = 0;
        for(int i = 0; i < len; ++i){
            cout << "IJ: " << i << '\n';
            for(int j = 0; j <= m; ++j){
                for(int k = 0; k <= n; ++k){
                    // cout << setw(3) << dp[i][j][k] << " \n"[k==maxn-1];
                    ans = max(ans, dp[i][j][k]);
                }
                // cout << '\n';
            }
            cout << '\n';
        }
        
        return ans;
    }
};