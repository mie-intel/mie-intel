#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class Solution {
public:
    vector <vector <int>> p;

    int cek(int m){
        ordered_set s;
        set <int> st;
        for(auto q : p){
            // cout << q[0] << " " << q[1] << '\n';
            int up = s.order_of_key(q[0]+1);
            int low = s.order_of_key(q[1]);
            int cnt = (up - low);
            if(cnt == 0){
                s.insert(q[0]);
                s.insert(q[0]-1);
                st.insert(q[0]);
                st.insert(q[0]-1);
            }
            else if(cnt == 1){
                if(st.count(q[0])){
                    s.insert(q[0]-1);
                    st.insert(q[0]-1);
                }
                else s.insert(q[0]), st.insert(q[0]);
            }
            else continue;
        }
        // for(auto p : st) cout << p << " ";
        // cout << '\n';
        // for(auto p : s) cout << p << " ";
        // cout << '\n';
        return s.size();
    }

    int intersectionSizeTwo(vector<vector<int>>& in) {
        p.clear();
        for(auto q : in) p.push_back({q[1], q[0]});
        sort(p.begin(), p.end());
        int l = 0, r = in.size() * 2, m;
        // while(l <= r){
        //     m = (l + r)/2;
        //     if(cek(m)){
        //         ans = min(ans, m);
        //         r--;
        //     }
        //     else{
        //         l++;
        //     }
        // }
        return cek(0);
    }
};