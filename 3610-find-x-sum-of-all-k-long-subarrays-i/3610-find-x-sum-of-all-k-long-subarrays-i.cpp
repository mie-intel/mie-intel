class Solution {
public:
    int sum(vector <int> v, int x){
        sort(v.begin(), v.end());
        // jumlah terbanyak, gede
        vector <pair <int, int>> f;
        int A = v[0];
        int cnt = 0;
        for(int i = 0; i < v.size(); ++i){
            if(v[i] == A){
                cnt++;
            }
            else{
                f.emplace_back(-cnt, -A);
                A = v[i];
                cnt = 1;
            }
        }
        f.emplace_back(-cnt, -A);
        sort(f.begin(), f.end());
        int res = 0;
        for(int i = 0; i < f.size() && i < x; ++i){
            res += f[i].first * f[i].second;
        }
        return res;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector <int> res;
        for(int i = 0; i + k - 1 < nums.size(); ++i){
            vector <int> nn = vector <int> (nums.begin()+i, nums.begin() + i + k);
            res.push_back(sum(nn, x));
        }
        return res;
    }
};