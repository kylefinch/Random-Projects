#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	FILE* myfile = NULL;
	myfile = fopen("test.txt", "r+");
	if (myfile == NULL){
		printf("GET FUCKED");
		return 1;
	}
	
	char base[80] = "identifier::",
		 search[80];
	char tmp[80];
	int bytes = 20;
		 
	printf("Whats your string??\n");
	scanf("%s", search);
	printf("Searching...\n");
	while (fgets(tmp, bytes, myfile) != NULL)
	{
		tmp[strlen(tmp)-1] = '\0';
		printf("Got line: %s\n", tmp);
		if (strncmp(base, tmp, strlen(base)) == 0)
		{
			bytes = (sizeof(char) * (strlen(tmp)) + 1);
			snprintf(tmp, 80, "%s%s", base, search);
			printf("%s length %d\n", tmp, (int)strlen(tmp));
			fseek(myfile, -bytes, SEEK_CUR);
			//fprintf(myfile, "%s\n", tmp);
			fputs(tmp, myfile);
			break;
		}
	}
	
	fclose(myfile);

	return 0;
}