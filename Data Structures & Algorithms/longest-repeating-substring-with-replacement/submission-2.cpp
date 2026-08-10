class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int left =0;
        int result =0;
        int n = s.size();
        for(int right =0; right< n; right++){
            mp[s[right]]++;

            int maxfreq =0;
            for(auto& [ch,cnt] : mp){
                maxfreq = max(maxfreq, cnt);
            }

            while((right-left+1)- maxfreq > k){
                mp[s[left]]--;
                left++;

                maxfreq =0;
                for(auto&[ch,cnt] : mp){
                    maxfreq = max(maxfreq, cnt);
                }
            }
            result = max(result, right-left+1);
        }
        return result;
    }
};
