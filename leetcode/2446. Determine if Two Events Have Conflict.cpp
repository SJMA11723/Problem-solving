class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int ini = ((event1[0][0] - '0') * 10 + event1[0][1] - '0') * 60 * 60 + ((event1[0][3] - '0') * 10 + event1[0][4] - '0') * 60,
            ini2 = ((event2[0][0] - '0') * 10 + event2[0][1] - '0') * 60 * 60 + ((event2[0][3] - '0') * 10 + event2[0][4] - '0') * 60,
            fin = ((event1[1][0] - '0') * 10 + event1[1][1] - '0') * 60 * 60 + ((event1[1][3] - '0') * 10 + event1[1][4] - '0') * 60,
            fin2 = ((event2[1][0] - '0') * 10 + event2[1][1] - '0') * 60 * 60 + ((event2[1][3] - '0') * 10 + event2[1][4] - '0') * 60;

        return !(fin < ini2 || fin2 < ini);
    }
};
