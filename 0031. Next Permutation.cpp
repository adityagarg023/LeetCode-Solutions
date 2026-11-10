#include <algorithm>
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return;
        int index = -1;
        for (int i = n - 2; i >= 0; i--)
            if (nums[i] < nums[i + 1])
            {
                index = i;
                break;
            }
        if (index >= 0)
            for (int i = n - 1; i > index; i--)
                if (nums[i] > nums[index])
                {
                    std::swap(nums[index], nums[i]);
                    break;
                }
        std::sort(nums.begin() + index + 1, nums.end());
    }
};