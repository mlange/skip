#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
    int line = 0;

    int skipLines;

    char buffer[409600];

    char *pathname;

    FILE *infile;

    if (argc != 3)
    {
        fprintf(stderr, "Usage: skip <lines> <filename>\n");
        exit(-1);
    }

    skipLines = atoi(argv[1]);
    pathname  = argv[2];

    infile = fopen(pathname, "r");
    if (!infile)
    {
        perror("fopen");
        exit(-1);
    }

    while (! feof(infile))
    {
        fgets(buffer, sizeof(buffer), infile);

        if (line++ >= skipLines)
            printf("%s", buffer);
    }

    fclose(infile);

    exit(0);
}
