#ifdef ARDUINO_TARGET
#include "Arduino.h"
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

unsigned char birth;

#ifdef ARDUINO_TARGET
void freeMemory()
{
    extern unsigned int __bss_end;
    extern unsigned int __heap_start;
    extern void *__brkval;
    int free_memory;
    Serial.println(((int)&free_memory) - ((int)&__bss_end));
}

void logMessage(char message[])
{
    Serial.print(String(message));
}
unsigned int getTime()
{
    return micros();
}
void printTime(unsigned int avg)
{
    char message[50];
    snprintf(message, 50, "t=%uus\n", avg);
    logMessage(message);
}
#else
void logMessage(char message[])
{
    cout << message;
}
unsigned int getTime()
{
    timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    unsigned int time_ns = (ts.tv_sec - birth) * 1e9 + ts.tv_nsec;
    return time_ns;
}
void printTime(unsigned int time_ns)
{
    char message[50];
    snprintf(message, 50, "The matrix operation took %u nanoseconds on average.\n", time_ns);
    logMessage(string(message));
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

void checkMatrix(unsigned long result[rows][columns], const unsigned long correction[rows][columns])
{
    unsigned char i = 0;
    while (i < rows)
    {
        unsigned char j = 0;
        while (j < columns)
        {
            if (result[i][j] != correction[i][j])
            {
                char message[50];
                snprintf(message, 50, "(%d,%d)%ul!=%ul\n", i, j, result[i][j], correction[i][j]);
                logMessage(message);
            }
            j++;
        }
        i++;
    }
}

long int calcValue(const unsigned char matrix[rows][columns], unsigned char row, unsigned char column, unsigned char index)
{
    long int value = 0;
    while (index < rows)
    {
        value += matrix[row][index] * matrix[index][column];
        index++;
    }
    return value;
}


void squareMatrix(const unsigned char source[rows][columns], unsigned long destination[rows][columns], unsigned char index)
{
    unsigned char row =  0;
    unsigned char column;
    while (row < rows)
    {
        column = 0;
        while (column < columns)
        {
            index = 0;
            destination[row][column] = calcValue(source, row, column, index);
            column++;
        }
        row++;
    }
}

void setup()
{
#ifdef ARDUINO_TARGET
    Serial.begin(460800);
#endif
}

void loop()
{
    unsigned char index = 0;
    unsigned char round = 0;
    unsigned char rounds = 1;
    unsigned int time_point;
unsigned long B[rows][columns];
#ifdef ARDUINO_TARGET
#endif

    time_point = getTime();
    while (round <= rounds)
    {
        squareMatrix(A, B, index);

//         if (checkMatrix(B, C) == false)
//         {
//             logMessage((char *)"ERR");
//             break;
//         }
//         if (round % 100 == 0)
//         {
//             char message[100];
//             snprintf(message, 100, "status %10d/%10d: %3u\n", round, rounds, avg);
//             logMessage(message);
//         }
//     }
//     logMessage((char *)"\n");
//     if (faults == false)
//     {
//         printMatrix(B);
//         printTime(avg);
//         logMessage((char *)"DONE\n");
        round++;
    }
    printTime((getTime() - time_point)/rounds);
//     checkMatrix(B, C);
    freeMemory();
#ifdef ARDUINO_TARGET
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
