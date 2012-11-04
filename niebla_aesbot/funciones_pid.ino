int PrimD()
{
  if(analogRead(A0) < 512) return 1;
  if(analogRead(A1) < 512) return 2;
  if(analogRead(A2) < 512) return 3;
  if(analogRead(A3) < 512) return 4;
  if(analogRead(A4) < 512) return 5;
  if(analogRead(A5) < 512) return 6;
  if(analogRead(A6) < 512) return 7;
  if(analogRead(A7) < 512) return 8;
  return 0;
}
int PrimI()
{
  if(analogRead(A7) < 512) return 8;
  if(analogRead(A6) < 512) return 7;
  if(analogRead(A5) < 512) return 6;
  if(analogRead(A4) < 512) return 5;
  if(analogRead(A3) < 512) return 4;
  if(analogRead(A2) < 512) return 3;
  if(analogRead(A1) < 512) return 2;
  if(analogRead(A0) < 512) return 1;
  return 0;
}
int control(int lectura)
{

  signed int errorLeido =0;
  signed int resultado=0;
  errorLeido = lectura - REFERENCIA;
  resultado = errorLeido*KP;  //Parte proporcional;
  resultado = resultado + (errorLeido - errorAnt)*KD;    //Anadido parte derivativa
  errorAnt=errorLeido;
  return resultado;                            //Devuelve la actuacion
}




