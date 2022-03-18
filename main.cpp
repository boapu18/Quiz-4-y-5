#include <iostream>
#include <cmath>
#include <list>
#include <algorithm>

/**
QUIZ #4 y #5
Analisis de Algoritmos
María Paula Bolaños Apú
2021026046
**/

using namespace std;

int costo(int N, int M, int x[], int y[]) {
   int xSize = M-1; // 1 asignacion
   int ySize = N-1; // 1 asignacion
   int horizontales = 1; // 1 asignacion
   int verticales = 1; // 1 asignacion
   int total = 0; //1 asignacion
   int corte = 0; // 1 asignacion
   sort(x, x + M);
   sort(y, y + N);
   // 1 asignacion
   for (int i = 0; N < i && M < i; i++){ // 3 comparaciones 1 asignacion 1 suma = 5
      if (y[ySize] >= x[xSize]){ // 2 indexaciones 1 comparacion = 3
         corte = y[ySize]; // 1 asignacion 1 indexacion = 2
         total += corte * horizontales; // 1 asignacion 1 suma 1 multiplicacion = 3
         verticales += 1; // 1 asignacion 1 suma = 2
         (ySize) -= 1; // 1 asignacion 1 resta = 2
      }else{
         corte = x[xSize]; // 1 asignacion 1 indexacion = 2
         total += corte * verticales; // 1 asignacion 1 suma 1 multiplicacion = 3
         horizontales += 1; // 1 asignacion 1 suma = 2
         xSize -= 1; // 1 asignacion 1 resta = 2
      }
   }
   if (y[ySize] >= 0){ // 1 indexacion 1 comparacion = 2
        // 1 asignacion
      for(int i = 0; i < N; i++) // i comparacion 1 asignacion 1 suma = 3
      total += y[i]; // 1 asignacion 1 suma = 2
      total *= horizontales; // 1 asignacion 1 multiplicacion = 2
   }
   if (x[xSize] >= 0){ // 1 indexacion 1 comparacion = 2
       // 1 asignacion
    for (int i = 0; i < M; i++) // i comparacion 1 asignacion 1 suma =3
      total += x[i]; // 1 asignacion 1 suma = 2
      total *= verticales; // 1 asignacion 1 multiplicacion  = 2
   }
   return total;
}
/**
f(n) = 7+(5+3+2+3+2+2+2+3+2+2*N)+3+(7*N)+3(7*M)
     = 7+(26*N)+3(7*N)+3+(7*M)
     = 7+47N+21M
O = O(n)
**/


void radixSort(int *arr, int n, int max) {
   int i, j, m, p = 1, index, temp, count = 0; // 7 asignaciones
   list<int> pocket[10];      //1 asignacion
   //1 asignacion
   for(i = 0; i< max; i++) { //1 comparacion 1 suma 1 asignacion = 3
      m = pow(10, i+1);      //1 asiganacion 1 llamado 2 parametros 1 suma = 5
      p = pow(10, i);        //1 asignacion 1 llamado 2 parametros = 4
      //1 asignacion
      for(j = 0; j<n; j++) { //1 comparacion 1 asignacion 1 suma = 3
         temp = arr[j]%m;    //1 asignacion 1 indexacion 1 modulo = 3
         index = temp/p;      //1 asiganacion 1 division = 2
         pocket[index].push_back(arr[j]); // 2 indexacion 1 llamado 1 parametro = 4
      }
      count = 0; //1 asignacion
      //1 asignacion
      for(j = 0; j<10; j++) {   //1 comparacion 1 asignacion 1 suma = 3
         while(!pocket[j].empty()) { //1 comparacion 1 indixacion 1 llamado = 3
            arr[count] = *(pocket[j].begin());  //2 indexacion 1 asignacion 1 llamado = 4
            pocket[j].erase(pocket[j].begin()); //2 indexacion 2 llamdo 1 parametro = 5
            count++;  //1 suma 1 asignacion = 2
         }
      }
   }
}
/**
f(n) = 9 + (3+5+4+4+3+2+4+1+4+3+4+5+2)
     = 9 + (44 (max-1 * n-1 * 10 * 10))
     = 9 + (44 * maxn - max - n * 200)
     = 44 * maxn - max - n * 200 + 9

O = O(n)

Loop invariant = arr[j]%m esta ordenado
**/

int main(){

    return 0;
}
