#include "header.h"

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ransomNoteCount[26] = {0};
        int magazineCount[26] = {0};
        // count the characters in ransomNote
        int len_ransomNote = ransomNote.size();
        for(int i = 0; i < len_ransomNote; i++) {
            ransomNoteCount[ransomNote[i]-'a']++;
        }

        // count the characters in magazine
        int len_magazine = magazine.size();
        for(int i = 0; i < len_magazine; i++) {
            magazineCount[magazine[i] - 'a']++;
        }

        // compare them both
        for(int i = 0; i < 26; i++) {
            if(ransomNoteCount[i] > magazineCount[i]) return false;
        }
        return true;
    }
};
