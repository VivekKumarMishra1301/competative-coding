class Solution
{
public:
    long long dividePlayers(vector<int> &skill)
    {
        int st = 0;
        int end = skill.size() - 1;
        sort(skill.begin(), skill.end());
        stack<int> hold1;
        vector<long long> hold;
        while (st < end)
        {
            int sum = skill[st] + skill[end];
            if (hold1.size() == 0 || hold1.top() == sum)
            {
                hold1.push(sum);
                hold.push_back(skill[st] * skill[end]);
            }
            else
            {
                return -1;
            }
            st++;
            end--;
        }

        long long sum = 0;
        for (int i = 0; i < hold.size(); i++)
        {
            sum = sum + hold[i];
        }
        return sum;
    }
};