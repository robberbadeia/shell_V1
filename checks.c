#include "shell.h"
/**
 * sig_handler - checks if Ctrl C is pressed
 * @sig_num: int
 * Return: Non
 */
void sig_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		/**
		 *print string if CTR C pressed
		 */
		_puts("\n#cisfun$ ");
	}
}

/**
* _EOF - handles the End of File
* @len: command lenght of getline function
* @buff: buffer pointer that points to the command line
* Return: Non
 */
void _EOF(int len, char *buff)
{
	(void)buff;
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(buff);
		}
		exit(0);
	}
}
/**
  * _isatty - verif if terminal
  * Return: Non
  */

void _isatty(void)
{
	if (isatty(STDIN_FILENO))
		_puts("#cisfun$ ");
}
