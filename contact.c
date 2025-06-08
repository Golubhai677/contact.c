            /*This program is for understand how we use file handling in c program*/
/*These four are header file*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
/*This is structure and array combination in which we store data dynamically*/
struct contacts{
    char name[20];
    char lname[20];
    double number;
    char mail[30];
}c[100];

int count=0;
// int currentline=0;
/*This is file pointer and contact.txt is file in which store data*/
FILE *fptr;
/*This read_data function is use for read data from file contact.txt*/
void read_data(){
    char buffer[256];                
    fptr=fopen("contact.txt","r");
    if(fptr==NULL){
        // printf("\nOoopps... can't read file!\n\n");
        fptr = fopen("contact.txt","w");
        fclose(fptr);
    }
    else{
        while((fgets(buffer,sizeof(buffer),fptr)) != NULL){
            count++;
        }
        rewind(fptr);
        for(int i=0; i<count;i++){
            fscanf(fptr,"%s%s%lf%s",&c[i].name,&c[i].lname,&c[i].number,&c[i].mail);
            // fscanf(tps,"%s%s%lf%s",&data[1].fname,&data[1].lname,&data[1].num,&data[1].mail);
        }
        fclose(fptr);
    }
}
/*This new_contact function is use for create new contact and store in file*/
void new_contact(){
    int n,i,x;
    fptr=fopen("contact.txt","a");
    printf("\nHow many contact do you want to create: ");
    scanf("%d",&n);
    x=count+n;
    printf("\nEnter details of new contact\n");
    // printf("%d\t",count);
    for(i=count;i<x;i++){
        // printf("%d\n",count);
        // printf("%d\n",i);
        fflush(stdin);
        printf("Enter name: ");
        gets(c[i].name);
        printf("Enter number: ");
        scanf("%lf",&c[i].number);
        printf("Enter email: ");
        scanf("%s",c[i].mail);
        printf("\n");
        count++;
        fprintf(fptr,"%s\t%.0lf\t%s\n",c[i].name,c[i].number,c[i].mail);
    }
    fclose(fptr);
    printf("successfully saved :)\n\n");

}
/*This view_contact function is for see contact from file and display on terminal*/
void view_contact(){
    printf("\nSaved contact: %d\n\n",count);
    // for(i=0;i<count;i++){
    //     printf("contact %d\n",i+1);
    //     printf("name: %s\n",c[i].name);
    //     printf("number: %.0lf\n",c[i].number);
    //     printf("mail: %s\n\n",c[i].mail);
    // }
    fptr=fopen("contact.txt","r");

    for(int i=0; i<count;i++){
        fscanf(fptr,"%s%s%lf%s",&c[i].name,&c[i].lname,&c[i].number,&c[i].mail);
        // fscanf(tps,"%s%s%lf%s",&data[1].fname,&data[1].lname,&data[1].num,&data[1].mail);
    }

    fclose(fptr);
    for(int i=0;i<count;i++){
        printf("name: %s %s\nnumber: %.0lf\nmail: %s\n",c[i].name,c[i].lname,c[i].number,c[i].mail);
        printf("************************\n\n");
    }
}

/*This delete_contact function is for delete contact in file*/
int delete_contact(){
    int i,n;
    printf("\nEnter the serial number in which you want to delete: ");
    scanf("%d",&n);
    if(n<0||n>count){
        printf("\nyou enterd wong serial number!\n\n");
    }
    //     for(i=n-1;i<count-1;i++){
        //         c[i]=c[i+1];
        //     }
        //     printf("\nsuccessfully deleted!\n");
        //     count--;
        // }
        // currentline =0;
        // for(i=0;i<count-1;i++){
        //     printf("contact %d\n",i+1);
        //     printf("name: %s\n",c[i].name);
        //     printf("number: %.0lf\n",c[i].number);
        //     printf("mail: %s\n\n",c[i].mail);
        // }
    else{
        fptr=fopen("contact.txt","r");
        for(int i=0; i<count;i++){
            fscanf(fptr,"%s%s%lf%s",&c[i].name,&c[i].lname,&c[i].number,&c[i].mail);
            // fscanf(tps,"%s%s%lf%s",&data[1].fname,&data[1].lname,&data[1].num,&data[1].mail);
        }
        // for(int i=0; i<count;i++){
        //     printf("%s\t%s\t%.0lf\t%s\n",c[i].name,c[i].lname,c[i].number,c[i].mail);
        //     // fscanf(tps,"%s%s%lf%s",&data[1].fname,&data[1].lname,&data[1].num,&data[1].mail);
        // }
        fclose(fptr);
        fptr=fopen("contact.txt","w");
        for(int i=0;i<count;i++){
            if(i != n-1){
                fprintf(fptr,"%s %s\t%.0lf\t%s\n",c[i].name,c[i].lname,c[i].number,c[i].mail);
            }
            // else{
            // count--;
            // }
        }
        count--;
        fclose(fptr);
        printf("\nsuccessfully deleted :(\n\n");
    }
}
/*this update_contact function is for update date in file*/
void update_contact(){
    int i,n;
    printf("\nEnter the serial number in which you want to Update: ");
    scanf("%d",&n);
    if(n>count||n<0){
        printf("\nyou enterd wrong serial number!\n\n");
    }
    else{
        fptr=fopen("contact.txt","r");
        for(int i=0; i<count;i++){
            fscanf(fptr,"%s%s%lf%s",&c[i].name,&c[i].lname,&c[i].number,&c[i].mail);
            // fscanf(tps,"%s%s%lf%s",&data[1].fname,&data[1].lname,&data[1].num,&data[1].mail);
        }
        fclose(fptr);

        fptr=fopen("contact.txt","w");
        for(int i=0;i<count;i++){
            if(i != n-1){
                fprintf(fptr,"%s %s\t%.0lf\t%s\n",c[i].name,c[i].lname,c[i].number,c[i].mail);
            }
            else{
                fflush(stdin);
                printf("Enter new name: ");
                gets(c[i].name);
                printf("Enter new number: ");
                scanf("%lf",&c[i].number);
                printf("Enter new email: ");
                scanf("%s",c[i].mail);
                fprintf(fptr,"%s\t%.0lf\t%s\n",c[i].name,c[i].number,c[i].mail);
            }
        }
        fclose(fptr);
        printf("\nsuccessfully updated :)\n\n");
    }
}


int main(){
    system("cls");
    read_data();
    int choice;
    // struct contacts c[100];
    printf("\n\n\t\tWELCOME TO CONTACT\n\n");
    do{
        menu:
        printf("1 New contacts\n2 Saved contacts\n3 delete contact\n4 Update contact\n0 Exit contacts\n");
        printf("\nEnter choice: ");
        scanf("%d",&choice);
        printf("\n");
        switch(choice){
            case 1:{
                new_contact();
                break;
            }
            case 2:{
                view_contact();
                break;
            }
            case 3:{
                delete_contact();
                break;
            }
            case 4:{
                update_contact();
                break;
            }
            case 0:{
                printf("\n-------EXIT-------\n");
                break;
            }
            default:{
                printf("\nyou entered wrong choice! ");
                getch();
                printf("\n\n");
                goto menu;
                break;
            }
        }

    }while(choice!=0);
    return 0;
}