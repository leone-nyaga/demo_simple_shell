#include "simple_shell.h"

void _fork(ShellData *shell_info)
{
        pid_t pid = 0;
        char **env = NULL;

        if (*shell_info->argument_array[0] == '/' || _getenv("PATH=", shell_info))
        {
                pid = fork();
                if (pid < 0)
                        return;
                if (pid == 0)
                {
                        shell_info->argument_array[0] = get_path(shell_info);
                        env = argument_array_to_array(shell_info->command_history);
                        if (execve(shell_info->argument_array[0], shell_info->argument_array, env) == -1)
                        {
                                error(shell_info, 0), free(shell_info->argument_array), free(shell_info->command_buffer);
                                free(shell_info->command_history), free(env), exit(127);
                        }
                }
                else
                {
                        waitpid(-1, &(shell_info->status), 0);
                        if (WIFEXITED(shell_info->status))
                                shell_info->exit_status = WEXITSTATUS(shell_info->status);
                }
        }
        else
        {
                errno = ENOTDIR, shell_info->exit_status = 127,  error(shell_info, 0);
        }
}

