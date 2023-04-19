//---------------------------------------------------------------------------
#ifndef UTiempoH
#define UTiempoH
//---------------------------------------------------------------------------
class Tiempo {
  private:
	 byte h;
	 byte m;
	 byte s;
  public:
	 Tiempo();
	 Tiempo(const Tiempo &);
	 Tiempo(byte,byte,byte);
	 __property byte Hora={read=GetHora,write=SetHora};
	 __property byte Minuto={read=m,write=SetMinuto};
	 __property byte Segundo={write=SetSegundo,read=GetSegundo};
	 void SetHora(byte);
	 void SetMinuto(byte);
	 void SetSegundo(byte);
	 byte GetHora();
	 byte GetMinuto();
	 byte GetSegundo();
	 Word EnMinutos();
	 Cardinal EnSegundos();
	 virtual String ToStr();
	 bool operator<(Tiempo &t2);
	 Tiempo operator=(Tiempo &t2);

};
//******* FIN de la clase Tiempo ***************************
class TiempoC :public Tiempo{
   private:
	 byte c;
   public:
	 TiempoC();
	 TiempoC(const TiempoC &);
	 TiempoC(byte,byte,byte,byte);
	 void SetCentesima(byte);
	 __property byte Centesima={read=c,write=SetCentesima};
	String ToStr();
};
//**** sobrecarga de operadores *****
bool operator==(Tiempo &t1,Tiempo &t2);
Tiempo operator+(Tiempo &t1,Tiempo &t2);
void ShowMessage(Tiempo &);

#endif



