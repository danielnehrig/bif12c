#include <stdio.h>
#include <string.h>
#ifdef _WIN32
#include <conio.h>
#else
#include <stdio.h>
#define clrscr() printf("\e[1;1H\e[2J");
#endif

// A Program Print Hello x times
void hallo() {
    clrscr();
    int input;
    printf("\nHello Program");
    printf("\nEnter Amount to print Hello : ");
    scanf("%i", &input);
    printf("\n");
    for(int i=0;i<=input;i++) {
        printf("Hallo\n");
    }
}
// B Program Calculate x+=i
void Calc() {
    clrscr();
    int input;
    int math=0;
    printf("\nThis is the Counting Program 1+2+3+5+8");
    printf("\nEnter Amount to Count up too : ");
    scanf("%i", &input);
    for(int i=0;i<=input;i++) {
        math += i;
    }
    printf("\nResult is : %i", math);
}

// C Program Output Every Prime Number Up to N
void prime() {
    clrscr();
    int input,math;
    printf("\nThis is the Prime Program");
    printf("\nEnter Amount to Count up too : ");
    scanf("%i", &input);
    printf("\n");
    for(int i=0;i<input;i++) {
        int j=1;
        math = i + (i + j);
        printf("%i ", math);
    }
    printf("\n");
}

void fibonacci() {
    clrscr();
    int input;
    unsigned long long first,second,math;
    first = 0;
    second = 1;
    printf("\nThis is the Fibonacci Program");
    printf("\nEnter Amount to Count up too : ");
    scanf("%i", &input);
    printf("\n");
    for(int i=0;i<input;i++) {
        if ( input == 0 ) {
            math = 0;
            break;
        }
        else if ( input == 1 ) {
            math = 1;
            break;
        }
        else {
            math = first + second;
            first = second;
            second = math;
        }
    printf("%llu ", math);
    }
}

int main() {
    char programm,answer;
    printf("a = Print 5x Hello\n");
    printf("b = Calc 1...n\n");
    printf("c = Prime Numbers ... n\n");
    printf("d = fibonacci Numbers ... n\n");
    printf("x = To Cancel\n");
    printf("\nChoose Which Programm To Start : ");
    scanf(" %c", &programm);
    printf("\n");
    // Program Selection
    switch(programm) {
        case 'a' : hallo(); break;
        case 'b' : Calc(); break;
        case 'c' : prime(); break;
        case 'd' : fibonacci(); break;
        case 'x' : return 0; break;
        default : printf("\n\nNo Input Try Again"); break;
    }
    printf("\n\nRun Another Program? : ");
    scanf("%s", &answer);
    printf("\n\n");
    if(strcmp(&answer, "yes") == 0) {
        clrscr();
        main();
    }else if(strcmp(&answer, "no") == 0) {
        return 0;
    } else {
        printf("Input yes or no");
    }
    return 0;
}
