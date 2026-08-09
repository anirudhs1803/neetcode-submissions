class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> mp;
        int left =0;
        int maxlen =0;
        int n = s.size();

        for(int right =0; right<n ; right++){
            while(mp.count(s[right])){
                mp.erase(s[left]);
                left++;
            }
            mp.insert(s[right]);
            maxlen = max(maxlen, right-left+1);
        }
        return maxlen;
    }
};
