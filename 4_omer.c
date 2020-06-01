#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define ARR_SIZE 10000

int ptr = 0;
pthread_mutex_t m1;
long sum = 0;


void print_arr(int *arr){
        int i = ARR_SIZE - 1;
        while(i--)
                printf("%d\n", *(arr + i));
}
int cnt2;
long sum_arr(int *arr){
        int i = 0;
        long sum = 0, dur;
        struct timeval stop, start;

        gettimeofday(&start, NULL);

        while(i < ARR_SIZE){
                sum += arr[i]; // arr[i];
                cnt2++;
                i++;
        }

        gettimeofday(&stop, NULL);

        printf("Calculations were completed in %lu microseconds\n", ((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec));

}

int once = 0;
struct timeval stopt, startt;
void *sum_th(void *arr_v){

        if(!once){
        
        gettimeofday(&startt, NULL);
        once = 1;
        }
        



        while(1){    
                pthread_mutex_lock( &m1 );
                
                sum += *((int*)arr_v + ptr); // arr[i];
                ptr++;
                if(ptr > ARR_SIZE){
                        sum -= *((int*)arr_v + (ptr - 1));
                        pthread_mutex_unlock( &m1 );
                        
                        break;
                }
             
                        
                pthread_mutex_unlock( &m1 );
        }
        
        
         
        gettimeofday(&stopt, NULL);
        
}

int main(){
         int arr[ARR_SIZE];
 int i = ARR_SIZE - 1;
 time_t t;

  pthread_t t1, t2, t3, t4;

 srand((unsigned) time(&t));

/* generate random array */
 while(i--){
        arr[i] = rand() % 9999999;
 }

sum_arr(arr);

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
