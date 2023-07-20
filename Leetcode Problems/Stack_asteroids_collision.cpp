class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> hold;
        for (int i = 0; i < asteroids.size(); i++)
        {
            if (asteroids[i] > 0 || hold.size() == 0)
            {
                hold.push_back(asteroids[i]);
            }
            else
            {
                while (hold.size() != 0 && hold[hold.size() - 1] > 0 && hold[hold.size() - 1] < abs(asteroids[i]))
                {
                    hold.pop_back();
                }

                if (hold.size() != 0 && hold[hold.size() - 1] == abs(asteroids[i]))
                {
                    hold.pop_back();
                }
                else if (hold.size() == 0 || hold[hold.size() - 1] < 0)
                {
                    hold.push_back(asteroids[i]);
                }
            }
        }
        return hold;
    }
};