class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {

        sort(people.begin(), people.end());
        int cnt = 0;
        int st = 0;
        int en = people.size() - 1;
        while (st <= en)
        {
            if (people[st] + people[en] <= limit)
            {
                cnt++;
                st++;
                en--;
            }
            else
            {
                cnt++;
                en--;
            }
        }
        return cnt;
    }
};