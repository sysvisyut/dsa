class Solution {
public:
    long long minInitialStrength(vector<int>& m, vector<vector<int>>& b) {
        int n = m.size();
        vector<long long> c(n + 1, 0);
        
        for(auto& v : b) c[v[0]] += v[2], c[v[1] + 1] -= v[2];

        for(int i = 1; i < n; ++i) c[i] += c[i - 1];
        long long r = 0;
        for(int i = n - 1; i >= 0; --i) r = r > 0 ? r + m[i] : max(0LL, m[i] - c[i]);
        return r;
    }
};