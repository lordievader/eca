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

const unsigned char rows = 20;
const unsigned char columns = 20;

#ifdef ARDUINO_TARGET
void freeMemory()
{
    extern unsigned int __bss_end;
    extern unsigned int __heap_start;
    extern void *__brkval;
    int free_memory;
    char message[50];
    snprintf(message, 50, "f=%db\n", ((int)&free_memory) - ((int)&__bss_end));
    Serial.print(message);
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
#ifdef ARDUINO_TARGET
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
#else
            int correct = C[i][j];
            if (result[i][j] != correct)
            {
                cout << result[i][j] << " != " << correct << " (" << i << "," << j << ")" << endl;
                return false;
            }
#endif
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
    int rounds = 1000;
#ifdef ARDUINO_TARGET
    Serial.println(F("START"));
    freeMemory();
#else
    cout << "START" << endl;
#endif

    char cache[rows][columns];
    int B[rows][columns];
    int round = 0;
    unsigned char row =  0;
    unsigned char column;
    while (row < rows)
    {
        column = 0;
        while (column < columns)
        {
#ifdef ARDUINO_TARGET
            cache[row][column] = (char)pgm_read_word(&A[row][column]);
#else
            cache[row][column] = (char)A[row][column];
#endif
            column++;
        }
        row++;
    }

    int temp;
#ifdef ARDUINO_TARGET
    unsigned long timePoint = micros();
#else
    clock_t timePoint = clock();
#endif
    while (round <= rounds)
    {
        row = 0;
        while (row < rows)
        {
#include "calc.h"
            row++;
        }
        round++;
    }
#ifdef ARDUINO_TARGET
    timePoint = micros() - timePoint;
    Serial.print(timePoint/rounds);
    Serial.println(" us");
    Serial.print(timePoint / rounds * 16);
    Serial.println(" ticks");
    Serial.print(timePoint / rounds * 16 / (20 * 20 * 20));
    Serial.println(" ticks per multiplication");
    Serial.println(checkMatrix(B));

    freeMemory();
    Serial.println(F("DONE"));
    while(1);
#else
    clock_t end = clock();
    double diff = double(clock() - timePoint);
    cout << diff / rounds / CLOCKS_PER_SEC << " us" << endl;
    cout << diff / rounds << " clicks" << endl;
    cout << diff / rounds / (20 * 20 * 20) << " ticks per multiplication" << endl;
    cout << checkMatrix(B) << endl;
    cout << "DONE" << endl;
#endif
}

#ifndef ARDUINO_TARGET
int main(int argc, char **argv) {
    timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    int birth = ts.tv_sec;
    setup();
    loop();
    return 0;
}
#endif
