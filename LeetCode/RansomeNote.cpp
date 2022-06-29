class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> rnCh(26, 0);
        vector<int> mzCh(26, 0);
        
        for(int i=0; i<ransomNote.size(); i++)
            rnCh[ransomNote[i]-'a'] ++;
        
        for(int i=0; i<magazine.size(); i++)
            mzCh[magazine[i]-'a'] ++;
        
        for(int i=0; i<26; i++)
            if(rnCh[i]>mzCh[i])
                return false;
        return true;
    }
};