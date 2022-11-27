class Solution {
public:
    int appendCharacters(string s, string t) {
        int idx = 0;
        for(int i = 0; i < s.size(); ++i)
            if(s[i] == t[idx]) idx++;
        return t.size() - idx;
    }
};