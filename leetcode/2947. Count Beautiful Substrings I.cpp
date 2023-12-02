class Solution {
public:
    bool is_vowel(char c){
        string vowels = "aeiuo";
        return (vowels.find(c) != string::npos);
    }
    int beautifulSubstrings(string s, int k) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; ++i){
            int v = 0, sz = 0;
            for(int j = i; j < n; ++j){
                if(is_vowel(s[j])) v++;
                sz++;
                if(v == sz - v && v * (sz - v) % k == 0) ans++;
            }
        }
        return ans;
    }
};