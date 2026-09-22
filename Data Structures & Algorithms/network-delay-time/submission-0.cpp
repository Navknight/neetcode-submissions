class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> gp(n + 1, vector<pair<int, int>>());
        for (auto& t : times) gp[t[0]].push_back({t[2], t[1]});

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, k});

        vector<int> dis(n + 1, INT_MAX);

        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            if (dis[node.second] > node.first) {
                dis[node.second] = node.first;

                for (auto& e : gp[node.second]) pq.push({node.first + e.first, e.second});
            }
        }

        int time = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (dis[i] == INT_MAX) return -1;
            time = max(time, dis[i]);
        }

        return time;
    }
};
