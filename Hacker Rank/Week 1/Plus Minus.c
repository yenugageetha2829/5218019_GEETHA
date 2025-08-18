#include <stdio.h>
int main() {
    int count;
    //array size
    if (scanf("%d", &count) != 1) {
        return 1; 
    }
     int pos = 0, neg = 0, zero = 0;//counters for positive,negative,zero values
     for (int i = 0; i < count; i++) {
        int value;
        scanf("%d", &value);

        if (value > 0) {
            ++pos;
        } else if (value < 0) {
            ++neg;
        } else {
            ++zero;
        }
    }

    double total = (double)count;
    printf("%.6lf\n", pos / total);
    printf("%.6lf\n", neg / total);
    printf("%.6lf\n", zero / total);

    return 0;
}