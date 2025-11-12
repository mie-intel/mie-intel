inline int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

inline int gg(vector <int> v, int l, int r){
    int tmp = v[l];
    while(l <= r){
        tmp = gcd(tmp, v[l++]);
    }
    return tmp;
}

bool cek(vector <int> v, int m){
    int n = v.size();
    for(int i = 0; i + m <= n; ++i){
        if(gg(v, i, i + m - 1) == 1) return 1;
    }
    return 0;
}

class Solution {
public:
    int minOperations(vector<int>& v) {
        int n = v.size();
        int res = 0;
        for(auto p : v){
            res += p == 1;
        }
        if(res != 0) return n - res;
        int l = 1, r = n, m;
        int ans = INT_MAX;
        while(l <= r){
            m = (l + r)/2;
            if(cek(v, m)){
                ans = min(ans, m);
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return (ans == INT_MAX ? -1 : ans + n - 2);
    }
};