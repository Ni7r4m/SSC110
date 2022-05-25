#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_schedules {
    char name[30];
    char duration[5]; 
    int priority;
    char start[5];
    char finish[5];
    int delay;
    int day;
} schedules;


int sort (const void * a, const void * b)
{

  schedules *scheduleA = (schedules *)a;
  schedules *scheduleB = (schedules *)b;

  return ( scheduleA->priority - scheduleB->priority );
}

char *char2min(const char *str, size_t n)
{
    size_t len = strlen(str);
    return (char *)str + len - n;
}

void int2time(char *output, int *hr, int *min)
{
    char tmp1[2]; //min
    char tmp2[4]; //hr
    char tmp0[2];
    char tmp3[2];
    
    sprintf(tmp1, "%d", *min);
    strcpy (tmp3, tmp1);
    if(strlen(tmp3) < 2) //if number is below 10 minutes
    {
        strcpy(tmp0, "0");
        strncat(tmp0, tmp1, 2);
        strcpy(tmp1, tmp0);
    }

    sprintf(tmp2, "%d", *hr);
    strcpy (tmp3, tmp2);
    if(strlen(tmp3) < 2) //ig number is below 10 hour
    {
        strcpy(tmp0, "0");
        strncat(tmp0, tmp2, 2);
        strcpy(tmp2, tmp0);
    }

    strncat(tmp2, tmp1, 2);
    strcpy(output, tmp2);
}

void calculate(int *hr, int *min, int *add_hr, int *add_min)
{
    if(*add_min + *min  >= 60) { //adds an hour if its over 60 mins
        *min = *min + *add_min - 60;
        *hr = *hr + *add_hr + 1;
        } 
    else {
        *hr = *hr + *add_hr;
        *min = *min + *add_min;
    }
}

