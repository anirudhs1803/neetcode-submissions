class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> result;
        for(int i =0; i<n; i++){
            int complement = target - nums[i];
            if (mp.count(complement)){
                result.push_back(mp[complement]);
                result.push_back(i);
                
            }
            mp[nums[i]] = i;
        }

        return result;
    }
};
