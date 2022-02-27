#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *infile;
    FILE *outfile;
    outfile = fopen("kormos.txt", "w");
    fprintf(outfile," Kormos Balazs\n Mernokinformatikus\n YE6BLB\n stb\n");
    fclose(outfile);

    infile = fopen("kormos.txt", "r");
    char line[50];
    while(!feof(infile)){
        fgets(line, 50, infile);
        puts(line);
    }
    fclose(infile);

    return 0;
}
