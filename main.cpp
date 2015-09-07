#ifdef ARDUINO_TARGET
#include "Arduino.h"
#define F_CPU 16000000
#define ARDUINO 100
#else
#include <string>
#include <ctime>
#include <iostream>
#endif

#include "ecamatrix.h"
#include "ansmatrix.h"
#include <stdio.h>
using namespace::std;

const int rows = 20;
const int columns = 20;
unsigned short A[rows][columns];
unsigned short B[rows][columns];
unsigned short C[rows][columns];

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
int getTime()
{
    int time = micros();
    return time;
}
void printTime(int avg)
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
int getTime()
{
    int time = clock();
    return time;
}
void printTime(int ticks)
{
    char message[100];
    snprintf(message, 100, "There have been %d ticks on average.\nThat is %.3li seconds.\n", ticks, (ticks/CLOCKS_PER_SEC));
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

void printMatrix(unsigned short matrix[rows][columns])
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
        logMessage((char *)"\n");
        output = "";
    }
}

bool checkMatrix(unsigned short result[rows][columns], unsigned short correction[rows][columns])
{
    int i = 0;
    while (i < rows)
    {
        int j = 0;
        while (j < columns)
        {
            if (result[i][j] != correction[i][j])
            {
                return false;
            }
            j++;
        }
        i++;
    }
    return true;
}

int calcValue(unsigned short matrix[rows][columns], int row, int column, int index)
{
    int value = 0;
    while (index < rows)
    {
        value += matrix[row][index] * matrix[index][column];
        index++;
    }
    return value;
}


void squareMatrix(unsigned short source[rows][columns], unsigned short destination[rows][columns], int index)
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
    matrix(A);
    ansmatrix(C);
    printMatrix(A);
    logMessage((char *)"\n\n");
}

void loop()
{
    int avg = 0;
    int index = 0;
    int rounds = 1000;
    for (int i = 0; i <= rounds; i++)
    {
        int begin = getTime();
        squareMatrix(A, B, index);
        int end = getTime();
        avg = (avg + (end - begin))/2;
        if (checkMatrix(B, C) == false)
        {
            logMessage((char *)"Fault detected");
            break;
        }
        if (i % 100 == 0)
        {
            char message[100];
            snprintf(message, 100, "status %10d/%10d: %3d\n", i, rounds, avg);
            logMessage(message);
        }
    }
    logMessage((char *)"\n");
//     printMatrix(B);
    printTime(avg);
    logMessage((char *)"DONE\n");
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
