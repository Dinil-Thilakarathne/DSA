#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

*/

char* longestCommonPrefix(char** strs, int strsSize) {
    char *LCP[200];
    int count = 0, matchedCount = 0;
    bool isMatched = false;
    for(int i = 0; i < strsSize; i++)
    {
        for(int j = 0; j < strlen(strs[i]); j++) {
            char checkChar = strs[i][j];
            // printf("%c \n", checkChar);

            for(int k = i + 1; k < strsSize; k++)
            {
                for(int q = 0;  q < strlen(strs[k]); q++)
                {

                    // printf("%c %c \n", checkChar, strs[k][q]);
                    if(strs[k][q] == checkChar){
                        LCP[count] = checkChar;
                        printf("%c ", LCP[count]);
                        matchedCount++;
                        isMatched= true;
                        break;
                    }
                }
                if(isMatched){
                    break;
                }
            }

        }
    }
    return LCP;
}


int main()
{
    char *testArray[] = {"flower","flow","flight"};
    char *LCP = longestCommonPrefix(testArray, 3);

    printf("%s", LCP);
}
