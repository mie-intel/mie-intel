#include <vector>

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& e) {
        int mx = 0;
        vector <pair <int, int>> en;
        for (auto p : e){
            en.emplace_back(p[1], p[2]);
        }
        sort(en.begin(), en.end());
        int i = 0;
        sort(e.begin(), e.end());
        int ans = 0;
        for(int j = 0; j < e.size(); ++j){
            while(i < e.size() && en[i].first < e[j][0]){
                mx = max(mx, en[i].second);
                i++;
            }
            ans = max(ans, mx + e[j][2]);
        }
        return ans;
    }
};