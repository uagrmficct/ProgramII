//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UTiempo.h"

Tiempo::Tiempo()
{ h=m=s=0;
}

Tiempo::Tiempo(const Tiempo &t)
{ h=t.h;
  m=t.m;
  s=t.s;
}
Tiempo::Tiempo(byte hh,byte mm,byte ss)
{ if ( (hh<24)&&(mm<60)&&(ss<60)){
	 h=hh;
	 m=mm;
	 s=ss;
  } else {
	 h=m=s=0;
  }
}

void Tiempo::SetHora(byte hh)
{
  if (hh<24)
	h=hh;
  else
	throw new Exception("Error:dato no valido");
}
void Tiempo::SetMinuto(byte mm)
{ if (mm<60)
	m=mm;
  else
	throw new Exception("Error:dato no valido");

}
void Tiempo::SetSegundo(byte ss)
{ if (ss<60)
	s=ss;
  else
	throw new Exception("Error:dato no valido");

}

byte Tiempo::GetHora()
{return h;}

byte Tiempo::GetMinuto()
{return m;}
byte Tiempo::GetSegundo()
{return s;}
Word Tiempo::EnMinutos()
{ return (h*60 + m);
}

Cardinal Tiempo::EnSegundos()
{ return h*60*60 + m*60 + s;
}

String Tiempo::ToStr()
{ String c;
  c=IntToStr(h)+":"+IntToStr(m)+":"+IntToStr(s);
  return c;
}
bool Tiempo::operator<(Tiempo &t2)
{bool m;
  m=EnSegundos()<t2.EnSegundos();
  return m;
}

Tiempo Tiempo::operator=(Tiempo &t2)
{  h=t2.h;
   m=t2.m;
   s=t2.s;
   return *this;
}

//***** implementacion de los operadores sobrecargados *****
bool operator==(Tiempo &t1,Tiempo &t2)
{ bool e;
  e=(t1.Hora==t2.Hora)&&(t1.Minuto==t2.Minuto)&&(t1.Segundo==t2.Segundo);
  return e;
}

Tiempo operator+(Tiempo &t1,Tiempo &t2)
{ Tiempo z;
  z.Hora=t1.Hora+t2.Hora;
  z.Minuto=t1.Minuto+t2.Minuto;
  z.Segundo=t1.Segundo+t2.Segundo;
  return z;
}
void ShowMessage(Tiempo &t)
{
 ShowMessage(t.ToStr());
}
//********  clase TiempoC  **********************
TiempoC::TiempoC():Tiempo()
{
  c=0;
}
TiempoC::TiempoC(const TiempoC &t):Tiempo(t)
{  c=t.c;
}
TiempoC::TiempoC(byte hh,byte mm,byte ss,byte cc):
		 Tiempo(hh,mm,ss)
{ if (cc<100)
	 c=cc;
  else
	c=0;
}
void TiempoC::SetCentesima(byte cc)
{
  if (cc<100)
	c=cc;
  else
	throw new Exception("Error:dato no válido");
}


String TiempoC::ToStr()
{
  return Tiempo::ToStr()+":"+IntToStr(c);
}

//---------------------------------------------------------------------------
#pragma package(smart_init)
