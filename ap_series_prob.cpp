#include <iostream>
using namespace std;

int main()
{
    // Write your code here
    int x, term = 0, count = 0;
    cin >> x;
    if (x >= 1 && x <= 1000)
    {
        for (int i = 1; count < x; i++) /*this also can be done using the while loop by using a counter condition*/
        {                               /*it is clear from above code we can writ condition in the for loop for any of the decalared variable within the condition semicvolon*/
            term = 3 * i + 2;
            if (term % 4 != 0)
            {
                cout << term << " ";
                count++;
            }
        }
    }
}
