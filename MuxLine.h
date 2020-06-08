#ifndef MUXLINE_H
#define MUXLINE_H

#include <Arduino.h>
#include <Mux4051.h>

#define MAXMUX 6

class MuxLine
{
	private:
	int num;		//liczba linii
	int lmax;		//liczba wejsc w linii
	Mux4051 mux[MAXMUX];
	int in_NO;		//numer wejscia w linii
	int in_L;		//numer linii
	int del;
	
	public:
	begin(int Lines, int IN, int A, int B, int C, int max, int delau);
	Reset(void);
	
	int readStep(void);

};


#endif /* MUXLINE_H */