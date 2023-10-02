class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        int alMove = 0;
        int boMove = 0;
        int rc = 0;
        for (int i = 0; i < colors.size(); i++)
        {
            if (colors[i] != 'A')
            {
                if (rc >= 3)
                {
                    alMove += (rc - 2);
                }
                rc = 0;
            }
            else
            {
                rc++;
            }
        }
        if (rc >= 3)
        {
            alMove += (rc - 2);
        }
        rc = 0;
        for (int i = 0; i < colors.size(); i++)
        {
            if (colors[i] != 'B')
            {
                if (rc >= 3)
                {
                    boMove += (rc - 2);
                }
                rc = 0;
            }
            else
            {
                rc++;
            }
        }

        if (rc >= 3)
        {
            boMove += (rc - 2);
        }
        rc = 0;

        if (alMove > boMove)
        {
            return true;
        }
        return false;
    }
};