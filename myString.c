#include <stdio.h>
#include <string.h>
#include "myString.h"

int getLine(char line[]){
    char cha = getchar();

	int i =0;

    while( cha != '\n'  ){
        line[i] = cha;
        cha = getchar();
        if (cha == EOF){
            return 0;
        }
        if (i<LINE){
        i++;
        }
        else{
        	break;
        }
    }

    line[i] = '\0';
    return strlen(line);
}


int substring(char *str1, char *str2) {
	char *char1 = str1;
	char *char2 = str2;
	while (*char1 != '\0' && *char2 != '\0') {

		if (*char1 == *char2) {
			char1++;
			char2++;
		}

		if (*char2 == '\0') {
			return 1;
		}
		char2 = str2;
		char1++;

	}
	return 0;

}


void print_lines(char *word ) {
    char line[LINE];
    int size = getLine(line);

    while (size != 0){
        if (substring(line,word)){
            printf("%s \n",line);
        }
        size = getLine(line);
    }
}

int getword(char w[]) {
    char cha = getchar();

	int i =0;
    if (cha == EOF)
        return 0;
    while(cha != '\n' && cha != '\t' && cha != ' '){
        w[i] = cha;
        cha = getchar();
        if (cha == EOF)
            return 0;
        if (i!=WORD){
        i++;
        }
        else
        	break;
    }
    w[i] = '\0';
    return strlen(w);
}





int similar (char * s, char * t, int n){
    int sIndex = 0;
    int tIndex = 0;

    while (s[sIndex] !='\0'|| t[tIndex]!='\0'){
        if(s[sIndex] == t[tIndex]){
            tIndex++;
            sIndex++;
        }
        else{
            n--;
            if (n < 0) {
                return 0;
            }
            sIndex++;
        }
    }

    if (!s[sIndex] && !t[tIndex])
        return 1;

    return 0;
}







void print_similar_words(char *word) {
    char w[WORD];
    int wSize = getword(w);

    while (wSize !=0){
        if (similar(w,word,1)){
            printf("%s \n",w);
        }
        wSize = getword(w);
    }
}
