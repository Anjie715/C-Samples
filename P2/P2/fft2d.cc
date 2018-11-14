// Distributed two-dimensional Discrete FFT transform
// Anjie Zhao

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <thread>

#include "Complex.h"
#include "InputImage.h"

#define Pi 3.1415926

constexpr unsigned int NUMTHREADS = 4;

using namespace std;

//undergrad students can assume NUMTHREADS will evenly divide the number of rows in tested images
//graduate students should assume NUMTHREADS will not always evenly divide the number of rows in tested images.
// I will test with a different image than the one given
void Transform1D(Complex* h, int w, Complex* H);
void Transform2D(const char* inputFN);
void Reverse1D(Complex* h, int w, Complex* H);
void Transform_Col(Complex* h, int w, int Col, Complex* H);
void Reverse_Col(Complex* h, int w, int Col, Complex* H);

void Transform2D(const char* inputFN) 
{ // Do the 2D transform here.
  // 1) Use the InputImage object to read in the Tower.txt file and
  //    find the width/height of the input image.
  // 2) Create a vector of complex objects of size width * height to hold
  //    values calculated
  // 3) Do the individual 1D transforms on the rows assigned to each thread
  // 4) Force each thread to wait until all threads have completed their row calculations
  //    prior to starting column calculations
  // 5) Perform column calculations
  // 6) Wait for all column calculations to complete
  // 7) Use SaveImageData() to output the final results

  InputImage image(inputFN);  // Create the helper object for reading the image
  // Step (1) in the comments is the line above.
  // Your code here, steps 2-7
    unsigned w = image.GetWidth();
    unsigned h = image.GetHeight();
    unsigned size = w*h;

    Complex *Input = image.GetImageData();
    vector<Complex> Output(size);
    vector<Complex> Output2d(size);
    vector<Complex> Inverse(size);
    vector<Complex> Inverse2d(size);

    unsigned n = h/NUMTHREADS;
    unsigned v = h%NUMTHREADS;
    unsigned nc = w/NUMTHREADS;
    unsigned vc = w%NUMTHREADS;

    for(int r=0;r<n;++r){
        thread t1(Transform1D, Input+r*w, w, &Output[0]+r*w);
        t1.detach();
    }
    for(int r=n;r<2*n;++r){
        thread t2(Transform1D, Input+r*w, w, &Output[0]+r*w);
        t2.detach();
    }
    for(int r=2*n;r<3*n;++r){
        thread t3(Transform1D, Input+r*w, w, &Output[0]+r*w);
        t3.detach();
    }
    for(int r=3*n;r<(4*n+v);++r){
        thread t4(Transform1D, Input+r*w, w, &Output[0]+r*w);
        t4.join();
    }


    for(int c=0;c<nc;++c){
        thread t1(Transform_Col,&Output[0]+c, w, h, &Output2d[0]+c);
        t1.detach();
    }
    for(int c=nc;c<2*nc;++c){
        thread t2(Transform_Col,&Output[0]+c, w, h, &Output2d[0]+c);
        t2.detach();
    }
    for(int c=2*nc;c<3*nc;++c){
        thread t3(Transform_Col,&Output[0]+c, w, h, &Output2d[0]+c);
        t3.detach();
    }
    for(int c=3*nc;c<(4*nc+vc);++c){
        thread t4(Transform_Col,&Output[0]+c, w, h, &Output2d[0]+c);
        t4.join();
    }

    image.SaveImageData("after1d.txt", &Output[0], w, h);
    image.SaveImageData("after2d.txt", &Output2d[0], w, h);
    image.SaveImageData("MyAfter2D.txt", &Output2d[0], w, h);

    for(int c=0;c<w;++c){
        Reverse_Col(&Output2d[0]+c, w, h, &Inverse2d[0]+c);
    }
    for(int r=0;r<h;++r){
        Reverse1D(&Inverse2d[0]+r*h, h, &Inverse[0]+r*h);
     }

    image.SaveImageDataReal("MyAfterInverse.txt", &Inverse[0], w, h);


    delete Input; Input = 0;
}

void Transform1D(Complex* h, int w, Complex* H)
{
  // Implement a simple 1-d DFT using the double summation equation
  // given in the assignment handout.  h is the time-domain input
  // data, w is the width (N), and H is the output array.
    for(int n = 0; n < w; ++n)
    {
        for(int k = 0; k < w; ++k)
        {
            //computation for the real part
            H[n].real += h[k].real * cos((2*Pi*n*k)/w) + h[k].imag * sin((2*Pi*n*k)/w);
            //computation for imagine part
            H[n].imag += -h[k].real * sin((2*Pi*n*k)/w) + h[k].imag * cos((2*Pi*n*k)/w);
        }
    }
}


void Transform_Col(Complex* h, int w, int Col, Complex* H)
{
    for(int n = 0; n < w; ++n)
    {
        int N = n * Col;
        for(int k = 0; k < w; ++k)
        {
            int K = k * Col;
            //computation for the real part
            H[N].real += h[K].real * cos((2*Pi*n*k)/w) + h[K].imag * sin((2*Pi*n*k)/w);
            //computation for imagine part
            H[N].imag += -h[K].real * sin((2*Pi*n*k)/w) + h[K].imag * cos((2*Pi*n*k)/w);
        }
    }
}

void Reverse1D(Complex* h, int w, Complex* H)
{
    for(int n = 0; n < w; ++n)
    {
        for(int k = 0; k < w; ++k)
        {
            H[n].real += h[k].real * cos((2*Pi*n*k)/w) - h[k].imag * sin((2*Pi*n*k)/w);
            H[n].imag += h[k].real * sin((2*Pi*n*k)/w) + h[k].imag * cos((2*Pi*n*k)/w);
        }
        H[n].real /= w;
        H[n].imag /= w;
    }
}

void Reverse_Col(Complex* h, int w, int Col, Complex* H)
{
    for(int n = 0; n < w; ++n)
    {
        int N = n * Col;
        for(int k = 0; k < w; ++k)
        {
            int K = k * Col;
            H[N].real += h[K].real * cos((2*Pi*n*k)/w) - h[K].imag * sin((2*Pi*n*k)/w);
            H[N].imag += h[K].real * sin((2*Pi*n*k)/w) + h[K].imag * cos((2*Pi*n*k)/w);
        }
        H[N].real /= w;
        H[N].imag /= w;
    }
}

int main(int argc, char** argv)
{
  string fn("Tower.txt"); // default file name
  if (argc > 1) fn = string(argv[1]);  // if name specified on cmd line
  Transform2D(fn.c_str()); // Perform the transform.
}  
  

  
