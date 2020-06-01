#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>


int th_cnt = 0;
pthread_mutex_t m1;
int sum = 0;




struct timeval stopt, startt;
void *sum_th(void *arr_v){

      
        gettimeofday(&startt, NULL);
    



        while(1){    
                pthread_mutex_lock( &m1 );
                
                sum += *((int*)arr_v + th_cnt); // (arr + i);
                th_cnt++;
                if(th_cnt > 10000){
                        sum -= *((int*)arr_v + (th_cnt - 1));
                        pthread_mutex_unlock( &m1 );
                        
                        break;
                }
             
                        
                pthread_mutex_unlock( &m1 );
        }
        
        
         
        gettimeofday(&stopt, NULL);
        
}

int main(){
         int arr[10000];
 int i = 10000 - 1;
 time_t t;
         struct timeval stop, start;
  pthread_t t1, t2, t3, t4;

 srand((unsigned) time(&t));

/* generate random array */
 while(i--){
        *(arr + i) = rand() % 9999999;
 }

i = 0;
sum = 0;
gettimeofday(&start, NULL);

        for(; i < 10000; i++)
                sum += *(arr + i); 
               
        

        gettimeofday(&stop, NULL);

        printf("Calculations were completed in %lu microseconds\n", ((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec));

sum = 0;

pthread_mutex_init(&m1, NULL);
pthread_create( &t1, NULL, sum_th, (void *)arr);
pthread_create( &t2, NULL, sum_th, (void *)arr);
pthread_create( &t3, NULL, sum_th, (void *)arr);
pthread_create( &t4, NULL, sum_th, (void *)arr);

  pthread_join( t1, NULL);
    pthread_join( t2, NULL);
      pthread_join( t3, NULL);
        pthread_join( t4, NULL);
        

         pthread_mutex_destroy(&m1);
        printf("Calculations were completed in %lu microseconds\n", ((stopt.tv_sec - startt.tv_sec) * 1000000 + stopt.tv_usec - startt.tv_usec));

}
