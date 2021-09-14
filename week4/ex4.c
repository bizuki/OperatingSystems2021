#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if(argc == 1) {
        return 0;
    }

    if (argv[argc - 1] == "&") {
        if (fork() != 0) {
            return 0;
        }
    }
    execv(argv[1], argv + 1);
}
// need to specify full path, but i think it's not that bad)
