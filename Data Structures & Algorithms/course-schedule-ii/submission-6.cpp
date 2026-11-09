class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> incoming(numCourses, 0);
        for (auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            incoming[pre[0]]++;
        }

        queue<int> q;
        vector<int> ans;

        for (int i = 0; i < numCourses; i++) {
            if (incoming[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);

            for (auto& e : graph[curr]) {
                if (--incoming[e] == 0) {
                    q.push(e);
                }
            }
        }

        for(auto& x: incoming) {
            if(x != 0) return {};
        }
        return ans;
    }
};
