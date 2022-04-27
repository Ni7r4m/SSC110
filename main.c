#include <stdio.h>
#include <string.h>


//insert time logic command here

struct schedule {
    char *name;
    char *duration; 
    int priority;
};

int main()
{
    struct schedule one;
    printf("Enter the name of the event... (30 characters max)\n");
    scanf ("%s", one.name);
    printf("Enter the priority of the event... (1 for earliest)\n");
    scanf ("%d", &one.priority);
    printf("Enter the duration of the event... (format HHMM)\n");
    scanf ("%s", one.duration);

    printf("You have entered that the event %s is on the %d priority and has a duration of %s.\n", one.name, one.priority, one.duration);
}