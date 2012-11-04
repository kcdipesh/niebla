void MotorDerecho(int Sentido)
{
  switch  (Sentido)
  {
  case Atras:
    digitalWrite(motor_derecho_a, LOW);
    digitalWrite(motor_derecho_b, HIGH);
    break;

  case Adelante:
    digitalWrite(motor_derecho_a, HIGH);
    digitalWrite(motor_derecho_b, LOW);
    break;

  case Stop:
    digitalWrite(motor_derecho_a, LOW);
    digitalWrite(motor_derecho_b, LOW);
    break;
  }
}



// ********************************************************************************************** //
//				   MOTOR IZQUIERDO					          //
// ********************************************************************************************** //

void MotorIzquierdo(int Sentido)
{


  switch(Sentido)
  {
  case Atras:
    digitalWrite(motor_izquierdo_a, LOW);
    digitalWrite(motor_izquierdo_b, HIGH);
    break;

  case Adelante:
    digitalWrite(motor_izquierdo_a, HIGH);
    digitalWrite(motor_izquierdo_b, LOW);
    break;

  case Stop:
    digitalWrite(motor_izquierdo_a, LOW);
    digitalWrite(motor_izquierdo_b, LOW);
    break;
  }      
}
void ponMotores(signed int mi,signed int md)
{


  // Actuamos sobre motor derecho
  if (md>0) 
  {
    if(md>250)
      md=250;
    MotorDerecho(Adelante);
    analogWrite(pwm_derecho,md );
  }
  else
  {
    if(md<-250)
      md=-250;
    MotorDerecho(Atras);
    analogWrite(pwm_derecho,-md );
  }
  // Actuamos sobre motor izquierdo
  if (mi>0) 
  {
    if(mi>250)
      mi = 250;
    MotorIzquierdo(Adelante);
    analogWrite(pwm_izquierdo,mi );

  }
  else
  {
    if(mi<-250)
      mi = -250;
    MotorIzquierdo(Atras);
    analogWrite(pwm_izquierdo,-mi );
  }
}


