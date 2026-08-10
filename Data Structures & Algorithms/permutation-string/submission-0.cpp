class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left =0;
        int windowsize = s1.size();
        int n = s2.size();
        unordered_map<char,int> mp1;
        for(int i =0; i< windowsize; i++){
            mp1[s1[i]]++;
        }
        unordered_map<char,int> mp2;
        int counter =0;
        for(int right =0; right<n; right++){
            mp2[s2[right]]++;
            counter++;
            if(counter> windowsize){
                counter--;
                mp2[s2[left]]--;
                if(mp2[s2[left]] == 0){
                    mp2.erase(s2[left]);
                }
                left++;
            }
            if(mp1 == mp2){
                return true;
            }
        }
        return false;
    }
};
