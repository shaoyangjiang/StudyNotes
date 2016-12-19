object MainForm: TMainForm
  Left = 272
  Top = 185
  Width = 638
  Height = 457
  BorderWidth = 1
  Caption = #22270#20070#20511#38405#20449#24687#31649#29702#31995#32479
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIForm
  Menu = MainMenu1
  OldCreateOrder = False
  WindowState = wsMaximized
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 628
    Height = 29
    ButtonHeight = 21
    ButtonWidth = 67
    Caption = 'ToolBar1'
    ShowCaptions = True
    TabOrder = 0
    object LoginTBtn: TToolButton
      Left = 0
      Top = 2
      Caption = #30331'    '#24405
      ImageIndex = 0
      OnClick = LoginTBtnClick
    end
    object BrowsingTBtn: TToolButton
      Left = 67
      Top = 2
      Caption = '    '#26597'    '#20070'    '
      ImageIndex = 3
      OnClick = BrowsingTBtnClick
    end
    object BorrowingTBtn: TToolButton
      Left = 134
      Top = 2
      Caption = #20511'    '#20070
      ImageIndex = 1
      OnClick = BorrowingTBtnClick
    end
    object ReturnTBtn: TToolButton
      Left = 201
      Top = 2
      Caption = #36824'    '#20070
      ImageIndex = 2
      OnClick = ReturnTBtnClick
    end
  end
  object MainMenu1: TMainMenu
    Left = 336
    Top = 80
    object NSystem: TMenuItem
      Caption = #31995#32479'(&S)'
      object NLogin: TMenuItem
        Caption = #31995#32479#30331#24405
        OnClick = NLoginClick
      end
      object NExit: TMenuItem
        Caption = #36864#20986#31995#32479
        OnClick = NExitClick
      end
    end
    object NOperation: TMenuItem
      Caption = #25805#20316'(&O)'
      GroupIndex = 1
      OnClick = NOperationClick
      object NBrowsingBook: TMenuItem
        Caption = #20070#30446#26597#35810'('#19968#33324#35835#32773')'
        OnClick = NBrowsingBookClick
      end
      object BorrowingManage: TMenuItem
        Caption = #20511#38405#31649#29702'('#35835#20070#39302#24037#20316#20154#21592')'
        object NBorrowingBook: TMenuItem
          Caption = #20511#20070
          OnClick = NBorrowingBookClick
        end
        object NRerurningBook: TMenuItem
          Caption = #36824#20070
          OnClick = NRerurningBookClick
        end
        object N1: TMenuItem
          Caption = '-'
        end
        object NReaderInsert: TMenuItem
          Caption = #27880#20876#35835#32773
          OnClick = NReaderInsertClick
        end
        object NReaderDelete: TMenuItem
          Caption = #27880#38144#35835#32773
          OnClick = NReaderDeleteClick
        end
        object N2: TMenuItem
          Caption = '-'
        end
        object NBookInsert: TMenuItem
          Caption = #26032#20070#20837#24211
          OnClick = NBookInsertClick
        end
        object NBookDelete: TMenuItem
          Caption = #26087#20070#28120#27760
          OnClick = NBookDeleteClick
        end
      end
      object SystemManage: TMenuItem
        Caption = #31995#32479#31649#29702'('#31995#32479#31649#29702#21592')'
        OnClick = SystemManageClick
      end
      object N3: TMenuItem
        Caption = '-'
      end
      object NAlterUserPass: TMenuItem
        Caption = #26356#25913#24080#21495
        OnClick = NAlterUserPassClick
      end
    end
    object NWindows: TMenuItem
      Caption = #31383#21475'(&W)'
      GroupIndex = 3
      object WinCloseAll1: TMenuItem
        Action = WinCloseAll
      end
      object Arrange1: TMenuItem
        Action = WindowArrange
      end
      object Cascade1: TMenuItem
        Action = WindowCascade
      end
      object Close1: TMenuItem
        Action = WindowClose
      end
      object MinimizeAll1: TMenuItem
        Action = WindowMinimizeAll
      end
      object TileHorizontally1: TMenuItem
        Action = WindowTileHorizontal
      end
      object TileVertically1: TMenuItem
        Action = WindowTileVertical
      end
    end
    object H1: TMenuItem
      Caption = #24110#21161'(&H)'
      GroupIndex = 4
    end
  end
  object ActionList1: TActionList
    Left = 368
    Top = 80
    object WindowClose: TWindowClose
      Category = 'Window'
      Caption = 'C&lose'
      Enabled = False
      Hint = 'Close'
    end
    object WindowCascade: TWindowCascade
      Category = 'Window'
      Caption = '&Cascade'
      Enabled = False
      Hint = 'Cascade'
      ImageIndex = 17
    end
    object WindowTileHorizontal: TWindowTileHorizontal
      Category = 'Window'
      Caption = 'Tile &Horizontally'
      Enabled = False
      Hint = 'Tile Horizontal'
      ImageIndex = 15
    end
    object WindowTileVertical: TWindowTileVertical
      Category = 'Window'
      Caption = '&Tile Vertically'
      Enabled = False
      Hint = 'Tile Vertical'
      ImageIndex = 16
    end
    object WindowMinimizeAll: TWindowMinimizeAll
      Category = 'Window'
      Caption = '&Minimize All'
      Enabled = False
      Hint = 'Minimize All'
    end
    object WindowArrange: TWindowArrange
      Category = 'Window'
      Caption = '&Arrange'
      Enabled = False
    end
    object WinCloseAll: TAction
      Category = 'Window'
      Caption = 'WinCloseAll'
      OnExecute = WinCloseAllExecute
      OnUpdate = WinCloseAllUpdate
    end
  end
  object LoginQuery: TQuery
    Active = True
    DatabaseName = 'MyCBuilderOdbc'
    SQL.Strings = (
      'Select * from LibrarianTable;')
    Left = 400
    Top = 80
  end
end
