class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        for (auto pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0) q.push(i);

        vector<int> order;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            order.push_back(curr);
            for (auto i : graph[curr])
                if (--indegree[i] == 0) q.push(i);
        }

        return order.size() == numCourses ? order : vector<int>();
    }
};
