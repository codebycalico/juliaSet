#include "FPToolkit.c"
#include <math.h>
#include <complex.h>

double radius = 2.0;
double width = 600;
double height = 600;

void julia(double radius, double cutoff){
  complex c, z;
  double xp, yp, x, y;
  double sf = (radius*2)/600;

  for(xp = 0; xp < width; xp++){
    for(yp = 0; yp < height; yp++){
      c = -0.8 + 0.156*I;
      x = xp*sf - radius-0.7;
      y = yp*sf - radius;
      z = x + y*I;
      for(int i= 0; i < cutoff; i++){
        z = cpow(z, 2) + c;
      }
      if(cabs(z) < 0.2){
        G_rgb(cabs(z)/0.2, 0.0, 0.0); //red
      }else if(cabs(z) < 0.4){
        G_rgb(0.0, cabs(z)/0.4, 0.0); //green
      }else if(cabs(z) < 0.6){
        G_rgb(0.0, 0.0, cabs(z)/0.6); //blue
      }else if(cabs(z) < 1.0){
        G_rgb(cabs(z)/1.0, cabs(z)/1.0, 0.0); //yellow
      }else if(cabs(z) < 2.0){
        G_rgb(cabs(z)/2.0, cabs(z)/2.0, cabs(z)/2.0); //white
      }else{
        G_rgb(0.0, 0.0, 0.0); //black
      }
      G_point(xp,yp);
    }
  }
  G_wait_key();
}

int main(){
  G_init_graphics(width, height);
  G_rgb(0.0, 0.0, 0.0);
  G_clear();

  double cutoff = 177.0;
  for(int i = 0; i < 5; i++){
    julia(radius, cutoff);
    radius -= 0.4;
  }
  G_save_to_bmp_file("julia.bmp");
}
