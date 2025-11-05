typedef long long ll;
#define fi first
#define se second

struct sol {
    ll sz, ans = 0;
    map <ll, ll> mp;
    set <pair <ll, ll>> l, r;
    sol(ll _x){
        sz = _x;
    }
    void add(ll x){
        ll cnt = mp[x];
        mp[x]++;
        if(r.count(make_pair(cnt, x))){
            auto p = *r.lower_bound(make_pair(cnt, x));
            r.erase(p);
            p.fi += 1;
            ans += x;
            r.insert(p);
        }
        else if(l.count(make_pair(cnt, x))){
            auto p = *l.lower_bound(make_pair(cnt, x));
            l.erase(p);
            p.fi += 1;
            auto q = *r.begin();
            r.erase(q);
            ans -= q.fi * q.se;
            if(q > p){
                ans += q.fi * q.se;
                r.insert(q);
                l.insert(p);
            }
            else{
                ans += p.fi * p.se;
                l.insert(q);
                r.insert(p);
            }
        }
        else{
            pair <ll, ll> pp = make_pair(1, x);
            if(r.size() < sz){
                // cout << "EAA " << x << " " << '\n';
                r.insert(pp);
                ans += pp.fi * pp.se;
            }
            else{
                auto p = *r.begin();
                r.erase(p);
                ans -= p.fi * p.se;
                if(pp > p){
                    r.insert(pp);
                    ans += pp.fi * pp.se;
                    l.insert(p);
                }
                else{
                    r.insert(p);
                    ans += p.fi * p.se;
                    l.insert(pp);
                }
            }
        }
        // cout <<" MAP ";
        // for(auto [s, w] : mp){
        //     cout << "{" << s << " " << w << "} ";
        // }
        // cout << '\n';

        // cout << "L: ";
        // for(auto s : l){
        //     cout << "" << s.fi << "," << s.se << " ";
        // }
        // cout << '\n';
        
        // cout << "R: ";
        // for(auto s : r){
        //     cout << "" << s.fi << "," << s.se << " ";
        // }
        // cout << '\n';
        // cout << "ANS " << ans << '\n';
    }
    void erase(ll x){
        ll cnt = mp[x];
        mp[x]--;
        // ada di kanan
        if(r.count(make_pair(cnt, x))){
            auto p = *r.lower_bound(make_pair(cnt, x));
            r.erase(p);
            ans -= p.fi * p.se;
            p.fi -= 1;
            
            // kalo l kosong
            if(l.empty()){
                if(p.fi > 0){
                    r.insert(p);
                    ans += p.fi * p.se;
                }
                    
            }
            else{
                auto q = *prev(l.end());
                if(q > p || p.fi == 0){
                    l.erase(q);
                    ans += q.fi * q.se;
                    r.insert(q);
                    if(p.fi > 0){
                        l.insert(p);
                    }
                }
                else{
                    if(p.fi > 0){
                        r.insert(p);
                        ans += p.fi * p.se;
                    }
                }
            }
        }
        else{
            auto p = *l.lower_bound(make_pair(cnt, x));
            l.erase(p);
            p.fi -= 1;
            if(p.fi > 0){
                l.insert(p);
            }
        }
        // cout <<" MAP ";
        // for(auto [s, w] : mp){
        //     cout << "{" << s << " " << w << "} ";
        // }
        // cout << '\n';

        // cout << "L: ";
        // for(auto s : l){
        //     cout << "" << s.fi << "," << s.se << " ";
        // }
        // cout << '\n';

        // cout << "R: ";
        // for(auto s : r){
        //     cout << "" << s.fi << "," << s.se << " ";
        // }
        // cout << '\n';
        // cout << "ANS " << ans << '\n';
    }
    ll get_sum(){
        return ans;
    }
};

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        sol A = sol(x);
        vector <ll> res;
        // cout << "INIT\n"; 
        for(int i = 0; i < k-1; ++i){
            A.add(nums[i]);
        }
        // cout << "SLIDING\n";
        for(int i = 0, j = k-1; j < nums.size(); j++, i++){
            // cout << "SLIDE " << nums[j] << '\n';
            A.add(nums[j]);
            res.push_back(A.get_sum());
            A.erase(nums[i]);
        }
        return res;
    }
};