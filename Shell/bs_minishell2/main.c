/*
** EPITECH PROJECT, 2022
** bs_minishell2
** File description:
** main
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "my.h"

int main(int argc, char **argv, char **env)
{
    char **cmd1 = my_strsplit(argv[1], ' ');
    char **cmd2 = my_strsplit(argv[2], ' ');
    char **cmd3 = my_strsplit(argv[3], ' ');
    int pipe1[2];
    int pipe2[2];

    (void)argc;
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1)
        return (84);
    if (fork() == 0) {
        close(pipe1[0]);
        dup2(pipe1[1], 1);
        execve(cmd1[0], cmd1, env);
    } else {
        wait(NULL);
        close(pipe1[1]);
        if (fork() == 0) {
            close(pipe1[1]);
            close(pipe2[0]);
            dup2(pipe1[0], 0);
            dup2(pipe2[1], 1);
            execve(cmd2[0], cmd2, env);
        } else {
            wait(NULL);
            close(pipe2[1]);
            if (fork() == 0) {
                close(pipe2[1]);
                dup2(pipe2[0], 0);
                execve(cmd3[0], cmd3, env);
            } else {
                wait(NULL);
            }
        }
    }
}
