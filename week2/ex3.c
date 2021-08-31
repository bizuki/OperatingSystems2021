#include <stdio.h>


int main (int argc, char* argv[]) {
    if (argc != 2) {
        printf("You must input only one argument - intger n");
        return 0;
    }

    int n;
    sscanf(argv[1], "%d", &n);

    char *line = (char*) malloc((2*n - 1)*sizeof(char));

    for (int i = 0; i < 2*n - 1; i++)
        line[i] = ' ';

    line[n - 1] = '*';

    puts(line);

    for (int i = 1; i < n; i++) {
        line[n - 1 + i] = '*';
        line[n - 1 - i] = '*';
        puts(line);
    }
    
    free(line);
}