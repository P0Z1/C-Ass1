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
void generateCode(const char* longName, char* shortName,const int max);

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
	/*printf("%d modules read from file\n", noOfElements);
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
	printf("%d\n", listOfModules[2].exam);*/


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

			//struct moduleInfo newModule;

			//char test[] = "test";
			//strcpy(newModule.modName, test);
			
			//call getModuleDetails with the address of the next free slot in the listOfModules array
			getModuleDetails(&listOfModules[noOfElements]);
			
			//imcrement the number of elements in the listOfModules array
			noOfElements++;

			break;
		case 3:
			printf("OpenWebPage here for the first module in the list.\n");
			getchar();
			openWebPage(listOfModules[0].modId);
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



void getModuleDetails(struct moduleInfo* pModuleInfo)
{	
	//local variables to hold user input and length of name
	char name[MAX+1] = "";
	char code[MAX + 1] = "";
	int id = 0;
	int ca = 0;
	int ex = 0;
	int len = 0;
	
	//ask for name
	printf("\nENTER MODULE NAME:\n");

	//use getchar() to stop fgets() from skipping a line
	getchar();

	//get input from user
	fgets(name, MAX, stdin);

	//set len to length of name
	len = strlen(name);

	//put \0 at end of name
	name[len] = '\0';

	//ask for code
	printf("\nENTER MODULE CODE:");
	//take input
	scanf("%s", code);

	//ask for id
	printf("\nENTER MODULE ID:");
	//take input
	scanf("%d", &id);

	//ask for ca
	printf("\nENTER MODULE CONT. ASSESMENT WEIGHTING:");
	//take input
	scanf("%d", &ca);

	//ask for exam
	printf("\nENTER MODULE EXAM WEIGHTING:");
	//take input
	scanf("%d", &ex);

	//test value of name
	//printf("\nvalue of name: %s\n", name);

	//put local variables values into the fields of the struct passed in by address
	strcpy((*pModuleInfo).modName,name);
	strcpy((*pModuleInfo).moduleCode, code);
	(*pModuleInfo).modId = id;
	(*pModuleInfo).CA = ca;
	(*pModuleInfo).exam = ex;

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

			//char firstWord[100];
			//int shortIndex = 1;int aNumber;

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



			//if at line 0 of mofule details in the file
			if (lineType == 0)
			{
				//copy module name from line into modName field of an element at position itemsRead in the list array
				strcpy(list[itemsRead].modName, line);
			}
			//if at line 1 of mofule details in the file
			else if (lineType == 1)
			{
				//copy module code from line into moduleCode field of an item at position itemsRead in list array
				strcpy(list[itemsRead].moduleCode, line);
			}
			//if at line 1 of mofule details in the file
			else if (lineType == 2)
			{
				//stores module id in modId field of an element at position itemsRead in the list array
				sscanf(line, "%d" , &list[itemsRead].modId);
			}
			//if at line 3 of mofule details in the file
			else if (lineType == 3)
			{
				//stores continious assesment mark in the CA field of an element at position itemsRead in the list array
				sscanf(line, "%d", &list[itemsRead].CA);
			}
			//if at line 4 of mofule details in the file
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





//displays module information to the user via the console
void showInfo(struct moduleInfo list[], int numElements)
{
	//holds the short version of modName
	char shortName[MAX] = "";

	//for each element
	for (int x = 0; x < numElements; x++)
	{
		//call generate code to fill shortName with modules short name
		generateCode(list[x].modName, shortName, MAX);

		//print all info of a module at position x in the list array
		printf("\n%s\t%s\t%d\t%d(CA)\t%d(T)\n", shortName/*list[x].modName*/,list[x].moduleCode,list[x].modId,list[x].CA,list[x].exam);
	}//end of for loop
}


//generates short names for modules from their full names
void generateCode(const char* longName, char *shortName, const int max)
{
	//length of module name
	int len = strlen(longName);

	//position in shortName[]
	int shortIndex = 1;

	//the first character in shortName will always be the first character in longName
	shortName[0] = longName[0];

	
	// as long as x is less than the length of the longName
	for (int x = 1; x < len; x++)
	{
		//if a space at position x in longName
		if (longName[x] == ' ')
		{
			//take the character after the space and put it in shortName at position shortIndex
			shortName[shortIndex] = longName[(x+1)];
		
			//increment shortIndex
			shortIndex++;
		}//end of if
	}//end of for loop

	//put \0 at the end of shortName to end it
	shortName[shortIndex] = '\0';
}


//opens a web page based on the id passed in
void openWebPage(int id)
{
	//code from blackboard slightly modified

	//printf("\nID comming into method is: %d\n", id);

	char command[500];//used 500 instead of MAX_COMMAND
	char url[] = "https://courses.cit.ie/index.cfm/page/module/moduleId/";
	char internet[] = "C:\\PROGRA~1\\INTERN~1\\iexplore.exe ";
	

	strcpy(command, internet);
	strcat(command, url);
	char snum[MAX];
	_itoa(id, snum, 10);//changed MAX to 10 for base 10
	strcat(command, snum); 

	printf("\nPress ENTER to run the command:\n %s", command);
	getch();

	system(command);

}