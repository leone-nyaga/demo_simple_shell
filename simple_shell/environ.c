#include "simple_shell.h"

char *get_path(ShellData *shell_info)
{
    char *str = _getenv("PATH=", shell_info);
    char *token, *strr;
    static char command_buffer[256 + PATH_MAX];
    struct stat st;
    int i = 0, word = 0, count = 0;

    if (!str)
        return shell_info->argument_array[0];
    if (str[0] == ':' && !stat(shell_info->argument_array[0], &st))
        return shell_info->argument_array[0];
    if (!_strncmp(shell_info->argument_array[0], "./", 2))
        return shell_info->argument_array[0];
    while (str && str[i])
    {
        if (!word && str[i] != ':')
        {
            word = 1;
            ++count;
        }
        else if (word && str[i] == ':')
            word = 0;
        i++;
    }
    token = strtok(str, ":");
    while (token && shell_info->argument_array[0])
    {
        strr = _append(command_buffer, token, shell_info->argument_array[0]);
        if (!stat(command_buffer, &st))
            return strr;
        if (count-- > 1 && *(token + strlen(token) + 1) == ':' && !stat(shell_info->argument_array[0], &st))
            return shell_info->argument_array[0];
        token = strtok(NULL, ":");
        _memset(command_buffer, 0, 256 + PATH_MAX);
    }
    return shell_info->argument_array[0];
}


void evaluate_var(ShellData *shell_info)
{
    int i = 0, j = 0, flag = 0, len = 0;
    static char *number;

    while ((shell_info->argument_array)[i])
    {

        if (*((shell_info->argument_array))[i] == '$')
        {
            flag = 1;
            break;
        }
        i++;
    }
    if (flag)
    {
        ((shell_info->argument_array))[i]++;
        len = strlen(((shell_info->argument_array))[i]);
        while (environ[j])
        {
            if (!strncmp(((shell_info->argument_array))[i], environ[j], len))
            {
                ((shell_info->argument_array))[i] = environ[j] + len + 1;
                break;
            }
            j++;
        }
    }
    else if (flag && !_strcmp(shell_info->argument_array[i], "?") && WIFEXITED(shell_info->status))
    {
        shell_info->argument_array[i] = number = convert(WEXITSTATUS(shell_info->status), 10);
    }
}

