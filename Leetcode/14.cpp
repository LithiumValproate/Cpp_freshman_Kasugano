class Solution {
  public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        if (strs.size() == 1)
            return strs[0];
        int minL = strs[0].length();
        for (const string& s : strs)
            minL = min(minL, (int)s.length());
        if (minL == 0)
            return "";
        int ans = 0;
        for (int i = 0; i < minL; i++) {
            char current = strs[0][i];
            bool mismatch = false;
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != current) {
                    mismatch = true;
                    break;
                }
            }
            if (mismatch)
                return strs[0].substr(0, i);
        }
        return strs[0].substr(0, minL);
    }
};