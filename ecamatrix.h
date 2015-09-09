#ifndef ECAMATRIX_H
#define ECAMATRIX_H
#ifdef ARDUINO_TARGET
const PROGMEM char A[20][20] = {
#else
const char A[20][20] = {
#endif
	{-6, 0, -9, 15, 8, 0, 4, -4, 4, 3, 9, -3, -12, 13, -7, -12, -8, 6, 1, -12, },
	{-12, 7, 14, 1, 4, 7, 4, -6, -5, -13, -3, -13, -9, -3, -13, 8, 3, 10, 2, -12, },
	{10, -8, -8, -4, 12, 7, -15, -9, -2, 1, 0, -9, -10, 7, 4, -15, 1, 2, -2, -1, },
	{-5, 15, -2, 8, -2, 14, 15, -8, -5, 9, -10, -14, -6, -13, 6, 3, 6, -12, 6, 15, },
	{-6, 15, 1, -9, -5, -2, 1, -6, 8, 9, 6, 2, -10, -4, 6, -9, 14, -2, 8, -7, },
	{-7, -4, -6, -6, 13, 15, -3, -7, -11, 5, -9, 8, 11, 8, 5, 2, -2, -3, -4, -14, },
	{15, -12, 2, 7, -15, -6, -5, -7, -10, -6, 11, -9, 4, 4, -15, 2, -7, 2, -2, -13, },
	{13, 9, 14, 14, 12, -2, 9, 12, -2, 5, 9, 13, 3, 13, 0, 11, 14, -14, 15, 3, },
	{-5, -13, -4, -11, -10, 4, -1, -7, 0, 4, 13, -1, -9, 7, 6, -10, -1, -4, 7, -14, },
	{-2, -2, -5, 7, -15, 9, 8, -4, -4, 7, -6, -15, 11, -4, -4, -5, 10, 3, 8, 12, },
	{7, -3, 15, -9, 4, -4, -14, -4, 2, -7, 1, 12, 15, -15, -11, 8, 0, 0, 8, -12, },
	{-6, -14, -11, -12, 7, 11, -13, 8, 2, -5, -8, 10, -14, -7, 12, -14, 4, 5, 0, 3, },
	{13, -11, 6, -10, 8, -6, -7, -6, -13, -12, 8, 7, 15, -4, -7, -4, 13, -10, 0, -10, },
	{0, 1, 7, -6, -15, -1, -9, 10, 9, -7, 6, 6, 3, -7, -8, 5, 1, -11, -7, 4, },
	{-1, 2, -6, 6, 15, 3, 6, -1, 13, -14, -5, 10, 5, 4, 11, 5, 14, -8, -4, 4, },
	{-5, -2, -11, -9, 3, -12, -14, -3, -5, 3, 8, 7, -2, -2, -6, 6, 8, -6, -13, 0, },
	{-13, 7, 2, 4, 4, 6, -6, -10, 7, -1, -13, -5, 6, -4, -6, -7, 13, -2, 12, -12, },
	{8, -6, -6, 4, -14, -2, -6, 13, -9, 11, 15, -9, 14, 9, 4, 7, -1, 15, -4, -12, },
	{-3, 3, 13, -7, 9, 4, 0, -10, -10, 12, 15, 0, 1, 14, 10, -11, -4, 11, 3, -3, },
	{6, 14, -11, -11, -5, 7, 4, 5, -1, -14, 6, -2, 0, -7, -7, 5, -7, 15, -14, 5, },

};
#endif