void  limpiar_sensor() //pongo los en vector  a ceros
{
  for (int i=1; i <= 8; i++)
    sensor[i]=0;
}
void  limpiar_sensor_ant()//pongo los en vector  a ceros
{
  for (int i=1; i <= 8; i++)
    sensor_ant[i]=0;
}
int comprobacion_lectura()
  //ejemplo de como dectecto:
  //
  // 0001100 --> un solo salto 
  //00110100 -->  decto  dos saltos
  //
  //es decir resto  la posion 7 con la 6  y asi sucesivamente hasta 0
  // viendo  cuando  la resta en es -1
  // y asi veo el numero de saltos
  //
  //vector -> 0  0  0  1  1  0  0
  //resta ->    0  0  1  0  -1 0   --> un solo salto
  //
  //vector -> 0  -1  0  1  1  0  0
  //resta ->    -1  0  1  0  -1 0   -->  dos saltos
  //
  //ademas de eso hago la media   de donde hay negro
  //cosa q despues vemaldra paa dectar  en a lado esta la marda de desviacion
{
  int acu=0, numero_acu=0;

  numero_lineas=0;
  for (int i=0; i < 9; i++)
  { 
    if ((sensor[i]-sensor[i+1])==-1)
      numero_lineas++;
    if (sensor[i]==1)
    {
      numero_acu++;
      acu=acu+i;
    }
  }
  media=acu/numero_acu;
  return(numero_lineas);
}

  
int comprobar_lado()
{
  int acu=0, numero_acu=0;
  for (int i=0; i < 9; i++)
  { 
    if ((sensor[i]-sensor[i+1])!=(sensor_ant[i]-sensor_ant[i+1]))
    {
      numero_acu ++;
      acu=acu+i;
    }
  }
  media_ant=acu/numero_acu;

  if (media>media_ant)
    return 1;
  else 
    return 2;
}

void  cambiar_sensor_ant_por_sensor()
{
  for (int i=0; i <= 8; i++)
    sensor_ant[i]=sensor[i];
}

void  mostrar_sensor()
{
  for (int i=0; i <= 9; i++)
    Serial.print(sensor[i]);    
  Serial.print("\n");
}

void  mostrar_sensor_ant()
{
  for (int i=0; i <= 9; i++)
    Serial.print(sensor_ant[i]);    
  Serial.print("\n");
}

void leer_sensores_vector()
{
  limpiar_sensor();
  if(analogRead(A0) < 512)sensor[1]=1;
  if(analogRead(A1) < 512)sensor[2]=1;
  if(analogRead(A2) < 512)sensor[3]=1;
  if(analogRead(A3) < 512)sensor[4]=1;
  if(analogRead(A4) < 512)sensor[5]=1;
  if(analogRead(A5) < 512)sensor[6]=1;
  if(analogRead(A6) < 512)sensor[7]=1;
  if(analogRead(A7) < 512)sensor[8]=1;
}

