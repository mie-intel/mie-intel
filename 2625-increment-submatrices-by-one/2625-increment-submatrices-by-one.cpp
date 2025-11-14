class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& q) {
        vector <vector <int>> v(n, vector <int> (n, 0));
        for(int i = 0; i < q.size(); ++i){
            int x = q[i][0];
            int y = q[i][1];
            int x1 = q[i][2];
            int y1 = q[i][3];
            // swap(x, y);
            v[x][y]++;
            if(x1+1<n) v[x1+1][y]--;
            if(y1+1<n) v[x][y1+1]--;
            if(x1+1<n && y1+1<n) v[x1+1][y1+1]++;
        }
        for(int i = 1; i < n; ++i) v[0][i] += v[0][i-1];
        for(int j = 1; j < n; ++j) v[j][0] += v[j-1][0];
        for(int i = 1; i < n; ++i)
            for(int j = 1; j < n; ++j)
                v[i][j] += v[i-1][j] + v[i][j-1] - v[i-1][j-1];

        return v; 
    }
};