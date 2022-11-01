class Solution {
public:
    string row1 = "QWERTYUIOP";
    string row2 = "ASDFGHJKL";
    string row3 = "ZXCVBNM";
    bool inrow1(string row) {
        for (int i = 0;i < row.size();i++) {
            bool flag = false;
            for (int j = 0;j < row1.size();j++) {
                if (row[i] == row1[j] || row[i] == row1[j] + 32) {
                    flag = true;
                }
            }
            if (flag == false) {
                return false;
            }
        }
        return true;
    }

    bool inrow2(string row) {
        for (int i = 0;i < row.size();i++) {
            bool flag = false;
            for (int j = 0;j < row2.size();j++) {
                if (row[i] == row2[j] || row[i] == row2[j] + 32) {
                    flag = true;
                }
            }
            if (flag == false) {
                return false;
            }
        }
        return true;
    }


    bool inrow3(string row) {
        for (int i = 0;i < row.size();i++) {
            bool flag = false;
            for (int j = 0;j < row3.size();j++) {
                if (row[i] == row3[j] || row[i] == row3[j] + 32) {
                    flag = true;
                }
            }
            if (flag == false) {
                return false;
            }
        }
        return true;
    }



    vector<string> findWords(vector<string>& words) {
        vector<string>hold;


        for (int i = 0;i < words.size();i++) {
            bool check = true;


            if (inrow1(words[i])) {

                hold.push_back(words[i]);
                continue;
            }

            if (inrow2(words[i])) {

                hold.push_back(words[i]);
                continue;
            }

            if (inrow3(words[i])) {

                hold.push_back(words[i]);
                continue;
            }


        }
        return hold;

    }
};