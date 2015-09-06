// #include "Arduino.h"
#include <string>

#define F_CPU 16000000
#define ARDUINO 100

#include "ecamatrix.h"
#include <stdio.h>
using namespace::std;

#ifdef Arduino_h
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

void printMatrix(unsigned char matrix[20][20])
{
#ifdef Arduino_h
    String output = "";
#else
    string output = "";
#endif
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            char str[6];
            sprintf(str, "%3u, ", matrix[i][j]);
#ifdef Arduino_h
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

void setup()
{
#ifdef Arduino_h
    Serial.begin(460800);
#endif
    unsigned char A[20][20];
    matrix(A);
    printMatrix(A);
}

void loop()
{
    logMessage("DONE");
#ifdef Arduino_h
    while(1);
#endif
}

#ifndef Arduino_h
int main(int argc, char **argv) {
    setup();
    loop();
    return 0;
}
#endif
