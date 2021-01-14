#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Tasks.h"

// DEFINITIONS

typedef void (fn_tsk)(int *, char *);

// FUNCTS

void sendHelp() {
	printf("Project manager, options:\n");
	printf("-a\t--all\tShow all projects and childs\n");
	printf("-n\t--new\tCreate a new project or child\n");
	printf("-d\t--delete\tDelete a project or a child\n");
	printf("-m\t--modify\tModify a project or a child\n");
	printf("-N\t--erase\tErase actual projects and recreate database");
}

// MAIN

int main (int argc, char **argv) {
	fn_tsk *tasks[4] = { &all, &new, &delete, &modify };
	int task = -1;
	char *argument = "";
	int modifiers[3] = { 0, 0, 0 }; 

	for (int i = 0; i < argc; i++) {
		if (argv[i][0] == '-' && argv[i][1] == '-') {
			char *option = argv[i];
			memmove(option, option+2, strlen(option) - 1);
			if (!strcmp(option, "all"))
				task = 0;
			else if (!strcmp(option, "new"))
				task = 1;
			else if (!strcmp(option, "delete"))
				task = 2;
			else if (!strcmp(option, "modify"))
				task = 3;
			else if (!strcmp(option, "erase"))
				modifiers[0] = 1;
		}
		else if (argv[i][0] == '-' && argv[i][1] != '-') {
			char *options = argv[i];
			memmove(options, options + 1, strlen(options));
			for (int i = 0; i < strlen(options); i++) {
				if (options[i] == 'a')
					task = 0;
				else if (options[i] == 'n')
					task = 1;
				else if (options[i] == 'd')
					task = 2;
				else if (options[i] == 'm')
					task = 3;
				else if (options[i] == 'N')
					modifiers[0] = 1;
			}
		}
		else if (i > 1) {
			argument = argv[i];
		}
	}

	if (task >= 0) {
		(*(tasks[task]))(modifiers, argument);
	} else {
		sendHelp();
	} 
	printf("\n");
	return 0;
}
