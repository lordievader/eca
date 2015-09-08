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

unsigned char birth;

#ifdef ARDUINO_TARGET
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
void freeMemory()
{
    extern unsigned int __bss_end;
    extern unsigned int __heap_start;
    extern void *__brkval;
    int free_memory;
    char message[50];
    snprintf(message, 50, "f=%db\n", ((int)&free_memory) - ((int)&__bss_end));
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
    snprintf(message, 50, "t=%uns\n", time_ns);
    logMessage(message);
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

bool checkMatrix(unsigned long result[rows][columns])
{
    unsigned char i = 0;
    while (i < rows)
    {
        unsigned char j = 0;
        while (j < columns)
        {
            unsigned long correct = pgm_read_dword(&C[i][j]);
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

unsigned long calcValue(unsigned char row, unsigned char column)
{
    unsigned long value = 0;
    unsigned char index = 0;
    while (index < rows)
    {
//         value += matrix[row][index] * matrix[index][column];
        unsigned char item1 = pgm_read_word(&A[row][index]);
        unsigned char item2 = pgm_read_word(&A[index][column]);
        value += (unsigned long)item1 * (unsigned long)item2;
        index++;
    }
    return value;
}


void squareMatrix(unsigned long destination[rows][columns])
{
    unsigned char row =  0;
    unsigned char column;
//     unsigned long value = 0;
    while (row < rows)
    {
        column = 0;
        while (column < columns)
        {
            destination[row][column] = calcValue(row, column);
//             value = calcValue(row, column);
            column++;
        }
        row++;
    }
}

unsigned int calc(unsigned char rounds)
{
    unsigned char round = 0;
    unsigned long B[rows][columns];
    unsigned int time_point = getTime();
    while (round <= rounds)
    {
        squareMatrix(B);
        round++;
    }
    unsigned int total = getTime() - time_point;
    Serial.println(checkMatrix(B));
    return total;
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
#endif
    unsigned int total = calc(rounds);
#ifdef ARDUINO_TARGET
    printTime(total/rounds);
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
