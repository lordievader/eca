#ifdef ARDUINO_TARGET
#include "Arduino.h"
#include <TimerOne.h>
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
    Timer1.initialize(8191);
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

    Timer1.restart();
    while (round <= rounds)
    {
        row = 0;
        while (row < rows)
        {
            column = 0;
            while (column < columns)
            {
                unsigned char index = 0;
//                 B[row][column] = 0;
                int temp = 0;
                while (index < rows)
                {
//                     B[row][column] += cache[row][index] * cache[index][column];
                    temp += cache[row][index] * cache[index][column];
                    index++;
                }
                B[row][column] = temp;
                column++;
            }
            row++;
        }
        round++;
    }
    unsigned int ticks = Timer1.read();
    Serial.print(ticks / rounds * 0.0625);
    Serial.println("us");
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
