#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clearscr(void)
{
#ifdef _WIN32
    system("cls");
#elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
    system("clear");
#else
#error "OS not supported."
#endif
}

int main(void)
{
    int i, j, n;
    double sec;
    
    clock_t start_t, end_t, total_t;
    
    clearscr();
    printf("Enter the run time(in sec) for the program  = ");
    scanf("%lf", &sec);
    
    clearscr();
    printf("Enter number of rows = ");
    scanf("%i", &n);
    clearscr();
    
    static const char ucase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ!“#$%‘()*+,-./0123456789:;<=>?@[]^_`abcdefghijklmnopqrstuvwxyz{|}~≥≤∙";
    const size_t ucase_count = sizeof(ucase) - 1;
    
    start_t = clock();
    while(total_t!=sec) {
        
        for(i=1; i<=n; i++)
        {
            for(j=i; j<=n; j++)
            {
                char random_char;
                int random_index = (double)rand() / RAND_MAX * ucase_count;
                
                random_char = ucase[random_index];
                printf("%c", random_char);
            }
            
            for(j=1; j<=(2*i-2); j++)
            {
                printf(" ");
            }
            
            for(j=i; j<=n; j++)
            {
                char random_char;
                int random_index = (double)rand() / RAND_MAX * ucase_count;
                
                random_char = ucase[random_index];
                printf("%c", random_char);
                
            }
            printf("\n");
        }
        
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=i; j++)
            {
                char random_char;
                int random_index = (double)rand() / RAND_MAX * ucase_count;
                
                random_char = ucase[random_index];
                printf("%c", random_char);
            }
            
            for(j=(2*i-2); j<(2*n-2); j++)
            {
                printf(" ");
            }
            
            for(j=1; j<=i; j++)
            {
                char random_char;
                int random_index = (double)rand() / RAND_MAX * ucase_count;
                
                random_char = ucase[random_index];
                printf("%c", random_char);
            }
            printf("\n");
        }
        clearscr();
        end_t = end_t + start_t;
        total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    }
    
    printf("\n\n\n\n\n");
    printf("Program executed for %lu seconds.\n\n\n", total_t);
    printf("\n\n\n\n\n");
    
    return 0;
}
