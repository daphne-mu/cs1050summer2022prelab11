/*
 * CS1050
 * Summer 2022
 * Prelab 11 
 * by Dilruba Parvin
 */
#include <stdio.h>

// Symbolic Constants
#define FILENAME "DnDMonsterScores.csv"

// Main
int main(void)
{
    FILE * fp;
    char name[256];

    fp = fopen(FILENAME,"r");

    // Only move on if we are able to open the file
    if (NULL!=fp)
    {
        // Throw away the first line
        fgets(name,255,fp);
        printf("Header line was: %s\n",name);

        // Read the important data from the next line
        if (fp && !feof(fp))
        {
            int ac,hp;

            // Only print if we read the 3 fields we expect
            if (3==fscanf(fp," %[^,],%d,%d,",name,&ac,&hp))
            {
                printf("\"%s\" : AC=%d,HP=%d\n",name,ac,hp);
            }
        }
    }

    // If you open a file, you had better close it
    fclose(fp);
}
