#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char name[100];
    int grade;
}student;

void storefile(int count){

    FILE *fp = fopen("student.dat","wb");
    student s;
    for(int i = 0; i < count;i++){
        printf("Enter id , name , grade: \n");
        scanf("%d %s %d",&s.id,s.name,&s.grade);
        fwrite(&s,sizeof(student),1,fp);
    }
    fclose(fp);
}

void seekfromfile(int position){

    FILE *fp = fopen("student.dat","rb");
    student s;
    fseek(fp,(position - 1)*sizeof(student),SEEK_SET);
    fread(&s,sizeof(student),1,fp);
    printf("\n %d record :\n",position);
    printf("ID: %d \nNAME: %s \nGRADE: %d\n",s.id,s.name,s.grade);
    fclose(fp);

}

void deletrecord(int position,int total){

    FILE *fp = fopen("student.dat","rb+");
    student s;
    for(int i = position;i < total;i++){
        fseek(fp,i * sizeof(student),SEEK_SET);
        fread(&s,sizeof(student),1,fp);
        fseek(fp,(i-1)*sizeof(student),SEEK_SET);
        fwrite(&s,sizeof(student),1,fp);
    }
    printf("\n FILE DELETED SUCCESSFULLY\n");
    fclose(fp);

}

int main(){

    int n = 3;
    storefile(n);
    seekfromfile(3);
    deletrecord(1,n);
    return 0;
}
