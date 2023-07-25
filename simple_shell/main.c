#include "simple_shell.h"

int main(int argc_custom, char **argv_custom) {
    ShellData shell_info;

    shell_info.argc = argc_custom;
    shell_info.argv = argv_custom[0];
    initialize_struct(&shell_info);
    signal(SIGINT, signal_hand);
    _shell(&shell_info);
    return (0);
}

void initialize_struct(ShellData *shell_info) {
    shell_info->command_buffer = NULL;
    shell_info->argument_array = NULL;
    shell_info->command_count = 0;
    shell_info->command_history = command_history();
    shell_info->exit_status = 0;
}

int get_exit_status(void) {
    int number = 0;

    if (errno == EACCES)
        number = 126;
    else if (errno == ENOTDIR || errno == ENOENT)
        number = 127;
    return number;
}

