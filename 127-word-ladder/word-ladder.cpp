class Solution 
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string>st(wordList.begin(), wordList.end());
        unordered_set<string>visited;
        queue<string>q;
        q.push(beginWord);
        visited.insert(beginWord);
        int steps = 1;

        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                string curr = q.front();
                q.pop();
                if (curr == endWord)
                return steps;

                for (int i = 0; i < curr.size(); i++)
                {
                    char original = curr[i];
                    for (char ch = 'a'; ch <= 'z'; ch++)
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
        return 0;
    }
};