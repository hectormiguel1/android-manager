//
// Created by hectorr on 12/4/19.
//

#ifndef ANDROID_MANAGER_ADB_H
#define ANDROID_MANAGER_ADB_H
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <fcntl.h>

#define BUFFER_SIZE 80
#define FASTBOOT_COMMAND "fastboot"

char adbLocation[BUFFER_SIZE];
char fastbootLocation[BUFFER_SIZE];

typedef enum {SYSTEM,RECOVERY,FASTBOOT,EMERGENCY_MODE } PARTITION;
typedef enum {NO_ERROR,ERROR} ERROR_CODES;

ERROR_CODES detectADB(char[]);
ERROR_CODES detectFastboot(char[]);
void reboot(PARTITION, char *);
void logcat(char *);
void listDevices(char **, size_t);
#endif //ANDROID_MANAGER_ADB_H
