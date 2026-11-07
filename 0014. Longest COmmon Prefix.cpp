class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";
        sort(strs.begin(), strs.end());
        string str1 = strs[0];
        string str2 = strs[strs.size() - 1];
        string ans = "";
        int i = 0, size1 = str1.size(), size2 = str2.size();
        while (i < size1 && i < size2)
        {
            if (str1[i] == str2[i])
            {
                ans += str1[i];
                i++;
            }
            else
                break;
        }
        return ans;
    }
};