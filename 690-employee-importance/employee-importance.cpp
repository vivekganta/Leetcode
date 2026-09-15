/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution 
{
public:
    int getImportance(vector<Employee*> employees, int id) 
    {
        unordered_map<int, Employee*>mp;
        for (auto e : employees)
        mp[e->id] = e;

        queue<int>q;
        int ans = 0;
        q.push(id);

        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            Employee* temp = mp[curr];
            ans += temp->importance;
            for (int sub : temp -> subordinates)
            q.push(sub);
        }
        return ans;
    }
};