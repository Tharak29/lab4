#include <stdio.h>
#include <string.h>

int main() {
    char production[20], alpha[20], beta[20];
    char non_terminal;

    printf("Enter production (Example: E=E+T|T): ");
    scanf("%s", production);

    non_terminal = production[0];

    char *rhs = strchr(production, '=');
    rhs++;

    char *part1 = strtok(rhs, "|");
    char *part2 = strtok(NULL, "|");

    if(part1[0] == non_terminal) {
        strcpy(alpha, part1 + 1);
        strcpy(beta, part2);
    }
    else {
        strcpy(alpha, part2 + 1);
        strcpy(beta, part1);
    }

    printf("\nGrammar after removing Left Recursion:\n");

    printf("%c -> %s%c'\n", non_terminal, beta, non_terminal);
    printf("%c' -> %s%c' | ε\n", non_terminal, alpha, non_terminal);

    return 0;
}
