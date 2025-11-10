class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack <int> st;
        int ans = 0;
        for(auto p : nums){
            while(!st.empty() && st.top() > p){
                st.pop();
                ans++;
            }
            if((st.empty() || st.top() < p) && p != 0) st.push(p);
        }
        ans += st.size();
        return ans;
    }
};