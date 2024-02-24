class Solution
{
public:
    int findUnsortedSubarray(vector<int> &v)
    {
        int l = INT_MAX, r = INT_MIN;
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i - 1] > v[i])
                l = min(l, v[i]);
        }
        for (int i = v.size() - 2; i >= 0; i--)
        {
            if (v[i + 1] < v[i])
                r = max(r, v[i]);
        }
        if (l == INT_MAX)
            return 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] > l)
            {
                l = i;
                break;
            }
        }
        for (int i = v.size() - 1; i >= 0; i--)
        {
            if (v[i] < r)
            {
                r = i;
                break;
            }
        }
        return r - l + 1;
    }
};