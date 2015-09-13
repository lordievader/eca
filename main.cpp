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
using namespace::std;

const unsigned char rows = 20;
const unsigned char columns = 20;

bool checkMatrix(int result[rows][columns], unsigned char i, unsigned char j)
{
	i = 0;
	j = 0;
	while (i < rows)
	{
		j = 0;
		while (j < columns)
		{
			#ifdef ARDUINO_TARGET
			if (result[i][j] != pgm_read_word(&C[i][j]))
			{
				                 Serial.print(result[i][j]);
				                 Serial.print(F(" != "));
				                 Serial.print(pgm_read_word(&C[i][j]));
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
	Serial.begin(115200);
	#endif
}

void loop()
{
	int rounds = 1000;
	#ifdef ARDUINO_TARGET
	Serial.println(F("START"));
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


	int temp[rows];
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
	Serial.println(checkMatrix(B, row, column));
	Serial.println(F("DONE"));
	while(1);
	#else
	clock_t end = clock();
	double diff = double(clock() - timePoint);
	cout << diff / rounds / CLOCKS_PER_SEC << " us" << endl;
	cout << diff / rounds << " clicks" << endl;
	cout << diff / rounds / (20 * 20 * 20) << " ticks per multiplication" << endl;
	cout << checkMatrix(B, row, column) << endl;
	cout << "DONE" << endl;
	#endif
}

#ifndef ARDUINO_TARGET
int main(int argc, char **argv) {
	setup();
	loop();
	return 0;
}
#endif
