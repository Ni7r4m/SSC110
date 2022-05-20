#include <stdio.h>
#include <string.h>
#include <stdlib.h>


 /* void time(char *time)
{
}



/*void count(char *a, char *b)
{
    int hStart, mStart, hEnd, mEnd;
    hStart = (atoi(strlen(*a, )));
    mStart = (atoi(*a));
    hEnd = (atoi(*b));
    mEnd = (atoi(*b));

    if(mStart + mEnd>=60)
    {
        hEnd++;
        strcpy()
    }
}*/


typedef struct s_schedules {
    char name[30];
    char duration[4]; 
    int priority;
} schedules;

int main()
{
    char input[10];
    int i;
    int numUsed = 0;
    int numMax = 1;

    schedules* schedule = malloc(numMax * sizeof *schedule); //allocating first few memories to be able to store data
    printf("\n" "Starting Festival Scheduler... \n" "\n" "Type 'help' to show lists of syntaxes in the app.\n");

    
    while (1) //loops into the scheduler window until user types the exit command.
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


        else if(strcmp(input, "add") == 0){ //if user types the add command.
            char tmpname[30];
            int tmppriority;
            char tmpduration[4];
            int i = 0;
            int hour = 0;
            int min = 0;
            
            if(numUsed == numMax)
            {
                numMax++;
                schedule = realloc(schedule, numMax * sizeof *schedule);
            }
            
            printf("Enter the priority of the event... (1 as earliest)\n");
            scanf ("%d", &tmppriority);
            i = tmppriority-1;
            schedule[i].priority = tmppriority;
            

            printf("Enter the name of the event... (30 characters max)\n");
            scanf ("%s", schedule[i].name);
            

            printf("Enter the duration of the event... (format HHMM)\n"); 
            scanf ("%s", schedule[i].duration);
            numUsed++;

            /*while ()
            {
                printf("Please enter a number.");
                scanf ("%d", &tmppriority);
            }
            if() //priority have no duplicate entry
            {
                i = tmppriority-1;
                printf("Enter the name of the event... (30 characters max)\n");
                scanf ("%s", tmpname);

                

                if (strlen(tmpname)<30){
                    printf("Enter the duration of the event... (format HHMM)\n"); 
                    scanf ("%s", tmpduration);

                    if() //checks if tmpduration can be converted to hour and minutes
                    {
                        printf("Added event successfully.\n");
                    }
                    else {
                        printf("Error! Duration is not in the correct format.\n");
                    }
                }

                else {
                    printf("Error! Event name is over 30 characters long.\n");
                }
            
            else {
                printf("Error! Priority number already exist on a list.\n");
            } */

/*
        else if (input, "del") == 0) { //if user types the del command.
            printf("\n" "Please select an event to delete based on the priority number. \n");
            scanf ("%d", &tmppriority);

            if(priority number is found on the schedule); {
                printf("You are going to remove the selected event:\n" 
                "\n" 
                "Do you want to continue? (y/n)\n")
                scanf ("%s", input);

                if (strcmp(input, "y") == 0) {
                    //insert remove command here
                    //updates all the priority
                    printf("Deleted event successfully.\n")
                }
            }
            else() {
                printf("Invalid priority number, please try again. \n");
            } */
        }
        
        else if(strcmp(input, "exit") == 0){ //if user types the exit command.
            break;
        }


        else if(strcmp (input, "export") == 0) { //if user types the export command.
            FILE *fileHandle;
            char filename[64];
            int i=0;
            
            printf("\n" "Please enter a name for the exported txt file.\n");
            scanf ("%s", filename);

            fileHandle = fopen(filename, "w");
            fprintf(fileHandle, "\n" "%-35s %-13s %s\n" "%-35s %-13s %s\n", "Name", "Priority", "Duration", "----------------------------------", "------------", "----------");

            for (i = 0; i<numUsed; i++){
                fprintf(fileHandle, "%-35s %-13d %s\n", schedule[i].name, schedule[i].priority, schedule[i].duration);
            }

            printf("Exported txt file successfully.\n");
            fclose(fileHandle);

        }


        else if(strcmp(input, "list") == 0){ //if user types the list command.
            printf("\n" "%-35s %-13s %s\n" "%-35s %-13s %s\n", "Name", "Priority", "Duration", "----------------------------------", "------------", "----------");

            for (i = 0; i<numUsed; i++){
                printf("%-35s %-13d %s\n", schedule[i].name, schedule[i].priority, schedule[i].duration);
            }
        }


        else { //if command is not recognised.
            printf ("\n" "Invalid syntax. Type 'help' to show a list of syntaxes.\n");
        }

    };
    return 0;
}