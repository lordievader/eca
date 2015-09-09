#ifdef ARDUINO_TARGET
#include "Arduino.h"
#include <avr/pgmspace.h>
#define F_CPU 16000000
#define ARDUINO 100
#else
#include <string>
#include <ctime>
#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#endif

#include "ecamatrix.h"
#include "ansmatrix.h"
#include <stdio.h>
using namespace::std;

#ifdef ARDUINO_TARGET
const PROGMEM unsigned char rows = 20;
const PROGMEM unsigned char columns = 20;
#else
const unsigned char rows = 20;
const unsigned char columns = 20;
#endif

#ifdef ARDUINO_TARGET
void freeMemory()
{
    extern unsigned int __bss_end;
    extern unsigned int __heap_start;
    extern void *__brkval;
    int free_memory;
    char message[50];
    snprintf(message, 50, "f=%db\n", ((int)&free_memory) - ((int)&__bss_end));
    Serial.print(String(message));
}
#endif

// void printMatrix(unsigned long matrix[rows][columns])
// {
// #ifdef ARDUINO_TARGET
//     String output = "";
// #else
//     string output = "";
// #endif
//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = 0; j < columns; j++)
//         {
//             char str[100];
//             snprintf(str, 100, "%3lu, ", matrix[i][j]);
// #ifdef ARDUINO_TARGET
//             output += String(str);
// #else
//             output += string(str);
// #endif
//         }
//         logMessage(output);
//         logMessage((char *)"\n");
//         output = "";
//     }
// }

bool checkMatrix(int result[rows][columns])
{
    unsigned char i = 0;
    while (i < rows)
    {
        unsigned char j = 0;
        while (j < columns)
        {
            int correct = pgm_read_word(&C[i][j]);
            if (result[i][j] != correct)
            {
                Serial.print(result[i][j]);
                Serial.print(F(" != "));
                Serial.print(correct);
                Serial.print(F(" ("));
                Serial.print(i);
                Serial.print(F(","));
                Serial.print(j);
                Serial.println(F(")"));
                return false;
            }
            j++;
        }
        i++;
    }
    return true;
}

void setup()
{
#ifdef ARDUINO_TARGET
    Serial.begin(460800);
#endif
}

