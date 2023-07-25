#include "simple_shell.h"

char **argument_array_to_array(list_t *head)
{
    int i = 0, len = list_length(head);
    char **argument_array = NULL; 

    if (!head)
        return NULL;
    argument_array = malloc(sizeof(char *) * (len + 1));
    if (!argument_array)
        return NULL;

    while (head)
    {
        argument_array[i] = head->str; 
        head = head->next;
        ++i;
    }
    argument_array[i] = NULL;
    return argument_array;
}

int unset_env(ShellData *shell_info)
{
    list_t *tmp = shell_info->command_history;
    size_t i = 0;

    if (shell_info->argument_array[1])
    {
        while (tmp)
        {
            shell_info->index = i;
            if (!(_strncmp(tmp->str, shell_info->argument_array[1], strlen(shell_info->argument_array[1]))))
            {
                list_delete(&(shell_info->command_history), i);
                break;
            }
            tmp = tmp->next;
            ++i;
        }
        return 1;
    }
    error(shell_info, 1);
    return 1;
}

int set_env(ShellData *shell_info)
{
    char *var_name = NULL;
    char *var_value = NULL;
    char temp[PATH_MAX] = {0};
    if (shell_info->argument_array[1] && shell_info->argument_array[2])
    {
        var_name = shell_info->argument_array[1];
        var_value = shell_info->argument_array[2];
        unset_env(shell_info);
        _strcat(temp, var_name);
        _strcat(temp, "=");
        _strcat(temp, var_value);

        list_insert(&(shell_info->command_history), shell_info->index, temp);
        return 1;
    }
    error(shell_info, 1);
    return 1;
}

