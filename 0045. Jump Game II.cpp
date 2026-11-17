class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int maxIndex = 0, n = nums.size(), jump = 0, current = 0;
        for (int i = 0; i < n - 1; i++)
        {
            maxIndex = max(maxIndex, i + nums[i]);
            if (i == current)
            {
                jump++;
                current = maxIndex;
            }
        }
        return jump;
    }
};