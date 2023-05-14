class Solution
{
public:
    bool doesValidArrayExist(vector<int> &derived)
    {
        vector<int> hold;
        vector<int> hold1;

        if (derived[0] == 1)
        {
            hold.push_back(0);
            hold.push_back(1);
            hold1.push_back(1);
            hold1.push_back(0);
        }
        else
        {
            hold.push_back(0);
            hold.push_back(0);
            hold1.push_back(1);
            hold1.push_back(1);
        }
        // int k

        for (int i = 1; i < derived.size(); i++)
        {
            if (derived[i] == 1)
            {
                // if(hold[i]!=1&&hold[i-1]!=1){
                //     return false;
                // }
                if (hold[i] == 1)
                {
                    hold.push_back(0);
                }
                else
                {
                    hold.push_back(1);
                }

                if (hold1[i] == 1)
                {
                    hold1.push_back(0);
                }
                else
                {
                    hold1.push_back(1);
                }
            }
            else
            {
                if (hold[i] == 1)
                {
                    hold.push_back(1);
                }
                else
                {
                    hold.push_back(0);
                }

                if (hold1[i] == 1)
                {
                    hold1.push_back(1);
                }
                else
                {
                    hold1.push_back(0);
                }
            }
        }

        if (hold[hold.size() - 2] ^ hold[0] != derived[derived.size() - 1] && hold1[hold1.size() - 2] ^ hold1[0] != derived[derived.size() - 1])
        {
            return false;
        }

        vector<int> der1;
        vector<int> der2;
        for (int i = 0; i < hold.size() - 1; i++)
        {
            der1.push_back(hold[i] ^ hold[i + 1]);
            der2.push_back(hold1[i] ^ hold1[i + 1]);
        }

        // cout<<der1.size()<<" "<<der2.size()<<" "<<derived.size();
        if (der1 == derived || der2 == derived)
        {
            return true;
        }

        // if(hold.size()==derived.size()||hold1.size()==derived.size()){
        //     return true;
        // }
        return false;
    }
};