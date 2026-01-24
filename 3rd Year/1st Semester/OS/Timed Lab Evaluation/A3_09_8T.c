/*************************************************************************************************
* Assignment No.: 8T
* Assignment    : Program to demonstrate deadlock avoidance using processes, semaphores and shared memory
* Date          : 04/11/2025
* Group No.     : A3
* Team No.      : 09
* Roll No.      : 002311001004, 002311001011, 002311001049
* Name          : Soham Das, Sarbo Sarcar, Arnob Bhakta
* Details       : C program to create three child processes that transfer random quantities
*                 between three shared global totals (stored in shared memory via mmap).
*                 POSIX named semaphores are used with resource ordering to prevent
*                 deadlock. The parent process prints the totals consistently.
*                 A SIGINT handler is included for graceful cleanup.
*
*
* Input         : None (All values initialized in the code).
* Output        : Displays the three individual totals and the grand total every second.
*                 The grand total should remain constant (300000).
*                 The program runs until interrupted (Ctrl+C).
*
*
* Compilation   : gcc A3_09_8T.c -o A3_09_8T -pthread
* Execution     : ./A3_09_8T
*
*
* Sample Output :
*
Parent process started. Monitoring totals... (Press Ctrl+C to stop)
------------------------------------------------------------------------
Total_1: 99999   | Total_2: 99999   | Total_3: 100002  | Grand Total: 300000
Total_1: 100024  | Total_2: 100010  | Total_3: 99966   | Grand Total: 300000
Total_1: 100069  | Total_2: 99980   | Total_3: 99951   | Grand Total: 300000
Total_1: 100076  | Total_2: 99950   | Total_3: 99974   | Grand Total: 300000
Total_1: 100156  | Total_2: 99950   | Total_3: 99894   | Grand Total: 300000
Total_1: 100182  | Total_2: 99930   | Total_3: 99888   | Grand Total: 300000
Total_1: 100254  | Total_2: 99940   | Total_3: 99806   | Grand Total: 300000
Total_1: 100405  | Total_2: 99890   | Total_3: 99705   | Grand Total: 300000
Total_1: 100415  | Total_2: 99930   | Total_3: 99655   | Grand Total: 300000
Total_1: 100516  | Total_2: 99930   | Total_3: 99554   | Grand Total: 300000
Total_1: 100593  | Total_2: 99940   | Total_3: 99467   | Grand Total: 300000
Total_1: 100703  | Total_2: 99940   | Total_3: 99357   | Grand Total: 300000
Total_1: 100806  | Total_2: 99890   | Total_3: 99304   | Grand Total: 300000
^C
SIGINT received. Cleaning up resources...
Cleanup complete. Exiting.
*
*
* (NOTE: Output continues indefinitely, showing consistent totals and grand total.
*        We have forced exit with Ctrl+C for purposes of brevity.)
*
*
* ==== Reason behind sleep() and usleep() calls in parent and child processes ====
*
* Sleep calls are essential for controlling the pace and observability of the program. 
* The sleep(1) in the parent thread is absolutely required to meet the "display every 
* 1 second" requirement, ensuring a consistent output rate. In the child threads, usleep 
* prevents them from consuming 100% CPU in a tight loop, which is critical for a usable 
* program. This "slows down" the rate of transactions, making the visible differences 
* between each 1-second print smaller, more gradual, and easier for a human to follow.
*
******************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>

int *Total_1, *Total_2, *Total_3;

const char *SEM_NAME_1 = "/total1_sem";
const char *SEM_NAME_2 = "/total2_sem";
const char *SEM_NAME_3 = "/total3_sem";

sem_t *sem1, *sem2, *sem3;

pid_t pid1 = -1, pid2 = -1, pid3 = -1;


void cleanup_handler(int sig) {
    printf("\nSIGINT received. Cleaning up resources...\n");

    if (pid1 > 0) kill(pid1, SIGTERM);
    if (pid2 > 0) kill(pid2, SIGTERM);
    if (pid3 > 0) kill(pid3, SIGTERM);

    wait(NULL);
    wait(NULL);
    wait(NULL);

    sem_close(sem1);
    sem_close(sem2);
    sem_close(sem3);
    sem_unlink(SEM_NAME_1);
    sem_unlink(SEM_NAME_2);
    sem_unlink(SEM_NAME_3);

    munmap(Total_1, sizeof(int));
    munmap(Total_2, sizeof(int));
    munmap(Total_3, sizeof(int));

    printf("Cleanup complete. Exiting.\n");
    exit(0);
}


void Child1() {
    srand(time(NULL) ^ getpid());

    while (1) {
        int quantity = (rand() % 10) + 1;
        int dest = rand() % 2;

        if (dest == 0) {
            sem_wait(sem1);
            sem_wait(sem2);

            if (*Total_1 >= quantity) {
                *Total_1 -= quantity;
                *Total_2 += quantity;
            }

            sem_post(sem2);
            sem_post(sem1);
        } else {
            sem_wait(sem1);
            sem_wait(sem3);

            if (*Total_1 >= quantity) {
                *Total_1 -= quantity;
                *Total_3 += quantity;
            }

            sem_post(sem3);
            sem_post(sem1);
        }
        usleep(100000);
    }
}

void Child2() {
    srand(time(NULL) ^ getpid());

    while (1) {
        int quantity = (rand() % 20) + 1;
        int dest = rand() % 2;

        if (dest == 0) {
            sem_wait(sem1);
            sem_wait(sem2);

            if (*Total_2 >= quantity) {
                *Total_2 -= quantity;
                *Total_1 += quantity;
            }

            sem_post(sem2);
            sem_post(sem1);
        } else {
            sem_wait(sem2);
            sem_wait(sem3);

            if (*Total_2 >= quantity) {
                *Total_2 -= quantity;
                *Total_3 += quantity;
            }

            sem_post(sem3);
            sem_post(sem2);
        }
        usleep(100000);
    }
}

void Child3() {
    srand(time(NULL) ^ getpid());

    while (1) {
        int quantity = (rand() % 30) + 1;
        int dest = rand() % 2;

        if (dest == 0) {
            sem_wait(sem1);
            sem_wait(sem3);

            if (*Total_3 >= quantity) {
                *Total_3 -= quantity;
                *Total_1 += quantity;
            }

            sem_post(sem3);
            sem_post(sem1);
        } else {
            sem_wait(sem2);
            sem_wait(sem3);

            if (*Total_3 >= quantity) {
                *Total_3 -= quantity;
                *Total_2 += quantity;
            }

            sem_post(sem3);
            sem_post(sem2);
        }
        usleep(100000);
    }
}


void Parent() {
    printf("Parent process started. Monitoring totals... (Press Ctrl+C to stop)\n");
    printf("------------------------------------------------------------------------\n");

    while (1) {
        sem_wait(sem1);
        sem_wait(sem2);
        sem_wait(sem3);

        int t1 = *Total_1;
        int t2 = *Total_2;
        int t3 = *Total_3;
        int grand_total = t1 + t2 + t3;

        sem_post(sem3);
        sem_post(sem2);
        sem_post(sem1);

        printf("Total_1: %-7d | Total_2: %-7d | Total_3: %-7d | Grand Total: %d\n",
               t1, t2, t3, grand_total);
         
        fflush(stdout);
        sleep(1);
    }
}


int main() {
    Total_1 = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE,
                   MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    Total_2 = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE,
                   MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    Total_3 = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE,
                   MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    if (Total_1 == MAP_FAILED || Total_2 == MAP_FAILED || Total_3 == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    *Total_1 = 100000;
    *Total_2 = 100000;
    *Total_3 = 100000;

    sem_unlink(SEM_NAME_1);
    sem_unlink(SEM_NAME_2);
    sem_unlink(SEM_NAME_3);

    sem1 = sem_open(SEM_NAME_1, O_CREAT, 0666, 1);
    sem2 = sem_open(SEM_NAME_2, O_CREAT, 0666, 1);
    sem3 = sem_open(SEM_NAME_3, O_CREAT, 0666, 1);
    if (sem1 == SEM_FAILED || sem2 == SEM_FAILED || sem3 == SEM_FAILED) {
        perror("sem_open");
        exit(1);
    }

    signal(SIGINT, cleanup_handler);

    pid1 = fork();
    if (pid1 == -1) {
        perror("fork 1");
        exit(1);
    }
    if (pid1 == 0) {
        signal(SIGINT, SIG_DFL);
        Child1();
        exit(0);
    }

    pid2 = fork();
    if (pid2 == -1) {
        perror("fork 2");
        exit(1);
    }
    if (pid2 == 0) {
        signal(SIGINT, SIG_DFL);
        Child2(); 
        exit(0);
    }

    pid3 = fork();
    if (pid3 == -1) {
        perror("fork 3");
        exit(1);
    }
    if (pid3 == 0) {
        signal(SIGINT, SIG_DFL);
        Child3(); 
        exit(0);
    }

    Parent();

    cleanup_handler(0);
    return 0;
}
