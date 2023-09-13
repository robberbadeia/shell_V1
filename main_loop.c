#include "shell.h"
/**
 *main_loop - Function
 *Return: int
 */
int main_loop(void)
{
	int len = 0;
	size_t buffsize = BUFFSIZE;
	char *buff = NULL, **argv, *value, *pathname;
	list_path *head = '\0';
	void (*buildin_function)(char **);
	/* main infinite loop*/
	while (len != EOF)
	{
		/* check if is it STDIN*/
		_isatty();
		/*get user command*/
		len = getline(&buff, &buffsize, stdin);
		/*check if getline success or not and print new line if not success*/
		_EOF(len, buff);
		/*Split the user command*/
		argv = commandsplit(buff, " \n");
		if (!argv || !argv[0])
			execute(argv);
		else
		{
			/*Return pointer to the directories in PATH within in env*/
			value = _getenv("PATH");
			/*Tokenize All PATH dirs and Store them into a linked list*/
			head = linklist(value);
			/*Which dir in PATH match argv[0] , Retrun: dir concatenated with filnsme*/
			pathname = _which(argv[0], head);
			buildin_function = checkbuild(argv);
			if (buildin_function)
			{
				free(buff);
				buildin_function(argv);
			}
			else if (!pathname)
				execute(argv);
			else if (pathname)
			{
				free(argv[0]);
				argv[0] = pathname;
				execute(argv);
			}
		}
	}
	free_list(head);
	free_argv(argv);
	free(buff);
	return (0);
}
