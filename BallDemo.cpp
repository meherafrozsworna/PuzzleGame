#include "iGraphics.h"
#include<time.h>
#include<stdlib.h>
#include<string.h>

char *image_namefix[16]= {"./images/13.bmp", "./images/9.bmp", "./images/5.bmp", "./images/1.bmp", "./images/14.bmp", "./images/10.bmp", "./images/6.bmp", "./images/2.bmp", "./images/15.bmp","./images/11.bmp", "./images/7.bmp", "./images/3.bmp", "./images/16.bmp", "./images/12.bmp", "./images/8.bmp","./images/4.bmp"};
char *image_name[16]= {"./images/1.bmp", "./images/2.bmp", "./images/3.bmp", "./images/4.bmp", "./images/5.bmp", "./images/16.bmp", "./images/7.bmp", "./images/8.bmp", "./images/9.bmp","./images/10.bmp", "./images/11.bmp", "./images/12.bmp", "./images/13.bmp", "./images/14.bmp", "./images/15.bmp","./images/6.bmp"};
char name[20];
char timess[10];
int gameState=-3;
int q;
int ttime;
/*
	function iDraw() is called again and again by the system.
*/
struct pictures
{
    int x;
    int y;
}pic1,pic2,pic3,pic4,pic5,pic6,pic7,pic8,pic9,pic10,pic11,pic12,pic13,pic14,pic15,pic16;

typedef struct{
int time;
char pname[20];
}scores;
scores players[100];

FILE *fp;

void updHighScore() {
    // ------
    players[q].time=ttime;
    strcpy(players[q].pname,name);
    ++q;

    fp = fopen("score.txt", "a");
    fprintf(fp, "%s %d\n", players[q-1].pname, players[q-1].time);
    fclose(fp);

    int i, j;
    for(i=0; i<q; ++i) {
        for(j=i+1; j<q; ++j) {
            if(players[i].time > players[j].time) {
                scores temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }
    fclose(fp);
}

void getHighScore() {
    fp = fopen("score.txt", "r+");

    if(fp == NULL) printf("Can't open file\n");
    else {
        q = 0;
        char s[100];
        int n;
        while(2 == fscanf(fp, "%s %d", s, &n)) {
            strcpy(players[q].pname, s);
            players[q].time = n;
            //printf("%d - %s %d\n --", q, s, n);
            ++q;
        }
    }
    fclose(fp);
}

void showpicture()
{
    iShowBMP( pic1.x, pic1.y, image_name[0]);
     iShowBMP( pic2.x, pic2.y, image_name[1]);
      iShowBMP( pic3.x, pic3.y, image_name[2]);
       iShowBMP( pic4.x, pic4.y, image_name[3]);
        iShowBMP( pic5.x, pic5.y, image_name[4]);
         iShowBMP( pic16.x, pic16.y, image_name[5]);
          iShowBMP( pic7.x, pic7.y, image_name[6]);
           iShowBMP( pic8.x, pic8.y, image_name[7]);
            iShowBMP( pic9.x, pic9.y, image_name[8]);
             iShowBMP( pic10.x, pic10.y, image_name[9]);
              iShowBMP( pic11.x, pic11.y, image_name[10]);
               iShowBMP( pic12.x, pic12.y, image_name[11]);
                iShowBMP( pic13.x, pic13.y, image_name[12]);
                 iShowBMP( pic14.x, pic14.y, image_name[13]);
                  iShowBMP( pic15.x, pic15.y, image_name[14]);
                   iShowBMP( pic6.x, pic6.y, image_name[15]);

}







void showg()
{
    int m=0;
    int n=0;

    int i,j,x,y;
    int counter2=0;
    int counter1=0;


    int counter3=0;
    for(i=m; i<4; i++)
    {
        x=i*128+100;
        counter1++;

        counter2=0;

        for(j=n; j<4; j++)
        {
            y=j*128+100;
            counter2++;

            iShowBMP(x,y,image_name[counter3]);
            counter3++;


        }

    }


}

void box()
{
    int i,j;
    iSetColor(0,0,0);
    for(i=0; i<5; i++)
    {
        iLine(100,612-i*128,612,612-i*128);
    }
    for(j=0; j<5; j++)
    {
        iLine(100+j*128,100,100+j*128,612);
    }
}


int mi, ni ;

void iDraw()
{
    //place
    iClear();
    if(gameState==-3)
    {
         //iShowBMP(0,0,"./images/second.bmp");
         iSetColor(0,0,64);
         iFilledRectangle(0,0,1200,700);
         iFilledCircle(600,350,220);
         iSetColor(0,255,255);
         iCircle(600,350,215);
         iCircle(600,350,130);

          iSetColor(0,255,255);
          //iText(420,400,"P",GLUT_BITMAP_TIMES_ROMAN_24);
          iText(450,450,"P",GLUT_BITMAP_TIMES_ROMAN_24);
          iText(495,495,"U",GLUT_BITMAP_TIMES_ROMAN_24);
          iText(555,515,"Z",GLUT_BITMAP_TIMES_ROMAN_24);
          iText(620,515,"Z",GLUT_BITMAP_TIMES_ROMAN_24);
          iText(680,500,"L",GLUT_BITMAP_TIMES_ROMAN_24);
          iText(730,450,"E",GLUT_BITMAP_TIMES_ROMAN_24);
          iText(495,200,"G",GLUT_BITMAP_TIMES_ROMAN_24);
          iText(555,175,"A",GLUT_BITMAP_TIMES_ROMAN_24);
          iText(620,175,"M",GLUT_BITMAP_TIMES_ROMAN_24);
          iText(680,200,"E",GLUT_BITMAP_TIMES_ROMAN_24);

            iSetColor(0,255,255);
         iFilledCircle(600,350,120);
         iSetColor(0,0,64);
         iFilledRectangle(500,320,200,60);
         iSetColor(0,255,255);
         iText(550,345,"S T A R T",GLUT_BITMAP_TIMES_ROMAN_24);



        iSetColor(0,255,0);
        //iText(200,400,"PRESS   S   TO  START",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    if(gameState==-2)
    {


        /*if((pic1.x==100&&pic1.y==484)&&(pic2.x==228&&pic2.y==484)&&(pic3.x==356&&pic3.y==484)&&(pic4.x==484&&pic4.y==484)&&(pic5.x==100&&pic5.y==356)&&(pic6.x==228&&pic6.y==356)&&(pic7.x==356&&pic7.y==356)&&(pic8.x==484&&pic8.y==356)&&(pic9.x==100&&pic9.y==228)&&(pic10.x==228&&pic10.y==228)&&(pic11.x==356&&pic11.y==228)&&(pic12.x==484&&pic12.y==228)&&(pic13.x==100&&pic13.y==100)&&(pic14.x==228&&pic14.y==100)&&(pic15.x==356&&pic15.y==100)&&(pic16.x==484&&pic16.y==100))
        {
            iSetColor(0,0 ,64);
            iFilledRectangle(500,450,200,30);
        }*/





        iSetColor(0,0 ,64);
        iFilledRectangle(0,0,1200,700);

        iSetColor(0,255,255);
        iFilledRectangle(500,450,200,30);
        iSetColor(0,0,0);
        iText(520,455,"PLAY GAME",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(0,255,255);
        iFilledRectangle(500,400,200,30);
        iSetColor(0,0,0);
        iText(560,405,"RANK",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(0,255,255);
        iFilledRectangle(500,350,200,30);
        iSetColor(0,0,0);
        iText(560,355,"HELP",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(0,255,255);
        iFilledRectangle(500,300,200,30);
        iSetColor(0,0,0);
        iText(560,305,"EXIT",GLUT_BITMAP_TIMES_ROMAN_24);



        if((pic1.x==100&&pic1.y==484)&&(pic2.x==228&&pic2.y==484)&&(pic3.x==356&&pic3.y==484)&&(pic4.x==484&&pic4.y==484)&&(pic5.x==100&&pic5.y==356)&&(pic6.x==228&&pic6.y==356)&&(pic7.x==356&&pic7.y==356)&&(pic8.x==484&&pic8.y==356)&&(pic9.x==100&&pic9.y==228)&&(pic10.x==228&&pic10.y==228)&&(pic11.x==356&&pic11.y==228)&&(pic12.x==484&&pic12.y==228)&&(pic13.x==100&&pic13.y==100)&&(pic14.x==228&&pic14.y==100)&&(pic15.x==356&&pic15.y==100)&&(pic16.x==484&&pic16.y==100))
        {
            iSetColor(0,0 ,64);
            iFilledRectangle(500,450,200,30);
        }





    }
    if(gameState==-1)
    {
        iSetColor(0,0,64);
        iFilledRectangle(0,0,1200,700);

        iSetColor(0,255,255);
        iText(200,500,"1 . USE YOUR MOUSE TO MOVE THE TILE",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(200,450,"2 . IF YOU CLICK ON THE TILE SIDE BY THE WHITE TILE  ",GLUT_BITMAP_TIMES_ROMAN_24 );
        iText(200,400,"    THEN IT WILL SWAP",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(200,350,"3 . IF YOU CAN MATCH TILES AS REAL PICTURE THEN YOU ",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(200,300,"    WILL WIN THE GAME",GLUT_BITMAP_TIMES_ROMAN_24);

            iFilledRectangle(900,200,200,30);
            iSetColor(0,0,0);
            iText(920,205,"GO TO BACK",GLUT_BITMAP_TIMES_ROMAN_24);
    }

   /* if(gameState==2)
    {
        //iShowBMP(0,0,"images\\background1.bmp");
   //iShowBMP(0,0, "image\\enter.bmp");

		iText(500, 350, "Enter Your Name :",GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(500, 300, 300, 30);
		iText(510, 305, name, GLUT_BITMAP_TIMES_ROMAN_24);

	}*/

     if(gameState == 1)
    {

	//PlaySound(0, 0, 0);
		//PlaySound("shift.wav", NULL, SND_LOOP | SND_ASYNC);
    iSetColor(0,0,64);
    iFilledRectangle(0,0,1200,700);
    iSetColor(0,255,255);
    //iFilledRectangle(0,0,1200,700);
    // iShowBMP(0,0,"./images/back2.bmp");
    int  j = 0 ;


    /*if(j==0)
    {
        srand((unsigned)time(NULL));
        j++ ;

    }*/



    showpicture();
    //showg();
    box();


    iSetColor(255, 255, 255);
     if((pic1.x==100&&pic1.y==484)&&(pic2.x==228&&pic2.y==484)&&(pic3.x==356&&pic3.y==484)&&(pic4.x==484&&pic4.y==484)&&(pic5.x==100&&pic5.y==356)&&(pic6.x==228&&pic6.y==356)&&(pic7.x==356&&pic7.y==356)&&(pic8.x==484&&pic8.y==356)&&(pic9.x==100&&pic9.y==228)&&(pic10.x==228&&pic10.y==228)&&(pic11.x==356&&pic11.y==228)&&(pic12.x==484&&pic12.y==228)&&(pic13.x==100&&pic13.y==100)&&(pic14.x==228&&pic14.y==100)&&(pic15.x==356&&pic15.y==100)&&(pic16.x==484&&pic16.y==100))
     {
        PlaySound(0,0,0);
        PlaySound("win.wav", NULL, SND_ASYNC);
        //PlaySound("win.wav", NULL, SND_LOOP | SND_ASYNC);
        gameState=2;

        // iText(200, 400, "YOU HAVE WON THE MATCH",GLUT_BITMAP_TIMES_ROMAN_24);

     }
    //iText(10, 10, "Press p for pause, r for resume, END for exit.");
     iSetColor(255, 255, 128);
		//iRectangle(700, 477, 150, 30);
		//iText(705, 482, name,GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(700, 435, 150, 30);
		iText(705, 440, timess, GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(700,293,150,30);
		iText(730,298,"SOLVE", GLUT_BITMAP_TIMES_ROMAN_24);
        iRectangle(700,251,150,30);
        iText(715,256,"SCRAMBLE", GLUT_BITMAP_TIMES_ROMAN_24);
        iRectangle(700,209,150,30);
        iText(740,216,"QUIT",GLUT_BITMAP_TIMES_ROMAN_24);

    }


    if(gameState==2)
    {

        iSetColor(0,0,64);
        iFilledRectangle(0,0,1200,700);
        //iFilledRectangle(0,0,1200,700);
        //iShowBMP(430,500,"./images/congratulation.bmp");
        //iSetColor(0,255,0);
        //iText(400,500,"CONGRATULATION",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(0,255,255);
        iText(500,500,"CONGRATULATION",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(450,400,"YOU HAVE WON THE GAME",GLUT_BITMAP_TIMES_ROMAN_24);

        iText(500, 255, "Enter Your Name :",GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(460, 200, 300, 30);
		iText(465, 205, name, GLUT_BITMAP_TIMES_ROMAN_24);

        // gameState = 3;
    }


    if(gameState==4)
    {
         iSetColor(0,0,64);
    iFilledRectangle(0,0,1200,700);
        iShowBMP(100,100,"./images/full.bmp");
        box();
        //iSetColor(0,255,0);
        //iText(100,50,"PRESS   P   TO  PLAY",GLUT_BITMAP_TIMES_ROMAN_24);



        iSetColor(255, 255, 128);
		//iRectangle(700, 477, 150, 30);
		//iText(705, 482, name,GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(700, 435, 150, 30);
		iText(705, 440, timess, GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(700,293,150,30);
		iText(730,298,"SOLVE", GLUT_BITMAP_TIMES_ROMAN_24);
        iRectangle(700,251,150,30);
        iText(715,256,"SCRAMBLE", GLUT_BITMAP_TIMES_ROMAN_24);
        iRectangle(700,209,150,30);
        iText(740,216,"QUIT",GLUT_BITMAP_TIMES_ROMAN_24);


    }
    if(gameState==5)
    {
        iSetColor(0,0,64);
        iFilledRectangle(0,0,1200,700);

        int lim = q, i;
        if(lim > 10) lim = 10;
        //printf("%d\n", lim);
        for(i=0; i<lim; ++i) {
            //printf("%s %d\n", players[i].pname, players[i].time);
            char tempStr[100];
            char temtStr2[100];
            sprintf(tempStr, "%s          ", players[i].pname);
            sprintf(temtStr2,"00:%d   ",players[i].time);
            iSetColor(0, 255, 255);
            iText(200,600,"NAME",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(500,600,"TIME",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(200,570,"-----",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(200,575,"-----",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(500,570,"-----",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(500,575,"-----",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(200, 500-i*50, tempStr,GLUT_BITMAP_TIMES_ROMAN_24);
            iText(500,500-i*50,temtStr2,GLUT_BITMAP_TIMES_ROMAN_24);
            iFilledRectangle(900,200,200,30);
            iSetColor(0,0,0);
            iText(920,205,"GO TO BACK",GLUT_BITMAP_TIMES_ROMAN_24);
        }
    }
    /*if(gameState==-2)

    {
        PlaySound(0,0,0);
        PlaySound("shift.wav", NULL, SND_LOOP | SND_ASYNC);
    }*/



}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{

}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{


    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {




        /*printf("%d %d",mx, my);
        char *t;
    //place your codes here
        if((mx>356&&mx<484)&&(my>100&&my<228))
        {
            t=image_name[12];
            image_name[12]=image_name[8];
            image_name[8]=t;
            //for(int i=0;i<16;i++) printf("%s\n",image_name[i]);

        }
    //get*/

   /* int blank_x,blank_y;
    if((mx>pic16.x)&&mx<(pic16.x+128)&&(my<pic16.y)&&(my>(pic16.y-128)))
    {
        blank_x=pic16.x;
        blank_y=pic16.y;
        pic16.x=pic5.x;
        pic16.y=pic5.y;
        pic5.x=blank_x;
        pic5.y=blank_y;
    }*/

    int blank_x,blank_y;
   // while(pic1.x!=100||pic1.y!=484||pic2.x!=228||pic2.y!=484||pic3.x!=356||pic3.y!=484||pic4.x!=484||pic4.y!=484||pic5.x!=100||pic5.y!=356||pic6.x!=228||pic6.y!=356||pic7.x!=356||pic7.y!=356||pic8.x!=484||pic8.y!=356||pic9.x!=100||pic9.y!=228||pic10.x!=228||pic10.y!=228||pic11.x!=356||pic11.y!=228||pic12.x!=484||pic12.y!=228||pic13.x!=100||pic13.y!=100||pic14.x!=228||pic14.y!=100||pic15.x!=356||pic15.y!=100||pic16.x!=484||pic16.y!=100)





    if(gameState==1)
    {


    //for pic1
    if((mx>pic1.x)&(mx<(pic1.x+128))&&(my>pic1.y)&&(my<(pic1.y+128)))
    {
        if(((pic1.x==(pic16.x-128))&&(pic1.y==(pic16.y)))||((pic1.x==(pic16.x+128))&&(pic1.y==(pic16.y)))||((pic1.x==(pic16.x))&&(pic1.y==(pic16.y+128)))||((pic1.x==(pic16.x))&&(pic1.y==(pic16.y-128))))
        {
            blank_x=pic16.x;
            blank_y=pic16.y;
            pic16.x=pic1.x;
            pic16.y=pic1.y;
            pic1.x=blank_x;
            pic1.y=blank_y;


        }
    }

    //for pic2
     if((mx>pic2.x)&(mx<(pic2.x+128))&&(my>pic2.y)&&(my<(pic2.y+128)))
    {
        if(((pic2.x==(pic16.x-128))&&(pic2.y==(pic16.y)))||((pic2.x==(pic16.x+128))&&(pic2.y==(pic16.y)))||((pic2.x==(pic16.x))&&(pic2.y==(pic16.y+128)))||((pic2.x==(pic16.x))&&(pic2.y==(pic16.y-128))))
        {
            blank_x=pic16.x;
            blank_y=pic16.y;
            pic16.x=pic2.x;
            pic16.y=pic2.y;
            pic2.x=blank_x;
            pic2.y=blank_y;

        }
    }

    //for pic3
        if((mx>pic3.x)&(mx<(pic3.x+128))&&(my>pic3.y)&&(my<(pic3.y+128)))
    {
        if(((pic3.x==(pic16.x-128))&&(pic3.y==(pic16.y)))||((pic3.x==(pic16.x+128))&&(pic3.y==(pic16.y)))||((pic3.x==(pic16.x))&&(pic3.y==(pic16.y+128)))||((pic3.x==(pic16.x))&&(pic3.y==(pic16.y-128))))
        {
            blank_x=pic16.x;
            blank_y=pic16.y;
            pic16.x=pic3.x;
            pic16.y=pic3.y;
            pic3.x=blank_x;
            pic3.y=blank_y;


        }
     }

     //for pic4
     if((mx>pic4.x)&(mx<(pic4.x+128))&&(my>pic4.y)&&(my<(pic4.y+128)))
    {
        if(((pic4.x==(pic16.x-128))&&(pic4.y==(pic16.y)))||((pic4.x==(pic16.x+128))&&(pic4.y==(pic16.y)))||((pic4.x==(pic16.x))&&(pic4.y==(pic16.y+128)))||((pic4.x==(pic16.x))&&(pic4.y==(pic16.y-128))))
        {
            blank_x=pic16.x;
            blank_y=pic16.y;
            pic16.x=pic4.x;
            pic16.y=pic4.y;
            pic4.x=blank_x;
            pic4.y=blank_y;


        }
    }

    //for pic5
    if((mx>pic5.x)&(mx<(pic5.x+128))&&(my>pic5.y)&&(my<(pic5.y+128)))
    {
        if(((pic5.x==(pic16.x-128))&&(pic5.y==(pic16.y)))||((pic5.x==(pic16.x+128))&&(pic5.y==(pic16.y)))||((pic5.x==(pic16.x))&&(pic5.y==(pic16.y+128)))||((pic5.x==(pic16.x))&&(pic5.y==(pic16.y-128))))
        {
            blank_x=pic16.x;
            blank_y=pic16.y;
            pic16.x=pic5.x;
            pic16.y=pic5.y;
            pic5.x=blank_x;
            pic5.y=blank_y;


        }
    }
    //for pic6
    if((mx>pic6.x)&(mx<(pic6.x+128))&&(my>pic6.y)&&(my<(pic6.y+128)))
    {
        if(((pic6.x==(pic16.x-128))&&(pic6.y==(pic16.y)))||((pic6.x==(pic16.x+128))&&(pic6.y==(pic16.y)))||((pic6.x==(pic16.x))&&(pic6.y==(pic16.y+128)))||((pic6.x==(pic16.x))&&(pic6.y==(pic16.y-128))))
        {
            blank_x=pic16.x;
            blank_y=pic16.y;
            pic16.x=pic6.x;
            pic16.y=pic6.y;
            pic6.x=blank_x;
            pic6.y=blank_y;


        }
    }
    //for pic7
    if((mx>pic7.x)&(mx<(pic7.x+128))&&(my>pic7.y)&&(my<(pic7.y+128)))
    {
        if(((pic7.x==(pic16.x-128))&&(pic7.y==(pic16.y)))||((pic7.x==(pic16.x+128))&&(pic7.y==(pic16.y)))||((pic7.x==(pic16.x))&&(pic7.y==(pic16.y+128)))||((pic7.x==(pic16.x))&&(pic7.y==(pic16.y-128))))
        {
            blank_x=pic16.x;
            blank_y=pic16.y;
            pic16.x=pic7.x;
            pic16.y=pic7.y;
            pic7.x=blank_x;
            pic7.y=blank_y;


        }
    }

    //for pic8
    if((mx>pic8.x)&(mx<(pic8.x+128))&&(my>pic8.y)&&(my<(pic8.y+128)))
    {
        if(((pic8.x==(pic16.x-128))&&(pic8.y==(pic16.y)))||((pic8.x==(pic16.x+128))&&(pic8.y==(pic16.y)))||((pic8.x==(pic16.x))&&(pic8.y==(pic16.y+128)))||((pic8.x==(pic16.x))&&(pic8.y==(pic16.y-128))))
        {
            blank_x=pic16.x;
            blank_y=pic16.y;
            pic16.x=pic8.x;
            pic16.y=pic8.y;
            pic8.x=blank_x;
            pic8.y=blank_y;


        }
    }

    //for pic9
    if((mx>pic9.x)&(mx<(pic9.x+128))&&(my>pic9.y)&&(my<(pic9.y+128)))
    {
        if(((pic9.x==(pic16.x-128))&&(pic9.y==(pic16.y)))||((pic9.x==(pic16.x+128))&&(pic9.y==(pic16.y)))||((pic9.x==(pic16.x))&&(pic9.y==(pic16.y+128)))||((pic9.x==(pic16.x))&&(pic9.y==(pic16.y-128))))
        {
            blank_x=pic16.x;
            blank_y=pic16.y;
            pic16.x=pic9.x;
            pic16.y=pic9.y;
            pic9.x=blank_x;
            pic9.y=blank_y;

        }
    }
    //for pic10
    if((mx>pic10.x)&(mx<(pic10.x+128))&&(my>pic10.y)&&(my<(pic10.y+128)))
    {
        if(((pic10.x==(pic16.x-128))&&(pic10.y==(pic16.y)))||((pic10.x==(pic16.x+128))&&(pic10.y==(pic16.y)))||((pic10.x==(pic16.x))&&(pic10.y==(pic16.y+128)))||((pic10.x==(pic16.x))&&(pic10.y==(pic16.y-128))))
        {
            blank_x=pic16.x;
            blank_y=pic16.y;
            pic16.x=pic10.x;
            pic16.y=pic10.y;
            pic10.x=blank_x;
            pic10.y=blank_y;


        }
    }
    //for pic11
    if((mx>pic11.x)&(mx<(pic11.x+128))&&(my>pic11.y)&&(my<(pic11.y+128)))
    {
        if(((pic11.x==(pic16.x-128))&&(pic11.y==(pic16.y)))||((pic11.x==(pic16.x+128))&&(pic11.y==(pic16.y)))||((pic11.x==(pic16.x))&&(pic11.y==(pic16.y+128)))||((pic11.x==(pic16.x))&&(pic11.y==(pic16.y-128))))
        {
            blank_x=pic16.x;
            blank_y=pic16.y;
            pic16.x=pic11.x;
            pic16.y=pic11.y;
            pic11.x=blank_x;
            pic11.y=blank_y;

        }
    }
    //for pic12
    if((mx>pic12.x)&(mx<(pic12.x+128))&&(my>pic12.y)&&(my<(pic12.y+128)))
    {
        if(((pic12.x==(pic16.x-128))&&(pic12.y==(pic16.y)))||((pic12.x==(pic16.x+128))&&(pic12.y==(pic16.y)))||((pic12.x==(pic16.x))&&(pic12.y==(pic16.y+128)))||((pic12.x==(pic16.x))&&(pic12.y==(pic16.y-128))))
        {
            blank_x=pic16.x;
            blank_y=pic16.y;
            pic16.x=pic12.x;
            pic16.y=pic12.y;
            pic12.x=blank_x;
            pic12.y=blank_y;


        }
    }
    //for pic13
    if((mx>pic13.x)&(mx<(pic13.x+128))&&(my>pic13.y)&&(my<(pic13.y+128)))
    {
        if(((pic13.x==(pic16.x-128))&&(pic13.y==(pic16.y)))||((pic13.x==(pic16.x+128))&&(pic13.y==(pic16.y)))||((pic13.x==(pic16.x))&&(pic13.y==(pic16.y+128)))||((pic13.x==(pic16.x))&&(pic13.y==(pic16.y-128))))
        {
            blank_x=pic16.x;
            blank_y=pic16.y;
            pic16.x=pic13.x;
            pic16.y=pic13.y;
            pic13.x=blank_x;
            pic13.y=blank_y;


        }
    }
    //for pic14
    if((mx>pic14.x)&(mx<(pic14.x+128))&&(my>pic14.y)&&(my<(pic14.y+128)))
    {
        if(((pic14.x==(pic16.x-128))&&(pic14.y==(pic16.y)))||((pic14.x==(pic16.x+128))&&(pic14.y==(pic16.y)))||((pic14.x==(pic16.x))&&(pic14.y==(pic16.y+128)))||((pic14.x==(pic16.x))&&(pic14.y==(pic16.y-128))))
        {
            blank_x=pic16.x;
            blank_y=pic16.y;
            pic16.x=pic14.x;
            pic16.y=pic14.y;
            pic14.x=blank_x;
            pic14.y=blank_y;


        }
    }

    //for pic15
    if((mx>pic15.x)&(mx<(pic15.x+128))&&(my>pic15.y)&&(my<(pic15.y+128)))
    {
        if(((pic15.x==(pic16.x-128))&&(pic15.y==(pic16.y)))||((pic15.x==(pic16.x+128))&&(pic15.y==(pic16.y)))||((pic15.x==(pic16.x))&&(pic15.y==(pic16.y+128)))||((pic15.x==(pic16.x))&&(pic15.y==(pic16.y-128))))
        {
            blank_x=pic16.x;
            blank_y=pic16.y;
            pic16.x=pic15.x;
            pic16.y=pic15.y;
            pic15.x=blank_x;
            pic15.y=blank_y;


        }
    }
 iRectangle(700,209,150,30);
        iText(740,216,"QUIT",GLUT_BITMAP_TIMES_ROMAN_24);

        if((mx>700)&&(mx<850)&&(my>293)&&(my<323))
        {
            PlaySound(0,0,0);
            gameState=4;
        }
        if((mx>700)&&(mx<850)&&(my>209)&&(my<239))
        {
         exit(0);
        }

    }

    if(gameState==4)
    {
         if((mx>700)&&(mx<850)&&(my>251)&&(my<281))
        {
             //PlaySound(0,0,0);
            PlaySound("shift.wav", NULL, SND_LOOP | SND_ASYNC);

            gameState=1;


        }
    }

    if(gameState==-2)
    {
         if((mx>500)&&(mx<700)&&(my>450)&&(my<480))

        {
             gameState=1;
              PlaySound(0,0,0);
                PlaySound("shift.wav", NULL, SND_LOOP | SND_ASYNC);
        }
        if((mx>500)&&(mx<700)&&(my>400)&&(my<430))
        {
               gameState=5;
               //updHighScore();
            getHighScore();

        }
         if((mx>500)&&(mx<700)&&(my>350)&&(my<380))
        {
            gameState=-1;
        }
        if((mx>500)&&(mx<700)&&(my>300)&&(my<330))
        {
          exit(0);
        }
    }

    if(gameState==5)
    {

        if((mx>900)&&(mx<1100)&&(my>200)&&(my<230))
        {
            gameState=-2;
        }

    }
     if(gameState==-1)
    {

        if((mx>900)&&(mx<1100)&&(my>200)&&(my<230))
        {
            gameState=-2;
        }

    }

     if(gameState==-3)
    {

        if((mx>500)&&(mx<700)&&(my>320)&&(my<380))
        {
            gameState=-2;
        }

    }





    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
    }
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{

   int static index = 0;
	if (key == 'q')
	{
		//do something with 'q'
	}
	if(gameState==2)
    {
     if (key != '\b' && key != '\r')
	{
		name[index] = key;
		index++;
		name[index] = 0;
	}
	else if (key == '\b')
	{
		if (index < 0)
			index = 0;
		else
			index--;
		name[index] = 0;
	}

	else
    {
        name[index] = 0;
        gameState = 5;

        updHighScore();
    }


    }
     if(gameState==3){
        if(key=='\r')
            gameState=4;
     }

    /*if(gameState==-3)
    {
        if(key=='S')
    {
        gameState=-2;
    }
    }*/

    /*if(gameState==3)
    {
        if(key=='P')
        {
            gameState=1;
        }
    }*/





    //place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

    if(key == GLUT_KEY_END)
    {
        exit(0);
    }

     if(key==  GLUT_KEY_HOME)
     {


        gameState=1;
       // printf("%d",gameState);
     }
    //place your codes for other keys here
}
void time()
{

	if (gameState == 1){
		static int secd = 0, mint = 0;
		if (secd > 59){
			mint += 1;
			secd = 0;
		}
		if (secd < 9) {
			timess[5] = '0' + secd;
			timess[6] = '\0';
		}
		else {
			timess[5] = '0' + (secd) / 10;
			timess[6] = '0' + (secd) % 10;
			timess[7] = '\0';
		}
		if (mint < 9){
			timess[0] = ' ';
			timess[1] = '0' + mint;
		}
		else
		{
			timess[0] = '0' + (mint) / 10;
			timess[1] = '0' + (mint) % 10;
		}

		ttime=(mint*60)+secd;
		secd++;
	}
	/*if (gameState == 2)
	{
		static int sec = 0, min = 0;
		if (sec > 59){
			min += 1;
			sec = 0;
		}
		if (sec < 9) {
			times[5] = '0' + sec;
			times[6] = '\0';
		}
		else {
			times[5] = '0' + (sec) / 10;
			times[6] = '0' + (sec) % 10;
			times[7] = '\0';
		}
		if (min < 9){
			times[0] = ' ';
			times[1] = '0' + min;
		}
		else
		{
			times[0] = '0' + (min) / 10;
			times[1] = '0' + (min) % 10;
		}
		sec++;
	}*/
}


int main()
{
    getHighScore();
    /*
    fp = fopen("score.txt", "r+");

    if(fp == NULL) printf("Can't open file\n");
    else {
        q = 0;
        char s[100];
        int n;
        while(2 == fscanf(fp, "%s %d", s, &n)) {
            strcpy(players[q].pname, s);
            players[q].time = n;
            ++q;
        }
    }
    fclose(fp);
    */




    iSetTimer(1000, time);
    //place your own initialization codes here.


   // mi=rand()%4;
   // ni=rand()%4;
   timess[2] = ' ';
	timess[3] = ':';
	timess[4] = ' ';



  pic1.x=100;
   pic1.y=100;
    pic2.x=100;
   pic2.y=228;
    pic3.x=100;
   pic3.y=356;
    pic4.x=100;
   pic4.y=484;
    pic5.x=228;
   pic5.y=100;
    pic16.x=228;
   pic16.y=228;
    pic7.x=228;
   pic7.y=356;
    pic8.x=228;
   pic8.y=484;
    pic9.x=356;
   pic9.y=100;
    pic10.x=356;
   pic10.y=228;
    pic11.x=356;
   pic11.y=356;
    pic12.x=356;
   pic12.y=484;


    pic13.x=484;
   pic13.y=100;
    pic14.x=484;
   pic14.y=228;
    pic15.x=484;
   pic15.y=356;
    pic6.x=484;
   pic6.y=484;



   PlaySound("start.wav", NULL, SND_LOOP | SND_ASYNC);



    //PlaySound("start.wav", NULL, SND_ASYNC);
    //PlaySound("pacman_beginning.wav", NULL, SND_ASYNC | SND_LOOP);
    //PlaySound("pacman_beginning.wav", NULL, SND_ASYNC | SND_LOOP);
    iInitialize(1200,700, "Ball Demo");

    return 0;
}
