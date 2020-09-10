/***************************************************************************
    Copyright (C) 2006 by Volodymyr Myrnyy (Vladimir Mirnyi)
 ***************************************************************************
 Permission to use, copy, modify, distribute and sell this software for any
 purpose is hereby granted without fee, provided that the above copyright
 notice appear in all copies and that both that copyright notice and this
 permission notice appear in supporting documentation.
 ***************************************************************************

 Generic simple and efficient Fast Fourier Transform (FFT) implementation
 using template metaprogramming

 ***************************************************************************/

#include "gfft.h"

 // initialization of the object factory
Loki::Factory<AbstractFFT<Tp>, unsigned int> gfft_factory;

// create an "holder" of the GFFT
AbstractFFT<Tp>* gfft;

// runtime definition of the data length
//int p = 2;
//int p = 8;
//int p = 9;
int p = 10; //Same as JUCEs FFT


int main()
{

    unsigned long i;

	// initialization of the object factory
	FactoryInit<GFFTList<GFFT, gfftMin, gfftMax>::Result>::apply(gfft_factory);

	// create an instance of the GFFT
    gfft = gfft_factory.CreateObject(p);

// sample data
    unsigned long n = 1<<p;
    Tp* data = new Tp [2*n];
    for (i=0; i<n; ++i) {
        data[2*i] = 2*i;
        data[2*i+1] = 2*i+1;
    }

// compute FFT
    gfft->fft(data);

// print the results
    cout<<"--------------------------------" << endl;
      for (i=0; i<n; ++i)
        cout << setw(10) << setprecision(5) << data[2*i] << "\t"
             << data[2*i+1] << "I" << endl;

    delete [] data;

    return 0;
}
