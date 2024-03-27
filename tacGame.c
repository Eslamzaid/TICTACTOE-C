#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void printBody(char pG[][3]);
void getUserInput(char playGround[][3]);
int setInputs(char name[]);
int checkingGame(char pG[][3]);

int COUNTER = 0;
char currentPlay;

int main()
{
    // Greetings
    printf("~~~~~~~~~~~~~~~~~~~~\n");
    printf("Hello and Welcome to TICTACTOE game made with C programming language (which is amazing!) \n");
    printf("~~~~~~~~~~~~~~~~~~~~\n");

    // Variables
    char playGround[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

    // Getting the First player character
    do
    {
        printf("Enter First player character ( X | O ): ");
        scanf(" %c", &currentPlay);
        if (currentPlay != 'X' && currentPlay != 'O')
            printf("Choose only between X and O!\n");
        else
            break;
    } while (1);

    // Game loop
    while (1)
    {
        printBody(playGround);
        getUserInput(playGround);
        int win = checkingGame(playGround);
        if (win > 0)
        {
            printBody(playGround);
            if (win == 1)
                printf("**** %c Won the game! ****\n", currentPlay == 'X' ? 'O' : 'X');
            else
                printf("##**!! Tie !!**##\n");
            break;
        }
    }
}

int checkingGame(char pG[][3])
{
    for (int i = 0; i < 3; i++)
    {
        // checking for rows
        if (pG[i][0] != ' ' && pG[i][0] == pG[i][1] && pG[i][1] == pG[i][2])
        {
            return 1;
        }
        // checking if columns
        if (pG[0][i] == pG[1][i] && pG[1][i] == pG[2][i] && pG[0][i] != ' ')
        {
            return 1;
        }
        // checking diagonals
        // Check main diagonal
        if (pG[0][0] != ' ' && pG[0][0] == pG[1][1] && pG[1][1] == pG[2][2])
        {
            return 1;
        }

        // Check anti-diagonal
        if (pG[0][2] != ' ' && pG[0][2] == pG[1][1] && pG[1][1] == pG[2][0])
        {
            return 1;
        }
    }
    if (COUNTER == 9)
        return 2;
    return 0;
}

void getUserInput(char playGround[][3])
{
    int row, column;

    while (1)
    { // Infinite loop until a valid input is provided
        printf("%c turn (Total game turns: %d)\n", currentPlay, COUNTER);
        row = setInputs("row");
        column = setInputs("column");

        if (playGround[row][column] != ' ')
        {
            printf("You can't put here (%c) is here!\n", playGround[row][column]);
        }
        else
        {
            playGround[row][column] = currentPlay;
            COUNTER++;
            if (currentPlay == 'X')
            {
                currentPlay = 'O';
            }
            else
            {
                currentPlay = 'X';
            }
            break; // Exit the loop after a valid input is provided
        }
    }
}

void printBody(char pG[][3])
{
    printf("%4d   %2d   %2d\n", 1, 2, 3);
    for (int i = 0; i < 3; i++)
    {
        printf("%2d%2c | %2c | %2c\n", i + 1, pG[i][0], pG[i][1], pG[i][2]); // Added newline character
        if (i < 2)
            printf("%3c--|----|---\n", '-'); // Added horizontal separators
    }
}

int setInputs(char name[])
{
    int type = 0;
    while (1)
    {
        printf("Enter %s (1~3): ", name);
        scanf("%d", &type);
        if (type <= 3 && type >= 1)
            break;
        printf("Please enter between 1 and 3!!\n");
    }
    return type - 1;
}
