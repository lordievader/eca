#ifdef ARDUINO_TARGET
#include "Arduino.h"
#define F_CPU 16000000
#define ARDUINO 100
#else
#include <string>
#include <ctime>
#endif

#include "ecamatrix.h"
#include <stdio.h>
using namespace::std;

const int rows = 20;
const int columns = 20;
unsigned char A[rows][columns];
unsigned char B[rows][columns];

#ifdef ARDUINO_TARGET
void logMessage(String sMessage)
{
    Serial.print(sMessage);
}
#else
void logMessage(string sMessage)
{
    printf(sMessage.c_str());
}
#endif

#ifdef ARDUINO_TARGET
int getTime()
{
    int time = millis();
    return time;
}
void printTime(int begin, int end)
{
    int diff = end - begin;
    char message[100];
    snprintf(message, 100, "%d millisseconds have passed since the beginning of this program.\n", diff);
    logMessage(String(message));
}
#else
int getTime()
{
    int time = clock();
    return time;
}
void printTime(int begin, int end)
{
    int diff = end - begin;
    char message[100];
    snprintf(message, 100, "There have been %d ticks since the beginning of this program.\n", diff);
    logMessage(string(message));
}
void printTime(int ticks)
{
    char message[100];
    snprintf(message, 100, "There have been %d ticks on average.\n", ticks);
    logMessage(string(message));
}
#endif

void printMatrix(unsigned char matrix[rows][columns])
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
            char str[6];
            sprintf(str, "%3u, ", matrix[i][j]);
#ifdef ARDUINO_TARGET
            output += String(str);
#else
            output += string(str);
#endif
        }
        logMessage(output);
        logMessage("\n");
        output = "";
    }
}

int calcValue(unsigned char matrix[rows][columns], int row, int column)
{
//     int A[columns];
//     int B[rows];
//     for (int j = 0; j < columns; j++)
//     {
//         A[j] = matrix[row][j];
//     }
//
//     for (int j = 0; j < rows; j++)
//     {
//         B[j] = matrix[j][column];
//     }

    int value = 0;
    for (int i = 0; i < rows; i++)
    {
//         value += A[i] * B[i];
        value += matrix[row][i] * matrix[i][column];
    }
    return value;
}


void squareMatrix(unsigned char source[rows][columns], unsigned char destination[rows][columns])
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            destination[row][column] = calcValue(source, row, column);

        }
    }
}

void setup()
{
#ifdef ARDUINO_TARGET
    Serial.begin(460800);
#endif
    matrix(A);
    printMatrix(A);
    logMessage("\n\n");
}

void loop()
{
    int avg = 0;
    for (int i = 0; i <= 100000; i++)
    {
        int begin = getTime();
        squareMatrix(A, B);
        int end = getTime();
        avg = (avg + (end - begin))/2;
    }
    printMatrix(B);
    printTime(avg);
    logMessage("DONE\n");
#ifdef ARDUINO_TARGET
    while(1);
#endif
}

#ifndef ARDUINO_TARGET
int main(int argc, char **argv) {
    setup();
    loop();
    return 0;
}
#endif
