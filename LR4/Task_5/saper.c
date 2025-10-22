#include "stdlib.h"
#include <stdio.h>
#include "saper.h"

char** createField(int n, int m){
    char **field=(char**)malloc(sizeof(char*)*n);
    for (int i = 0; i < n; i++){
        field[i]=(char *)malloc(sizeof(char)*m);
    }
    return field;
}

char** inputField(int n, int m,char s, char** field){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            field[i][j]=s;
        }
    }
    return field;
}
char** inputNumbersField(int n, int m,char** field){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (field[i][j] != '*') {
                int mines=0;
                for (int ai = -1; ai<=1; ai++){
                    for (int aj = -1; aj <= 1; aj++){
                        if (ai==0 && aj==0) continue;
                        int ni=i+ai, mj=j+aj;
                        if (ni>=0 && ni<n && mj>=0 && mj<m){
                            if (field[ni][mj]=='*') {
                                mines++;
                            }
                        }
                    }
                }
                field[i][j] = mines + '0';
            }
        }
    }
    return field;
}


void freeField(int n, char** field){
    for (int i = 0; i < n; i++)
    {
        free(field[i]);
    }
    free(field);
    
}