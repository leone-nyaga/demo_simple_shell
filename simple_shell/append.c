#include "simple_shell.h"

char *_append(char *buff, char *token, char *s)
{
    _strcat(buff, token);
    _strcat(buff, "/");
    _strcat(buff, s);
    return buff;
}

char *_getenv(char *name, ShellData *shell_info)
{
    size_t len = strlen(name);
    list_t *head = shell_info->command_history;

    while (head)
    {
        if (!_strncmp(name, head->str, len))
        {
            name = head->str + len;
            return name;
        }
        head = head->next;
    }
    return NULL;
}

