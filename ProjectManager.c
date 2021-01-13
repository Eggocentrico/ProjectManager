#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sendHelp() {
	printf("Project manager, options:\n");
	printf("-a\t--all\tShow all projects and childs\n");
	printf("-n\t--new\tCreate a new project or child\n");
	printf("-d\t--delete\tDelete a project or a child\n");
	printf("-m\t--modify\tModify a project or a child");
}

void all(int *mod, char *arg) {
	printf("Showing all");
}

void new(int *mod, char *arg) {
	printf("New");
}

void delete(int *mod, char *arg) {
	printf("Deleting");
}

void modify(int *mod, char *arg) {
	printf("Modify");
}

void (*tasks[4])(int *mod, char *arg) = malloc(sizeof(void (*)(int *, char*))*6);

int main (int argc, char **argv) {
	int task = -1;
	char *argument = "";
	int modifiers[3] = { 0, 0, 0 }; 
	if (argc <= 1) {
		sendHelp();
	}
	else {
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
				}
			}
			else {
				strcat(argument, argv[i]);
			}
		}
	}

	if (task >= 0) {
		(*tasks[task])(modifiers, argument);
	} 
	printf("\n");
	return 0;
}
