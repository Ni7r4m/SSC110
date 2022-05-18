#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void time(char *time)
{
    

}



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
    int numUsed;

struct schedules schedule[100];

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

        else if(strcmp(input, "add") == 0){
            int number;
            printf("Enter the array location number");
            scanf ("%d", &number);

            printf("Enter the name of the event... (30 characters max)\n");
            scanf ("%s", schedule[number].name);

            if (strlen(tmpname)<30){
                printf("Enter the priority of the event... (1 as earliest)\n");
                scanf ("%d", &schedule[number].priority);
                printf("Enter the duration of the event... (format HHMM)\n"); 
                scanf ("%s", schedule[number].duration);

                printf("Added event successfully.\n");
            }
            else {
                printf("Event name is over 30 characters long.\n");
            }
        }
        

        else if(strcmp (input, "import") == 0) { //if user types the import command.
            FILE *fileHandle;
            char filename[64];
            
            printf("\n" "Please enter the txt file name.\n");
            scanf ("%s", filename);

            fileHandle = fopen(filename, "r");
            if(fileHandle != NULL)
            {
                char buffer[200];  // assume all lines are less than 199 characters
                int n = 0;
                
                while(fgets(buffer, 200, fileHandle) != NULL) //checks if there is a line
                {
                    if(fscanf(fileHandle, "%30[^ ,\n\t], %3[^ ,\n\t], %4[^ ,\n\t]", schedule[n].name, schedule[n].priority, schedule[n].duration) == 3) //formatting check
                    {
                        n++;
                    }
                }
                printf("Imported txt file successfully.\n");
            }

            else
            {
                printf("Cannot find the txt file. Please double-check your file name and try again.\n");
            }

            fclose(fileHandle);

        }

        else if(strcmp (input, "export") == 0) {
            FILE *fileHandle;
            char filename[64];
            int i=0;
            
            printf("\n" "Please enter a name for the exported txt file.\n");
            scanf ("%s", filename);

            fileHandle = fopen(filename, "w");
            fprintf(fileHandle, "\n" "%-35s %-13s %s\n" "%-35s %-13s %s\n", "Name", "Priority", "Duration", "----------------------------------", "------------", "----------");

            i = 0;
            numUsed = sizeof(schedule) / sizeof(schedule[0]);
            while(i < numUsed){
                fprintf(fileHandle, "%-35s %-13d %s\n", schedule[i].name, schedule[i].priority, schedule[i].duration);
                i = i+1;
            }

            printf("Exported txt file successfully.\n");
            fclose(fileHandle);

        }

        else if(strcmp(input, "exit") == 0){ //if user types the exit command.
            break;
        }

        else if(strcmp(input, "list") == 0){ //if user types the list command.
            printf("\n" "%-35s %-13s %s\n" "%-35s %-13s %s\n", "Name", "Priority", "Duration", "----------------------------------", "------------", "----------");

            int i = 0;
            numUsed = sizeof(schedule) / sizeof(schedule[0]);
            while(i < numUsed){
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