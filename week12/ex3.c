#include <stdlib.h>
#include <unistd.h>
#include <linux/input.h>
#include <stdio.h>
#include <stdbool.h>

bool pressed_keys[255];

struct shortcut {
    int len;
    short int* keys;
    char* msg;
};

struct shortcut* shortcuts;

void init_shortcuts() {
    shortcuts = malloc(sizeof(struct shortcut) * 3);
    
    {
        shortcuts[0].len = 2;
        shortcuts[0].keys = malloc(sizeof(char) * 2);
        shortcuts[0].keys[0] = KEY_P;
        shortcuts[0].keys[1] = KEY_E;
        shortcuts[0].msg = "I passed the Exam!";
    }

    {
        shortcuts[1].len = 3;
        shortcuts[1].keys = malloc(sizeof(char) * 3);
        shortcuts[1].keys[0] = KEY_C;
        shortcuts[1].keys[1] = KEY_A;
        shortcuts[1].keys[2] = KEY_P;
        shortcuts[1].msg = "Get some cappuccino!";
    }

    {
        shortcuts[2].len = 3;
        shortcuts[2].keys = malloc(sizeof(char) * 3);
        shortcuts[2].keys[0] = KEY_W;
        shortcuts[2].keys[1] = KEY_I;
        shortcuts[2].keys[2] = KEY_N;
        shortcuts[2].msg = "Now's your chance to be a big shot\nBe a big, be a big, bi-ig shot";
    }
}


void check_shortcuts() {
    for (int i = 0; i < 3; i++) {
        bool pressed = true;
        for (int key = 0; key < shortcuts[i].len; key++) {
            if (!pressed_keys[shortcuts[i].keys[key]]) {
                pressed = false;
            }
        }
        if (pressed) {
            printf("%s\n", shortcuts[i].msg);
            for (int key = 0; key < shortcuts[i].len; key++) {
                pressed_keys[shortcuts[i].keys[key]] = false;
            }
        }
    }
    fflush(stdout);
}

int main()
{
    FILE *dev;
    dev = fopen("/dev/input/by-path/platform-i8042-serio-0-event-kbd", "r");

    if (dev == NULL)
    {
        printf("Cannot open /dev/input/by-path/platform-i8042-serio-0-event-kbd\n");
        return 1;
    }
    init_shortcuts();

    struct input_event ie;
    while (fread(&ie, sizeof(struct input_event), 1, dev))
    {
        if (ie.type != EV_KEY) {
            continue;   
        }
        if (ie.value > 1) {
            continue;
        }
        pressed_keys[ie.code] = ie.value;

        check_shortcuts();
        
    }

    fclose(dev);
    return 0;
}