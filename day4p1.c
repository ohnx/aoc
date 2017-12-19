#include <stdio.h>
#include <string.h>
#include "hashmap.h"

int main() {
    char buf[128];
    char *p;
    char *start;
    hashmap *map;
    int numValid = 0;

    *buf = 0;

    /* loop for a while */
    while (1) {
        /* reset values */
        map = hashmap_new();
        start = p = buf;
        /* read line */
        fgets(buf, 128, stdin);
        buf[strlen(buf)-1] = 0;

        if (*buf == '!') break;

        /* put each token into the hashmap */
        do {
            if (*p == ' ') {
                /* split and add to hashmap */
                *p = '\0';
                printf("checking token `%s`... %s\n", start, hashmap_get(map, start) != NULL ? "found!" : "not found.");
                if (hashmap_get(map, start) != NULL) {
                    /* repeated, ignore this passphrase */
                    goto ignore_passphrase;
                } else {
                    hashmap_put(map, start, (void *)1);
                }
                start = p + 1;
            }
        } while (*(++p) != '\0');

        printf("checking token `%s`... %s\n", start, hashmap_get(map, start) != NULL ? "found!" : "not found.");
        if (hashmap_get(map, start) != NULL) goto ignore_passphrase;

        numValid++;

    ignore_passphrase:
        hashmap_destroy(map);
        printf("numValid = %d\n", numValid);
    }

    printf("%d\n", numValid);

    return 0;
}
