#include <iostream>
#include <vector>
using namespace std;
int maxArea(vector<int> &height)
{
    int area = 0;

    for (int i = 0; i < height.size(); i++)
    {

        for (int j = i + 1; height.size(); j++)
        {

            signed int area2 = min(height[i], height[j]) * (j - i);
            if (area2 > area)
            {
                area = area2;
            }
        }
    }
    return area;
}
int main()
{
    vector<int> v;
    int c;
    int size;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> c;
        v.push_back(c);
    }
    cout << maxArea(v);
}