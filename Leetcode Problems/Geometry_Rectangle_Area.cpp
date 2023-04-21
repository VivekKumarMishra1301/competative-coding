class Solution
{
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        long area1 = 0;
        area1 = abs(ax2 - ax1) * abs(ay2 - ay1);
        long area2 = 0;
        area2 = abs(bx2 - bx1) * abs(by2 - by1);
        cout << area1 << " " << area2 << " ";
        long cx = 0;
        long cy = 0;
        cx = min(ax2, bx2) - max(ax1, bx1);
        cy = min(ay2, by2) - max(ay1, by1);
        cout << cx << " ";
        if (cx < 0 || cy < 0)
        {
            return area1 + area2;
        }

        cout << cy;
        // cout<<cx*cy;
        return (area1 + area2) - (cx * cy);
    }
};