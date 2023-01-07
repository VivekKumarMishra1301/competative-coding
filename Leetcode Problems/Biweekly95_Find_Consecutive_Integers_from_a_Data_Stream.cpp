class DataStream
{
public:
    long k = 0;
    long val = 0;
    vector<int> hold;
    long l = 0;
    DataStream(int value, int k)
    {
        this->k = k;
        // this->l=k;
        this->val = value;
        // hold.push_back(val);
    }

    bool consec(int num)
    {
        hold.push_back(num);
        if (num == val)
        {
            l++;
        }
        else
        {
            l = 0;
        }
        if (hold.size() < k)
        {
            return false;
        }
        else if (l >= k)
        {

            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */