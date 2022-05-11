#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//insert time logic command here for calculation (should return day, time)



struct schedules {
    char name[30];
    char duration[4]; 
    int priority;
};

int main()
{
    char input[10];
    char tmpname[30];
    int tmppriority;
    char tmpduration[4];
    int i;
    int numUsed;

struct schedules schedule[100];

    printf("\n" "Starting Festival Scheduler... \n" "\n" "Type 'help' to show lists of syntaxes in the app.\n");

    
    while (1)
    {
        printf("\n" "SCHEDULER>");
        scanf ("%s", input);
        
        if(strcmp(input, "help") == 0){  //if user types the help command.
            printf("\n" "%-10s %s\n" "%-10s %s\n" "%-10s %s\n"  "%-10s %s\n" "%-10s %s\n" "%-10s %s\n",
            "ADD", "Adds an event from the schedule.",
            "DEL", "Removes an event from the schedule.",
            "EXIT", "Quits Festival Scheduler.", 
            "EXPORT", "Exports the events into a txt file.",
            "IMPORT", "Imports events from a txt file.",
            "LIST", "Shows all the list of events in Festival Scheduler."); 
        }

        else if(strcmp(input, "add") == 0){

            printf("Enter the name of the event... (30 characters max)\n");
                scanf ("%s", schedule[0].name);
                if (strlen(tmpname)<30){
                    printf("Enter the priority of the event... (leave it blank to put the event below an existing one)\n");
                    scanf ("%d", &schedule[0].priority);
                    printf("Enter the duration of the event... (format HHMM)\n"); 
                    scanf ("%s", schedule[0].duration);

                /*printf("Enter the name of the event... (30 characters max)\n");
                scanf ("%s", &tmpname);
                if (strlen(tmpname)<30){
                    printf("Enter the priority of the event... (leave it blank to put the event below an existing one)\n");
                    scanf ("%d", &tmppriority);
                    printf("Enter the duration of the event... (format HHMM)\n"); 
                    scanf ("%s", &tmpduration);

                   /* i = tmppriority - 1;
                    schedule[0].name = tmpname;
                    schedule[0].priority = tmppriority;
                    schedule[0].duration = tmpduration; */

                    printf("Added event successfully.\n");
                }
                else {
                    printf("Error! Event name is over 30 characters long.\n");
                }
        }
        /*else if (input, "del") == 0) { //if user types the del command.
            printf("\n" "Please select an event to delete based on the priority number. \n");
            scanf ("%d", &tmppriority);

            if(priority number is found on the schedule); {
                printf("You are going to remove the selected event:\n" 
                "\n" 
                "Do you want to continue? (Y/N)\n")
                scanf ("%s", input);

                if (yes); {
                    //insert remove command here
                    //updates all the priority
                    printf("Deleted event successfully.\n")
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
                printf("\n" "Import successful!\n");
            }
            else {
                printf("\n" "Cannot find the txt file. Please double-check your file name and try again.");
            }
        }
        */
        else if(strcmp(input, "exit") == 0){ //if user types the exit command.
            break;
        }

        else if(strcmp(input, "list") == 0){ //if user types the list command.
            printf("\n" "Day 1: \n" "\n");
            printf("%-35s %-13s %s\n" "%-35s %-13s %s\n", "Name", "Priority", "Duration", "----------------------------------", "------------", "----------");

            i = 0;
            numUsed = sizeof(schedule) / sizeof(schedule[0]);
            if(i < numUsed){
                printf("%-35s %-13d %s\n", schedule[i].name, schedule[i].priority, schedule[i].duration);
                i = i+1;
            }

        }

        else { //if command is not recognised.
            printf ("\n" "Invalid syntax. Type 'help' to show a list of syntaxes.\n");
        }

    };
    return 0;
}