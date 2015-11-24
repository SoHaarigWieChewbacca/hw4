#include <cmath>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

void reading(double* const p, int& N);
void filter(double* const p, int N);
void result(double* const p, int N);

int main(){

   int N;
   double* p = new double[N];

   reading(p, N);
   filter(p, N);
   result(p, N);
   
   delete[] p;

   return 0;
}


void reading(double* const p, int& N){
   
   N = 237;
   const string fname = "noisy.txt"; 
   ifstream in(fname.c_str());

   for(int i=0; i<N; i++)
      in >> p[i];

   in.close();
} 

void filter(double* const p, int N){
   
   double p0 = p[0];
   double p1 = p[1];
   double p2 = p0;
   
   p[0] = (p[N-1] + p[0] + p[1])/3.0;
   
   for(int i=1; i<N-1; i++){
      p[i] = (p0 + p[i] + p[i+1])/3.0;
      p0 = p1;
      p1 = p[i+1];
   }
   p[N-1] = (p0 + p[N-1] + p2)/3.0;
}

void result(double* const p, int N){
   
   ofstream out("filtered.txt");
   
   for(int i=0; i<N; i++)
      out << p[i] << endl;

    out.close();
}



