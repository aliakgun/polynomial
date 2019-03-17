/*
*************************************************
*This program generates polynomial              *
*Pn(x)=a[0]x^n+a[1]x^(n-1)+a[2]x^(n-2)+...+a[n] *
*n=degree of the polynomial                     *
*p0(x)=a[0]                                     *
*pi(x)=pi-1(x)*x+a[i],i=1,2,3,...,n             *
*We will use this algorithm because power       *
*function is very slow.                         *
*************************************************
*/
/**
 @author Ali Akgun
 @file polynomial.c
 @bug There is no known bugs.
 @brief This c file generates polynomial by using horner scheme
 Pn(x) = a[0]x ^ n + a[1]x ^ (n - 1) + a[2]x ^ (n - 2) + ... + a[n]
 n : Degree of the polynomial
 p0(x) : a[0]
 pi(x) : pi-1(x) * x + a[i] , i = 1,2,3,...,n
 @todo Documentation of the algorithm
*/
#include<stdio.h> ///For standard input-output functions
#define SIZE 1000 ///Size of the polynomial constants array.
typedef struct{
    int degree;
    float x,constanta[SIZE],p;
}polynomial_t;
void drive_f(polynomial_t *polynomial);//This function interacts with the user.
void fill_f(polynomial_t *polynomial);//This function gets the constants from the user.
float calculate_polynomial(polynomial_t *polynomial);//Calculates the value of the Polynomial
int main(){
    polynomial_t polynomial;
    printf("Polynomial generator\n");
    drive_f(&polynomial);
    fill_f(&polynomial);
    printf("%.2f\n",calculate_polynomial(&polynomial));
}
/**
 @brief This function interacts with the user.
 @param Specifier address of the polynomial type.
 @return Nothing
*/
void drive_f(polynomial_t *polynomial){
    printf("Polynomial form is Pn(x)=a[0]x^n+a[1]x^(n-1)+a[2]x^(n-2)+...+a[n]\n");
    printf("Please enter the degree of the polynomial(n)\n");
    scanf("%d", &(*polynomial).degree);
    printf("Please enter the polynomial variable(x)\n");
    scanf("%f", &(*polynomial).x);
    printf("Please enter the constants of the polynomial as ordered a[0],a[1],...a[n] by using space>>");
}
/**
 @brief This function fills the constants of the polynomial.
 @param Specifier address of the polynomial type.
 @return Nothing
*/
void fill_f(polynomial_t *polynomial){
    for (int i = 0 ;i <= (*polynomial) . degree ;i++){
        scanf("%f",&(*polynomial) . constanta[i]);
    }
}
/**
 @brief Calculates value of the polynomial.
 @param Specifier address of the polynomial type.
 @return Value of the polynomial
*/
float calculate_polynomial(polynomial_t *polynomial){
    (*polynomial) . p = (*polynomial) . constanta[0];
    for (int i = 1;i <= (*polynomial) . degree;i++){
        (*polynomial) . p = ((*polynomial) . p) * ((*polynomial) . x) + ((*polynomial) . constanta[i]);
    }
    return ((*polynomial) . p);
}
