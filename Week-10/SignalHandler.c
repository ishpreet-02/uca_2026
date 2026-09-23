#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t signal_count = 0;

void handle_sigint(int sig) {
    signal_count++;

    if (signal_count < 3) {
        printf("\nSIGINT caught! You pressed Ctrl+C %d time(s). Press Ctrl+C %d more time(s) to exit.\n",
               signal_count, 3 - signal_count);
    } else {
        printf("\nSIGINT caught 3 times. Exiting program...\n");
        exit(0);
    }
}

int main() {
    // Register the signal handler
    signal(SIGINT, handle_sigint);
    
    printf("Program running (PID: %d). Try pressing Ctrl+C...\n", getpid());

    while (1) {
        sleep(1);
    }

    return 0;
}