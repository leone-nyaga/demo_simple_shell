#include "simple_shell.h"

void free_list(list_t *command_history)
{
    list_t *current = command_history;
    while (current != NULL)
    {
        list_t *next = current->next;
        free(current->str);
        free(current);
        current = next;
    }
}
