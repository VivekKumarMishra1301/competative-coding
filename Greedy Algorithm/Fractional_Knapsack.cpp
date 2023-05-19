#include <bits/stdc++.h>
using namespace std;
class item
{
public:
    int prof, weight;
};
bool compare(item a, item b)
{
    double val1 = ((double)(a.prof) / a.weight);
    double val2 = ((double)(b.prof) / b.weight);
    return val1 > val2;
};

double fKnap(vector<item> &arr, int cap, int n)
{
    sort(arr.begin(), arr.end(), compare);
    double p = 0;
    int cw = 0;
    for (int i = 0; i < n; i++)
    {
        if (cw + arr[i].weight <= cap)
        {
            p += arr[i].prof;
            cw += arr[i].weight;
        }
        else
        {
            int nw = cap - cw;
            p += arr[i].prof * ((double)nw / arr[i].weight);
            return p;
        }
    }
    return p;
};

int main()
{

    // write your code here
    int n;
    int cap;
    cin >> n >> cap;
    vector<item> arr(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        int b;
        cin >> a >> b;
        item obj;
        obj.prof = a;
        obj.weight = b;
        arr[i] = obj;
    }
    cout << fKnap(arr, cap, n) << ".000000";
    return 0;
}