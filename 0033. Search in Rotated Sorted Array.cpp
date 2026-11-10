class Solution
{
public:
    int pivot(vector<int> &nums)
    {
        int s = 0;
        int e = nums.size() - 1;
        int m = s + (e - s) / 2;
        while (s < e)
        {
            m = s + (e - s) / 2;
            if (nums[m] >= nums[0])
                s = m + 1;
            else
                e = m;
        }
        return s;
    }
    int binary(vector<int> &nums, int s, int e, int target)
    {
        while (s <= e)
        {
            int m = s + (e - s) / 2;
            if (nums[m] == target)
                return m;
            else if (nums[m] < target)
                s = m + 1;
            else
                e = m - 1;
        }
        return -1;
    }
    int search(vector<int> &nums, int target)
    {
        if (nums.empty())
            return -1;
        int p = pivot(nums);
        if (nums[p] <= target && target <= nums[nums.size() - 1])
            return binary(nums, p, nums.size() - 1, target);
        else
            return binary(nums, 0, p - 1, target);
    }
};