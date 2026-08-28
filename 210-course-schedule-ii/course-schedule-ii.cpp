class Solution 
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses, 0);
        for (auto pre : prerequisites)
        {
            int u = pre[0];
            int v = pre[1];
            adj[v].push_back(u);
            ++indegree[u];
        }
        vector<int>ans;
        int count = 0;
        queue<int>q;
        for (int i = 0; i < numCourses; i++)
        if (indegree[i] == 0)
        q.push(i);

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ++count;
            ans.push_back(node);
            for (auto neigh : adj[node])
            {
                --indegree[neigh];
                if (indegree[neigh] == 0)
                q.push(neigh);
            }
        }
        if (count == numCourses)
        return ans;
        else
        return {};
    }
};