#include <stdio.h>
#include <string.h>
#include "myString.h"


int main()
{
    char word[WORD];
    char option[WORD];
    getword(word);
    getword(option);

    if(option[0] == 'a')
        print_lines(word);

    if(option[0] == 'b') {
        print_similar_words(word);
    }
    return 0;
}
