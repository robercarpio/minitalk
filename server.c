#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void handler(int sig, siginfo_t *info, void *context)
{
    static char c = 0;
    static int bits_received = 0;

    (void)context; // No usado, evita warning

    if (sig == SIGUSR1)
        c = (c << 1);
    else if (sig == SIGUSR2)
        c = (c << 1) | 1;

    bits_received++;

    if (bits_received == 8)
    {
        if (c == '\0')
            write(1, "\n", 1);
        else
            write(1, &c, 1);
        c = 0;
        bits_received = 0;
    }
    kill(info->si_pid, SIGUSR1);
}

int main(void)
{
    struct sigaction sa;

    printf("PID Server: %d\n", getpid());

    sa.sa_sigaction = handler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    while (1)
        pause();
    return 0;
}
