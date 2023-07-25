#include "simple_shell.h"

list_t *list_insert(list_t **head, unsigned int index, char *str)
{
    unsigned int i;
    list_t *tmp;
    list_t *new_node;

    i = 0;
    tmp = *head;
    while (i < index - 1)
    {
        if (!tmp)
            return NULL;
        tmp = tmp->next;
        i++;
    }
    new_node = malloc(sizeof(list_t));
    if (!new_node)
        return NULL;
    if (index)
    {
        new_node->next = tmp->next;
        tmp->next = new_node;
    }
    else
    {
        new_node->next = tmp;
        *head = new_node;
    }
    new_node->str = str_dup(str);
    return new_node;
}

