#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

pthread_mutex_t lock;
int number = 0;
int score = 0;
int maxGuesses = 10;

void *numberGenerator(void *arg)
{
    pthread_mutex_lock(&lock);
    number = (rand() % 1000) + 1;
    int player = *((int *)arg);
    printf("Player %d thinks of a number between 1 and 1000: %d\n", player, number);
    pthread_mutex_unlock(&lock);
    return NULL;
}

void *numberGuesser(void *arg)
{
    int player = *((int *)arg);
    srand(time(NULL) + player);
    int guess;
    for (int i = 0; i < maxGuesses; i++) {
        pthread_mutex_lock(&lock);
        guess = (rand() % 1000) + 1;
        pthread_mutex_unlock(&lock);

        printf("Player %d guessed %d\n", player, guess);
        score++;

        if (number == guess)
        {
            printf("Player %d correctly guessed: %d\n", player, number);
            break;
        }

        usleep(500000);
    }
    return NULL;
}

int main()
{
    pthread_t thread1, thread2, thread3, thread4;
    int p1 = 1, p2 = 2;
    pthread_mutex_init(&lock, NULL);
    int score1 = 0, score2 = 0;
    int n = 0;
    int round = 2 * (rand() % 4 + 1);

    for (int i = 0; i < round; i++) {
        if (n % 2 == 0) {
            score = 0;
            pthread_create(&thread1, NULL, numberGenerator, &p1);
            pthread_create(&thread2, NULL, numberGuesser, &p2);
            pthread_join(thread1, NULL);
            pthread_join(thread2, NULL);
            score2 += score;
        }
        else {
            score = 0;
            pthread_create(&thread3, NULL, numberGenerator, &p2);
            pthread_create(&thread4, NULL, numberGuesser, &p1);
            pthread_join(thread3, NULL);
            pthread_join(thread4, NULL);
            score1 += score;
        }

        printf("\n");
        n++;
    }

    printf("Player 1's score: %d\n", score1);
    printf("Player 2's score: %d\n", score2);
    if (score1 > score2) {
        printf("Player 1 wins\n");
    }
    else if (score1 < score2) {
        printf("Player 2 wins\n");
    }
    else {
        printf("It's a draw\n");
    }
    pthread_mutex_destroy(&lock);
    return 0;
}