void loop()
{
    unsigned char rounds = 1000;
#ifdef ARDUINO_TARGET
    Serial.println(F("START"));
    freeMemory();
//     Timer1.initialize(8191);
#endif

    char cache[rows][columns];
    int B[rows][columns];
    unsigned char round = 0;
    unsigned char row =  0;
    unsigned char column;
    while (row < rows)
    {
        column = 0;
        while (column < columns)
        {
            cache[row][column] = (char)pgm_read_word(&A[row][column]);
            column++;
        }
        row++;
    }

    int temp;
    unsigned long timePoint = micros();
    while (round <= rounds)
    {
        row = 0;
        while (row < rows)
        {
//             column = 0;
//             while (column < columns)
//             {
//                 temp = cache[row][0] * cache[0][column];
//                 temp += cache[row][1] * cache[1][column];
//                 temp += cache[row][2] * cache[2][column];
//                 temp += cache[row][3] * cache[3][column];
//                 temp += cache[row][4] * cache[4][column];
//                 temp += cache[row][5] * cache[5][column];
//                 temp += cache[row][6] * cache[6][column];
//                 temp += cache[row][7] * cache[7][column];
//                 temp += cache[row][8] * cache[8][column];
//                 temp += cache[row][9] * cache[9][column];
//                 temp += cache[row][10] * cache[10][column];
//                 temp += cache[row][11] * cache[11][column];
//                 temp += cache[row][12] * cache[12][column];
//                 temp += cache[row][13] * cache[13][column];
//                 temp += cache[row][14] * cache[14][column];
//                 temp += cache[row][15] * cache[15][column];
//                 temp += cache[row][16] * cache[16][column];
//                 temp += cache[row][17] * cache[17][column];
//                 temp += cache[row][18] * cache[18][column];
//                 temp += cache[row][19] * cache[19][column];
//                 B[row][column] = temp;
//
//                 column++;
//             }
temp = cache[row][0] * cache[0][0];
temp += cache[row][1] * cache[1][0];
temp += cache[row][2] * cache[2][0];
temp += cache[row][3] * cache[3][0];
temp += cache[row][4] * cache[4][0];
temp += cache[row][5] * cache[5][0];
temp += cache[row][6] * cache[6][0];
temp += cache[row][7] * cache[7][0];
temp += cache[row][8] * cache[8][0];
temp += cache[row][9] * cache[9][0];
temp += cache[row][10] * cache[10][0];
temp += cache[row][11] * cache[11][0];
temp += cache[row][12] * cache[12][0];
temp += cache[row][13] * cache[13][0];
temp += cache[row][14] * cache[14][0];
temp += cache[row][15] * cache[15][0];
temp += cache[row][16] * cache[16][0];
temp += cache[row][17] * cache[17][0];
temp += cache[row][18] * cache[18][0];
temp += cache[row][19] * cache[19][0];
B[row][0] = temp;
temp = 0;
temp += cache[row][0] * cache[0][1];
temp += cache[row][1] * cache[1][1];
temp += cache[row][2] * cache[2][1];
temp += cache[row][3] * cache[3][1];
temp += cache[row][4] * cache[4][1];
temp += cache[row][5] * cache[5][1];
temp += cache[row][6] * cache[6][1];
temp += cache[row][7] * cache[7][1];
temp += cache[row][8] * cache[8][1];
temp += cache[row][9] * cache[9][1];
temp += cache[row][10] * cache[10][1];
temp += cache[row][11] * cache[11][1];
temp += cache[row][12] * cache[12][1];
temp += cache[row][13] * cache[13][1];
temp += cache[row][14] * cache[14][1];
temp += cache[row][15] * cache[15][1];
temp += cache[row][16] * cache[16][1];
temp += cache[row][17] * cache[17][1];
temp += cache[row][18] * cache[18][1];
temp += cache[row][19] * cache[19][1];
B[row][1] = temp;
temp = 0;
temp += cache[row][0] * cache[0][2];
temp += cache[row][1] * cache[1][2];
temp += cache[row][2] * cache[2][2];
temp += cache[row][3] * cache[3][2];
temp += cache[row][4] * cache[4][2];
temp += cache[row][5] * cache[5][2];
temp += cache[row][6] * cache[6][2];
temp += cache[row][7] * cache[7][2];
temp += cache[row][8] * cache[8][2];
temp += cache[row][9] * cache[9][2];
temp += cache[row][10] * cache[10][2];
temp += cache[row][11] * cache[11][2];
temp += cache[row][12] * cache[12][2];
temp += cache[row][13] * cache[13][2];
temp += cache[row][14] * cache[14][2];
temp += cache[row][15] * cache[15][2];
temp += cache[row][16] * cache[16][2];
temp += cache[row][17] * cache[17][2];
temp += cache[row][18] * cache[18][2];
temp += cache[row][19] * cache[19][2];
B[row][2] = temp;
temp = 0;
temp += cache[row][0] * cache[0][3];
temp += cache[row][1] * cache[1][3];
temp += cache[row][2] * cache[2][3];
temp += cache[row][3] * cache[3][3];
temp += cache[row][4] * cache[4][3];
temp += cache[row][5] * cache[5][3];
temp += cache[row][6] * cache[6][3];
temp += cache[row][7] * cache[7][3];
temp += cache[row][8] * cache[8][3];
temp += cache[row][9] * cache[9][3];
temp += cache[row][10] * cache[10][3];
temp += cache[row][11] * cache[11][3];
temp += cache[row][12] * cache[12][3];
temp += cache[row][13] * cache[13][3];
temp += cache[row][14] * cache[14][3];
temp += cache[row][15] * cache[15][3];
temp += cache[row][16] * cache[16][3];
temp += cache[row][17] * cache[17][3];
temp += cache[row][18] * cache[18][3];
temp += cache[row][19] * cache[19][3];
B[row][3] = temp;
temp = 0;
temp += cache[row][0] * cache[0][4];
temp += cache[row][1] * cache[1][4];
temp += cache[row][2] * cache[2][4];
temp += cache[row][3] * cache[3][4];
temp += cache[row][4] * cache[4][4];
temp += cache[row][5] * cache[5][4];
temp += cache[row][6] * cache[6][4];
temp += cache[row][7] * cache[7][4];
temp += cache[row][8] * cache[8][4];
temp += cache[row][9] * cache[9][4];
temp += cache[row][10] * cache[10][4];
temp += cache[row][11] * cache[11][4];
temp += cache[row][12] * cache[12][4];
temp += cache[row][13] * cache[13][4];
temp += cache[row][14] * cache[14][4];
temp += cache[row][15] * cache[15][4];
temp += cache[row][16] * cache[16][4];
temp += cache[row][17] * cache[17][4];
temp += cache[row][18] * cache[18][4];
temp += cache[row][19] * cache[19][4];
B[row][4] = temp;
temp = 0;
temp += cache[row][0] * cache[0][5];
temp += cache[row][1] * cache[1][5];
temp += cache[row][2] * cache[2][5];
temp += cache[row][3] * cache[3][5];
temp += cache[row][4] * cache[4][5];
temp += cache[row][5] * cache[5][5];
temp += cache[row][6] * cache[6][5];
temp += cache[row][7] * cache[7][5];
temp += cache[row][8] * cache[8][5];
temp += cache[row][9] * cache[9][5];
temp += cache[row][10] * cache[10][5];
temp += cache[row][11] * cache[11][5];
temp += cache[row][12] * cache[12][5];
temp += cache[row][13] * cache[13][5];
temp += cache[row][14] * cache[14][5];
temp += cache[row][15] * cache[15][5];
temp += cache[row][16] * cache[16][5];
temp += cache[row][17] * cache[17][5];
temp += cache[row][18] * cache[18][5];
temp += cache[row][19] * cache[19][5];
B[row][5] = temp;
temp = 0;
temp += cache[row][0] * cache[0][6];
temp += cache[row][1] * cache[1][6];
temp += cache[row][2] * cache[2][6];
temp += cache[row][3] * cache[3][6];
temp += cache[row][4] * cache[4][6];
temp += cache[row][5] * cache[5][6];
temp += cache[row][6] * cache[6][6];
temp += cache[row][7] * cache[7][6];
temp += cache[row][8] * cache[8][6];
temp += cache[row][9] * cache[9][6];
temp += cache[row][10] * cache[10][6];
temp += cache[row][11] * cache[11][6];
temp += cache[row][12] * cache[12][6];
temp += cache[row][13] * cache[13][6];
temp += cache[row][14] * cache[14][6];
temp += cache[row][15] * cache[15][6];
temp += cache[row][16] * cache[16][6];
temp += cache[row][17] * cache[17][6];
temp += cache[row][18] * cache[18][6];
temp += cache[row][19] * cache[19][6];
B[row][6] = temp;
temp = 0;
temp += cache[row][0] * cache[0][7];
temp += cache[row][1] * cache[1][7];
temp += cache[row][2] * cache[2][7];
temp += cache[row][3] * cache[3][7];
temp += cache[row][4] * cache[4][7];
temp += cache[row][5] * cache[5][7];
temp += cache[row][6] * cache[6][7];
temp += cache[row][7] * cache[7][7];
temp += cache[row][8] * cache[8][7];
temp += cache[row][9] * cache[9][7];
temp += cache[row][10] * cache[10][7];
temp += cache[row][11] * cache[11][7];
temp += cache[row][12] * cache[12][7];
temp += cache[row][13] * cache[13][7];
temp += cache[row][14] * cache[14][7];
temp += cache[row][15] * cache[15][7];
temp += cache[row][16] * cache[16][7];
temp += cache[row][17] * cache[17][7];
temp += cache[row][18] * cache[18][7];
temp += cache[row][19] * cache[19][7];
B[row][7] = temp;
temp = 0;
temp += cache[row][0] * cache[0][8];
temp += cache[row][1] * cache[1][8];
temp += cache[row][2] * cache[2][8];
temp += cache[row][3] * cache[3][8];
temp += cache[row][4] * cache[4][8];
temp += cache[row][5] * cache[5][8];
temp += cache[row][6] * cache[6][8];
temp += cache[row][7] * cache[7][8];
temp += cache[row][8] * cache[8][8];
temp += cache[row][9] * cache[9][8];
temp += cache[row][10] * cache[10][8];
temp += cache[row][11] * cache[11][8];
temp += cache[row][12] * cache[12][8];
temp += cache[row][13] * cache[13][8];
temp += cache[row][14] * cache[14][8];
temp += cache[row][15] * cache[15][8];
temp += cache[row][16] * cache[16][8];
temp += cache[row][17] * cache[17][8];
temp += cache[row][18] * cache[18][8];
temp += cache[row][19] * cache[19][8];
B[row][8] = temp;
temp = 0;
temp += cache[row][0] * cache[0][9];
temp += cache[row][1] * cache[1][9];
temp += cache[row][2] * cache[2][9];
temp += cache[row][3] * cache[3][9];
temp += cache[row][4] * cache[4][9];
temp += cache[row][5] * cache[5][9];
temp += cache[row][6] * cache[6][9];
temp += cache[row][7] * cache[7][9];
temp += cache[row][8] * cache[8][9];
temp += cache[row][9] * cache[9][9];
temp += cache[row][10] * cache[10][9];
temp += cache[row][11] * cache[11][9];
temp += cache[row][12] * cache[12][9];
temp += cache[row][13] * cache[13][9];
temp += cache[row][14] * cache[14][9];
temp += cache[row][15] * cache[15][9];
temp += cache[row][16] * cache[16][9];
temp += cache[row][17] * cache[17][9];
temp += cache[row][18] * cache[18][9];
temp += cache[row][19] * cache[19][9];
B[row][9] = temp;
temp = 0;
temp += cache[row][0] * cache[0][10];
temp += cache[row][1] * cache[1][10];
temp += cache[row][2] * cache[2][10];
temp += cache[row][3] * cache[3][10];
temp += cache[row][4] * cache[4][10];
temp += cache[row][5] * cache[5][10];
temp += cache[row][6] * cache[6][10];
temp += cache[row][7] * cache[7][10];
temp += cache[row][8] * cache[8][10];
temp += cache[row][9] * cache[9][10];
temp += cache[row][10] * cache[10][10];
temp += cache[row][11] * cache[11][10];
temp += cache[row][12] * cache[12][10];
temp += cache[row][13] * cache[13][10];
temp += cache[row][14] * cache[14][10];
temp += cache[row][15] * cache[15][10];
temp += cache[row][16] * cache[16][10];
temp += cache[row][17] * cache[17][10];
temp += cache[row][18] * cache[18][10];
temp += cache[row][19] * cache[19][10];
B[row][10] = temp;
temp = 0;
temp += cache[row][0] * cache[0][11];
temp += cache[row][1] * cache[1][11];
temp += cache[row][2] * cache[2][11];
temp += cache[row][3] * cache[3][11];
temp += cache[row][4] * cache[4][11];
temp += cache[row][5] * cache[5][11];
temp += cache[row][6] * cache[6][11];
temp += cache[row][7] * cache[7][11];
temp += cache[row][8] * cache[8][11];
temp += cache[row][9] * cache[9][11];
temp += cache[row][10] * cache[10][11];
temp += cache[row][11] * cache[11][11];
temp += cache[row][12] * cache[12][11];
temp += cache[row][13] * cache[13][11];
temp += cache[row][14] * cache[14][11];
temp += cache[row][15] * cache[15][11];
temp += cache[row][16] * cache[16][11];
temp += cache[row][17] * cache[17][11];
temp += cache[row][18] * cache[18][11];
temp += cache[row][19] * cache[19][11];
B[row][11] = temp;
temp = 0;
temp += cache[row][0] * cache[0][12];
temp += cache[row][1] * cache[1][12];
temp += cache[row][2] * cache[2][12];
temp += cache[row][3] * cache[3][12];
temp += cache[row][4] * cache[4][12];
temp += cache[row][5] * cache[5][12];
temp += cache[row][6] * cache[6][12];
temp += cache[row][7] * cache[7][12];
temp += cache[row][8] * cache[8][12];
temp += cache[row][9] * cache[9][12];
temp += cache[row][10] * cache[10][12];
temp += cache[row][11] * cache[11][12];
temp += cache[row][12] * cache[12][12];
temp += cache[row][13] * cache[13][12];
temp += cache[row][14] * cache[14][12];
temp += cache[row][15] * cache[15][12];
temp += cache[row][16] * cache[16][12];
temp += cache[row][17] * cache[17][12];
temp += cache[row][18] * cache[18][12];
temp += cache[row][19] * cache[19][12];
B[row][12] = temp;
temp = 0;
temp += cache[row][0] * cache[0][13];
temp += cache[row][1] * cache[1][13];
temp += cache[row][2] * cache[2][13];
temp += cache[row][3] * cache[3][13];
temp += cache[row][4] * cache[4][13];
temp += cache[row][5] * cache[5][13];
temp += cache[row][6] * cache[6][13];
temp += cache[row][7] * cache[7][13];
temp += cache[row][8] * cache[8][13];
temp += cache[row][9] * cache[9][13];
temp += cache[row][10] * cache[10][13];
temp += cache[row][11] * cache[11][13];
temp += cache[row][12] * cache[12][13];
temp += cache[row][13] * cache[13][13];
temp += cache[row][14] * cache[14][13];
temp += cache[row][15] * cache[15][13];
temp += cache[row][16] * cache[16][13];
temp += cache[row][17] * cache[17][13];
temp += cache[row][18] * cache[18][13];
temp += cache[row][19] * cache[19][13];
B[row][13] = temp;
temp = 0;
temp += cache[row][0] * cache[0][14];
temp += cache[row][1] * cache[1][14];
temp += cache[row][2] * cache[2][14];
temp += cache[row][3] * cache[3][14];
temp += cache[row][4] * cache[4][14];
temp += cache[row][5] * cache[5][14];
temp += cache[row][6] * cache[6][14];
temp += cache[row][7] * cache[7][14];
temp += cache[row][8] * cache[8][14];
temp += cache[row][9] * cache[9][14];
temp += cache[row][10] * cache[10][14];
temp += cache[row][11] * cache[11][14];
temp += cache[row][12] * cache[12][14];
temp += cache[row][13] * cache[13][14];
temp += cache[row][14] * cache[14][14];
temp += cache[row][15] * cache[15][14];
temp += cache[row][16] * cache[16][14];
temp += cache[row][17] * cache[17][14];
temp += cache[row][18] * cache[18][14];
temp += cache[row][19] * cache[19][14];
B[row][14] = temp;
temp = 0;
temp += cache[row][0] * cache[0][15];
temp += cache[row][1] * cache[1][15];
temp += cache[row][2] * cache[2][15];
temp += cache[row][3] * cache[3][15];
temp += cache[row][4] * cache[4][15];
temp += cache[row][5] * cache[5][15];
temp += cache[row][6] * cache[6][15];
temp += cache[row][7] * cache[7][15];
temp += cache[row][8] * cache[8][15];
temp += cache[row][9] * cache[9][15];
temp += cache[row][10] * cache[10][15];
temp += cache[row][11] * cache[11][15];
temp += cache[row][12] * cache[12][15];
temp += cache[row][13] * cache[13][15];
temp += cache[row][14] * cache[14][15];
temp += cache[row][15] * cache[15][15];
temp += cache[row][16] * cache[16][15];
temp += cache[row][17] * cache[17][15];
temp += cache[row][18] * cache[18][15];
temp += cache[row][19] * cache[19][15];
B[row][15] = temp;
temp = 0;
temp += cache[row][0] * cache[0][16];
temp += cache[row][1] * cache[1][16];
temp += cache[row][2] * cache[2][16];
temp += cache[row][3] * cache[3][16];
temp += cache[row][4] * cache[4][16];
temp += cache[row][5] * cache[5][16];
temp += cache[row][6] * cache[6][16];
temp += cache[row][7] * cache[7][16];
temp += cache[row][8] * cache[8][16];
temp += cache[row][9] * cache[9][16];
temp += cache[row][10] * cache[10][16];
temp += cache[row][11] * cache[11][16];
temp += cache[row][12] * cache[12][16];
temp += cache[row][13] * cache[13][16];
temp += cache[row][14] * cache[14][16];
temp += cache[row][15] * cache[15][16];
temp += cache[row][16] * cache[16][16];
temp += cache[row][17] * cache[17][16];
temp += cache[row][18] * cache[18][16];
temp += cache[row][19] * cache[19][16];
B[row][16] = temp;
temp = 0;
temp += cache[row][0] * cache[0][17];
temp += cache[row][1] * cache[1][17];
temp += cache[row][2] * cache[2][17];
temp += cache[row][3] * cache[3][17];
temp += cache[row][4] * cache[4][17];
temp += cache[row][5] * cache[5][17];
temp += cache[row][6] * cache[6][17];
temp += cache[row][7] * cache[7][17];
temp += cache[row][8] * cache[8][17];
temp += cache[row][9] * cache[9][17];
temp += cache[row][10] * cache[10][17];
temp += cache[row][11] * cache[11][17];
temp += cache[row][12] * cache[12][17];
temp += cache[row][13] * cache[13][17];
temp += cache[row][14] * cache[14][17];
temp += cache[row][15] * cache[15][17];
temp += cache[row][16] * cache[16][17];
temp += cache[row][17] * cache[17][17];
temp += cache[row][18] * cache[18][17];
temp += cache[row][19] * cache[19][17];
B[row][17] = temp;
temp = 0;
temp += cache[row][0] * cache[0][18];
temp += cache[row][1] * cache[1][18];
temp += cache[row][2] * cache[2][18];
temp += cache[row][3] * cache[3][18];
temp += cache[row][4] * cache[4][18];
temp += cache[row][5] * cache[5][18];
temp += cache[row][6] * cache[6][18];
temp += cache[row][7] * cache[7][18];
temp += cache[row][8] * cache[8][18];
temp += cache[row][9] * cache[9][18];
temp += cache[row][10] * cache[10][18];
temp += cache[row][11] * cache[11][18];
temp += cache[row][12] * cache[12][18];
temp += cache[row][13] * cache[13][18];
temp += cache[row][14] * cache[14][18];
temp += cache[row][15] * cache[15][18];
temp += cache[row][16] * cache[16][18];
temp += cache[row][17] * cache[17][18];
temp += cache[row][18] * cache[18][18];
temp += cache[row][19] * cache[19][18];
B[row][18] = temp;
temp = 0;
temp += cache[row][0] * cache[0][19];
temp += cache[row][1] * cache[1][19];
temp += cache[row][2] * cache[2][19];
temp += cache[row][3] * cache[3][19];
temp += cache[row][4] * cache[4][19];
temp += cache[row][5] * cache[5][19];
temp += cache[row][6] * cache[6][19];
temp += cache[row][7] * cache[7][19];
temp += cache[row][8] * cache[8][19];
temp += cache[row][9] * cache[9][19];
temp += cache[row][10] * cache[10][19];
temp += cache[row][11] * cache[11][19];
temp += cache[row][12] * cache[12][19];
temp += cache[row][13] * cache[13][19];
temp += cache[row][14] * cache[14][19];
temp += cache[row][15] * cache[15][19];
temp += cache[row][16] * cache[16][19];
temp += cache[row][17] * cache[17][19];
temp += cache[row][18] * cache[18][19];
temp += cache[row][19] * cache[19][19];
B[row][19] = temp;
temp = 0;

            row++;
        }
        round++;
    }
    timePoint = micros() - timePoint;
    Serial.print(timePoint/rounds);
    Serial.println(" us");
    Serial.print(timePoint / rounds * 16);
    Serial.println(" ticks");
    Serial.print(timePoint / rounds * 16 / (20 * 20 * 20));
    Serial.println(" ticks per multiplication");
    Serial.println(checkMatrix(B));

#ifdef ARDUINO_TARGET
    freeMemory();
    Serial.println(F("DONE"));
    while(1);
#endif
}

#ifndef ARDUINO_TARGET
int main(int argc, char **argv) {
    timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    birth = ts.tv_sec;
    setup();
    loop();
    return 0;
}
#endif
