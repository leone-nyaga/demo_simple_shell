#include "simple_shell.h"

size_t list_length(const list_t *hd)
{
    size_t command_count = 0;

    while (hd)
    {
        command_count++;
        hd = hd->next;
    }
    return command_count;
}

int list_delete(list_t **head, size_t index)
{
    unsigned int j;
    list_t *current;
    list_t *forward;

    if (*head == NULL)
        return (-1);
    current = *head;
    if (index == 0)
    {
        *head = current->next;
        free(current->str);
        free(current);
        return (1);
    }
    for (j = 0; j < index - 1; j++)
    {
        if (current->next == NULL)
            return (-1);
        current = current->next;
    }
    forward = *head;
    if (forward->next == NULL)
        return (-1);
    forward = current->next;
    current->next = forward->next;
    free(forward->str);
    free(forward);
    return (1);
}

list_t *command_history(void)
{
    int i = 0;
    list_t *head = NULL;

    while (environ[i])
    {
        adding(&head, environ[i]);
        ++i;
    }
    return (head);
}

