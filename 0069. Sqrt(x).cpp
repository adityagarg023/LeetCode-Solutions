class Solution
{
public:
    int mySqrt(int x)
    {
        // 0 & 1 themselves are their square root
        if (x == 0 || x == 1)
            return x;
        // Binary search for rest of the integers
        int s = 1;
        int e = x;
        int ans = 0;
        while (s <= e)
        {
            int m = s + ((e - s) / 2);
            if (m == x / m)
            {
                ans = m;
                return ans;
            }
            else if (m < x / m)
            {
                ans = m;
                s = m + 1;
            }
            else
            {
                e = m - 1;
            }
        }
        return ans;
    }
};