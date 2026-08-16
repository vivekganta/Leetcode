class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) 
    {
        int n = A.size();
        vector<int>ans(n, 0);
        if (A[0] == B[0])
        ans[0] = 1;
        else
        ans[0] = 0;
        unordered_set<int>st;
        st.insert(A[0]);
        st.insert(B[0]);
        for (int i = 1; i < n; i++)
        {
            if (A[i] == B[i])
            ans[i] = 1 + ans[i - 1];
            else
            {
                int count = 0;
                if (st.count(A[i]))
                count += 1;
                else
                st.insert(A[i]);
                
                if(st.count(B[i]))
                count += 1;
                else
                st.insert(B[i]);
                
                ans[i] = count + ans[i - 1];
            }
        } 
        return ans;
    }
};