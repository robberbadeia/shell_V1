#include "shell.h"
/**
 * free_list - frees a list_t
 *@head: pointer to our linked list
 */
void free_list(list_path *head)
{
	list_path *storage;

	while (head)
	{
		storage = head->p;
		free(head->dir);
		free(head);
		head = storage;
	}

}
/**
 *free_argv - frees the array of pointers arv
 *@arv: array of pointers
 */

void free_argv(char **arv)
{
	int i;

	for (i = 0; arv[i]; i++)
		free(arv[i]);
	free(arv);
}
