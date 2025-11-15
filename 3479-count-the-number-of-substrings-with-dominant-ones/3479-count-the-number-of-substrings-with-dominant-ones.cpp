class Solution {
public:
    const static int maxn = 4e4 + 1;
    int pref[maxn];
    // buat ukuran 1 - sqrt(N), cek occurences substringnya berapa
    int numberOfSubstrings(string s) {
        int n = s.length();
        pref[0] = 0;
        for(int i = 0; i < n; ++i) pref[i+1] = pref[i] + (s[i] == '1');
        for(int i = 0; i < n; ++i){
            cout << pref[i] << " \n"[i==n-1];
        }
        int ans = 0;
        for(int i = 0; i < n; ++i){
            int one = 0;
            int zero = 0;

            for(int j = i; j < n; ++j){
                // cout << i << " " << j << '\n';
                one = pref[j+1] - pref[i];
                zero = (j - i + 1) - one;
                if(zero * zero > one){
                    j += (zero * zero) - one - 1;
                }
                else if(zero * zero == one){
                    ans++;
                }
                else if(zero * zero < one){
                    ans++;
                    int diff = ((int)sqrt(one)) - zero;
                    int nextj = j + diff;
                    if(nextj >= n){
                        ans += (n - j - 1);
                    }
                    else{
                        ans += diff;
                    }
                    j = nextj;
                }
            }
        }
        return ans;
    }
};