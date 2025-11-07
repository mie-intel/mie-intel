typedef long long ll;

class Solution {
public:
    vector <ll> v;
    int add[100002];
    bool cek(ll n, ll m, ll r, ll k){
        memset(add, 0, sizeof add);
        for(int i = 1; i <= n; ++i){
            add[i] += add[i-1];
            ll top = min(r + i, n);
            ll bot = max(i - r, 1ll);
            ll sum = v[top] - v[bot-1] + add[i];
            if(sum < m){
                if(m - sum > k) return false;
                k -= (m - sum);
                add[i] += (m - sum);
                add[min(i + r + r + 1, n+1)] -= (m - sum);
            }
            sum = v[top] - v[bot-1] + add[i];
        }
        return true;
    }
    // r = 1
    // {1, 2, 3}
    long long maxPower(vector<int>& s, int r, int k) {
        v = {0};
        int n = s.size();
        for(int i = 0; i < s.size(); ++i){
            v.push_back(v[i] + s[i]);
        }
        ll l = 0, rr = 1e11;
        ll ans = 0;
        while(l <= rr){
            ll m = (l + rr)/2;
            if(cek(n, m, r, k)){
                ans = max(ans, m);
                l = m + 1;
            }
            else{
                rr = m - 1;
            }
        }
        // cek(pref, n, 5, r, k);
        return ans;
    }
};