#include <stdio.h>
#include <stdlib.h>

typedef struct complex{
        float re;
        float im;
}complex_t;

typedef struct{
        complex_t (*func[5])(struct complex, struct complex);
}ops_t;


void complex_print(complex_t c){
        printf("%f+%fi\n",c.re, c.im);
}

complex_t complex_add(complex_t n1, complex_t n2){
        complex_t temp;

        temp.re = n1.re + n2.re;
        temp.im = n1.im + n2.im;

        return temp;
}

complex_t complex_mult(complex_t n1, complex_t n2){
        complex_t temp;

        temp.re = n1.re * n2.re;
        temp.im = n1.im * n2.im;

        return temp;
}

complex_t complex_sub(complex_t n1, complex_t n2){
        complex_t temp;

        temp.re = n1.re - n2.re;
        temp.im = n1.im - n2.im;

        return temp;
}

complex_t complex_div(complex_t n1, complex_t n2){
        complex_t temp;

        if(n2.re == 0 || n2.im == 0)
                return temp;

        temp.re = n1.re / n2.re;
        temp.im = n1.im / n2.im;

        return temp;
}

complex_t exit_p(complex_t dummy1, complex_t dummy2){
        exit(0);
}

int main(){
        complex_t c1, c2;
        int op;
        ops_t ops;
        ops.func[0] = &complex_add;
        ops.func[1] = &complex_sub;
        ops.func[2] = &complex_mult;
        ops.func[3] = &complex_div;
        ops.func[4] = &exit_p;
        

while(1){
        printf(" Please enter your choise of operation");
        scanf("%d", &op);

        /* take the first number */
        printf("Please enter the real part of your first number:");
        scanf("%f", &(c1.re));
        printf("Please enter the imaginary part of your first number:");
        scanf("%f", &(c1.im));

        /* take the second one */
        printf("Please enter the real part of your second number:");
        scanf("%f", &(c2.re));
        printf("Please enter the imaginary part of your second number:");
        scanf("%f", &(c2.im));
        
        complex_t temp = ops.func[op - 1](c1, c2);
        complex_print(temp);
}
        
}
