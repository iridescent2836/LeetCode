#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring_old(char * s){
    int max,left=0,right=0;
    char *s1="";
    int j=0,l;
    int haveSameChar=0;
    l=strlen(s);
    if(!strcmp(s,s1)) max=0; // if s is empty, set max = 0
    else max=1; // is s is not empty, then its length of longest substring would be at least 1. 
    for(right=0;right<l;right++){
        for(j=left;j<right;j++){
            if(s[j]!=s[right]){
                haveSameChar=0;
            }
            else {
                left=j+1;
                haveSameChar=1;
                break;
            }
        }
        if(haveSameChar==0){
            max=(max>(right-left+1))?max:(right-left+1);
        }
    }
    return max;
}


