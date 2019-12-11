#include "adb.h"

int main()
{
    detectADB (adbLocation);
    printf("ADB FOUND AT: %s", adbLocation);
    detectFastboot (fastbootLocation);
    printf ("Fastboot found at: %s", fastbootLocation);
    logcat(NULL);
    reboot(SYSTEM,NULL);

}

