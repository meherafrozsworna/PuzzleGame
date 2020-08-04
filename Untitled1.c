#include<stdio.h>
#include<string.h>

int main(){


    FILE *fp;
    //char str[1000];
    fp=fopen("score.txt", "r");
    //fscanf(fp, "%s",str);
    /*while(1){
            int len=strlen(str);
            char ch=str[len-1];
            if(ch== '\0') break;
            fscanf(fp, "%s",str);
    }*/

    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);  //same as rewind(f);

    char *str = malloc(fsize + 1);
    fread(str, fsize, 1, fp);

    printf(str);


    return 0;
}
