#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main(int argc, char* argv[])
{
	FILE* infile = NULL;
	FILE* outfile = fopen(argv[2], "w");
	char ch;
	int char_count = 0;

	if (argc != 3)
	{
		printf("NEED MO\n");
		return 0;
	}

	printf("%s\n", argv[0]);
	if ((infile = fopen(argv[1], "r")) == NULL)
	{
		fprintf("GET FUCKED\n", outfile);
	}
	else
	{
		ch = fgetc(infile);
		while (ch != EOF)
		{
			fprintf(outfile, "%.2x ", ch);

			if ((char_count % 2) == 1)
				fputc(' ', outfile);
			char_count++;

			if ((char_count % 16) == 0)
				fputc('\n', outfile);

			ch = fgetc(infile);
		}

		while ((char_count % 16) != 0)
		{
			fprintf(outfile, "00 ");

			if ((char_count % 2) == 1)
				fputc(' ', outfile);
			char_count++;
		}
		fputc('\n', outfile);
	}
	printf("Wrote %d characters\n", char_count);

	fclose(infile);
	fclose(outfile);
	return 0;
}