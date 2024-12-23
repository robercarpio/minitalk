#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <aio.h>
volatile sig_atomic_t got_signal = 0;

void handler(int sig)
{
    if (sig == SIGUSR1)
    {
        got_signal = 1;
    }
}

void send_bit(pid_t server_pid, char c)
{
    int i = 8;

    while (i--)
    {
        if (c & (1 << i))
        {
            if (kill(server_pid, SIGUSR2) == -1)
            {
                perror("Error enviando señal SIGUSR2");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            if (kill(server_pid, SIGUSR1) == -1)
            {
                perror("Error enviando señal SIGUSR1");
                exit(EXIT_FAILURE);
            }
        }
        usleep(100);
        while (!got_signal)
            pause();
        got_signal = 0;
    }
}

void send_string(pid_t server_pid, const char *str)
{
    while (*str)
    {
        send_bit(server_pid, *str);
        str++;
    }
    send_bit(server_pid, '\0');
}

int main(int argc, char **argv)
{
    pid_t server_pid;

    if (argc != 3)
    {
        write(2, "Uso: ./client <PID> <mensaje>\n", 30);
        return EXIT_FAILURE;
    }

    server_pid = atoi(argv[1]);
    if (server_pid <= 0)
    {
        write(2, "PID inválido\n", 14);
        return EXIT_FAILURE;
    }

    struct sigaction sa;
    sa.sa_handler = handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);

    send_string(server_pid, argv[2]);

    return EXIT_SUCCESS;
}
