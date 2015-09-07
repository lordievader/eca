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

const int rows = 20;
const int columns = 20;
unsigned long B[rows][columns];
// unsigned long C[rows][columns];

int birth;

#ifdef ARDUINO_TARGET
void logMessage(char message[])
{
    String sMessage = String(message);
    Serial.print(sMessage);
}
void logMessage(String sMessage)
{
    Serial.print(sMessage);
}
unsigned int getTime()
{
    unsigned int time = micros();
    return time;
}
void printTime(unsigned int avg)
{
    char message[100];
    snprintf(message, 100, "Calculation took %d microseconds on average.\nThat is %il ticks.", avg, int(floor((avg / 62.5)+0.5)));
    logMessage(message);
}
void printTime(int begin, int end)
{
    int diff = end - begin;
    char message[100];
    snprintf(message, 100, "%d microseconds have passed since the beginning of this program.\n", diff);
    logMessage(message);
}
#else
void logMessage(char message[])
{
    cout << message;
}
void logMessage(string sMessage)
{
    cout << sMessage.c_str();
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
    char message[100];
    snprintf(message, 100, "The matrix operation took %u nanoseconds on average.\n", time_ns);
    logMessage(string(message));
}
void printTime(int begin, int end)
{
    int diff = end - begin;
    char message[100];
    snprintf(message, 100, "There have been %d ticks since the beginning of this program.\n", diff);
    logMessage(string(message));

}
#endif

void printMatrix(const unsigned char matrix[rows][columns])
{
#ifdef ARDUINO_TARGET
    String output = "";
#else
    string output = "";
#endif
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            char str[100];
            snprintf(str, 100, "%3u, ", matrix[i][j]);
#ifdef ARDUINO_TARGET
            output += String(str);
#else
            output += string(str);
#endif
        }
        logMessage(output);
        logMessage((char *)"\n");
        output = "";
    }
}

void printMatrix(unsigned long matrix[rows][columns])
{
#ifdef ARDUINO_TARGET
    String output = "";
#else
    string output = "";
#endif
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            char str[100];
            snprintf(str, 100, "%3lu, ", matrix[i][j]);
#ifdef ARDUINO_TARGET
            output += String(str);
#else
            output += string(str);
#endif
        }
        logMessage(output);
        logMessage((char *)"\n");
        output = "";
    }
}

bool checkMatrix(unsigned long result[rows][columns], unsigned long correction[rows][columns])
{
    int i = 0;
    while (i < rows)
    {
        int j = 0;
        while (j < columns)
        {
            if (result[i][j] != correction[i][j])
            {
                char message[100];
                snprintf(message, 100, "%lu != %lu", result[i][j], correction[i][j]);
                logMessage(message);
                return false;
            }
            j++;
        }
        i++;
    }
    return true;
}

long int calcValue(const unsigned char matrix[rows][columns], int row, int column, int index)
{
    long int value = 0;
    while (index < rows)
    {
        value += matrix[row][index] * matrix[index][column];
        index++;
    }
    return value;
}


void squareMatrix(const unsigned char source[rows][columns], unsigned long destination[rows][columns], int index)
{
    int row =  0;
    while (row < rows)
    {
        int column = 0;
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
//     ansmatrix(C);
    printMatrix(A);
    logMessage((char *)"\n\n");
}

void loop()
{
    unsigned int avg = 0;
    unsigned char index = 0;
    int round = 0;
    int rounds = 1;
    bool faults = false;

    while (round <= rounds)
    {
        unsigned int begin = getTime();
        squareMatrix(A, B, index);
        unsigned int end = getTime();
        avg = (avg + (end - begin))/2;
//         if (checkMatrix(B, C) == false)
//         {
//             logMessage((char *)"Fault detected");
//             faults = true;
//             break;
//         }
        if (round % 100 == 0)
        {
            char message[100];
            snprintf(message, 100, "status %10d/%10d: %3u\n", round, rounds, avg);
            logMessage(message);
        }
        round++;
    }
    logMessage((char *)"\n");
    if (faults == false)
    {
        printMatrix(B);
        printTime(avg);
        logMessage((char *)"DONE\n");
    }
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
