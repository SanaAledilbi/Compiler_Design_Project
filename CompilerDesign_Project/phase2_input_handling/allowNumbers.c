#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define NUM 256

int tokenval;
int lookahead;
int nbrline = 1;
bool IL;

void expr(void);
void rest(void);
void term(void);
void match(int);
void error(void);
int lexan();

//////////expr Function
void expr(void)
{
    term();
    ///////code of REST
    while (1) {
        if (lookahead == '+') {
            match('+');
            term();

            if (IL)
                printf("pop r1\npop r2\nadd r2,r1\npush r2");

            else
                putchar('+');



        }
        else if (lookahead == '-') {
            match('-');
            term();

            if (IL)
                printf("pop r1\npop r2\nsub r2,r1\npush r2");

            else
                putchar('-');



        }
        else
            break;
    }
    ////////end of REST 
}

//////////term Function
void term(void)
{
    if (lookahead == NUM) {

        if (IL)
            printf("push %d\n", tokenval);

        else
            printf("%d", tokenval);


        match(lookahead);
    }
    else
        error();
}
//////////match Function
void match(int t)
{
    if (lookahead == t)
        lookahead = lexan();
    else
        error();
}
//////////error Function
void error(void)
{
    printf("syntax error\n"); /* print error message */
    //exit(1); /* then halt */
}


////////////function lexan
int lexan() {

    int t;
    while (1)
    {
        t = getchar();
        if ((t == ' ') || (t == '\t'));
        else if (t == '\n')
            nbrline++;
        else if (isdigit(t))
        {
            ungetc(t, stdin);
            scanf("%d", &tokenval);

            return NUM;
        }
        else
            return t;
    }

}

int main(void)
{

    char choice;
    while (1) {
        printf("Choose output format:\n");
        printf("Enter 'p' for Postfix or 'i' for IL: ");
        scanf(" %c", &choice);
        getchar();

        if (choice == 'i') {
            IL = true;
            break;
        }
        else if (choice == 'p')
        {
            IL = false;
            break;
        }
        else {
            printf("Invalid choice.\n");
            continue;
        }
    }

    printf("Enter expression: ");
    lookahead = lexan();
    expr();
    putchar('\n'); // adds trailing newline character

}