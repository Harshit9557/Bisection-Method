#include<stdio.h>
#include<math.h>
float f(float x){
    return 2*x*x*x-2*x-5;
}
int main(){
    int it,i=0;
    float a,b,e,c;
    while(1){
        printf("Enter Interval: ");
        scanf("%f%f",&a,&b);
        fflush(stdin);
        if(f(a)*f(b)>0)
            printf("Incorrect Guesses!\nEnter Interval Again: ");
        else if(f(a)*f(b)==0)
        {
            if(f(a)==0)
                printf("%f",a);
            else
                printf("%f",b);
            break;
        }
        else{
            printf("Enter Error: ");
            scanf("%f",&e);
            printf("Enter No of Iterations: ");
            scanf("%d",&it);
            c=(a+b)/2;
            for(i=1;i<it;++i)
            {
                float t=c;
                if((f(a)*f(c))<0)
                    b=c;
                else
                    a=c;
                c=(a+b)/2;
                if(abs(f(c)-f(t))<=e)
                {
                    printf("Answer = %f",c);
                    return 0;
                }
            }
            printf("Insufficient iteration");
        }
    }
    return 0;
}

