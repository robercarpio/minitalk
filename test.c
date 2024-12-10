#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define MAX_MESSAGE_LEN 256

volatile sig_atomic_t signal_received = 0;
char global_message[MAX_MESSAGE_LEN];

void handler(int sig)
{
    if (sig == SIGUSR1)
    {
        signal_received = 1;
        snprintf(global_message, MAX_MESSAGE_LEN, "Mensaje recibido: Señal SIGUSR1");
    }
    else if (sig == SIGUSR2)
    {
        signal_received = 1;
        snprintf(global_message, MAX_MESSAGE_LEN, "Mensaje recibido: Señal SIGUSR2");
    }
}

int main(void)
{
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);

    printf("Mi PID es: %d\n", getpid());
    fflush(stdout);

    while (1)
    {
        if (signal_received)
        {
            write(1, global_message, strlen(global_message));
            write(1, "\n", 1);
            signal_received = 0;
        }
        usleep(100000); // Reduce el uso de CPU
    }

    return 0;
}


// #include <signal.h>
// #include <unistd.h>
// #include <stdio.h>

// void    handler(int sig)
// {
//     if (sig == SIGUSR1)
//         write(1,"test1",5);
//     else if (sig == SIGUSR2)
//         write(1,"test2",5);
// }

// int main(void)
// {
//     signal(SIGUSR1,handler);
//     signal(SIGUSR2,handler);
//     printf("Mi PID es: %d\n", getpid());
//     fflush(stdout);
//     int i;
//     while (1)
//     {
//         i = 0;
//     }
//     return (0);
// }