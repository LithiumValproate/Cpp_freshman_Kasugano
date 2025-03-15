class Solution {
  public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        vector<int> dig;
        do {
            int tmp = x % 10;
            dig.push_back(tmp);
            x /= 10;
        } while (x > 0);
        for (int i = 0; i < dig.size(); i++)
            if (dig[i] != dig[dig.size() - i - 1])
                return false;
        return true;
    }
};