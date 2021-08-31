#include <stdio.h>
#include <string.h>


int main (void) {
    char *string;
    printf("Please type a string you want to reverse\n");
    fflush(stdout);
    {
        size_t len = 0;
        getline(&string, &len, stdin);
    }

    unsigned int string_length = strlen(string);

    char *l = string, *r = string + string_length - 1;
    char tmp;

    while (l < r) {
        tmp = *r;
        *r = *l;
        *l = tmp;
        l++;
        r--;
    }
    printf("Your reversed string - \"%s\"", string);
}