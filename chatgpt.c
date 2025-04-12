#define _GNU_SOURCE
#include <stdio.h>
#include <signal.h>
#include <ucontext.h>
#include <unistd.h>

void signal_handler(int signo, siginfo_t *info, void *context) {
    ucontext_t *ctx = (ucontext_t *)context;
	signo = signo + 2;
	printf("%d\n", info->si_pid);
// #ifdef __x86_64__
    printf("Inside handler...\n");

    int *rbp = (int *)ctx->uc_mcontext.gregs[REG_RBP]; // Get base pointer
    int *local_num_ptr = rbp - 1; // `num` is stored just before the base pointer
    printf("Old num: %d\n", *local_num_ptr);

    *local_num_ptr = 100; // Change `num` on stack

    printf("New num: %d\n", *local_num_ptr);
// #else
//     printf("Unsupported architecture.\n");
// #endif
}

int main() {
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = signal_handler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL); // Register signal handler

    int num = 42; // LOCAL variable

    printf("num before signal: %d\n", num);
    raise(SIGUSR1); // Send signal to self
    printf("num after signal: %d\n", num);

    return 0;
}
