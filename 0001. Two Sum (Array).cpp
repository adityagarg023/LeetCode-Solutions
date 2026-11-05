class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<pair<int, int>> numspair;
        for (int i = 0; i < nums.size(); i++)
            numspair.push_back({nums[i], i});
        sort(numspair.begin(), numspair.end());
        int i = 0, j = numspair.size() - 1;
        vector<int> ans;
        while (i < j)
        {
            int sum = numspair[i].first + numspair[j].first;
            if (sum == target)
            {
                ans.push_back(numspair[i].second);
                ans.push_back(numspair[j].second);
                return ans;
            }
            else if (sum < target)
                i++;
            else
                j--;
        }
        return ans;
    }
};