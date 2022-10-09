/*Chef has the binary representation SS of a number XX with him. He can modify the number by applying the following operation exactly once:

Make X := X \oplus \lfloor \frac{X}{2^{Y}} \rfloorX:=X⊕⌊
2
Y

X
​
 ⌋, where (1 \leq Y \leq |S|)(1≤Y≤∣S∣) and \oplus⊕ denotes the bitwise XOR operation.
Chef wants to minimize the value of XX after performing the operation. Help Chef in determining the value of YY which will minimize the value of XX after the operation.

Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
Each test case consists of two lines of inputs:
The first line contains the length of the binary string SS.
The second line contains the binary string SS.
Output Format
For each test case, output on a new line, the value of YY which will minimize the value of XX after the operation.

Constraints
1 \leq T \leq 5 \cdot 10^41≤T≤5⋅10
4

1 \leq |S| \leq 10^51≤∣S∣≤10
5

The sum of |S|∣S∣ over all test cases won't exceed 5 \cdot 10^55⋅10
5
 .
SS contains the characters 00 and 11 only.
Sample 1:
Input
Output
4
2
10
2
11
3
101
3
110
2
1
2
1
Explanation:
Test case 11: Since S = 10S=10 is the binary representation of 22, the current value of X = 2X=2. On choosing Y = 2Y=2, XX becomes 2 \oplus \lfloor \frac{2}{2^{2}} \rfloor = 22⊕⌊
2
2

2
​
 ⌋=2. We can show that this is the minimum value of XX we can achieve after one operation.

Test case 22: Since S = 11S=11 is the binary representation of 33, the current value of X = 3X=3. On choosing Y = 1Y=1, XX becomes 3 \oplus \lfloor \frac{3}{2^{1}} \rfloor = 23⊕⌊
2
1

3
​
 ⌋=2. We can show that this is the minimum value of XX we can achieve after one operation.

Test case 33: Since S = 101S=101 is the binary representation of 55, the current value of X = 5X=5. On choosing Y = 2Y=2, XX becomes 5 \oplus \lfloor \frac{5}{2^{2}} \rfloor = 45⊕⌊
2
2

5
​
 ⌋=4. We can show that this is the minimum value of XX we can achieve after one operation.

Test case 44: Since S = 110S=110 is the binary representation of 66, the current value of X = 6X=6. On choosing Y = 1Y=1, XX becomes 6 \oplus \lfloor \frac{6}{2^{1}} \rfloor = 56⊕⌊
2
1

6
​
 ⌋=5. We can show that this is the minimum value of XX we can achieve after one operation.*/

#include <iostream>
using namespace std;
int getResult(char *input, int size)
{
    int result = size;

    for (int i = 1; i <= size; i++)
    {
        if (input[i] == '1')
        {
            return i;
        }
    }
    return result;
}
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        char str[n];
        for (int i = 0; i < n; i++)
        {
            cin >> str[i];
        }
        int ans = getResult(str, n);
        cout << ans << endl;
    }
    return 0;
}
