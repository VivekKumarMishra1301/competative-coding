class Solution
{
public:
    string categorizeBox(int length, int width, int height, int mass)
    {
        long vol = long(long(length) * long(width) * long(height));
        cout << vol;
        int ch = 10000;
        if ((length >= ch || width >= ch || height >= ch || vol >= 1000000000) && mass >= 100)
        {
            return "Both";
        }
        else if (mass >= 100)
        {
            return "Heavy";
        }
        else if (length >= ch || width >= ch || height >= ch || vol >= 1000000000)
        {
            return "Bulky";
        }
        else
        {
            return "Neither";
        }
    }
};