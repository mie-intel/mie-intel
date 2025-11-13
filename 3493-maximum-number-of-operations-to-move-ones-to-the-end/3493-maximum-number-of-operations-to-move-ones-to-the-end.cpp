class Solution {
public:
    int maxOperations(string s) {
        int ones = 0;
        int last = -1;
        int ans = 0;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '1'){
                ans += (last != -1 && i-last > 1) * ones;
                last = i;
                ones++;
            }
        }
        int n = s.length();
        ans += (last != -1 && n-last > 1) * ones;
        return ans;
    }
};