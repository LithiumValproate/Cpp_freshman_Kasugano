class Solution {
  public:
    const string Roman[7] = {"I", "V", "X", "L", "C", "D", "M"};
    const int Integer[7] = {1, 5, 10, 50, 100, 500, 1000};
    int romanToInt(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            int curr = trans(s[i]);
            if (i == s.length() - 1)
                ans += Integer[curr];
            else {
                int next = trans(s[i + 1]);
                if (Integer[curr] >= Integer[next])
                    ans += Integer[curr];
                else
                    ans -= Integer[curr];
            }
        }
        return ans;
    }

  private:
    int trans(char r) {
        for (int i = 0; i < 7; i++)
            if (Roman[i] == string(1, r))
                return i;
        return -1;
    }
};