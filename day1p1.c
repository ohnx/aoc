#include <stdio.h>

int main() {
    char buf[4097];
    char *p;
    char lastChar;
    unsigned int runningTotal;
    unsigned long int sum;

    /* read input */
    fscanf(stdin, "%4096s", buf);

    /* variable initialization */
    lastChar = *buf;
    runningTotal = 0;
    sum = 0;
    p = buf;

    /* loop through everything */
    while (*(++p) != '\0') {
        if (*p == lastChar) {
            /* increment running total */
            runningTotal++;
        } else if (runningTotal > 0) {
            /* add once it's done */
            sum += runningTotal * (lastChar - '0');
            runningTotal = 0;
        }
        /* update last char */
        lastChar = *p;
    }

    /* add the last bit */
    if (runningTotal > 0) {
        /* add once it's done */
        sum += runningTotal * (lastChar - '0');
        runningTotal = 0;
    }

    /* check the last character */
    if (*buf == *(--p)) {
        sum += (*buf - '0');
    }

    /* output sum */
    printf("%lu\n", sum);

    return 0;
}
