class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int maxlength =0;

        for(int num: seen){
            if(!seen.count(num-1)){
                int length =1;
                int current = num;
                while(seen.count(current+1)){
                    current++;
                    length++;
                }
                maxlength = max(maxlength, length);
            }
        }

        return maxlength;
    }
};
