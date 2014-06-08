// The set [1,2,3,…,n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order,
// We get the following sequence (ie, for n = 3):

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.

// Note: Given n will be between 1 and 9 inclusive.

class Solution {
public:
    string getPermutation(int n, int k) {
        string res("");
        vector<int> coeff(n, 0);
        int f = fact(n-1);
        int tmp = k-1;
        for(int i = n-1; i > 0; --i) {
            coeff[i] = tmp/f;
            tmp = tmp%f;
            f /= i;
        }
        vector<int> nums(n, 0);
        for(int i = 0; i < n; ++i)
            nums[i] = i+1;
        for(int i = n-1; i >= 0; --i) {
            vector<int>::iterator it = nums.begin()+coeff[i];
            res += '0'+*it;
            nums.erase(it);
        }
        return res;
    }
    
    int fact(int n) {
        int res = 1;
        for(int i = 2; i <= n; ++i)
            res *= i;
        return res;
    }
};
