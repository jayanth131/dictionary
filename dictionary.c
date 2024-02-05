#include <stdio.h>
#include <string.h>
#define FILE_NAME "dict.txt"
#define SOURCE_LENGTH 150
#define WORD_LENGTH 40
#define URL_LENGTH 300

void main()
{
	char Music_Source[SOURCE_LENGTH];
	char given_word[WORD_LENGTH];

	printf("Enter a word: ");
	scanf("%s", given_word);

	char url[URL_LENGTH];
	sprintf(url, "%s%s%s%s", "curl \"https://api.dictionaryapi.dev/api/v2/entries/en/", given_word,"\">", FILE_NAME);
	printf("%s", url);

	system(url);

	FILE *Fp_dict = fopen("dict.txt", "r");
	fseek(Fp_dict, 0, SEEK_END);
	int size = ftell(Fp_dict);

	rewind(Fp_dict);

	char link[size];
	fread(link, size, 1, Fp_dict);
	fclose(Fp_dict);

	char *ToDivid = ":";

	char *tokenizer = strtok(link, ToDivid);

	char *ToCheck = "\"https";

	int inIf = 0;


	while(tokenizer != NULL)
	{
		if ( !strcmp( ToCheck, token))
		{
			if ( !strcmp(ToCheck, "\"https"))
				ToDivid = ",";

			tokenizer = strtok(NULL, ToDivid);


			if ( inIf == 0)
			{
				sprintf(Music_Source, " \"vlc.exe https:%s", tokenizer);
				ToCheck = "definition";
			}

			else
			{
				tokenizer = strtok(NULL, "\"");
				if (inIf == 1)
				{	
					printf("\ndefinition: ");
					ToCheck = "example";
				}
				else
				{
					printf("\nexample: ");
				}

				printf("%s\n", tokenizer);

			}

			ToDivid = "\"";
			if (inIf == 2)
			{
				tokenizer = NULL;
			}
			inIf++;
		}
		else
		{
			tokenizer = strtok(NULL, ToDivid);
		}
	}
	printf("\nIf you want to listen pronunciation for '%s'. \nEnter 1 else enter any number expect 1: ", given_word);

	int choice;
	scanf("%d", &choice);

	if ( choice == 1)
		system(Music_Source);	
}
