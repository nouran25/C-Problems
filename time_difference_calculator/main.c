#include <stdio.h>
#include <stdlib.h>

struct time
{
    int hours;
    int minutes;
    int seconds;
};

struct time get_time();
struct time time_difference(struct time, struct time);

int main()
{
    struct time time1, time2, diff;
    time1 = get_time();
    time2 = get_time();
    diff = time_difference(time1, time2);
    printf("The difference between the two times is: %d:%d:%d\n", diff.hours, diff.minutes, diff.seconds);

    return 0;
}

struct time get_time()
{
    struct time temp;
    printf("Enter time in hours: ");
    scanf("%d", &temp.hours);
    printf("Enter time in minutes: ");
    scanf("%d", &temp.minutes);
    printf("Enter time in seconds: ");
    scanf("%d", &temp.seconds);
    return temp;
}

struct time time_difference(struct time time1, struct time time2)
{
    struct time temp;

    // Handle seconds difference, and borrow if necessary
    if (time1.seconds < time2.seconds)
    {
        time1.minutes--;
        time1.seconds += 60;
    }
    temp.seconds = time1.seconds - time2.seconds;

    // Handle minutes difference, and borrow if necessary
    if (time1.minutes < time2.minutes)
    {
        time1.hours--;
        time1.minutes += 60;
    }
    temp.minutes = time1.minutes - time2.minutes;

    // Handle hours difference
    temp.hours = time1.hours - time2.hours;

    return temp;
}
