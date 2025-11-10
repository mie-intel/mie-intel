class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack <int> st;
        int ans = 0;
        for(auto p : nums){
            if(st.empty()){
                if(p != 0) st.push(p);
                continue;
            }
            if(st.top() == p) continue;
            if(st.top() < p){
                st.push(p);
            }
            else{
                while(!st.empty() && st.top() > p){
                    st.pop();
                    ans++;
                }
                if((st.empty() || st.top() < p) && p != 0) st.push(p);
            }
        }
        while(!st.empty()){
            st.pop();
            ans++;
        }
        return ans;
    }
};