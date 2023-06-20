#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main () {
    int input1;
    int input2;
    int input3;
    //variables to store guesses

    int correct_spot;
    int wrong_spot;
    //number of numbers in correct or wrong spots

    int tries = 15;

    srand(time(NULL));
    int num1 = rand() % 9+1;
    int num2 = rand() % 9+1;
    int num3 = rand() % 9+1;
    //numbers are randomly generated



    //ensures that there are no repeat numbers generated
    while(num1 == num2 || num1==num3){
        num1 = rand() % 9+1;
        num2 = rand() % 9+1;
        num3 = rand() % 9+1;
    }
    while(num2 == num1 || num2==num3){
        num1 = rand() % 9+1;
        num2 = rand() % 9+1;
        num3 = rand() % 9+1;
    }


    int code[3] = {num1, num2, num3};


    while(tries != 0){
        tries = tries - 1;

        correct_spot = 0;
        wrong_spot = 0;
        //resets values to 0

        printf("Guess the three digit code \n");
        printf("Input in the form of: 1,2,3");
        sleep(2);
        fflush(stdin);
        scanf("%d,%d,%d", &input1, &input2, &input3);


        //if an input is correct
        if (input1 == num1){
            correct_spot = correct_spot + 1;
        }
        if (input2 == num2){
            correct_spot = correct_spot + 1;
        }
        if (input3 == num3){
            correct_spot = correct_spot + 1;
        }

        //if an input is wrong, but matches the value of another random number slot
        if (input1 != num1){
            if (input1 == num2 || input1 == num3){
                wrong_spot = wrong_spot + 1;
            }
        }
        if (input2 != num2){
            if (input2 == num1 || input2 == num3){
                wrong_spot = wrong_spot + 1;
            }
        }
        if (input3 != num3){
            if (input3 == num2 || input3 == num1){
                wrong_spot = wrong_spot + 1;
            }
        }

        sleep(2);
        printf("%d digits are in the correct spot \n", correct_spot);
        sleep(1);
        printf("%d correct digits are in the wrong spot \n", wrong_spot);
        sleep(1);
        printf("You have %d tries left \n \n \n", tries);
        sleep(1);

        //if user guessed correctly
        if (input1 == num1 && input2 == num2 && input3 == num3){
            printf("Correct number inputted, proceed.");
            return 0;
        }

    }
    //if user ran out of tries and lost
    printf("The code was %d,%d,%d. You failed. \n", code[0], code[1], code[2]);
    return 1;

}
