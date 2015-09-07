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
#include <map>
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
int getTime()
{
    int time = millis();
    return time;
}
void printTime(int avg)
{
    char message[100];
    snprintf(message, 100, "Calculation took %d milliseconds on average.\n", avg);
    logMessage(String(message));
}
void printTime(int begin, int end)
{
    int diff = end - begin;
    char message[100];
    snprintf(message, 100, "%d milliseconds have passed since the beginning of this program.\n", diff);
    logMessage(String(message));
}
#else
void logMessage(string sMessage)
{
    printf(sMessage.c_str());
}
int getTime()
{
    int time = clock();
    return time;
}
void printTime(int ticks)
{
    char message[100];
    snprintf(message, 100, "There have been %d ticks on average.\nOne tick is %.3f milliseconds.\n", ticks, (1.0/CLOCKS_PER_SEC)*1000);
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

int calcValue(unsigned char matrix[rows][columns], int row, int column, int index)
{
    int value = 0;
    while (index < rows)
    {
        value += matrix[row][index] * matrix[index][column];
        index++;
    }
    return value;
}


void squareMatrix(unsigned char source[rows][columns], unsigned char destination[rows][columns], int index)
{
    int row =  0;
    int column = 0;
    while (row < rows)
    {
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
    printMatrix(A);
    logMessage("\n\n");
}

void loop()
{
    int avg = 0;
    int index = 0;
    for (int i = 0; i <= 1000000; i++)
    {
        int begin = getTime();
        squareMatrix(A, B, index);
        int end = getTime();
        avg = (avg + (end - begin))/2;
    }
//     printMatrix(B);
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
