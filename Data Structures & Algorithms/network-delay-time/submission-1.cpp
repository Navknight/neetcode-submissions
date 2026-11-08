class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);

        for (auto& time : times) {
            graph[time[0]].push_back({time[2], time[1]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        vector<int> dist(n + 1, INT32_MAX);
        dist[k] = 0;

        pq.push({0, k});

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            for (auto& t : graph[node]) {
                if (t.first + time < dist[t.second]) {
                    pq.push({t.first + time, t.second});
                    dist[t.second] = t.first + time;
                }
            }
        }

        int ans = 0;
        for (int i = 1; i < n + 1; i++) {
            if (dist[i] == INT32_MAX) return -1;
            ans = max(dist[i], ans);
        }

        return ans;
    }
};
