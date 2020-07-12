#include<stdio.h>
void find(float take);
void planet(float in,float he,int x);
int main(){
    float weight,height,bmi;
    int op,flag = 0;
    printf("Enter your weight in kilograms\n");
    scanf("%f",&weight);
    printf("\n");
    printf("Enter your height in meters\n");
    scanf("%f",&height);
    printf("\n");
    bmi = weight/(height*height);
    printf("Yor BMI is %.2f\n",bmi);
    if(bmi<18.5){
        printf("You are underweight on earth\n");
        flag = 1;
    }
    else if(bmi>25){
        printf("You are overweight on earth\n");
        flag = 2;
    }
    else{
        printf("You have normal BMI on earth\n");
        flag = 0;
    }
    printf("\nBMI < 18.5 => Underweight\n");
    printf("18.5 < BMI < 25 => Normal\n");
    printf("BMI > 25 => Overweight\n");
    do{
        printf("\n");
        op = 0;
        printf("Choose any option by entering corresponding number\n");
        printf("1 => Calculate your weight on different planets or moon\n");
        printf("2 => Find planet suitable for you based on your BMI\n");
        printf("3 => Exit\n");
        scanf("%d",&op);
        printf("\n");
        if(op == 1)
            find(weight/9.8);
        else if(op == 2)
            planet(weight/9.8,height,flag);
    }while(op!=3);
    return(0);
}
void find(float take){
    printf("Your weight on Mercury is: %.2f kg\n",take*3.59);
    printf("Your weight on Venus is:   %.2f kg\n",take*8.87);
    printf("Your weight on Mars is:    %.2f kg\n",take*3.77);
    printf("Your weight on Jupiter is: %.2f kg\n",take*25.95);
    printf("Your weight on Saturn is:  %.2f kg\n",take*11.08);
    printf("Your weight on Uranus is:  %.2f kg\n",take*10.67);
    printf("Your weight on Neptune is: %.2f kg\n",take*14.07);
    printf("Your weight on Pluto is:   %.2f kg\n",take*0.42);
    printf("Your weight on Moon is:    %.2f8 kg\n",take*1.62);
}
void planet(float in,float he,int x){
    float moon,mars,jup,sat,nep,ura,plut,merc,ven,m,n;
    int i,p=10;
    moon = in*1.62;
    mars = in*3.77;
    ven = in*8.87;
    ura = in*10.67;
    nep = in*14.07;
    jup = in*25.95;
    sat = in*11.08;
    plut = in*0.42;
    merc = in*3.59;
    float grah[9] = {merc,ven,mars,jup,sat,ura,nep,plut,moon};
    m = (in*9.8)/(he*he);
    if(x == 1){
        for(i=0;i<9;i++){
            n = (grah[i])/(he*he);
            if((n>m)&&(n<25)&&(n>18.5)){
                m = n;
                p=i;
            }
        }
    }
    else if(x == 2){
        for(i=0;i<9;i++){
            n = (grah[i])/(he*he);
            if((n<m)&&(n<25)&&(n>18.5)){
                m = n;
                p=i;
            }
        }
    }
    switch(p){
    case 0:
        printf("Mercury will be best planet for you as your weight on Mercury will be %f kg with BMI = %f\n",merc,m);
        break;
    case 1:
        printf("Venus will be best planet for you as your weight on Venus will be %f kg with BMI = %f\n",ven,m);
        break;
    case 2:
        printf("Mars will be best planet for you as your weight on Mars will be %f kg with BMI = %f\n",mars,m);
        break;
    case 3:
        printf("Jupiter will be best planet for you as your weight on Jupiter will be %f kg with BMI = %f\n",jup,m);
        break;
    case 4:
        printf("Saturn will be best planet for you as your weight on Saturn will be %f kg with BMI = %f\n",sat,m);
        break;
    case 5:
        printf("Uranus will be best planet for you as your weight on Uranus will be %f kg with BMI = %f\n",ura,m);
        break;
    case 6:
        printf("Neptune will be best planet for you as your weight on Neptune will be %f kg with BMI = %f\n",nep,m);
        break;
    case 7:
        printf("Pluto will be best planet for you as your weight on Pluto will be %f kg with BMI = %f\n",plut,m);
        break;
    case 8:
        printf("Moon will be best for you as your weight on Moon will be %f kg with BMI = %f\n",moon,m);
        break;
    default:
        printf("Your weight is normal on Earth, better live on Earth!!");
        break;
    }
}
