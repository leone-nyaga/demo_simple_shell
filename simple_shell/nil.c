#include "simple_shell.h"

void free_l(list_t *command_history)
{
	list_t *current = command_history;
	list_t *next = NULL;

	if (command_history == NULL)
		return;
	while (current->next != NULL)
	{
		free(current->str);
		next = current->next;
		free(current);
		current = next;
	}

	free(current->str);
	free(current);
}

list_t *adding(list_t **head, const char *str)
{
	list_t *new_node = NULL;
	list_t *current = *head;

	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return NULL;
	new_node->str = str_dup(str);
	new_node->next = NULL;
	if (!*head)
	{
		*head = new_node;
		return *head;
	}
	while (current->next)
		current = current->next;
	current->next = new_node;
	return new_node;
}

