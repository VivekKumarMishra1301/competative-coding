class Solution
{
public:
    int pivotInteger(int n)
    {
        int st = 1;
        int end = n;
        stack<int> hold1;
        stack<int> hold2;
        hold1.push(1);
        hold2.push(n);
        int top1 = hold1.top();
        ;
        int top2 = hold2.top();
        while (st < end)
        {
            top1 = hold1.top();
            top2 = hold2.top();
            hold1.pop();
            hold2.pop();
            if (top1 > top2)
            {
                end--;
                top2 = top2 + end;
            }
            else if (top1 < top2)
            {
                st++;
                top1 = top1 + st;
            }
            else
            {
                st++;
                end--;
                top2 = top2 + end;
                top1 = top1 + st;
            }
            hold1.push(top1);
            hold2.push(top2);
        }
        if (top1 == top2)
        {
            return st;
        }
        return -1;
    }
};