int main()
{
    char input[10];
    int numUsed = 1;
    int delay;
    char t_close[5]; strcpy(t_close,"2200");
    char tmpduration[5];
    schedules schedule[100];
    int hr, min, tmp_hr, tmp_min;
    char c_hr[2]; c_hr[2] = 0;
    int max_hr, max_min, day;

    printf("\n" "Starting Festival Scheduler... \n" "\n" "Type 'help' to show lists of syntaxes in the app.\n");

            schedule[0].priority = 0;
            strcpy(schedule[0].name, "NULL");
            strcpy(schedule[0].finish, "0800"); //automatically reserves the first array for the start time

    
    while (1) //loops into the scheduler window until user types the exit command.
    {
        printf("\n" "SCHEDULER>");
        scanf ("%s", input);
        
        if(strcmp(input, "help") == 0){  //if user types the help command.
            printf("\n" "%-10s %s\n" "%-10s %s\n" "%-10s %s\n"  "%-10s %s\n" "%-10s %s\n" "%-10s %s\n" "%-10s %s\n" "%-10s %s\n",
            "ADD", "Adds an event from the schedule.",
            "DEL", "Removes an event from the schedule.",
            "EXIT", "Quits Festival Scheduler.", 
            "EXPORT", "Exports the events into a txt file.",
            "IMPORT", "Imports events from a txt file.",
            "LIST", "Shows all the list of events in Festival Scheduler.",
            "SETTIME", "Sets the opening and closing time of the festival.",
            "UPDATE", "Updates an event from the schedule."); 
            
        }

        else if(strcmp(input, "add") == 0){ //if user types the add command.
            int i;
            char tmpname[30];
            int tmppriority;

            printf("Enter the priority of the event... (1 as earliest)\n"); //asks user about the priority of the event.
            scanf ("%d", &tmppriority);
            i = tmppriority;
            schedule[i].priority = tmppriority;
            
            printf("Enter the name of the event... (30 characters max)\n"); //asks user about the name of the event.
            scanf ("%30s", tmpname);
            strcpy(schedule[i].name, tmpname);

            printf("Enter the duration of the event... (format HHMM)\n"); //ask user about the duration of the event.
            scanf ("%4s", tmpduration);
            strcpy(schedule[i].duration, tmpduration);

            printf("Enter the time needed for the event preparation... (format MM)\n"); //ask user about the duration of the event.
            scanf ("%2d", &delay);
            schedule[i].delay = delay;

            numUsed++;
            qsort (schedule, numUsed, sizeof(schedules), sort);
            printf("Added event successfully.\n");
        }
        
        else if (strcmp(input, "del") == 0) { //if user types the del command.

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
                    "Do you want to continue? (y/n)\n", schedule[key].name, schedule[key].duration);
                    scanf ("%s", input);

                    if (strcmp(input, "y") == 0) {
                        schedule[key].priority = 100-numUsed;
                        for(int count = key+1; count < numUsed; count++)
                        {
                            schedule[count].priority = schedule[count].priority-1;
                        }
                        qsort (schedule, numUsed, sizeof(schedules), sort);
                        printf("Deleted event successfully.\n");
                        numUsed--;
                    }
                    success++;
                    break;
                }
            }
            if(success != 1) {
                printf("Invalid priority number, please try again. \n");
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
                char delay[3];
                char priority[3];
                int n = 1;
                
                while(fgets(buffer, 200, fileHandle) != NULL) //checks if there is a line 
                {
                    if(sscanf(buffer, "%30[^ ,\n\t], %3[^ ,\n\t], %4[^ ,\n\t], %2[^ ,\n\t]", schedule[n].name, priority, schedule[n].duration, delay) == 4)
                     //formatting check
                    {
                        printf("%d", n);
                        schedule[n].priority = atoi(priority);
                        schedule[n].delay = atoi(delay);
                        n++;
                        numUsed++;
                        qsort (schedule, numUsed, sizeof(schedules), sort);
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

        else if(strcmp (input, "export") == 0) { //if user types the export command.
            FILE *fileHandle;
            char filename[64];
            int i=1;
            
            printf("\n" "Please enter a name for the exported txt file.\n");
            scanf ("%s", filename);

            fileHandle = fopen(filename, "w");
            fprintf(fileHandle, "\n" "%-35s %-13s %-6s %-11s %-8s %-8s\n" "%-35s %-13s %-6s %-11s %-8s %-8s\n", "Name", "Priority", "Day", "Duration", "Start", "End",
             "----------------------------------", "------------", "-----","----------", "-------", "-------");

            while(i != numUsed){
                fprintf(fileHandle, "%-35s %-13d %-6d %-11s %-8s %-8s\n", schedule[i].name, schedule[i].priority, schedule[i].day, schedule[i].duration, schedule[i].start, schedule[i].finish);
                i++;
            }

            printf("Exported txt file successfully.\n");
            fclose(fileHandle);

        }

        else if(strcmp(input, "exit") == 0){ //if user types the exit command.
            break;
        }

        else if(strcmp(input, "list") == 0){ //if user types the list command.
            printf("\n" "%-35s %-13s %-6s %-11s %-8s %-8s\n" "%-35s %-13s %-6s %-11s %-8s %-8s\n", "Name", "Priority", "Day", "Duration", "Start", "End",
             "----------------------------------", "------------", "-----","----------", "-------", "-------");

            int i = 1;
            while(i != numUsed){
                printf("%-35s %-13d %-6d %-11s %-8s %-8s\n", schedule[i].name, schedule[i].priority, schedule[i].day, schedule[i].duration, schedule[i].start, schedule[i].finish);
                i++;
            }

        }

        else if(strcmp(input, "settime") == 0){ //if user types the settime command.
            printf("Festival opening and closing time is set to %s and %s.\n", schedule[0].finish, t_close);
            printf("Please enter the opening time of the festival. (HHMM)\n");
            scanf ("%4s", schedule[0].finish);
            
            printf("Please enter the closing time of the festival. (HHMM)\n");
            scanf ("%4s", t_close);
            printf("Opening and closing time successfully changed to  %s and %s.\n", schedule[0].finish, t_close);
        }

        else if(strcmp(input, "update") == 0){ //if user types the settime command.
            int key;
            char tmpname[30];
            int done = 0;

            printf("Please select an event to delete based on the priority number.\n"); //asks user about the priority of the event.
            scanf ("%d", &key);

            for(int i=0; i<numUsed; i++)
                {
                if(schedule[i].priority==key); {
                    printf("%d", key);
                printf("Enter the name of the event... (30 characters max)\n"); //asks user about the name of the event.
                scanf ("%30s", tmpname);
                strcpy(schedule[key].name, tmpname);
                

                printf("Enter the duration of the event... (format HHMM)\n"); //ask user about the duration of the event.
                scanf ("%4s", tmpduration);
                strcpy(schedule[key].duration, tmpduration);

                printf("Enter the time needed for the event preparation... (format MM)\n"); //ask user about the duration of the event.
                scanf ("%2d", &delay);
                schedule[key].delay = delay;
                printf("Updated event successfully.\n");
                done++;
                break;
                }
            }
            if(done!=1)
            {
                printf("Error. The priority number inputted cannot be found.\n");
            }
        }

        else { //if command is not recognised.
            printf ("\n" "Invalid syntax. Type 'help' to show a list of syntaxes.\n");
        }

        //calculating the time after every operation
        strncpy(c_hr, t_close, 2);
        max_hr = atoi(c_hr); //1
        max_min = atoi(char2min(t_close, 2));
        day = 1;
        for(int count = 1; count < numUsed; count++) //loop for the calculation of start and end time
        {
            strncpy(c_hr, schedule[count-1].finish, 2);
            hr = atoi(c_hr); //1
            min = atoi(char2min(schedule[count-1].finish, 2));
            tmp_hr = 0;
            tmp_min = schedule[count].delay;
            
            calculate(&hr, &min, &tmp_hr, &tmp_min);
            int2time(tmpduration, &hr, &min);
            strcpy(schedule[count].start, tmpduration); //calculates start time

            strncpy(c_hr, schedule[count].duration, 2);
            tmp_hr = atoi(c_hr); 
            tmp_min = atoi(char2min(schedule[count].duration, 2)); //initiates time to be added to the start time

            calculate(&hr, &min, &tmp_hr, &tmp_min);

            if(hr>max_hr && min>max_min) //if exceeds the closing time
            {
                
                strncpy(c_hr, schedule[0].finish, 2);
                hr = atoi(c_hr); 
                min = atoi(char2min(schedule[0].finish, 2)) + schedule[count].delay;
                int2time(tmpduration, &hr, &min);
                strcpy(schedule[count].start, tmpduration); //updates the starting time

                calculate(&hr, &min, &tmp_hr, &tmp_min);
                day++;
            }

            int2time(tmpduration, &hr, &min); 
            strcpy(schedule[count].finish, tmpduration); //converts and puts the string on the final time to the struct
            schedule[count].day = day;
        }
    };
    return 0;
}