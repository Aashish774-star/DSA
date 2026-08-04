class Solution {
public:
    int findSquareSum(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        while (true) {
            slow = findSquareSum(slow);
            fast = findSquareSum(findSquareSum(fast));

            if (slow == fast) {
                break;
            }
        }

        if (slow == 1) {
            return true;
        }

        return false;
    }
};