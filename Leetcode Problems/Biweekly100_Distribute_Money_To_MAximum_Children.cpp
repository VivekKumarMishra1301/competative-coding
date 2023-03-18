class Solution
{
public:
    int distMoney(int money, int children)
    {
        if (money < children)
        {
            return -1;
        }

        vector<int> ch(children, 1);
        for (int i = 0; i < children; i++)
        {
            ch[i] = 1;
            money--;
        }

        int cnt = 0;
        for (int i = 0; i < children; i++)
        {
            if (money >= 7)
            {
                ch[i] += 7;
                money = money - 7;
                cnt++;
            }
            else
            {
                ch[i] += money;
                money = 0;
            }

            if (ch[i] == 4 && i + 1 < children)
            {
                ch[i] -= 1;
                money++;
            }
            else if (ch[i] == 4)
            {
                cnt--;
                ch[i] -= 1;
                ch[i - 1] += 1;
            }
        }
        if (money > 0)
        {
            cnt--;
        }

        return cnt;
    }
};