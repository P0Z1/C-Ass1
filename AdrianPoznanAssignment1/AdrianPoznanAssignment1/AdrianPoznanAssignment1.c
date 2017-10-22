/*
*	description:  Starter  Code for Assignment 1
*/
#define _CRT_SECURE_NO_WARNINGS 1
#define MAX 200
#define MAX_NO_OF_MODULES  10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct moduleInfo {
	char name[6];
	//  Add your other fields here
	
	char modName[MAX+1];
	char moduleCode[MAX+1];
	int modId;
	int CA;
	int exam;

};

void getModuleDetails(struct moduleInfo* moduleInfo);
int loadInfo(struct moduleInfo list[]);
void showInfo(struct moduleInfo list[], int numOfElements);
void openWebPage(int id);
void generateCode(char* longName, char* shortName, int max);

int main()
{
	printf("Hello world!\n");
	int choice = 99;



	// load modules data from a file
	struct moduleInfo  listOfModules[MAX_NO_OF_MODULES];
	int noOfElements = 0;

	//  1. TODO  Complete this method to read in information from the file

	noOfElements = loadInfo(listOfModules);

	//testing
	printf("%d modules read from file\n", noOfElements);
	printf("%s\n", listOfModules[0].modName);
	printf("%s\n", listOfModules[0].moduleCode);
	printf("%d\n", listOfModules[0].modId);
	printf("%d\n", listOfModules[0].CA);
	printf("%d\n", listOfModules[0].exam);
	printf("%s\n", listOfModules[1].modName);
	printf("%s\n", listOfModules[1].moduleCode);
	printf("%d\n", listOfModules[1].modId);
	printf("%d\n", listOfModules[1].CA);
	printf("%d\n", listOfModules[1].exam); 
	printf("%s\n", listOfModules[2].modName);
	printf("%s\n", listOfModules[2].moduleCode);
	printf("%d\n", listOfModules[2].modId);
	printf("%d\n", listOfModules[2].CA);
	printf("%d\n", listOfModules[2].exam);


	do
	{
		printf("\nMenu\n\n");
		printf("1. Show Modules\n");;
		printf("2. Add a Module \n");
		printf("3. Open a Web Page\n");
		printf("4. Show calendar \n");

		scanf("%d", &choice);

		switch (choice)
		{
		case 1: /*Call function here to do the required operation*/
			showInfo(listOfModules, noOfElements);
			break;
		case 2: /*Call function here to do the required operation*/
			printf("options");

			struct moduleInfo newModule;
			getModuleDetails(&newModule);

			break;
		case 3:
			printf("OpenWebPage here for the first module in the list.\n");
			getchar();
			openWebPage(1245);
			break;
		case 4:
			printf("Goodbye\n");
			getchar();
			break;
		default: printf("Wrong Choice. Enter again\n");
			break;
		}

	} while (choice != 5);
	return 0;
}






void getModuleDetails(struct moduleInfo* moduleInfo)
{


}






int loadInfo(struct moduleInfo list[])
{
	printf("In loadInfo:\n");
	FILE* fp = NULL;
	const char fileName[] = "moduleInfo.txt";
	fp = fopen(fileName, "r");
	int itemsRead = 0;
	if (fp != NULL)
	{
		int lineType = 0;
		char line[MAX];
		while (fgets(line, MAX, fp) != NULL)
		{
			printf("Reading line type: %d : %s\n", lineType, line);

			char firstWord[100];
			int aNumber;

			//  remove /n from end of line
			int len = strlen(line);
			line[len - 1] = '\0';
			printf("Now Parsing line: %d %s\n", lineType, line);

			//  copy  information to a field in your structure
			//  Dont forge to use strcpy  for strings
			//  whether you convert it to an int will depend on the lineType
			//  if lineType = 1 then copy the name to the .name field
			//  if lineType = 3 its a module Id use sscanf to  convert it to a number. 

			//sscanf(line, "%s", firstWord);
			//sscanf(line, "%d", &aNumber);

			if (lineType == 0)
			{
				//copy module name from line into modName field of an element at position itemsRead in the list array
				strcpy(list[itemsRead].modName, line);
			}
			else if (lineType == 1)
			{
				//copy module code from line into moduleCode field of an item at position itemsRead in list array
				strcpy(list[itemsRead].moduleCode, line);
			}
			else if (lineType == 2)
			{
				//stores module id in modId field of an element at position itemsRead in the list array
				sscanf(line, "%d" , &list[itemsRead].modId);
			}
			else if (lineType == 3)
			{
				//stores continious assesment mark in the CA field of an element at position itemsRead in the list array
				sscanf(line, "%d", &list[itemsRead].CA);
			}
			else if (lineType == 4)
			{
				//stores final exam mark in the exam field of an element at position itemsRead in the list array
				sscanf(line, "%d", &list[itemsRead].exam);
			}

			lineType++;
			if (lineType == 5)
			{
				lineType = 0;
				itemsRead++;
				printf("---------------------\n");
			}

		} // end while
		fclose(fp);
	}
	else {
		printf("File %s not found\n", fileName);
	}
	return itemsRead;
}






void showInfo(struct moduleInfo list[], int numElements)
{
	for (int x = 0; x < numElements; x++)
	{
		//prints all info of a module at position x in the list array
		printf("\n%s\t\t\t%s\t%d\t%d(CA)\t%d(T)\n", list[x].modName,list[x].moduleCode,list[x].modId,list[x].CA,list[x].exam);
	}





	// from board
}


void generateCode(char* longName, char *shortName, const int max)
{
	int len = strlen(longName);
	int i = 0;
	int shortPos = 0;
	char prev = '-';
	while (i < len)
	{
		if ((prev == "-") || prev == ' ')
		{
			shortName[shortPos] = longName[i];
			shortPos++;
		}
		prev = longName[i];
		i++;
	}
	shortName[shortPos] = '\0';
}



//end of from board










void openWebPage(int id)
{

}