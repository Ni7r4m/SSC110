#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_schedules {
    char name[30];
    char duration[4]; 
    int priority;
    struct schedules *next;
} schedules;

schedules *insert_into_list(schedules **head, int *newPriority, char *newName, char *newDuration)
{
    /* prevItem is previous, thisItem will be the one following */
    
    schedules *prevItem = NULL,
              *thisItem = *head;

    /* While our new value is greater, walk the list */
    
    for (; thisItem && *newPriority >= thisItem->priority;
         thisItem = thisItem->next)
         prevItem = thisItem;

    /* At the insertion point, or run out of list */

    /* Create the new item */

    schedules *newItem = (schedules *) malloc(sizeof(schedules));

    // Chain up next item in the list (or NULL)

    newItem->priority = *newPriority;
    newItem->next = thisItem;

    // Chain up the previous item (or we're the new head)

    if (prevItem)
        // Not the first, make the previous one point to us
        
        prevItem->next = newItem;
    else
        // We're the new head of the list

        *head = newItem;
    
    return newItem;
}


int main()
{
    schedules *head = NULL;
    char input[10];
    int i;
    int numUsed = 0;
    int numMax = 1;

    //schedules* schedule = malloc(numMax * sizeof *schedule); //allocating first few memories to be able to store data
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
                //schedule = realloc(schedule, numMax * sizeof *schedule);
            }
            
            printf("Enter the priority of the event... (1 as earliest)\n");
            scanf ("%2d", &tmppriority);
            

            printf("Enter the name of the event... (30 characters max)\n");
            scanf ("%30s", tmpname);
            

            printf("Enter the duration of the event... (format HHMM)\n"); 
            scanf ("%4s", tmpduration);

            insert_into_list(&head, &tmppriority, tmpname, tmpduration);


            numUsed++;

             /*int count; //check command
            while(count != 1)
            {
                count = 0;
                for(int a = 0; a < numUsed; a++)
                {
                    if(schedule[i].priority > schedule[i+1].priority)
                    swap(&schedule[i].priority, &schedule[i+1].priority);
                    count++;
                }
                count++;
            } */
        }

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


        /*else if (strcmp(input, "del") == 0) { //if user types the del command.

            int key;
            int success = 0;
            printf("\n" "Please select an event to delete based on the priority number. \n");
            scanf ("%d", &key);

            for(int i=0; i<numUsed; i++)
                {
                if(schedule[i].priority==key); {
                    printf("You are going to remove the selected event:\n" 
                    "\n" "Event name: %s\n" 
                    "Event duration: %s\n"
                    "Do you want to continue? (y/n)\n");
                    scanf ("%s", input);

                    if (strcmp(input, "y") == 0) {
                        memset(&array[key], 0, sizeof(array[key] ) );
                        //updates all the priority
                        printf("Deleted event successfully.\n");
                        numused--;
                    }
                    success++;
                    break;
                }
            }
            if(success != 1) {
                printf("Invalid priority number, please try again. \n");
            }
        }*/
        

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

            while(head){
                fprintf(fileHandle, "%-35s %-13d %s\n", head->name, head->priority, head->duration);
            }

            printf("Exported txt file successfully.\n");
            fclose(fileHandle);

        }


        else if(strcmp(input, "list") == 0){ //if user types the list command.
            printf("\n" "%-35s %-13s %s\n" "%-35s %-13s %s\n", "Name", "Priority", "Duration", "----------------------------------", "------------", "----------");

            while(head) {
                printf("%-35s %-13d %s\n", head->name, head->priority, head->duration);
                break;
            }
        }


        else { //if command is not recognised.
            printf ("\n" "Invalid syntax. Type 'help' to show a list of syntaxes.\n");
        }

    };
    return 0;
}