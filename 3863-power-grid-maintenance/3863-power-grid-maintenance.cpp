const int maxn = 1e5 + 1;
int par[maxn];

int find(int a){
    if(par[a] == a) return a;
    return par[a] = find(par[a]);
}

bool same(int a, int b){
    return find(a)  == find(b);
}

void join(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    par[a] = b;
}

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& con, vector<vector<int>>& que) {
        for(int i = 0; i < maxn; ++i) par[i] = i;
        set <int> st[maxn];
        for(auto p : con){
            join(p[0], p[1]);
        }
        for(int i = 1; i <= c; ++i){
            st[find(i)].insert(i);
        }
        vector <int> ans;
        for(auto p : que){
            if(p[0] == 1){
                int pa = find(p[1]);
                if(st[pa].empty()) ans.push_back(-1);
                else{
                    if(st[pa].count(p[1])) ans.push_back(p[1]);
                    else ans.push_back(*st[pa].begin());
                }
            }
            else{
                int pa = find(p[1]);
                st[pa].erase(p[1]);
            }
        }
        return ans;
    }
};