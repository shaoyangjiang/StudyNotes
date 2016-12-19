//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TTimer *Timer1;
        TPanel *P17;
        TPanel *P18;
        TPanel *P21;
        TPanel *P23;
        TPanel *P15;
        TPanel *P22;
        TPanel *P19;
        TPanel *P20;
        TPanel *P24;
        TPanel *P25;
        TPanel *P28;
        TPanel *P30;
        TPanel *P29;
        TPanel *P26;
        TPanel *P27;
        TPanel *P16;
        TPanel *P1;
        TPanel *P2;
        TPanel *P5;
        TPanel *P7;
        TPanel *P6;
        TPanel *P3;
        TPanel *P4;
        TPanel *P8;
        TPanel *P9;
        TPanel *P12;
        TPanel *P14;
        TPanel *P13;
        TPanel *P10;
        TPanel *P11;
        TButton *Button1;
        void __fastcall Panel1Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        void showA(int n);
        void showB(int n);
        void showC(int n);
        void showD(int n);
        int minutes(int m1,int m2);
        int hours(int h1,int h2);
        void showMinutes(int m);
        void showHours(int h);
};

//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
