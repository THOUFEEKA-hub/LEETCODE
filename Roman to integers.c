#include <stdio.h>
#include <string.h>
int value(char r) {
    if (r == 'I') return 1;
    if (r == 'V') return 5;
    if (r == 'X') return 10;
    if (r == 'L') return 50;
    if (r == 'C') return 100;
    if (r == 'D') return 500;
    if (r == 'M') return 1000;
    return 0;
}
int romanToInt(char *s) {
    int total = 0;
    int length = strlen(s);

    for (int i = 0; i < length; i++) {
        int current = value(s[i]);
        int next = value(s[i + 1]);

        if (current < next)
            total -= current;
        else
            total += current;
    }

    return total;
}
