#include <stdio.h>
#include <string.h>
#define FILE_NAME "dict.txt"
#define SOURCE_LENGTH 100
#define WORD_LENGTH 50
#define URL_LENGTH 500

void main()
{
	char MusicSource[SOURCE_LENGTH];
	char word[WORD_LENGTH];

	printf("Enter a word: ");
	scanf("%s", word);

	char url[URL_LENGTH];
	sprintf(url, "%s%s%s%s", "curl \"https://api.dictionaryapi.dev/api/v2/entries/en/", word,"\">", FILE_NAME);
	printf("%s", url);

	system(url);

	FILE *Fpdict = fopen("dict.txt", "r");
	fseek(Fpdict, 0, SEEK_END);
	int size = ftell(Fpdict);

	rewind(Fpdict);

	char link[size];
	fread(link, size, 1, Fpdict);
	fclose(Fpdict);

	char *ToDivid = ":";

	char *token = strtok(link, ToDivid);

	char *ToCheck = "\"https";

	int inIf = 0;


	while(token != NULL)
	{
		if ( !strcmp( ToCheck, token))
		{
			if ( !strcmp(ToCheck, "\"https"))
				ToDivid = ",";

			token = strtok(NULL, ToDivid);


			if ( inIf == 0)
			{
				sprintf(MusicSource, " \"vlc.exe https:%s", token);
				ToCheck = "definition";
			}

			else
			{
				token = strtok(NULL, "\"");
				if (inIf == 1)
				{	
					printf("\ndefinition: ");
					ToCheck = "example";
				}
				else
				{
					printf("\nexample: ");
				}

				printf("%s\n", token);

			}

			ToDivid = "\"";
			if (inIf == 2)
			{
				token = NULL;
			}
			inIf++;
		}
		else
		{
			token = strtok(NULL, ToDivid);
		}
	}
	printf("\nIf you want to listen pronunciation for '%s'. \nEnter 1 else enter any number expect 1: ", word);

	int choice;
	scanf("%d", &choice);

	if ( choice == 1)
		system(MusicSource);	
}