class Solution 
{
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) 
    {
        vector<string>ans;
        for (string query : queries)
        {
            for (string word : dictionary)
            {
                int diff = 0;
                for (int i = 0; i < word.size(); i++)
                {
                    if (word[i] != query[i])
                    ++diff;
                }

                if (diff <= 2)
                {
                    ans.push_back(query);
                    break;
                }
            }
        }
        return ans;
    }
};