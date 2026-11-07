class Solution
{
public:
    void backtracking(int index, string digits, string mapping[], string curr, vector<string> &ans)
    {
        if (index == digits.length())
        {
            ans.push_back(curr);
            return;
        }
        int num = digits[index] - '0';
        string value = mapping[num];
        for (int i = 0; i < value.length(); i++)
        {
            curr.push_back(value[i]);
            backtracking(index + 1, digits, mapping, curr, ans);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        string curr = "";
        vector<string> ans;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backtracking(0, digits, mapping, curr, ans);
        return ans;
    }
};