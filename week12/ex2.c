#include <stdlib.h>
#include <unistd.h>
#include <linux/input.h>
#include <stdio.h>

int main()
{
    FILE *dev;
    dev = fopen("/dev/input/by-path/platform-i8042-serio-0-event-kbd", "r");
    if (dev == NULL)
    {
        printf("Cannot open /dev/input/by-path/platform-i8042-serio-0-event-kbd\n");
        return 1;
    }
    FILE *out;
    out = fopen("ex2.txt", "w");
    
    struct input_event ie;
    while (fread(&ie, sizeof(struct input_event), 1, dev))
    {
        if (ie.type != EV_KEY) {
            continue;   
        }
        if (ie.value == 1) {
            fprintf(out, "PRESSED ");
        } else if (ie.value == 0) {
            fprintf(out, "RELEASED ");
        } else {
            continue;
        }
        fprintf(out, "0x%04x (%d)\n", ie.code, ie.code);
        fflush(out);
    }

    fclose(dev);
    fclose(out);
    return 0;
}