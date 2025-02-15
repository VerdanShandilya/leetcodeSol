class Solution {
public:
    bool helper(string &num, int target, int index, int currSum) {
        if (index == num.size()) {
            return currSum == target;
        }

        int sum = 0;
        for (int i = index; i < num.size(); i++) {
            sum = sum * 10 + (num[i] - '0');
            if (sum + currSum > target) break;
            if (helper(num, target, i + 1, currSum + sum)) return true;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int square = i * i;
            string sqStr = to_string(square);
            if (helper(sqStr, i, 0, 0)) {
                ans += square;
            }
        }
        return ans;
    }
};
