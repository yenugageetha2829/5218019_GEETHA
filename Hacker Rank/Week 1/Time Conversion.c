#include <stdio.h>
#include <string.h>
int main() {
    char input[15];
    scanf("%s", input);
    timeConversion(input);
    return 0;
}
void timeConversion(char *time12) {
    int hour, minute, second;
    char meridian[3]; //it will tells the AM or PM
    
    sscanf(time12, "%2d:%2d:%2d%s", &hour, &minute, &second, meridian);
    
    if (strcmp(meridian, "AM") == 0) {
        if (hour == 12) hour = 0; // midnight case
    } else {
        if (hour != 12) hour += 12; // add 12 except for 12 PM
    }
    printf("%02d:%02d:%02d\n", hour,minute,second);
}