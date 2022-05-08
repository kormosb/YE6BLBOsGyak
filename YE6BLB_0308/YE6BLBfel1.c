#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    char bekeres[20];
    printf("Add meg a parancsot: ");
    scanf("%s", bekeres);
    i = system(bekeres);
    return i;
}
