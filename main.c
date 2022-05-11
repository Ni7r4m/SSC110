#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//insert time logic command here

struct schedules {
    char *name[30];
    char *duration[4]; 
    int priority;
};

int main()
{
    //char *input[10];
    printf("\n" "Starting Festival Scheduler... \n" "\n" "Type 'help' to show lists of syntaxes in the app.\n");

    /*
    while (1)
    {
        printf("\n" "SCHEDULER>")
        scanf ("%s", input);
        
        if(insert strcmp help command here){  //if user types the help command.
            printf("\n" "%-10s %s\n" "%-10s %s\n" "%-10s %s\n" "%-10s %s\n" "%-10s %s\n" "%-10s %s\n",
            "ADD", "Adds an event from the schedule.",
            "DEL", "Removes an event from the schedule.",
            "NEXT", "Shows the next day of the festival (up to day 7).",
            "PREV", "Shows the previous day of the festival",
            "IMPORT", "Imports events from a txt file.",
            "EXIT", "Quits Festival Scheduler."); 
        };

        if (strcmp del) { //if user types the del command.
            printf("\n" "Please select an event to delete based on the priority number. \n");
            scanf ("%s", input);

            if(priority number is found on the schedule); {
                printf("You are going to remove the selected event:\n" 
                "\n" 
                "Do you want to continue? (Y/N)\n")
                scanf ("%s", input);

                if (yes); {
                    //insert remove command here
                }
            }
            else() {
                printf("Invalid priority number, please try again. \n");
            }
        }

        if(strcmp import) { //if user types the import command.
            printf();
            scanf ("%s", input);

            if(success) {
                printf("\n" "Import successful!");
            }
            else() {
                printf("\n" "Import failed! You may either have invalid txt format or that you may have mistyped the txt file name. Please double-check your txt file and try again.");
            }
        }
        
        if(strcmp exit){ //if user types the exit command.
            break;
        };

        else() { //if command is not recognised.
            printf ("\n" "Invalid syntax. Type 'help' to show a list of syntaxes.")
        };

    };
    return 0;
    */

    struct schedules schedule1;
    printf("Enter the name of the event... (30 characters max)\n");
    scanf ("%s", schedule1.name);
    printf("Enter the priority of the event... (1 for earliest)\n");
    scanf ("%d", &schedule1.priority);
    printf("Enter the duration of the event... (format HHMM)\n");
    scanf ("%s", schedule1.duration);

printf("\n" "Day 1: \n" "\n");
printf("%-35s %-13s %s\n" "%-35s %-13s %s\n", "Name", "Priority", "Duration", "----------------------------------", "------------", "----------");
printf("%-35s %-13d %s\n", schedule1.name, schedule1.priority, schedule1.duration);

return 0;
}