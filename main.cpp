#include <allegro.h>
#include "inicia.h"


int main()
{
allegro_init();
  install_keyboard();
  install_timer();
  install_mouse();
  install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
   set_color_depth(8);
   set_gfx_mode(GFX_AUTODETECT_WINDOWED,640,450, 0, 0);
BITMAP *buffer=create_bitmap(640,7000);
BITMAP *bala =load_bitmap("DISPARO.bmp",NULL);
BITMAP *balaE =load_bitmap("ENEMIGOBALA.bmp",NULL);
BITMAP *NAVE=load_bitmap("NAVE1.bmp",NULL);
BITMAP *NAVETURBO=load_bitmap("POTENCIA1.bmp",NULL);
BITMAP *NAVEIZQ=load_bitmap("NAVEIZQ.bmp",NULL);
BITMAP *NAVEDER=load_bitmap("NAVEDER.bmp",NULL);
BITMAP *FONDO=load_bitmap("FONDO.bmp",NULL);
BITMAP *NAVEIZQTURBO=load_bitmap("NAVEIZQT.bmp",NULL);
BITMAP *NAVEDERTURBO=load_bitmap("NAVEDERT.bmp",NULL);
BITMAP *ENEMIGO4=load_bitmap("ENEMIGO.bmp",NULL);
BITMAP *ENEMIGO=load_bitmap("ENEMIGO0.bmp",NULL);
BITMAP *ENEMIGO1=load_bitmap("ENEMIGO1.bmp",NULL);
BITMAP *ENEMIGO2=load_bitmap("ENEMIGO2.bmp",NULL);
BITMAP *ENEMIGO3=load_bitmap("ENEMIGO3.bmp",NULL);
BITMAP *DESAPARESE=load_bitmap("DESAPARESE.bmp",NULL);
BITMAP *bun1=load_bitmap("bun1.bmp",NULL);
BITMAP *bun2=load_bitmap("bun2.bmp",NULL);
BITMAP *bun3=load_bitmap("bun3.bmp",NULL);
MIDI *musica1  = load_midi("Harry_Potter.mid");
SAMPLE *sonido1 = load_wav("SHOT.wav");
int x=269;
int y=329;
int yb,xb;
int by,bx;
bool b3=false;
bool b2=false;
bool bb=false;
int i=450;
int j=1;
int xr=160,yr=80,cont=1;
int mx,my;
play_midi(musica1, 1);
while(!key[KEY_ESC]){
/*if(cont%2==0){
    xr =3+rand()%150;
    yr =5+rand()%285;
    blit(FONDO,buffer,0,--i,0,0,640,900);  if(i == 0) i=450;
masked_blit( ENEMIGO, buffer, 0, 0, xr, yr, 42, 41);
blit(buffer,screen,0,0,0,0,640,900);
rest(120);
}*/
mx=mouse_x;
my=mouse_y;
blit(FONDO,buffer,0,--i,0,0,640,7000);  if(i == 0) i=450;
masked_blit( NAVE, buffer, 0, 0, x,y, 42, 41);
masked_blit( ENEMIGO, buffer, 0, 0, mx,my, 83, 72);
blit(buffer,screen,0,0,0,0,640,900);

  if(key[ KEY_SPACE ]){
        bb=true;
yb=y-15;
xb=x+17;
  }else if(key[KEY_RIGHT]){
  x+=40;
blit(FONDO,buffer,0,--i,0,0,640,7000);  if(i == 0) i=450;
masked_blit(NAVEIZQTURBO, buffer, 0, 0, x, y, 32, 48);
masked_blit( ENEMIGO, buffer, 0, 0, mx,my, 83, 72);
 blit(buffer,screen,0,0,0,0,640,900);
  rest(120);

  }else if(key[KEY_LEFT]){
    x-=40;
blit(FONDO,buffer,0,--i,0,0,640,7000);  if(i == 0) i=450;
masked_blit( ENEMIGO, buffer, 0, 0, mx,my, 83, 72);
masked_blit( NAVEDERTURBO, buffer, 0, 0, x, y, 31, 48);
 blit(buffer,screen,0,0,0,0,640,900);
  rest(120);


  }else if(key[KEY_DOWN] ){

    y+=40;
blit(FONDO,buffer,0,--i,0,0,640,7000);  if(i == 0) i=450;
masked_blit( ENEMIGO, buffer, 0, 0, mx,my, 83, 72);
masked_blit( NAVE, buffer, 0, 0, x, y, 42, 41);
 blit(buffer,screen,0,0,0,0,640,900);
  rest(120);




  }else if(key[KEY_UP]){
    y-=35;
    --i;
    --i;
blit(FONDO,buffer,0,--i,0,0,640,7000);  if(i == 0) i=450;
masked_blit( ENEMIGO, buffer, 0, 0, mx,my, 83, 72);
masked_blit( NAVETURBO, buffer, 0, 0, x, y, 41, 47);
 blit(buffer,screen,0,0,0,0,640,900);
  rest(120);
}
 /* else if(key[KEY_ENTER]){
  cont++;
  }*/

if(bb){
    yb-=17;
play_sample(sonido1, 200, 150, 1000, 0);
    masked_blit( bala, screen, 0, 0, x+18, yb, 8, 17);

}
if ((xb+18 >= mx)
          && (xb+18 <= mx + 90)
          && (yb >= my)
          && (yb <= my +41))
        {
    masked_blit( bun1, buffer, 0, 0, mx,my, 86, 66);
    blit(buffer,screen,0,0,0,0,640,900);
    rest(150);
    masked_blit( bun2, buffer, 0, 0,mx,my, 86, 66);
    blit(buffer,screen,0,0,0,0,640,900);
    rest(150);
    masked_blit( bun3, buffer, 0, 0, mx,my, 86, 66);
    blit(buffer,screen,0,0,0,0,640,900);
    rest(160);
            yb-=450;
            bb=false;
           rest(120);
        }

if(mouse_b&1){
        b2=true;
by=my;
bx=mx;
b3=true;
  }
if(b3){
    play_sample(sonido1, 200, 150, 1000, 0);
    masked_blit( ENEMIGO1, buffer, 0, 0, mx,my, 92, 60);
    blit(buffer,screen,0,0,0,0,640,900);
    rest(60);
    masked_blit( ENEMIGO2, buffer, 0, 0, mx,my, 92, 60);
    blit(buffer,screen,0,0,0,0,640,900);
    rest(60);
    masked_blit( ENEMIGO3, buffer, 0, 0, mx,my, 88, 62);
    blit(buffer,screen,0,0,0,0,640,900);
    rest(60);
    masked_blit( ENEMIGO4, buffer, 0, 0, mx,my, 89, 72);
    blit(buffer,screen,0,0,0,0,640,900);}
    if(b2){
        b3=false;
        by+=17;
    masked_blit( bala, screen, 0, 0, bx+37, by, 8, 17);}

if ((bx+37 >= x)
          && (bx+37<= x +42)
          && (by >= y)
          && (by <= y +41))
        {
    masked_blit( bun1, buffer, 0, 0, x,y, 86, 66);
    blit(buffer,screen,0,0,0,0,640,900);
    rest(150);
    masked_blit( bun2, buffer, 0, 0, x,y, 86, 66);
    blit(buffer,screen,0,0,0,0,640,900);
    rest(150);
    masked_blit( bun3, buffer, 0, 0, x,y,86, 66);
    blit(buffer,screen,0,0,0,0,640,900);
    rest(160);
            b2=false;
            by+=450;
          rest(120);
        }



if(key[KEY_S]){
midi_pause();
}
if(key[KEY_R]){
midi_resume();
}

rest(30);
/*if(mx=xb){
blit(FONDO,buffer,0,--i,0,0,640,900);  if(i == 0) i=450;
masked_blit( DESAPARESE, buffer, 0, 0, mx, my, 42, 41);
blit(buffer,screen,0,0,0,0,640,900);
rest(120);
}*/
}
readkey();
destroy_bitmap(buffer);
destroy_midi(musica1);
destroy_sample(sonido1);
allegro_exit();
return 0;
}
END_OF_MAIN();
