#include <stdio.h>

#define ROWS    6
#define COLS    7
#define FOUR    4

char scores[ROWS][COLS];
char header[] = "  A   B   C   D   E   F   G  ";
char horbar[] = "|---|---|---|---|---|---|---|";
int bin = 0;
char disc = 'X';

void init_scores();
void board();
void choose();
void fill_bin();
int check(char disc);
int check_direction(int start_row, int start_col, int row_inc, int col_inc, char disc);

/* main function *************************************************************/

int main()
{
    init_scores();
    board();

    while (1)
    {
        printf("Player %c, your turn!\n", disc);
        choose();
        printf("\n\n");
        board();
        if (check('X'))
        {
            printf("\n\nPlayer X wins!\n\n");
            break;
        }
        if (check('O'))
        {
            printf("\n\nPlayer O wins!\n\n");
            break;
        }
    }

    return 0;
}

/* helper functions **********************************************************/

void init_scores()
{
    // Initialize the board with empty spaces:
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            scores[i][j] = ' ';
        }
    }
}

void board()
{
    // Print the board along with the headers:
    printf("%s\n", header);
    printf("%s\n", horbar);

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("| %c ", scores[i][j]);
        }
        printf("|\n");
        printf("%s\n", horbar);
    }
}

void choose()
{
    // Prompt user to choose a bin (column A-G):
    char c;

    while (1)
    {
        printf("\nChoose bin: ");
        scanf(" %c", &c);
        switch(c)
        {
            case 'A': case 'a': bin = 0; break;
            case 'B': case 'b': bin = 1; break;
            case 'C': case 'c': bin = 2; break;
            case 'D': case 'd': bin = 3; break;
            case 'E': case 'e': bin = 4; break;
            case 'F': case 'f': bin = 5; break;
            case 'G': case 'g': bin = 6; break;
            default:
                printf("\nWrong letter! Try again.\n\n");
                board();
                continue;
        }

        // If the chosen column is valid and not full:
        if (scores[0][bin] == ' ')
        {
            fill_bin();
            disc = (disc == 'X') ? 'O' : 'X';
            break;
        }
        else
        {
            printf("\nColumn full! Try again.\n");
        }
    }
}

void fill_bin()
{
    // Fill the lowest available row in the chosen column:
    for (int row = ROWS - 1; row >= 0; row--)
    {
        if (scores[row][bin] == ' ')
        {
            scores[row][bin] = disc;
            break;
        }
    }
}

int check(char disc)
{
    // Check if the player has won:
    int i, j;

    // Check rows and columns
    for (i = 0; i < ROWS; ++i)
    {
        for (j = 0; j < COLS; ++j)
        {
            if (scores[i][j] == disc)
            {
                // Check horizontally, vertically, and diagonally
                if (check_direction(i, j, 0, 1, disc) ||  // Horizontal
                    check_direction(i, j, 1, 0, disc) ||  // Vertical
                    check_direction(i, j, 1, 1, disc) ||  // Diagonal down-right
                    check_direction(i, j, 1, -1, disc))   // Diagonal up-right
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int check_direction(int start_row, int start_col, int row_inc, int col_inc, char disc)
{
    int count = 0;
    for (int i = 0; i < FOUR; ++i)
    {
        int row = start_row + i * row_inc;
        int col = start_col + i * col_inc;
        if (row >= 0 && row < ROWS && col >= 0 && col < COLS && scores[row][col] == disc)
        {
            count++;
        }
        else
        {
            break;
        }
    }
    return (count == FOUR);
}
