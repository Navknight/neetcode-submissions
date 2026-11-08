class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> incoming(numCourses, 0);
        for (auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            incoming[pre[0]]++;
        }
        vector<bool> visited(numCourses, 0);

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (incoming[i] == 0) {
                q.push(i);
                visited[i] = true;
            }
        }

        while (!q.empty()) {
            auto& ch = graph[q.front()];
            q.pop();
            for (auto& i : ch) {
                incoming[i]--;
                if (incoming[i] == 0) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) return false;
        }

        return true;
    }
};
