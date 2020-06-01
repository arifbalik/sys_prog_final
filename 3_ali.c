#include <stdio.h>

typedef struct complex{
        float re;
        float im;
}complex_t;




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

int main(){
        complex_t c1, c2;
        int op;

        complex_t (*func[5])(struct complex, struct complex);

        func[0] = NULL;
        func[1] = &complex_add;
        func[2] = &complex_sub;
        func[3] = &complex_mult;
        func[4] = &complex_div;
        

        printf("Welcome! Please enter your choise of operation");
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
        
        complex_t temp = func[op](c1, c2);
        complex_print(temp);
        
}
