#include <stdio.h>
#include <string.h>
#include <time.h>


typedef struct
{
    int year;
   int month;
   int day;

}Date;


typedef struct
{
    int id;
    char titre[40];
    char description[50];
    char state[20];
    Date date;
} Tache ;


  char states[3][30] = {
        "A realiser",
        "en cours de realisation",
        "finalisee"
    };
  Tache emp[50];

    int TNum=0;
  int i;

     void afficheOne(Tache x){

        printf("%d \n" , x.id);
         printf("%s  \n" , x.titre);
          printf("%s  \n" , x.description);
            printf("%s  \n" , x.state);
           printf("%d/%d/%d   \n" , x.date.year,x.date.month,x.date.day);





}
int compareDates(Date d1, Date d2) {
   
    if (d1.year < d2.year) {
        return -1;
    } else if (d1.year > d2.year) {
        return 1;
    }

   
    if (d1.month < d2.month) {
        return -1;
    } else if (d1.month > d2.month) {
        return 1;
    }

    
    if (d1.day < d2.day) {
        return -1;
    } else if (d1.day > d2.day) {
        return 1;
    }

   
    return 0;
}


  int search(char x[]){

     for(i =0 ; i<TNum ; i++){

        if(strcmp(x, emp[i].titre)==0){
            return i;
        }

     }
     return -1;


  }




    void ajoute(){
     Tache t;
            t.id=TNum;

            printf("Entrer le titre \n ");
            scanf("%s", t.titre);
            if(search(t.titre)>=0){
                printf("cette tache deja exist");
                return;
            }

            printf("Entrer la description: \n");
            scanf("%s", t.description);


            strcpy(t.state ,  states[1]);
            printf("Entrer le jour the deathline: \n");
            scanf("%d", &t.date.day);

            printf("Entrer le mois ur the deathline: \n");
            scanf("%d", &t.date.month);

            printf("Entrer l'ans  the deathline: \n");
            scanf("%d", &t.date.year);




             emp[TNum]=t;

            TNum++;

}
void ajouteM(){
    int x=1;

    while(x){
      ajoute();
      printf("si tu veux ajouter un autre tache entre 1 , si non 0 ");
      scanf("%d" , &x);


    }
}
void copierEmp(Tache* copy){


    for(int i=0;i<TNum;i++){
        copy[i]=emp[i];
    }


}

void afficheParOrderALF(){
    Tache x[50];
    copierEmp(x);

    for(int i=1 ; i < TNum ; i++){

        Tache current=x[i];
        int j=i-1;

        while (j >= 0 && strcmp(current.titre, x[j].titre) < 0) {
             x[j + 1]=x[j];
            j--;
        }
        x[j + 1] = current;

    }
    for(int i=0;i<TNum;i++ ){
       afficheOne(x[i]);
    }
}

void afficheParDate(){
    Tache x[50];
    copierEmp(x);

    for(int i=1 ; i < TNum ; i++){

        Tache current=x[i];
        int j=i-1;

        while (j >= 0 && compareDates(x[i].date,x[j + 1].date) < 0) {
             x[j + 1]=x[j];
            j--;
        }
        x[j + 1] = current;

    }
    for(int i=0;i<TNum;i++ ){
       afficheOne(x[i]);
    }
}





// void affich(){


//     for (int i = 0; i < TNum; i++)
//     {
//         printf("%d \n" , emp[i].id);
//          printf("%s  \n" , emp[i].titre);
//           printf("%s  \n" , emp[i].description);
//             printf("%s  \n" , emp[i].state);
//            printf("%d/%d/%d   \n" , emp[i].date.year,emp[i].date.month,emp[i].date.day);



//     }

// }








int main(){





ajoute();
ajoute();
ajoute();
afficheParOrderALF();
printf("//////////");
afficheParDate();






    return 0;
}
