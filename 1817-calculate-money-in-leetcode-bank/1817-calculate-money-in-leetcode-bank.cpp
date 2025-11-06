class Solution {
public:
    int totalMoney(int n) {
        int start = 0;
        int add = 0;
        int ans = 0;
        for(int i = 0; i < n; ++i){
            if(i % 7 == 0){
                start++;
                add = 0;
            }
            else{
                add++;
            }
            ans += start + add;
        }
        return ans;
    }
};