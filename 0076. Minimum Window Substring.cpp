class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.size(), m = t.size();
        if (m > n)
            return "";
        vector<int> freq(128, 0);
        for (char c : t)
            freq[c]++;
        int left = 0, count = 0, mini = INT_MAX, start = 0;
        for (int right = 0; right < n; right++)
        {
            if (freq[s[right]] > 0)
                count++;
            freq[s[right]]--;
            while (count == m)
            {
                if (right - left + 1 < mini)
                {
                    mini = right - left + 1;
                    start = left;
                }
                freq[s[left]]++;
                if (freq[s[left]] > 0)
                    count--;
                left++;
            }
        }
        if (mini == INT_MAX)
            return "";
        else
            return s.substr(start, mini);
    }
};