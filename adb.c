//
// Created by hectorr on 12/4/19.
//

#include "adb.h"
char * partitions[] = {"system","recovery","bootloader","edl"};

ERROR_CODES detectADB(char *dest)
{
    char buffer[BUFFER_SIZE];
    FILE * process = popen("which adb","r");
    fgets(buffer, sizeof ( buffer) -1, process);
    sprintf(dest,"%s",buffer);
    return NO_ERROR;
}

ERROR_CODES detectFastboot(char * dest)
{
    char buffer[BUFFER_SIZE];
    FILE * processPtr = popen("which fastboot","r");
    fgets(buffer, sizeof ( buffer) -1, processPtr);
    sprintf (dest,"%s",buffer);
    return NO_ERROR;
}

void reboot(PARTITION part, char * devID)
{
    char command[BUFFER_SIZE];
    if(devID == NULL)
    {
        sprintf(command, "adb reboot %s",partitions[part]);
    } else{
        sprintf(command, "adb -s %s reboot %s",devID,partitions[part]);

    }
    FILE *processPtr = popen(command,"r");
    pclose(processPtr);
}

void logcat(char * devID)
{
    char command[80];
    if(devID == NULL)
    {
        sprintf (command, "x-terminal-emulator -e '%s %s'", adbLocation, "logcat");

    } else
    {
        sprintf ( command, "x-terminal-emulator -e '%s -s %s %s'", adbLocation, devID, "logcat" );
    }
    FILE * processPtr = popen(command,"r");
    pclose(processPtr);
}

void listDevices(char** deviceIds, size_t arraySize)
{
    char command[80];
    char buffer[1024];
   // sprintf (command,"/usr/bin/adb devices");
    FILE * outFile = popen ("/usr/bin/adb devices","r");
    if(outFile == NULL)
    {
        printf("ERROR OPENING PROCES");
    }
    int counter = 0;
    while(fgets(buffer,sizeof(buffer),outFile) != NULL)
    {
        printf("%s",buffer);
    }

}
