class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        unordered_map<char, int> mp2;

        for(char i : s){
            mp[i]++;
        }
        for(char j : t){
            mp2[j]++;
        }

        if(mp == mp2){
            return true;
        }
        else{
            return false;
        }
    }
};
