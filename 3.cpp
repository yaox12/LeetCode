class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)  return 0;
        int ans = 1;
        int temp = 1;
        for (int i = 0; i < s.size() - 1; i ++) {
            int tpos = s.substr(i - temp + 1, temp).find(s[i + 1]);
            if (tpos == string::npos)
                temp ++;
            else
                temp -= tpos;
            ans = ans > temp ? ans : temp;
        }
        return ans;
    }
};