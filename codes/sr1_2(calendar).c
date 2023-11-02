#include <stdio.h>

int main() {
    int day, month, year, weekday;

    scanf("%d %d %d", &day, &month, &year);
    
    if ((year == 1582)&&(month == 10)&&(day>=5)&&(day<=14))
        printf("%s\n", "uncorrect date");
    else {
        if ((month == 1)||(month == 2)) {
            month += 12;
            year -= 1;
        }
    
        if ((year >= 1583) || ((year == 1582)&&((month > 10)&&(month <= 12)) || (month == 10)&&(day>=15)))
            weekday = (day + (13*month + 13)/5 + year + year/4 - year/100 + year/400 + 5) % 7;
        else
            weekday = (day + (13*month + 13)/5 + year + year/4 + 3) % 7;


        switch (weekday) {
            case 0:
                printf("%s\n", "monday");
                break;
            case 1:
                printf("%s\n", "tuesday");
                break;
            case 2:
                printf("%s\n", "wednesday");
                break;
            case 3:
                printf("%s\n", "thursday");
                break;
            case 4:
                printf("%s\n", "friday");
                break;
            case 5:
                printf("%s\n", "saturday");
                break;
            case 6:
                printf("%s\n", "sunday");
                break;
            };
    }
    return 0;
}
