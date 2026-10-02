class Solution 
{
public:
    bool isIsomorphic(string s, string t) 
    {
        unordered_map<char, char>S, T;
        for (int i = 0; i < s.size(); i++)
        {
            if (!S.count(s[i]))
            {
                if (T.count(t[i]))
                return false;
                
                S[s[i]] = t[i];
                T[t[i]] = s[i];
            }
            else
            {
                if (S[s[i]] == t[i])
                continue;
                else
                return false;
            }
        }
        return true;
    }
};