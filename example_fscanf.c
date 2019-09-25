/*
	Example of fprintf and fscanf on IT Training.
	Written by Chun-Hsiang Chao
	Date:20190925
*/
#include <stdio.h>

int main (int argc, char *argv[]){
    FILE *in, *out;
    struct pirate {
        char name[100]; /* real name */
        unsigned long booty; /* in pounds sterling */
        unsigned int beard_len; /* in inches */
    } p, blackbeard = { "Edward Teach", 950, 48 };

    out = fopen ("data", "w");

    if (!out) {
        perror ("fopen");
        return 1;
    }

	fprintf(out, "%s\n%lu\n%u\n", blackbeard.name, blackbeard.booty, blackbeard.beard_len);
    if (fclose (out)) {
        perror ("fclose");
        return 1;
    }
    
    in = fopen ("data", "r");

    if (!in) {
        perror ("fopen");
        return 1;
    }
	fscanf(in, "%[^\n]%lu\n%u\n", p.name, &p.booty, &p.beard_len);
    if (fclose (in)) {
        perror ("fclose");
        return 1;
    }

    printf ("name=\"%s\" booty=%lu beard_len=%u\n",
                p.name, p.booty, p.beard_len);
    return 0;
}

