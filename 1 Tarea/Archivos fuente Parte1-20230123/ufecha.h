//---------------------------------------------------------------------------
#ifndef ufechaH
#define ufechaH
//---------------------------------------------------------------------------
class Fecha{
  private:
    byte d,m;
    Word a;
  public:
    Fecha(){d=1;m=1;a=2000;};
    __property byte Dia={read=d,write=d};
    __property byte Mes={read=m,write=m};
    __property Word Anio={read=a,write=a};
    virtual String ToStr(){return IntToStr(d)+"/"+IntToStr(m)+"/"+IntToStr(a);};
};
#endif
 