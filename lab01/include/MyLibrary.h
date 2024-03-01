#include <stdio.h>
#include <string.h>

void PrintInfo(const char *path)
{
    printf("[INFO]:: %s\n",path);
}

void PrintName(const char *name)
{
    char Added[20];
    Added[0]=0;
    strcat(Added,"Name: ");
    strcat(Added,name);
    PrintInfo(Added);
}

/** Wynik dzialania programu:
[INFO]:: Name: Bartek
[INFO]:: /home/brachwal/workspace/ppo/2022_2023/lab01/ex
*/