class Solution
{
public:
    int closetTarget(vector<string> &words, string target, int startIndex)
    {
        int n = words.size();
        int leftdist = -1;
        bool flag = false;
        if (words[startIndex] == target)
        {
            return 0;
        }
        int i = (startIndex + 1) % n;
        int count = 0;
        while (i != startIndex)
        {
            if (words[i] == target)
            {
                flag = true;
                count++;
                break;
            }
            count++;
            i = (i + 1) % n;
        }
        cout << count;
        if (flag)
        {
            leftdist = count;
        }
        int j = (startIndex - 1 + n) % n;
        bool jhanda = false;
        int rightdist = -1;
        int counter = 0;

        while (j != startIndex)
        {
            if (words[j] == target)
            {
                jhanda = true;
                counter++;
                break;
            }
            counter++;
            j = (j - 1 + n) % n;
        }
        cout << counter;
        if (jhanda)
        {
            rightdist = counter;
        }

        if (flag && jhanda)
        {
            return min(leftdist, rightdist);
        }
        else if (flag && !jhanda)
        {
            return leftdist;
        }
        else if (!flag && jhanda)
        {
            return jhanda;
        }
        else
        {
            return -1;
        }
    }
};