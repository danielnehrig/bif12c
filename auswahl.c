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
    int input,k,j=3;
    printf("\nThis is the Prime Program");
    printf("\nEnter Amount to Count up too : ");
    scanf("%i", &input);
    printf("\n");
    for(int i=2;i<=input; ) {
        for(k=2;k<=j-1;k++) {
            if(j%k == 0)
                break;
        }
        if ( k == j ) {
            printf("%i ", j);
            i++;
        }
        j++;
    }
    printf("\n");
}

void fullc() {
    clrscr();
    int i = 0;
    int arrlen;
    char operation[255];
    float input[255];
    float dash,math;
    dash = 0;
    math = 0;
    printf("\nThis is the Full Calculator Program");
    // Method 2
    do {
        char push;
        printf("\nEnter Number : ");
        scanf(" %f", &input[i]);
        if(!math) {
            math = input[0];
        }
        printf("\nEnter Operation : ");
        scanf(" %c", &push);
        if(push != '=') {
            operation[i] = push;
        } else {
            break;
        }
        i++;
    } while (operation[i-1] != '=');
    arrlen = i;
    printf("\nIs Math init? = %f", math);
    printf("\nArray Length : %d", arrlen);
    for(int k = 0;k<arrlen;k++) {
        // Check if the next operator is valid to to calculate
        if(
                // Method 1
                (operation[k] == '+' && 
                 (operation[k+1] != '*' || operation[k+1] != '/')) || 
                (operation[k] == '+' && 
                 (operation[k+1] == '+' || operation[k+1] == '-')) || 
                (operation[k] == '-' && 
                 (operation[k+1] != '*' || operation[k+1] != '/')) ||
                (operation[k] == '-' && 
                 (operation[k+1] == '-' || operation[k+1] == '+'))) 
        {
            switch (operation[k]) {
                case '+' : dash += input[k+1]; break;
                case '-' : dash -= input[k+1]; break;
                default: break;
            }
        } else if(operation[k] == '*' || operation[k] == '/') {
            switch (operation[k]) {
                case '*' : math *= input[k+1]; break;
                case '/' : math /= input[k+1]; break;
                default  : break;
            }
        } else {
            // throw exception
            printf("\nOut of Range at char %c on index %i", operation[k], k);
            fullc();
        }
    }
    math += dash;
    printf("\nResult is %f", math);
    printf("\nRestart Caluclation? (yes,no) : ");
    char restart;
    scanf("%s", &restart);
    if(strcmp(&restart,"yes") == 0) {
        fullc();
    }
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
    printf("e = Full Calculator ... n\n");
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
        case 'e' : fullc(); break;
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
