#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        return 0;
    }
    
    if (argc > 2) {
        printf("This shell can only take command without any parameters");
    }

    system(argv[1]);
}
