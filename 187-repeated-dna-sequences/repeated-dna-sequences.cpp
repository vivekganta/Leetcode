class Solution 
{
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        unordered_set<string>seen, repeated;
        for (int i = 0; i + 10 <= s.size(); i++)  
        {
            string sub = s.substr(i, 10);
            if (seen.count(sub))
            repeated.insert(sub);
            else
            seen.insert(sub);
        }  
        vector<string>ans;
        for (auto &str : repeated)
        ans.push_back(str);

        return ans;
    }
};