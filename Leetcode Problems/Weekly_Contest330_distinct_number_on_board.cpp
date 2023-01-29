class Solution
{
public:
    int distinctIntegers(int n)
    {
        int counter = 0;
        unordered_map<int, int> meraMap;
        while (n > 1)
        {
            for (int i = 2; i <= n; i++)
            {
                if (n % i == 1 && meraMap.count(i) == 0)
                {
                    counter++;
                    meraMap[i]++;
                }
            }
            n--;
        }
        return counter + 1;
    }
};