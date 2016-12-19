object BorrowingBook: TBorrowingBook
  Left = 10
  Top = 40
  Width = 1014
  Height = 665
  Caption = #22270#20070#20511#20986
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  WindowState = wsMaximized
  PixelsPerInch = 96
  TextHeight = 13
  object Label9: TLabel
    Left = 421
    Top = 29
    Width = 119
    Height = 17
    AutoSize = False
    Caption = #35835#32773#20449#24687#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label10: TLabel
    Left = 420
    Top = 243
    Width = 119
    Height = 17
    AutoSize = False
    Caption = #22270#20070#20449#24687#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label11: TLabel
    Left = 421
    Top = 465
    Width = 119
    Height = 17
    AutoSize = False
    Caption = #20511#38405#25805#20316#20449#24687#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object GroupBox1: TGroupBox
    Left = 24
    Top = 24
    Width = 361
    Height = 585
    Caption = '   '#20511#20070#25805#20316#65306
    Ctl3D = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentCtl3D = False
    ParentFont = False
    TabOrder = 0
    object Label1: TLabel
      Left = 28
      Top = 43
      Width = 89
      Height = 17
      AutoSize = False
      Caption = #35835#32773#26465#30721#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 28
      Top = 99
      Width = 89
      Height = 17
      AutoSize = False
      Caption = #35835#32773#22995#21517#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 27
      Top = 267
      Width = 89
      Height = 17
      AutoSize = False
      Caption = #20070'           '#21495#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 27
      Top = 325
      Width = 89
      Height = 17
      AutoSize = False
      Caption = #20070'           '#21517#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 27
      Top = 378
      Width = 89
      Height = 17
      AutoSize = False
      Caption = #32534'           '#32773#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label6: TLabel
      Left = 28
      Top = 156
      Width = 89
      Height = 17
      AutoSize = False
      Caption = #20511#20986#26085#26399#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label7: TLabel
      Left = 28
      Top = 207
      Width = 89
      Height = 17
      AutoSize = False
      Caption = #24212#36824#26085#26399#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label8: TLabel
      Left = 7
      Top = 434
      Width = 89
      Height = 17
      AutoSize = False
      Caption = #25805#20316#21592#32534#21495#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object leavingBookNumLabel: TLabel
      Left = 34
      Top = 529
      Width = 227
      Height = 33
      AutoSize = False
      Caption = 'XXXX'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -20
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ReaderIdEdit: TEdit
      Left = 112
      Top = 40
      Width = 121
      Height = 26
      TabOrder = 0
    end
    object ReaderNameEdit: TEdit
      Left = 112
      Top = 96
      Width = 161
      Height = 26
      Color = clSilver
      Ctl3D = False
      ParentCtl3D = False
      ReadOnly = True
      TabOrder = 1
    end
    object ISBNEdit: TEdit
      Left = 112
      Top = 262
      Width = 121
      Height = 26
      TabOrder = 2
    end
    object BookNameEdit: TEdit
      Left = 112
      Top = 321
      Width = 209
      Height = 26
      Color = clSilver
      ReadOnly = True
      TabOrder = 3
    end
    object EditorEdit: TEdit
      Left = 112
      Top = 374
      Width = 121
      Height = 26
      Color = clSilver
      ReadOnly = True
      TabOrder = 4
    end
    object BorrowDateEdit: TEdit
      Left = 112
      Top = 152
      Width = 121
      Height = 26
      Color = clSilver
      ReadOnly = True
      TabOrder = 5
    end
    object ReturnDateEdit: TEdit
      Left = 112
      Top = 204
      Width = 121
      Height = 26
      Color = clSilver
      ReadOnly = True
      TabOrder = 6
    end
    object LibrarianIdEdit: TEdit
      Left = 111
      Top = 430
      Width = 121
      Height = 26
      Color = clSilver
      ReadOnly = True
      TabOrder = 7
    end
    object BitBtn1: TBitBtn
      Left = 263
      Top = 470
      Width = 75
      Height = 25
      Caption = '  '#20511'  '#20986
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 8
      OnClick = BitBtn1Click
      Kind = bkOK
    end
  end
  object DBGrid1: TDBGrid
    Left = 419
    Top = 55
    Width = 578
    Height = 114
    Ctl3D = False
    DataSource = ReaderTableDataSource1
    ParentCtl3D = False
    ReadOnly = True
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
  object DBGrid2: TDBGrid
    Left = 419
    Top = 270
    Width = 578
    Height = 122
    Ctl3D = False
    DataSource = BookTableDataSource2
    ParentCtl3D = False
    ReadOnly = True
    TabOrder = 2
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
  object DBGrid3: TDBGrid
    Left = 419
    Top = 492
    Width = 578
    Height = 113
    Ctl3D = False
    DataSource = BorrowingTableDataSource3
    ParentCtl3D = False
    ReadOnly = True
    TabOrder = 3
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
  object ReaderTableQuery1: TQuery
    Active = True
    DatabaseName = 'MyCBuilderOdbc'
    SQL.Strings = (
      'Select * from ReaderTable;')
    Left = 704
    Top = 288
  end
  object ReaderTableDataSource1: TDataSource
    DataSet = ReaderTableQuery1
    Left = 744
    Top = 283
  end
  object BookTableQuery2: TQuery
    Active = True
    DatabaseName = 'MyCBuilderOdbc'
    SQL.Strings = (
      'Select * from BookTable;')
    Left = 760
    Top = 75
  end
  object BookTableDataSource2: TDataSource
    DataSet = BookTableQuery2
    Left = 720
    Top = 72
  end
  object BorrowingTableDataSource3: TDataSource
    DataSet = BorrowingTableQuery3
    Left = 776
    Top = 480
  end
  object BorrowingTableQuery3: TQuery
    Active = True
    DatabaseName = 'MyCBuilderOdbc'
    SQL.Strings = (
      'Select * from BorrowingTable;')
    Left = 736
    Top = 480
  end
end
