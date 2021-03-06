/*******************************************
 * Author: Michail Georgiou 
*  Last Modified: Time-stamp: <2014-06-04 10:50:54 mike_georgiou>   
*
*
Predictor_To_Corrector.cpp -- This function is switcing the necessary
arrays in order to  proceed into the corrector step
*
* Written on Tuesday,  6 May 2014.
********************************************/
#include "../Struct.h"

void Predictor_To_Corrector(Ar* Arr)
{
  double*** Temp;
      /*Passing the data to proceed  to the next time step*/
      Temp = Arr->rho_old;
      Arr->rho_old = Arr->rho;
      Arr->rho = Temp;

      Temp = Arr->rho;
      Arr->rho = Arr->rho_new;
      Arr->rho_new = Temp;

      Temp = Arr->residual_x_old;
      Arr->residual_x_old = Arr->residual_x;
      Arr->residual_x = Temp;

      Temp = Arr->residual_y_old;
      Arr->residual_y_old = Arr->residual_y;
      Arr->residual_y = Temp;

      Temp = Arr->residual_z_old;
      Arr->residual_z_old = Arr->residual_z;
      Arr->residual_z = Temp;

      // Introducing q which in fact is pressure^{n-1}
      Temp = Arr->pressure_old;
      Arr->pressure_old = Arr->pressure;
      Arr->pressure = Temp;


}
