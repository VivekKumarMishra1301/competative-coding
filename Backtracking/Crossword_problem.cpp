#include <bits/stdc++.h>
using namespace std;
#define n 10

bool isValidVertical(char cross[n][n], int row, int col, int index, string word)
{
    int l = row;
    for (int i = index; word[i] != ';' && word[i] != '\0'; i++)
    {
        if (l >= n)
        {
            return false;
        }
        if (cross[l][col] == '+')
        {
            return false;
        }

        if (cross[l][col] == '-')
        {
            l++;
            continue;
        }

        if (cross[l][col] != word[i])
        {

            return false;
        }
        l++;
    }
    // cout<<row<<col;
    return true;
}
bool isValidHorizontal(char cross[n][n], int row, int col, int index, string word)
{
    int l = col;
    for (int i = index; word[i] != ';' && word[i] != '\0'; i++)
    {
        if (l >= n)
        {
            return false;
        }
        if (cross[row][l] == '+')
        {
            return false;
        }

        if (cross[row][l] == '-')
        {
            l++;
            continue;
        }

        if (cross[row][l] != word[i])
        {
            return false;
        }
        l++;
    }
    // cout<<row;
    return true;
}

int setVertical(char cross[n][n], vector<bool> &helper, int row, int col, int index, string word)
{
    int l = row;
    int ind = index;
    for (int i = index; word[i] != ';' && word[i] != '\0'; i++)
    {
        cross[l][col] = word[i];
        helper[l] = true;
        l++;
        ind++;
    }
    // cout<<ind<<" ";
    return ind;
}
int setHorizontal(char cross[n][n], vector<bool> &helper, int row, int col, int index, string word)
{
    int l = col;
    int ind = index;
    for (int i = index; word[i] != ';' && word[i] != '\0'; i++)
    {
        cross[row][l] = word[i];
        helper[l] = true;
        l++;
        ind++;
    }
    // cout<<ind<<" ";
    return ind;
}

void resetVertical(char cross[n][n], vector<bool> &helper, int row, int col)
{

    for (int i = row; i < n; i++)
    {
        if (helper[i] == true)
        {
            cross[i][col] = '-';
        }
    }
}
void resetHorizontal(char cross[n][n], vector<bool> &helper, int row, int col)
{

    for (int i = col; i < n; i++)
    {
        if (helper[i] == true)
        {
            cross[row][i] = '-';
        }
    }
}

void printCross(char cross[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << cross[i][j];
        }
        cout << endl;
    }
}

bool crossword(char cross[n][n], string words, int index)
{
    if (index >= words.length())
    {
        //  cout<<"hua"<<" ";

        printCross(cross);
        return true;
    }

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (cross[r][c] == '-' || cross[r][c] == words[index])
            {
                if (isValidVertical(cross, r, c, index, words))
                {
                    vector<bool> helper(n, false);
                    int ind = setVertical(cross, helper, r, c, index, words);
                    if (crossword(cross, words, ind + 1))
                    {
                        return true;
                    }
                    resetVertical(cross, helper, r, c);
                }
                if (isValidHorizontal(cross, r, c, index, words))
                {
                    vector<bool> helper(n, false);
                    int ind = setHorizontal(cross, helper, r, c, index, words);
                    if (crossword(cross, words, ind + 1))
                    {
                        return true;
                    }
                    resetHorizontal(cross, helper, r, c);
                }
            }
        }
    }
    return false;
}

int main()
{

    // write your code here
    char cross[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cross[i][j];
        }
    }

    string str;
    cin >> str;
    crossword(cross, str, 0);
    //    for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<cross[i][j];
    //     }
    //     cout<<endl;
    // }
    return 0;
}