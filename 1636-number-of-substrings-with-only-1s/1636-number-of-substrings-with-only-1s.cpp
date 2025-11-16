typedef long long ll;
const ll mod = 1e9 + 7;

class Solution {
public:
    ll calc(ll x){
        return (x * (x + 1) / 2) % mod;
    }
    int numSub(string s) {
        ll cnt = 0;
        ll ans = 0;
        for(char c : s){
            if(c == '0'){
                ans += calc(cnt);
                ans %= mod;
                cnt = 0;
            }
            else cnt++;
        }
        ans += calc(cnt);
        ans %= mod;
        return ans;
    }
};