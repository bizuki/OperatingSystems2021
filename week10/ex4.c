#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <string.h>

struct file_info {
    long inode;
    int max_len;
    int current_len;
    char** files;
};

struct file_info create_new_file_info() {
    struct file_info info;
    info.inode = -1;
    info.max_len = 1;
    info.current_len = 0;
    info.files = malloc(sizeof(char*));
    return info;
}

int main() {
    DIR *dirp = opendir("./tmp");

    if (dirp == NULL) {
        printf("Can't find directory with name tmp\n");
        return 1;
    }


    struct dirent* current_file;
    int current_size = 0;
    int size = 1;

    struct file_info* file_infos = malloc(sizeof(struct file_info));
    file_infos[0] = create_new_file_info();
    while ((current_file = readdir(dirp)) != NULL) {
        struct stat fstat;
        char* file_path = malloc(4 + strlen(current_file->d_name));
        if (strcmp(current_file->d_name, ".") == 0 || strcmp(current_file->d_name, "..") == 0) {
            continue;
        } 
        strcpy(file_path, "tmp/");
        strcat(file_path, current_file->d_name);

		stat(file_path, &fstat);

        if (fstat.st_nlink < 2) {
            continue;
        }

        bool inserted = false;

        for (int i = 0; i < current_size; i++) {
            if (file_infos[i].inode != fstat.st_ino) {
                continue;   
            }
            // adding to list
            if (file_infos[i].max_len == file_infos[i].current_len) {
                file_infos[i].max_len *= 2;
                file_infos[i].files = realloc(file_infos[i].files, sizeof(char*) * file_infos[i].max_len);
            }
            file_infos[i].files[file_infos[i].current_len] = current_file->d_name;
            file_infos[i].current_len++;
            inserted = true;
        }

        if (inserted) {
            continue;
        }
        
        if (size == current_size) {
            size *= 2;
            file_infos = realloc(file_infos, sizeof(struct file_info) * size);
        }

        file_infos[current_size] = create_new_file_info();
        file_infos[current_size].inode = fstat.st_ino;
        file_infos[current_size].files[0] = current_file->d_name;
        file_infos[current_size].current_len++;
        current_size++;
    }

    for (int i = 0; i < current_size; i++) {
        printf("%s - ",  file_infos[i].files[0]);
        for(int j = 1; j < file_infos[i].current_len; j++) {
            printf("%s ", file_infos[i].files[j]);
        }
        printf("\n");
        free(file_infos[i].files);
    }
    free(file_infos);
    closedir(dirp);
}