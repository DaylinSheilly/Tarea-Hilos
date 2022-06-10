#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <assert.h>
#include <sys/wait.h>

//TIEMPO DE CREACION DE UN HILO

clock_t start, end;
pthread_t hilo;
double timer = 0;

int tiempoMedido, tiempoTotal, mayor, menor = 0;
int tiempos[7];
int promedio = 0;
int x;

void *worker(void *data)
{
  return NULL;
}

int main() 
{ 
  for(int i=0;i<7;i++)
  {
    start = clock();
    pthread_create(&hilo,NULL, worker,NULL);
    pthread_join(hilo, NULL);
    
    end = clock();
    tiempoMedido = end - start;
    
    tiempos[i] = tiempoMedido;
    
    start=0;
    end=0;
  }
  
  mayor = tiempos[0];
  for(int x=0;x<7;x++)
  {
    if(mayor>=tiempos[x])
    {
      mayor = mayor;
    }
    else if(mayor<=tiempos[x])
    {
      mayor = tiempos[x];
    }
  }
  
  menor = tiempos[0];
  for(int x=0;x<7;x++)
  {
    if(menor>=tiempos[x])
    {
      menor = tiempos[x];
    }
    else if(menor<=tiempos[x])
    {
      menor = menor;
    }
  }
  
  for(int y=0;y<7;y++)
  {
    if(tiempos[y]!=menor && tiempos[y]!=mayor)
    {
      tiempoTotal = tiempoTotal + tiempos[y];
    }
  }
  
  promedio=tiempoTotal/5;
  printf("%i", promedio);
  printf(" milisegundos tarda en promedio en crearse un hilo. \n");

  start=0;
  end=0;
  
  //TOMA DE TIEMPO DE CREACION DE UN PROCESO
  
  for(int i=0;i<7;i++)
  {
    start = clock();
    pid_t pid = fork();
  
    assert(pid>=0);
  
    if(pid != 0) //proceso padre
    {
      end = clock();
      break;
    }
    tiempoMedido = end - start;
    
    tiempos[i] = tiempoMedido;
    
    start=0;
    end=0;
  }
  
  mayor = tiempos[0];
  for(int x=0;x<7;x++)
  {
    if(mayor>=tiempos[x])
    {
      mayor = mayor;
    }
    else if(mayor<=tiempos[x])
    {
      mayor = tiempos[x];
    }
  }
  
  menor = tiempos[0];
  for(int x=0;x<7;x++)
  {
    if(menor>=tiempos[x])
    {
      menor = tiempos[x];
    }
    else if(menor<=tiempos[x])
    {
      menor = menor;
    }
  }
  
  for(int y=0;y<7;y++)
  {
    if(tiempos[y]!=menor && tiempos[y]!=mayor)
    {
      tiempoTotal = tiempoTotal + tiempos[y];
    }
  }
  
  promedio=tiempoTotal/5;
  printf("%i", promedio);
  printf(" milisegundos tarda en promedio en crearse un proceso. \n");
}