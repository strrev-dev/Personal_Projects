/*creating a game*/
/*This is a simple number guessing game where the user has to guess a randomly generated number between 1 and 100.
The user has 10 attempts to guess the number. The program provides feedback on whether the guess is too high or too low. If the user guesses the number within 5 attempts, a congratulatory message is displayed.*/
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <stdbool.h>    

int main(int argc, char const *argv[])
{
    int number, guess, attempts = 0;
    srand(time(0)); // Seed the random number generator
    number = rand() % 100 + 1; // Generate a random number between 1 and 100
    printf("Welcome to the Number Guessing Game!\n");
    printf("I have selected a number between 1 and 100. Can you guess it?\n");
    printf("You have 10 attempts to guess the number.\n");
    printf("Let's start!\n");
    while (attempts < 10) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;
        
        if (guess < 1 || guess > 100) {
            printf("Please enter a number between 1 and 100.\n");
            attempts--; // Do not count this attempt
            continue;
        }

        if (guess < number) {
            printf("Too low! Try again.\n");
        } else if (guess > number) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number %d in %d attempts.\n", number, attempts);
            if (attempts <= 5) {
                printf("Great job! You guessed it in less than 5 attempts!\n");
            }
            break;
        }
    }
    if (attempts == 10) {
        printf("Sorry! You've used all your attempts. The number was %d.\n", number);
    }   
    
    return 0;
}
