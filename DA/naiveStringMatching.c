#include <stdio.h>
#include <string.h> 

void search(char *pat, char *txt){
    int m = strlen(pat); 
    int n = strlen(txt); 

    //Sliding through the text
    for(int i = 0; i <= n-m; i++){
        int j;
        //Checking if there's any mismatch between the characters
        for (j = 0 ; j < m; j++){
            if (txt[i + j] != pat[j]){
                break;
            }
        }
        //Checking if the pattern matches.
        if (j == m){
            printf("Pattern found at index %d\n", i);
        }
    }
}

int main(){
    char txt[25] = "AABAAABA";
    char pat[25] = "AAC";
    search(pat, txt);
    return 0;
}