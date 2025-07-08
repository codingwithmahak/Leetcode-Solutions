class Solution {
public:
    #define ll long long
    vector<vector<ll>> dp;
    ll solve(ll i, vector<vector<int>>& events, ll k) {
        if (i >= events.size()) return 0;
        if (k <= 0) return 0;
        if (dp[i][k] != -1LL) return dp[i][k];

        ll nt = solve(i + 1, events, k);

        ll ind = upper_bound(events.begin() + i + 1, events.end(), events[i][1],
            [](ll val, const vector<int>& event) {
                return val < event[0];
            }) - events.begin();

        ll t = events[i][2] + solve(ind, events, k - 1); 

        return dp[i][k] = max(nt, t);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end()); // Sort events by start time
        dp.resize(events.size() + 1, vector<ll>(k + 1, -1LL));
        return solve(0, events, k);
    }
};