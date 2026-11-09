#define _GNU_SOURCE
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *text = NULL;
size_t len = 100;
extern char **environ;
void Ende();
void p_envlist(char **);
void p_env();
void add_env();
void mod_env();
void rem_env();

int main( /*int argc, char *argv[]*/){

while(1)
{
   char **evptr = NULL;
    printf ( "\n----------------------\n");
    printf ( "Environement-List Menu\n");
    printf ( "----------------------\n\n");
    printf ( "[1]: Print environment list\n");
    printf ( "[2]: Print environment entry (getenv)\n");
    printf ( "[3]: Add environment entry (putenv)\n");
    printf ( "[4]: Modify environment entry\n");
    printf ( "[5]: Remove environment entry\n");
    printf ( "[6]: End\n");
    getline(&text, &len, stdin);
    evptr = environ;
    int c = atoi(text);
    if ( c == 1 ){
         p_envlist(evptr);
        }
    else if ( c == 2 ){
         p_env();
}
    else if ( c == 3 ){
         add_env();
         }
    else if ( c == 4 ){
         mod_env();
         }
    else if ( c == 5 ){
         rem_env();
         }
    else if ( c == 6 ){
          Ende();
        }
}
return EXIT_SUCCESS;
}

void p_envlist(char **evptr){
     while ( *evptr ) printf ("%s\n",*evptr++);
}
void p_env(){
	int i = 0;
	char input[4096];
	char* s;
	printf("Type environment entry : ");
	scanf("%4095s", input);
	for(i = 0; i < (int)strlen(input); i++){
		input[i] = (char)toupper((int)input[i]);
	        s = getenv(input);
	        if(s)
		  printf("\n%s=%s\n", input, s);
	        else
		printf("\n%s : unknown entry\n", input);
               }

}
void add_env(){
        int i = 0;
        char name[4095];
        char value[4095];
	printf("Type to add to environment : \n");
	printf("Name  : ");
	scanf("%4095s", name);
	printf("Value : ");
	scanf("%4095s", value);
	for(i = 0; i < (int) strlen(name); i++)
		name[i] = (char) toupper((int)name[i]);
	if(setenv(name, value, 0) == 0)
		printf("\n%s=%s\n", name, value);
	else
		printf("\n%s : could not be added\n", name);
}
void mod_env(){
       	char name[4096];
	char value[4069];
	int i = 0;
	printf("Type to modify environment entry : \n");
	printf("Name  : ");
	scanf("%4095s", name);
	printf("Value : ");
	scanf("%4095s", value);
	for(i = 0; i < (int) strlen(name); i++)
		name[i] = (char) toupper((int)name[i]);
	if(setenv(name, value, 1) != -1)
		printf("\n%s=%s\n", name, value);
	else
		printf("\n%s : could not be added\n", name);
}
void rem_env(){
        char name[4096];
	int i = 0;
	puts("\n[[4]: Modify environment entry (setenv)\n");
	printf("Type to modify environment entry : \n");
	printf("Name  : ");
	scanf("%4095s", name);
	for(i = 0; i < (int) strlen(name); i++)
		name[i] = (char) toupper((int)name[i]);
	if(unsetenv(name) != -1)
		printf("\n%s : removed\n", name);
	else
		printf("\n%s : could not be added\n", name);
}
void Ende(){
	exit(EXIT_SUCCESS);
}

/*Quellen: Vorlesungskripten, StackOverflow, Copilot */