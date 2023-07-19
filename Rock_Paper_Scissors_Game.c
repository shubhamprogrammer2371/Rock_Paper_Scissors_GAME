#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rockPaperScissors(char you, char comp)
{
    // return 1 if you win , -1 if you loose and 0 if it's draw
    if (you == comp) // draw
        return 0;
    if ((you == 'r' && comp == 's') || (you == 'p' && comp == 'r') || (you == 's' && comp == 'p')) // user win
        return 1;
    if ((you == 'r' && comp == 'p') || (you == 'p' && comp == 's') || (you == 's' && comp == 'r')) // computer win
        return -1;
}

int main()
{
    char you, comp;
    int result, temp_number, choice, score = 0;
    printf("****************** Welcome to the Rock,Paper and Scissors Game *******************\n\n");
    while (1)
    {
        // random generation for computer
        srand(time(0));
        temp_number = rand() % 10 + 1;
        if (temp_number < 3)
            comp = 's';
        else if ((temp_number > 3) && (temp_number < 6))
            comp = 'p';
        else
            comp = 'r';
        printf("-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n> Press 1 to start the game.\n> Press 0 to end the game.\n\nEnter your choice : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("\nChoose any of the aliases from 'r' for Rock , 'p' for Paper or 's' for Scissors : ");
            scanf("%s", &you);

            result = rockPaperScissors(you, comp);
            printf("\nComputer choosed : \"%c\"\n", comp);

            switch (result)
            {
            case 1:
                score++;
                printf("You are the Winner!!!!!!!!!!\n");
                break;
            case -1:
                printf("Sorry, Computer won. Better luck next time :)\n");
                break;
            case 0:
                printf("It's an draw\n");
                break;
            }
        }
        else if (choice == 0)
        {
            printf("\nI hope you liked the Rock,Paper and Scissors game :)\nYou got the score of %d from the game.", score);
            exit(0);
        }
        else
        {
            printf("\nInvalid Choice!! Please enter 1 or 0.\n");
        }
    }
    return 0;
}
