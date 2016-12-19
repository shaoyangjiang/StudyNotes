//---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ActnList.hpp>
#include <StdActns.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <DBTables.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *NSystem;
        TMenuItem *NLogin;
        TMenuItem *NExit;
        TMenuItem *NOperation;
        TMenuItem *NBrowsingBook;
        TMenuItem *NWindows;
        TMenuItem *H1;
        TMenuItem *BorrowingManage;
        TMenuItem *SystemManage;
        TMenuItem *NBorrowingBook;
        TMenuItem *NRerurningBook;
        TMenuItem *N1;
        TMenuItem *NReaderInsert;
        TMenuItem *NReaderDelete;
        TMenuItem *N2;
        TMenuItem *NBookInsert;
        TMenuItem *NBookDelete;
        TActionList *ActionList1;
        TWindowClose *WindowClose;
        TWindowCascade *WindowCascade;
        TWindowTileHorizontal *WindowTileHorizontal;
        TWindowTileVertical *WindowTileVertical;
        TWindowMinimizeAll *WindowMinimizeAll;
        TWindowArrange *WindowArrange;
        TAction *WinCloseAll;
        TMenuItem *WinCloseAll1;
        TMenuItem *Arrange1;
        TMenuItem *Cascade1;
        TMenuItem *Close1;
        TMenuItem *MinimizeAll1;
        TMenuItem *TileHorizontally1;
        TMenuItem *TileVertically1;
        TMenuItem *N3;
        TMenuItem *NAlterUserPass;
        TQuery *LoginQuery;
        TToolBar *ToolBar1;
        TToolButton *LoginTBtn;
        TToolButton *BorrowingTBtn;
        TToolButton *ReturnTBtn;
        TToolButton *BrowsingTBtn;
        void __fastcall NLoginClick(TObject *Sender);
        void __fastcall NExitClick(TObject *Sender);
        void __fastcall NBrowsingBookClick(TObject *Sender);
        void __fastcall NOperationClick(TObject *Sender);
        void __fastcall NBorrowingBookClick(TObject *Sender);
        void __fastcall NRerurningBookClick(TObject *Sender);
        void __fastcall NReaderInsertClick(TObject *Sender);
        void __fastcall NReaderDeleteClick(TObject *Sender);
        void __fastcall NBookInsertClick(TObject *Sender);
        void __fastcall NBookDeleteClick(TObject *Sender);
        void __fastcall WinCloseAllExecute(TObject *Sender);
        void __fastcall test1Click(TObject *Sender);
        void __fastcall WinCloseAllUpdate(TObject *Sender);
        void __fastcall NAlterUserPassClick(TObject *Sender);
        void __fastcall SystemManageClick(TObject *Sender);
        void __fastcall LoginTBtnClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall BrowsingTBtnClick(TObject *Sender);
        void __fastcall BorrowingTBtnClick(TObject *Sender);
        void __fastcall ReturnTBtnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
        String IdentityStr, UserName, PassStr;
        bool Login();
        bool IsCreatedForm(TForm *Form);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
