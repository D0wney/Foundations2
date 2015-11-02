// Kevin Downey
// CS431 
// Program 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

                                              /*  States */
                        /*  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20  */
int DFA[27][21]={/* 0 a */{19,19,19,19,19,19,19,20,20,20,20,19,20,20,20,20,20,20,20,19,20},
                 /* 1 b */{19,19,19,19,19,19,19,20,20,20,20,19,20,20,20,20,20,20,20,19,20},
                 /* 2 c */{19,19,19,19, 5,19,19, 8,20,20,20,19,13,20,20,20,20,20,20,19,20},
                 /* 3 d */{19,19,19,19,19,19,19,20,20,20,20,19,20,20,20,20,20,20,20,19,20},
                 /* 4 e */{19,19,19,19,19,19,19,20,20,20,20,19,20,20,20,20,20,20,20,19,20},
                 /* 5 f */{19,19,19,19,19,19,19,20,20,20,20,19,20,20,20,20,20,20,20,19,20},
                 /* 6 g */{19,19,19,19,19,19,19,20,20,20,20,19,20,20,20,20,20,20,20,19,20},
                 /* 7 h */{19,19,19,19,19,19,19,20,20,20,20,19,20,20,20,20,20,20,20,19,20},
                 /* 8 i */{19,19,19,19,19,19,19,20,20,20,20,19,20,20,20,20,20,20,20,19,20},
                 /* 9 j */{19,19,19,19,19,19,19,20,20,20,20,19,20,20,20,20,20,20,20,19,20},
                /* 10 k */{19,19,19,19,19,19,19,20,20,20,20,19,20,20,20,20,20,18,20,19,20},
                /* 11 l */{19,19,19,19,19,19,19,20,20,20,20,19,20,20,20,20,20,20,20,19,20},
/* Elements */  /* 12 m */{19,19,19,19,19,19,11,20,20,10,20,19,20,20,15,20,20,20,20,19,20},
	            /* 13 n */{19,19,19,19,19,19,19,20,20,20,20,19,20,20,20,20,20,20,20,19,20},
                /* 14 o */{19,19,19,19,19, 6,19,20, 9,20,20,19,20,14,20,20,20,20,20,19,20},
                /* 15 p */{19,19,19,19,19,19,19,20,20,20,20,19,20,20,20,20,20,20,20,19,20},
                /* 16 q */{19,19,19,19,19,19,19,20,20,20,20,19,20,20,20,20,20,20,20,19,20},
                /* 17 r */{19,19,19,19,19,19,19,20,20,20,20,19,20,20,20,20,20,20,20,19,20},
                /* 18 s */{19,19,19,19,19,19,19,20,20,20,20,19,20,20,20,20,20,20,20,19,20},
                /* 19 t */{19,19,19,19,19,19,19,20,20,20,20,19,20,20,20,20,20,20,20,19,20},
                /* 20 u */{19,19,19,19,19,19,19,17,20,20,20,19,20,20,20,20,17,20,20,19,20},
                /* 21 v */{19,19,19,19,19,19,19,20,20,20,20,19,20,20,20,20,20,20,20,19,20},
                /* 22 w */{ 1, 2, 3,19,19,19,19,20,20,20,20,19,20,20,20,20,20,20,20,19,20},
	       	    /* 23 x */{19,19,19,19,19,19,19,20,20,20,20,19,20,20,20,20,20,20,20,19,20},
		        /* 24 y */{19,19,19,19,19,19,19,20,20,20,20,19,20,20,20,20,20,20,20,19,20},
                /* 25 z */{19,19,19,19,19,19,19,20,20,20,20,19,20,20,20,20,20,20,20,19,20},
                /* 26 . */{20,12,12, 4,20,12, 7,20,20,16,20,12,20,20,16,20,20,20,20,12,20}};


int acceptedStates[] = {10, 11, 15, 18};
char language[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','.'};

// Returns next state
int NEXT_STATE(char inputChar, int state)
{
        int i;
        for(i=0;i<27;i++)
        {
                if(inputChar==language[i]){
                        printf("%c --> %d\n", inputChar, DFA[i][state]); // prints next state
                        return DFA[i][state];
                }
        }
        return -1; //not in language
}


int main()
{
        char play; // if user wants to play or not
        printf("Do you want to enter a string? (y/n): ");
        scanf("%c", &play);

        while(play=='y') // continues playing user doesn't enter 'y'
        {
                int acceptState= 0; // returns 0 or 1 based on final state
                int state=0;
                char* inputString;
                inputString = (char *) malloc(1000);

                printf("Enter a string: "); // User input string
                scanf("%s", inputString);
                printf("%s\n", inputString);

                int inputLength = strlen(inputString);

                int i = 0;
                char inputChar;
                printf("--> %d\n", state);

                while(i<inputLength) // runs through string
                {
                        state = NEXT_STATE(inputString[i], state);
                        i++;
                }

                for(i=0; i<4; i++) // checks if the final state is accepted
                {
                        if(state==acceptedStates[i]){
                                acceptState = 1;
                        }
                }

                if(acceptState == 1)
                        printf("ACCEPTED\n");
                else
                        printf("REJECTED\n");

                printf("\n");
                printf("Do you want to enter a string? (y/n): ");
                scanf(" %c", &play);
        }
}