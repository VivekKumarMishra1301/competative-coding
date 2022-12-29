/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        vector<vector<int>> hold(m, vector<int>(n, 0));

        int count = m * n;
        int rs = 0;
        int re = n - 1;
        int cs = 0;
        int ce = m - 1;
        int num = 1;
        while (count > 0)
        {
            for (int i = rs; i <= re; i++)
            {
                if (head != NULL)
                {

                    hold[cs][i] = head->val;
                    head = head->next;
                }
                else
                {
                    hold[cs][i] = -1;
                }

                count--;
            }

            cs++;
            if (count == 0)
            {
                break;
            }
            for (int i = cs; i <= ce; i++)
            {

                if (head != NULL)
                {

                    hold[i][re] = head->val;
                    head = head->next;
                }
                else
                {
                    hold[i][re] = -1;
                }

                count--;
            }
            re--;

            if (count == 0)
            {
                break;
            }

            for (int i = re; i >= rs; i--)
            {

                if (head != NULL)
                {

                    hold[ce][i] = head->val;
                    head = head->next;
                }
                else
                {
                    hold[ce][i] = -1;
                }

                count--;
            }
            if (count == 0)
            {
                break;
            }

            ce--;

            for (int i = ce; i >= cs; i--)
            {

                if (head != NULL)
                {

                    hold[i][rs] = head->val;
                    head = head->next;
                }
                else
                {
                    hold[i][rs] = -1;
                }

                count--;
            }
            rs++;
        }
        return hold;
    }
};