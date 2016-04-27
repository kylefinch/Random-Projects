#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	FILE* myfile = NULL;
	myfile = fopen("test3.txt", "r+");

	char base[80] = "identifier::",
		search[80] = "new";
	char tmp[80];
	int pos = ftell(myfile), num = 0;
	size_t size = 80;

	//while (fgets(tmp, 80, myfile) != NULL)
	while ((num = getline(&tmp, &size, myfile)) != -1)
	{
		if (strncmp(base, tmp, strlen(base)) == 0)
		{
			// Wipe out the newline from fgets()
			tmp[strlen(tmp) - 1] = '\0';
			sprintf(tmp, "%s%s%s", base, search, "\0");
			//snprintf(tmp, 80, "%s%s", base, search);
			// go to the beginning of the last line
			fseek(myfile, pos, SEEK_SET);
			// write the line
			fprintf(myfile, "%s\n", tmp);
			// flush to the file
			fflush(myfile);
			break;
		}
		// capture the position of the beginning of the next line
		pos = ftell(myfile);
	}

	fclose(myfile);

	return 0;
}