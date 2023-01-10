class MinStack
{
public:
    vector<int> hold;
    MinStack()
    {
    }

    void push(int val)
    {
        hold.push_back(val);
    }

    void pop()
    {
        hold.pop_back();
    }

    int top()
    {
        return hold[hold.size() - 1];
    }

    int getMin()
    {
        int minimum = INT_MAX;
        for (int i = 0; i < hold.size(); i++)
        {
            if (hold[i] < minimum)
            {
                minimum = hold[i];
            }
        }
        return minimum;
    }
};
