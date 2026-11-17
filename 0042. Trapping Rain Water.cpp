class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (height.empty())
            return 0;
        int left = 0, right = height.size() - 1, leftmax = 0, rightmax = 0,
            water = 0;
        while (left < right)
        {
            // Update max height from left and right
            leftmax = max(height[left], leftmax);
            rightmax = max(height[right], rightmax);
            // Water trapped depends on smaller of the two max heights
            if (leftmax <= rightmax)
                water += leftmax - height[left++];
            else
                water += rightmax - height[right--];
        }
        return water;
    }
};