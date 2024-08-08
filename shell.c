#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_NUM_ARGS 100

char *read_input(void){
	char *input=NULL;
	ssize_t bufsize=0;

	getline(&input, &bufsize, stdin);
	return input;
}

char **parse_input(char *input){
	int position = 0;
	char **tokens = malloc(MAX_NUM_ARGS * sizeof(char *));
	char *token;

	if (!token){
		fprintf(stderr, "allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(input, "\t\r\n\a");
	while(token != NULL){
		tokens[position] = token;
		position++;

	if (position >= MAX_NUM_ARGS){
		fprintf(stderr, "too many arguments\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(NULL, "\t\r\n\a");
	}
	tokens[position]=NULL;
	return tokens;
}

int main(){
	char *input;
	char **args;

	while(1){
		printf("shell> ");
		input = read_input();
		args = parse_input(input);

		for(int i=0; args[i]!=NULL; i++){
			printf("Args[%d]: %s\n", i, args[i]);
		}

		free(input);
		free(args);
	}
	return 0;
}
