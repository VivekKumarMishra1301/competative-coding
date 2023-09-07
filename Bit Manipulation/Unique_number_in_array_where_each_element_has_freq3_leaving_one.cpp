int elementThatAppearsOnce(vector<int> arr)
{
    // Write your code here.
    int hold = 0;
    for (int i = 0; i < 64; i++)
    {
        int cnt = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[j] & (1 << i))
            {
                cnt++;
            }
        }
        // cout<<cnt<<" ";
        if (cnt % 3 != 0)
        {
            hold = (hold | (1 << i));
        }
    }
    return hold;
}