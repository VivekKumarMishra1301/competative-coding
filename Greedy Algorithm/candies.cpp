int requiredCandies(vector<int> &students)
{
    // Write your code here.
    vector<int> candies(students.size(), 1);
    for (int i = 1; i < students.size(); i++)
    {
        if (students[i] > students[i - 1] && candies[i] <= candies[i - 1])
        {
            candies[i] = candies[i - 1] + 1;
        }
    }
    for (int i = students.size() - 2; i >= 0; i--)
    {
        if (students[i] > students[i + 1] && candies[i] <= candies[i + 1])
        {
            candies[i] = candies[i + 1] + 1;
        }
    }
    int tot = 0;
    for (auto i : candies)
    {
        tot += i;
    }
    return tot;
}