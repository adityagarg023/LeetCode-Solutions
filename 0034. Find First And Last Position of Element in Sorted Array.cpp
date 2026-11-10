class Solution
{
public:
    int firstocc(vector<int> &nums, int target)
    {
        int s = 0;
        int e = nums.size() - 1;
        int m = s + (e - s) / 2;
        int ans = -1;
        while (s <= e)
        {
            m = s + (e - s) / 2;
            if (nums[m] == target)
            {
                ans = m;
                e = m - 1;
            }
            else if (nums[m] < target)
                s = m + 1;
            else
                e = m - 1;
        }
        return ans;
    }
    int lastocc(vector<int> &nums, int target)
    {
        int s = 0;
        int e = nums.size() - 1;
        int m = s + (e - s) / 2;
        int ans = -1;
        while (s <= e)
        {
            m = s + (e - s) / 2;
            if (nums[m] == target)
            {
                ans = m;
                s = m + 1;
            }
            else if (nums[m] < target)
                s = m + 1;
            else
                e = m - 1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans;
        ans.push_back(firstocc(nums, target));
        ans.push_back(lastocc(nums, target));
        return ans;
    }
};