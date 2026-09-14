class Solution 
{
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) 
    {
        unordered_set<string>st(bank.begin(), bank.end());
        unordered_set<string>visited;
        queue<string>q;
        int steps = 0;
        q.push(startGene);
        visited.insert(startGene);
        string chars = "ACGT";
        
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                string curr = q.front();
                q.pop();
                if (curr == endGene)
                return steps;

                for (int i = 0; i < 8; i++)
                {
                    char original = curr[i];
                    for (char ch : chars)
                    {
                        curr[i] = ch;
                        if (st.count(curr) && !visited.count(curr))
                        {
                            visited.insert(curr);
                            q.push(curr);
                        }
                    }
                    curr[i] = original;
                }
            }

            ++steps;
        }
        return -1;
    }
};