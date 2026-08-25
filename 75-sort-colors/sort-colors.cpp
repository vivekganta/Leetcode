class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a = 0, b = 0, c = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 0)
            ++a;
            else if (nums[i] == 1)
            ++b;
            else
            ++c;
        }
        for (int i = 0; i < a; i++)
        nums[i] = 0;
        for (int i = 0; i < b; i++)
        nums[i + a] = 1;
        for (int i = 0; i < c; i++)
        nums[a + b + i] = 2;
    }
};