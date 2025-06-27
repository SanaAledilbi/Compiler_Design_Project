#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>


int lookahead;
bool IL = false;
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
    if (isdigit(lookahead)) {

        if (IL)
            printf("push %c\n", lookahead);

        else
            putchar(lookahead);


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
        if ((t == ' ') || (t == '\t') || (t == '\n'));
        else
            return t;
    }

}

int main(void)
{
    lookahead = lexan();
    expr();
    putchar('\n'); /* adds trailing newline character */
}