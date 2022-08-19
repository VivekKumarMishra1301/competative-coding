#include <iostream>
using namespace std;

int main()
{

    /* Read input as specified in the question.
     * Print output as specified in the question.
     */
    char c;
    int alpha = 0, num = 0, sym = 0;
    c = cin.get();
    while (c != '$')
    {
        if (c >= 'a' && c <= 'z')
        {
            alpha++;
        }
        else if (c >= '0' && c <= '9')
        {
            num++;
        }
        else if (c == ' ' || c == '\t' || c == '\n')
        {
            sym++;
        }
        c = cin.get();
    }
    cout << alpha << " " << num << " " << sym;
}
