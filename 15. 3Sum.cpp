// approach 1 => time -> O(N^3) :(    ======      space -> O(1)  :)
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &v)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = i + 1; j < v.size(); j++)
            {
                for (int k = j + 1; k < v.size(); k++)
                {
                    if (v[i] + v[j] + v[k] == 0)
                    {
                        ans.push_back({v[i], v[j], v[k]});
                    }
                }
            }
        }
        return ans;
    }
};
// approach 1 => time -> O(N^2*long n)     ======      space -> O(N)
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &v)
    {
        set<vector<int>> ans;
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
        {
            int j = i + 1, k = v.size() - 1;
            while (j < k)
            {
                if ((v[i] + v[j] + v[k]) == 0)
                    ans.insert({v[i], v[j], v[k--]});
                else if ((v[i] + v[j] + v[k]) < 0)
                    j++;
                else
                    k--;
            }
        }
        vector<vector<int>> fans;
        for (auto i : ans)
            fans.push_back(i);
        return fans;
    }
};