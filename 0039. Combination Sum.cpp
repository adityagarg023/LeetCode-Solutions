class Solution
{
public:
    void backtrack(int index, vector<int> &candidates, int target, int currSum,
                   vector<int> curr, vector<vector<int>> &ans)
    {
        if (currSum == target)
        {
            ans.push_back(curr);
            return;
        }
        if (currSum > target || index == candidates.size())
            return;
        backtrack(index + 1, candidates, target, currSum, curr, ans);
        curr.push_back(candidates[index]);
        backtrack(index, candidates, target, currSum + candidates[index], curr,
                  ans);
        curr.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(0, candidates, target, 0, curr, ans);

        return ans;
    }
};