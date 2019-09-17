#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <switch.h>
#include "keyboard.h"

// Variables

long int num1 = 0;
long int num2 = 0;
long int result;
int mode = 1;
float resultDiv;
char *swkdbout = 0;

// Actual code

void startupf() {
    printf(
    "SwitchMaths by PaskaPinishkes, inspired by Calculator-NX by Thomleg\n"
    "Press X to input first number\n"
    "Press Y to input second number\n"
    "Press A to calculate\n"
    "Press L or R to change operation\n1 is Addition\n2 is Substraction\n3 is Multiplication\n4 is Division\n"
    "Press B or + to exit\n"

    );
}

int main(int argc, char **argv)
{
    consoleInit(NULL);
    userAppInit();
    startupf();

    while(appletMainLoop())
    {
        hidScanInput();
        u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);

        if (kDown & KEY_PLUS || kDown & KEY_B)
        break;

        if (kDown & KEY_X) {
            swkdbout = popKeyboardf("Type the first number", 256);
            num1 = atol(swkdbout);
        }

        if (kDown & KEY_Y) {
            swkdbout = popKeyboardf("Type the second number", 256);
            num2 = atol(swkdbout);
        }

        if (kDown & KEY_L || kDown & KEY_R) {
            mode++;
            if (mode == 5)
            mode = 1;

            consoleClear();
            startupf();
            printf("Operation mode set to %d", mode);
        }

        // Calculate
        if (kDown & KEY_A) {
            consoleClear();
            startupf();
            printf("Calculating...\n");

            switch (mode) {
                case 1:
                    result = num1 + num2;
                    consoleClear();
                    startupf();
                    printf("The result of %ld + %ld is %ld", num1, num2, result);
                    break;

                case 2:
                    result = num1 - num2;
                    consoleClear();
                    startupf();
                    printf("The result of %ld - %ld is %ld", num1, num2, result);
                    break;

                case 3:
                    result = num1 * num2;
                    consoleClear();
                    startupf();
                    printf("The result of %ld multiplicated by %ld is %ld", num1, num2, result);
                    break;

                case 4:
                    resultDiv = (float)num1 / num2;
                    consoleClear();
                    startupf();
                    if (num2 == 0)
                    printf("Nice try");
                    else
                    printf("The result of %ld divided by %ld is %f", num1, num2, resultDiv);
                    break;

                default:
                    printf("Invalid operation");
            
            }
        }




        consoleUpdate(NULL);
    }
    consoleExit(NULL);
    return 0;
}