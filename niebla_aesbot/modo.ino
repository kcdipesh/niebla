void modos(int modo)
{       


  switch(modo)
  {
  case 1:
    KP=		        30	;//      modo lento seguro	
    KD=			180;
    70	;//	 NO TOCAR
    BIAS=               100     ;//      NO BORRAR
    break;
  case 2:
    KP=		        28	;//	VELOCIDAD RAPIDA 1
    KD=			190	;//	NO TOCAR
    BIAS=               120     ;//     NO BORRAR
    break;
  case 3:
    KP=		        28	;	
    KD=			195	;	
    BIAS=               130     ;
    break;
  case 4:
    KP=		        30	;	
    KD=			195	;	
    BIAS=               140     ;
    break;
  case 5:
    KP=		        35	;	
    KD=			200	;	
    BIAS=               150     ;
    break;
  case 6:
    KP=		        45	;	
    KD=			200	;	
    BIAS=               70      ;
    break;
  case 7:
    KP=		        50	;	
    KD=		        200	;	
    BIAS=               70      ;
    break;



  }
}

