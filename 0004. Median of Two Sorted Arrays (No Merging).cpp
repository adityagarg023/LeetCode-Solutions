class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int size1 = nums1.size(), size2 = nums2.size(), i = 0, j = 0,
            totalSize = size1 + size2, ind2 = totalSize / 2, ind1 = ind2 - 1,
            count = 0, ind1el = 0, ind2el = 0;
        while (i < size1 && j < size2)
        {
            if (nums1[i] < nums2[j])
            {
                if (count == ind1)
                    ind1el = nums1[i];
                if (count == ind2)
                    ind2el = nums1[i];
                i++;
            }
            else
            {
                if (count == ind1)
                    ind1el = nums2[j];
                if (count == ind2)
                    ind2el = nums2[j];
                j++;
            }
            count++;
        }
        while (i < size1)
        {
            if (count == ind1)
                ind1el = nums1[i];
            if (count == ind2)
                ind2el = nums1[i];
            count++;
            i++;
        }
        while (j < size2)
        {
            if (count == ind1)
                ind1el = nums2[j];
            if (count == ind2)
                ind2el = nums2[j];
            count++;
            j++;
        }
        if (totalSize % 2 == 1)
            return ind2el;
        return (ind1el + ind2el) / 2.0;
    }
};