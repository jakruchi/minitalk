#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdbool.h>

// Flag to indicate signal reception
volatile sig_atomic_t signal_received = 0;

// Signal handler function
void handle_signal(int sig) {
    if (sig == SIGUSR1) {
        printf("\nReceived SIGUSR1. Resuming execution...\n");
        signal_received = 1;  // Set flag to break out of pause()
    }
}

int main() {
    // Register signal handler
    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);

    printf("Process ID: %d\n", getpid());
    printf("Waiting for SIGUSR1 signal...\n");

    // Wait for signal
    while (!signal_received) {
        pause();  // Program waits here until a signal is received
    }

    // Continue execution after receiving signal
    printf("Continuing execution...\n");

    return 0;
}
