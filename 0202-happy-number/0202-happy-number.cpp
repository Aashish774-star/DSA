class Solution {
public:
    int findSqSum(int n) {
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

        while(fast != 1)
        {
            slow = findSqSum(slow);
            fast = findSqSum(findSqSum(fast));
            if(slow == fast && slow != 1)
            {
                return false;
            }
        }
        return true;
    }
};