/*
-------------------------------------
File:    decode_message.c
Project: Lab3_cp264
file description
-------------------------------------
Author:  Aleksander Sienkiewicz
ID:      210222490
Email:   sien2490@mylaurier.ca
Date:    Jan 31 2023
-------------------------------------

Program Description:
===================
   Given a 2D character array, called "scrambled", filled with ad hoc characters, this program uses the [row, col]
pair values stored in the 2D integer array, called "key", to retrieve characters from the "scrambled" array.
The retrieved individual characters are concatenated, left to right, and in the order that they are retrieved, to
form the complete decoded message. The message is then output.
------------------------------------------------------------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//===================== GLOBAL MACRO DEFINITIONS ==========================================================

#define cNUL '\0'   // NULL character
#define sNUL "\0"   // NULL String
#define cBlank ' '  // Blank character
#define sBlank " "  // Blank String
#define cUScore '_' // Underscore character
#define sUScore "_" // Underscore string.

// Define machine-independent TRUE and FALSE values
#ifdef TRUE
#undef TRUE
#undef FALSE
#endif
#define TRUE (1 == 1)
#define FALSE (0 == 1)
// ======================== Statement Function Definitions.
#define F_MIN(v1, v2) (((v1) < (v2)) ? (v1) : (v2))    // Return the less    of v1 and v2
#define F_MAX(v1, v2) (((v1) > (v2)) ? (v1) : (v2))    // Return the greater of v1 and v2
#define ZF_MIN(v1, v2) (F_MAX(0, (F_MIN((v1), (v2))))) // Like F_MIN, but lower bounds the result at ZERO
#define ZF(v) (F_MAX(0, (v)))                          // Lower bounds the value "v" at ZERO.
#define F_NOT(v) (((v) == TRUE) ? FALSE : TRUE)        // Logical Negation.
#define F_ABS(v) (((v) >= 0) ? (v) : (-(v)))           // Absolute value

//====================== GLOBAL CONSTANTS ==================================================================
#define MAX_NUM_ROWS 5   // Max. number of rows.
#define MAX_NUM_COLS 6   // Max. number of columns.
#define MAX_KEY_PAIRS 15 // Max. number of [row, col] key pairs.

int main(int argc, char *argv[])
{
    //==============================
    setbuf(stdout, NULL); // Turns standard output buffering off

    //<***Your Variable Declarations here ***>

    // "scrambled" - 2D Character Array storing adhoc characters.
    char scrambled[MAX_NUM_ROWS][MAX_NUM_COLS] = {{"zd_k83"},
                                                  {"Ju9_Tn"},
                                                  {"bgm7If"},
                                                  {"ax0DLU"},
                                                  {"p_QoiR"}};
    // "Key" - 2D Integer Array storing the message key pairs [row, col].
    //         Note: The range of the row, col pair values stored in the "key"
    //               array is as shown below:
    //               [row, col] ==> [1...5, 1...6], not [0...4, 0...5]!!!
    int key[MAX_KEY_PAIRS][2] = {
        {3, 5}, // I
        {5, 2}, //_
        {4, 1}, // a
        {3, 3}, // m  // Fill these spaces with right numbers
        {1, 3}, //_
        {1, 2}, // d  // Fill these spaces with right numbers
        {5, 4}, // o
        {5, 5}, // i
        {2, 6}, // n  // Fill these spaces with right numbers
        {3, 2}, // g
        {2, 4}, //_
        {4, 5}, // L  // Fill these spaces with right numbers
        {4, 1}, // a
        {3, 1}, // b  // Fill these spaces with right numbers
        {1, 6}  // 3
    };
    char output[MAX_KEY_PAIRS + 1] = "";
    for (int i = 0; i < MAX_KEY_PAIRS; i++)
    {
        int col = key[i][1] - 1;
        int row = key[i][0] - 1;

        char *str = &scrambled[row][col];
        if (*str != '_')//(space)
        {
            strncat(output, str, 1);//(concatonate if not spave)
        }
        else
        {
            char out = ' ';//add the whitespace
            strncat(output, &out, 1);//then continue with concat
        }
    }
    output[MAX_KEY_PAIRS] = '\0';

    printf("::: Decoded Message: [%s]\n", output);

    printf("\n");
    printf(":::\n");
    printf("::: Program Terminated.\n");
    printf(":::\n");

    return 0;

    return 0;
}
