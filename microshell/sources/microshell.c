/* 
 * Napisz program microshell.c, będący własną, minimalistyczną wersją shella 
 * (tzn. będzie uruchamiał zewnętrzne programy z argumentami wprowadzonymi przez użytkownika).
 * 
 * Główny program będzie w pętli:
 *
 *   wyświetlał znak zachęty > ,
 *   odczytywał linię znaków wprowadzoną przez użytkownika,
 *   dzielił po spacjach linię znaków na poszczególne tokeny - argumenty,
 *   uruchamiał proces potomny z argumentami z kroku 3.

 * Możesz przyjąć, że na potrzeby tego zadania:
 * - wprowadzana komenda razem z argumentami jest nie dłuższa niż 50 znaków,
 * - powinny działać podstawowe komendy nie wymagające interakcji 
 *   użytkownika, np. ls, cat, echo, exit (!), itp. (obsługę cd zostaw na deser przy zadaniu dodatkowym),
 * nie są wprowadzane złośliwe argumenty, np. ls "some dir".
 *
 */

#include "microshell.h"

int tokenize(char input[], char* command[]) {

	int i = 0;
    char *token = strtok(input, " ");
	while(token) {
	    command[i++] = token;   /* 
                                      http://en.cppreference.com/w/c/string/byte/strtok 
                                      If str == NULL, the call is treated as a subsequent calls to strtok: 
                                      the function continues from where it left in previous invocation. 
                                      The behavior is the same as if the previously stored pointer is passed as str. 
                                */
		token = strtok(NULL, " ");
    }
	command[i] = NULL; /* MAX_COMMAND_ELEMENTS = MAX_COMMAND_LENGTH / 2 + 1 */

	return i + 1; /* return size */
}

void subprocess(char* command[]) {

	LOG("subprocess pid: %d\n", getpid());
	if ( execvp(command[0], command) < 0 ) {
		ERROR("Unknown Command: %s\n", command[0]);
		exit(1);
	}
}

int main(int argc, char* argv[]) {

	char line[MAX_COMMAND_LENGTH];
	char* command[MAX_COMMAND_ELEMENTS];
	LOG("Started\n");

	/* Infinite loop */
	while (1) {

		pid_t  pid;
		int status;
		printf("\r> ");
		if (fgets(line, sizeof(line), stdin)) {

			/* Remove new line */
			size_t length = strlen(line)-1;
			if (line[length] == '\n')
				line[length] = '\0';

			if ( !line[0] ) {
				continue;
			}

			tokenize(line, command);

			if ( strcmp(command[0], "exit") == 0 ) {
				break;
			}
		}
		else {
			continue;
		}

		LOG("process pid: %d\n", getpid());

		pid = fork();
		switch(pid)
		{
			case 0:
				subprocess(command);
				break;

			case -1:
				ERROR("The child process has not been created");
				break;

			default:
				waitpid(pid, &status, 0);
		}	
	}

	LOG("Finished\n");
	return 0;
}
