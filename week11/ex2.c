#include <dirent.h> 
#include <stdio.h> 
#include <string.h> 

int main() {
    DIR *d;
    struct dirent *dir;
    d = opendir("/");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0)
                printf("%s\n", dir->d_name);
        }
        closedir(d);
    }
    return 0;
}