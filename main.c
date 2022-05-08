#include <stdio.h>
#include <string.h>


//insert time logic command here

struct schedules {
    char *name[30];
    char *duration[4]; 
    int priority;
};

int main()
{
    struct schedules schedule1;
    printf("Enter the name of the event... (30 characters max)\n");
    scanf ("%s", schedule1.name);
    printf("Enter the priority of the event... (1 for earliest)\n");
    scanf ("%d", &schedule1.priority);
    printf("Enter the duration of the event... (format HHMM)\n");
    scanf ("%s", schedule1.duration);



printf("\n");
printf("%-35s %-13s %s", "Name", "Priority", "Duration\n");
printf("%-35s %-13s %s", "----------------------------------", "------------", "----------\n");
printf("%-35s %-13d %s", schedule1.name, schedule1.priority, schedule1.duration);

return 0;
}