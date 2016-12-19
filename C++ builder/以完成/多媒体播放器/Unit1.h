//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <MPlayer.hpp>
#include "stdio.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TPanel *PanelAVI;
        TPanel *Display;
        TMediaPlayer *mprMain;
        TOpenDialog *OpenFile;
        TMenuItem *N1;
        TMenuItem *miFileOpen;
        TMenuItem *miFileClose;
        TMenuItem *miFileEjectCD;
        TMenuItem *miFileExit;
        TMenuItem *N6;
        TMenuItem *miFunctionAVI;
        TMenuItem *miFunctionCD;
        TMenuItem *miFunctionmp3;
        TMenuItem *miFunctionOthers;
        TMenuItem *C1;
        TMenuItem *miControlPlay;
        TMenuItem *miControlPause;
        TMenuItem *miControlStop;
        TMenuItem *miControlStep;
        TMenuItem *miControlBack;
        TMenuItem *miControlHome;
        TMenuItem *H1;
        TMenuItem *miHelpAbout;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall miFileOpenClick(TObject *Sender);
        void __fastcall miFileEjectCDClick(TObject *Sender);
        void __fastcall miFileExitClick(TObject *Sender);
        void __fastcall miFunctionAVIClick(TObject *Sender);
        void __fastcall miFunctionCDClick(TObject *Sender);
        void __fastcall miFunctionmp3Click(TObject *Sender);
        void __fastcall miFunctionOthersClick(TObject *Sender);
        void __fastcall miControlPlayClick(TObject *Sender);
        void __fastcall miControlPauseClick(TObject *Sender);
        void __fastcall miControlStopClick(TObject *Sender);
        void __fastcall miControlStepClick(TObject *Sender);
        void __fastcall miControlBackClick(TObject *Sender);
        void __fastcall miControlHomeClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
