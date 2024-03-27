#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

pthread_mutex_t lock;
int number = 0;
int score = 0;

void *numberGenerator(void *arg)
{
    pthread_mutex_lock(&lock);
    number = rand() % 100;
    int player = *((int *)arg);
    if (player == 1) {
        printf("\n");
        printf("Player 1 thinks %d", number);
        printf("\n");
    } else {
        printf("Player 2 thinks %d", number);
        printf("\n");
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

void *numberGuesser(void *arg)
{
    srand(time(NULL));
    int guess;
    while (1)
    {
        pthread_mutex_lock(&lock);
        guess = rand() % 100;
        pthread_mutex_unlock(&lock);

        int player = *((int *)arg);
        if (player == 1) {
            printf("Player 1 guessed %d\n", guess);
        } else {
            printf("Player 2 guessed %d\n", guess);
        }
        score++;

        if (number == guess)
        {
            if (player == 1) {
                printf("player 1 correctly guessed : %d\n", number);
            } else {
                printf("player 2 correctly guessed : %d\n", number);
            }
            break;
        }
    }
    return NULL;
}

int main()
{
    srand(time(NULL));
    pthread_t thread1, thread2;
    int p1 = 1, p2 = 2;
    pthread_mutex_init(&lock, NULL);
    int score1 = 0, score2 = 0;
    int n = 0;
    int round = 2 * (rand() % 15);

    for (int i = 0; i < round * 2; i++) {
        if (n % 2 == 0) {
            score = 0;
            pthread_create(&thread1, NULL, numberGenerator, &p1);
            pthread_join(thread1, NULL);
            pthread_create(&thread2, NULL, numberGuesser, &p2);
            pthread_join(thread2, NULL);
            score2 += score;
        }
        else {
            score = 0;
            pthread_create(&thread2, NULL, numberGenerator, &p2);
            pthread_join(thread2, NULL);
            pthread_create(&thread1, NULL, numberGuesser, &p1);
            pthread_join(thread1, NULL);
            score1 += score;
        }

        printf("\n");
        n++;
    }

    printf("Player 1's score: %d\n", score1);
    printf("Player 2's score: %d\n", score2);
    if (score1 > score2) {
        printf("player2 win");
    }
    else if (score1 < score2) {
        printf("player1 win");
    }
    else printf("it's draw");
    pthread_mutex_destroy(&lock);
    return 0;
}