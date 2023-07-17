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
    int result, temp_number;
    // random generation for computer
    srand(time(0));
    temp_number = rand() % 100 + 1;
    if (temp_number < 33)
        comp = 's';
    else if ((temp_number > 33) && (temp_number < 66))
        comp = 'p';
    else
        comp = 'r';

    printf("Choose any of the aliases from 'r' for Rock , 'p' for Paper or 's' for Scissors : ");
    scanf("%c", &you);
    result = rockPaperScissors(you, comp);
    printf("Computer choosed : \"%c\"\n", comp);

    switch (result)
    {
    case 1:
        printf("You are the Winner!!!!!!!!!!");
        break;
    case -1:
        printf("Sorry, Computer won. Better luck next time :)");
        break;
    case 0:
        printf("It's an draw");
        break;
    }
    return 0;
}