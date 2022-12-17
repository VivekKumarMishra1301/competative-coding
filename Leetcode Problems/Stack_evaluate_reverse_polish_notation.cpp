class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<long> hold;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*")
            {
                int num = 2;
                vector<long> hold1;
                while (num--)
                {
                    hold1.push_back(hold.top());
                    hold.pop();
                }
                if (tokens[i] == "+")
                {
                    hold.push(hold1[1] + hold1[0]);
                }
                else if (tokens[i] == "-")
                {
                    hold.push(hold1[1] - hold1[0]);
                }
                else if (tokens[i] == "*")
                {
                    hold.push(hold1[1] * hold1[0]);
                }
                else
                {
                    hold.push(hold1[1] / hold1[0]);
                }
            }
            else
            {
                hold.push(stoi(tokens[i]));
            }
        }

        return hold.top();
        return 0;
    }
};