#include <signal.h>
#include <unistd.h>
#include <stdio.h>

// Manejador de señales que recibe información sobre la señal.
void handler(int sig, siginfo_t *info, void *context)
{
    static char c = 0;
    static int bits_received = 0;

    (void)context; // No usado, evita warning

    // Determinar el valor del bit (SIGUSR1: bit 0, SIGUSR2: bit 1)
    if (sig == SIGUSR1)
        c = (c << 1); // Agregar un bit `0`
    else if (sig == SIGUSR2)
        c = (c << 1) | 1; // Agregar un bit `1`

    bits_received++;

    // Cuando recibimos 8 bits, un carácter completo
    if (bits_received == 8)
    {
        if (c == '\0') // Fin de la cadena
            write(1, "\n", 1);
        else
            write(1, &c, 1);
        c = 0;
        bits_received = 0;
    }

    // Confirmar recepción al cliente
    kill(info->si_pid, SIGUSR1);
}

int main(void)
{
    struct sigaction sa;

    // Mostrar PID del servidor
    printf("Servidor PID: %d\n", getpid());

    // Configuración para recibir señales con información adicional
    sa.sa_sigaction = handler;
    sa.sa_flags = SA_SIGINFO;  // Usar SIGINFO para recibir la estructura siginfo_t
    sigemptyset(&sa.sa_mask);  // Vaciar la máscara de señales
    sigaction(SIGUSR1, &sa, NULL); // Registrar el manejador para SIGUSR1
    sigaction(SIGUSR2, &sa, NULL); // Registrar el manejador para SIGUSR2

    // Esperar señales indefinidamente
    while (1)
        pause();

    return 0;
}
