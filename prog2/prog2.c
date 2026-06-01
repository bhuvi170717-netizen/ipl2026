#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char name[100];
    int grade;
}student;

void readfile(int count){

    FILE *fp = fopen("student.txt","w");
    student s;
    for(int i = 0;i < count;i++){
        printf("ENTER ID, NAME, GRADE: \n");
        scanf("%d %s %d",&s.id,s.name,&s.grade);
        
        fprintf(fp,"%d %s %d\n",s.id,s.name,s.grade);
    }
    fclose(fp);
}

void storeposition(long position[],int count){

    FILE *fp = fopen("student.txt","r");
    char line[100];
    for(int i = 0; i < count;i++){
        
        position[i] = ftell(fp);
        fgets(line,sizeof(line),fp);
    }
    fclose(fp);
}

void displayrecord(long position){

    FILE *fp = fopen("student.txt","r");
    student s;
    char line[100];
    fseek(fp,position,SEEK_SET);
    fgets(line,sizeof(line),fp);

    sscanf(line,"%d %s %d",&s.id,s.name,&s.grade);
    printf("ID: %d\nNAME:%s\nGRADE:%d\n",s.id,s.name,s.grade);
    fclose(fp);

}

int main(){

    int n = 3;
    readfile(n);
    
    long position[10];
    storeposition(position,n);

    printf("RECORD OF 1ST STUDENT: \n");
    displayrecord(position[0]);
    return 0;
}