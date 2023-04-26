#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char c, b[15];
    int i = 0;
    printf("Expression terminated by $:");
    while ((c = getchar()) != '$') b[i++] = c;
    int n = i - 1;
    printf("Given Expression:%s\nSymbol Table\nSymbol\taddr\ttype\n", b);
    for (int j = 0, x = 0; j <= n; j++) {
        c = b[j];
        if (isalpha(c)) {
            void *p = malloc(c);
            printf("%c\t%d\tidentifier\n", c, p);
        } else if (c == '+' || c == '-' || c == '*' || c == '=') {
            void *p = malloc(c);
            printf(" %c\t%d\toperator\n", c, p);
        }
    }
    return 0;
}


/*
OUTPUT:
Expression terminated by $:A=B+C$                                               
Given Expression:A=B+C                                                          
Symbol Table                                                                    
                                                                                
Symbol   addr    type                                                           
A        1828    identifier                                                     
                                                                                
 =       1898    operator                                                       
                                                                                
B        1964    identifier                                                     
                                                                                
 +       2034    operator                                                       
                                                                                
C        2082    identifier                                                     
*/
