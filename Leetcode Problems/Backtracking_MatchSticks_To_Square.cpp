class Solution
{
public:
    //     bool square(int s1,int s2,int s3,int s4,int ind,vector<int>&match,int side){
    //         if(ind==match.size()){
    //             if(s1==s2&&s2==s3&&s3==s4&&s4==side){
    //                 return true;
    //             }
    //             return false;
    //         }

    //         bool p1,p2,p3,p4;
    //         if(s1+match[ind]<=side)

    //              return square(s1+match[ind],s2,s3,s4,ind+1,match,side);
    //         if(s2+match[ind]<=side)
    //             return square(s1,s2+match[ind],s3,s4,ind+1,match,side);
    //         if(s3+match[ind]<=side)
    //             return square(s1,s2,s3+match[ind],s4,ind+1,match,side);
    //         if(s4+match[ind]<=side)
    //             return square(s1,s2,s3,s4+match[ind],ind+1,match,side);
    //             // return p1||p2||p3||p4;

    //         return false;
    //     }

    bool square(int ind, vector<int> &hold, vector<int> &match, int len)
    {
        if (ind == match.size())
        {
            return true;
        }

        for (int i = 0; i < 4; i++)
        {
            if (hold[i] + match[ind] <= len)
            {
                hold[i] += match[ind];
                if (square(ind + 1, hold, match, len))
                {
                    return true;
                }
                hold[i] -= match[ind];
            }
        }
        return false;
    }

    bool makesquare(vector<int> &matchsticks)
    {

        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (matchsticks.size() < 4)
        {
            return false;
        }
        if (sum % 4 != 0)
            return false;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        // reverse(matchsticks.begin(),matchsticks.end());
        vector<int> side(4, 0);
        return square(0, side, matchsticks, sum / 4);
    }
};