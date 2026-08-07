class Solution 
{
public:
    int nthUglyNumber(int n) 
    {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        unordered_set<long long> vis;

        pq.push(1);
        vis.insert(1);

        long long ugly = 1;

        for (int i = 0; i < n; i++) 
        {
            ugly = pq.top();
            pq.pop();

            if (!vis.count(ugly * 2)) 
            {
                pq.push(ugly * 2);
                vis.insert(ugly * 2);
            }

            if (!vis.count(ugly * 3)) 
            {
                pq.push(ugly * 3);
                vis.insert(ugly * 3);
            }

            if (!vis.count(ugly * 5)) 
            {
                pq.push(ugly * 5);
                vis.insert(ugly * 5);
            }
        }

        return ugly;
    }
};