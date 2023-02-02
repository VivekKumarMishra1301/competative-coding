class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        unordered_map<char, int> meraMap;
        for (int i = 0; i < order.size(); i++)
        {
            meraMap[order[i]] = i;
        }

        for (auto i : meraMap)
        {
            cout << i.first << ":" << i.second << " ";
        }
        cout << endl;

        vector<int> code;
        for (int i = 1; i < words.size(); i++)
        {

            string str1 = words[i - 1];
            string str2 = words[i];
            int j = 0;
            int k = 0;
            if (meraMap[str2[0]] > meraMap[str1[0]])
            {
                continue;
            }
            else if (meraMap[str2[0]] < meraMap[str1[0]])
            {
                return false;
            }
            int sum1 = 0;
            int sum2 = 0;
            while (j < str1.size() && k < str2.size())
            {

                sum2 += meraMap[str2[k]];
                sum1 += meraMap[str1[j]];
                j++;
                k++;
            }
            if (sum1 == sum2 && str2.size() < str1.size())
            {
                return false;
            }
            else if (sum1 > sum2 && str1.size() < str2.size())
            {
                return false;
            }
        }

        return true;
    }
};