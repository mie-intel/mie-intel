class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(), capacity.rend());
        int sum = 0;
        for(auto p : apple) sum += p;
        int cnt = 0;
        for(auto p : capacity){
            sum -= p;
            cnt++;
            if(sum <= 0) break;
        }
        return cnt;
    }
};