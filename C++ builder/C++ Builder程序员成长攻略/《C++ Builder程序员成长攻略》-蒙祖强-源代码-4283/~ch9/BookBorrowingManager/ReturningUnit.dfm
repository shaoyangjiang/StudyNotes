object ReturningBook: TReturningBook
  Left = 129
  Top = 48
  Width = 883
  Height = 627
  Caption = #36824#20070
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
  object Label13: TLabel
    Left = 20
    Top = 377
    Width = 261
    Height = 25
    AutoSize = False
    Caption = #24403#21069#24050#21457#29983#30340#20511#38405#20449#24687#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object DBGrid1: TDBGrid
    Left = 16
    Top = 400
    Width = 849
    Height = 177
    DataSource = DataSource1
    ReadOnly = True
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'TaskId'
        Title.Caption = #20511#38405#20107#21153#32534#21495
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'ReaderId'
        Title.Caption = #35835#32773#26465#30721
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'ReaderName'
        Title.Caption = #35835#32773#22995#21517
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'ISBN'
        Title.Caption = #20070#21495
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'BookName'
        Title.Caption = #20070#21517
        Width = 211
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Editor'
        Title.Caption = #32534#32773
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'BorrowDate'
        Title.Caption = #20511#20986#26085#26399
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'ReturnDate'
        Title.Caption = #24212#35813#36824#26085#26399
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'LibrarianId'
        Title.Caption = #25805#20316#21592#32534#21495
        Visible = True
      end>
  end
  object GroupBox1: TGroupBox
    Left = 21
    Top = 14
    Width = 845
    Height = 345
    Caption = ' '#21018#21457#29983#30340#20511#38405#65288#36824#20070#65289#20449#24687#65306' '
    TabOrder = 1
    object Label1: TLabel
      Left = 39
      Top = 33
      Width = 129
      Height = 25
      AutoSize = False
      Caption = #24453#36824#20070#31821#30340#20070#21495#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 519
      Top = 77
      Width = 113
      Height = 25
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
      Left = 86
      Top = 77
      Width = 113
      Height = 25
      AutoSize = False
      Caption = #20070'           '#21517#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 86
      Top = 122
      Width = 113
      Height = 25
      AutoSize = False
      Caption = #32534'           '#32773#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 85
      Top = 166
      Width = 113
      Height = 25
      AutoSize = False
      Caption = #20986'   '#29256'   '#31038#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label6: TLabel
      Left = 86
      Top = 215
      Width = 113
      Height = 25
      AutoSize = False
      Caption = #20986#29256#26085#26399#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label7: TLabel
      Left = 84
      Top = 265
      Width = 113
      Height = 25
      AutoSize = False
      Caption = #20215'           '#26684#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label8: TLabel
      Left = 517
      Top = 120
      Width = 113
      Height = 25
      AutoSize = False
      Caption = #24615'           '#21035#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label9: TLabel
      Left = 520
      Top = 166
      Width = 113
      Height = 25
      AutoSize = False
      Caption = #24037#20316#21333#20301#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label10: TLabel
      Left = 517
      Top = 215
      Width = 113
      Height = 25
      AutoSize = False
      Caption = #36523'           '#20221#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label11: TLabel
      Left = 518
      Top = 265
      Width = 113
      Height = 25
      AutoSize = False
      Caption = #24050#20511#25968#37327#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label12: TLabel
      Left = 519
      Top = 33
      Width = 113
      Height = 25
      AutoSize = False
      Caption = #35835#32773#26465#30721#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object BitBtn1: TBitBtn
      Left = 728
      Top = 305
      Width = 75
      Height = 25
      Caption = ' '#36824'  '#20070' '
      TabOrder = 0
      OnClick = BitBtn1Click
      Kind = bkOK
    end
    object ISBNEdit: TEdit
      Left = 167
      Top = 33
      Width = 121
      Height = 19
      Ctl3D = False
      ParentCtl3D = False
      TabOrder = 1
      Text = '11231'
    end
    object BookNameEdit: TEdit
      Left = 166
      Top = 75
      Width = 249
      Height = 21
      Color = clMenuBar
      Ctl3D = True
      ParentCtl3D = False
      ReadOnly = True
      TabOrder = 2
      Text = 'BookNameEdit'
    end
    object EditorEdit: TEdit
      Left = 166
      Top = 119
      Width = 121
      Height = 21
      Color = clMenuBar
      ReadOnly = True
      TabOrder = 3
      Text = 'EditorEdit'
    end
    object PublisherEdit: TEdit
      Left = 166
      Top = 164
      Width = 241
      Height = 21
      Color = clMenuBar
      ReadOnly = True
      TabOrder = 4
      Text = 'PublisherEdit'
    end
    object PubDateEdit: TEdit
      Left = 166
      Top = 212
      Width = 121
      Height = 21
      Color = clMenuBar
      ReadOnly = True
      TabOrder = 5
      Text = 'PubDateEdit'
    end
    object PriceEdit: TEdit
      Left = 166
      Top = 261
      Width = 121
      Height = 21
      Color = clMenuBar
      ReadOnly = True
      TabOrder = 6
      Text = 'PriceEdit'
    end
    object NameEdit: TEdit
      Left = 600
      Top = 75
      Width = 121
      Height = 21
      Color = clMenuBar
      ReadOnly = True
      TabOrder = 7
      Text = 'NameEdit'
    end
    object GenderEdit: TEdit
      Left = 600
      Top = 119
      Width = 121
      Height = 21
      Color = clMenuBar
      ReadOnly = True
      TabOrder = 8
      Text = 'GenderEdit'
    end
    object UnitEdit: TEdit
      Left = 600
      Top = 164
      Width = 185
      Height = 21
      Color = clMenuBar
      ReadOnly = True
      TabOrder = 9
      Text = 'UnitEdit'
    end
    object IdentEdit: TEdit
      Left = 600
      Top = 212
      Width = 121
      Height = 21
      Color = clMenuBar
      ReadOnly = True
      TabOrder = 10
      Text = 'IdentEdit'
    end
    object NumberEdit: TEdit
      Left = 600
      Top = 262
      Width = 121
      Height = 21
      Color = clMenuBar
      ReadOnly = True
      TabOrder = 11
      Text = 'NumberEdit'
    end
    object ReaderIdEdit: TEdit
      Left = 600
      Top = 31
      Width = 121
      Height = 21
      Color = clMenuBar
      ReadOnly = True
      TabOrder = 12
      Text = 'ReaderIdEdit'
    end
  end
  object ReturningTableQuery1: TQuery
    Active = True
    DatabaseName = 'MyCBuilderOdbc'
    SQL.Strings = (
      'Select * from BorrowingTable;')
    Left = 448
    Top = 32
  end
  object BookTableQuery2: TQuery
    Active = True
    DatabaseName = 'MyCBuilderOdbc'
    SQL.Strings = (
      'Select * from BookTable;')
    Left = 448
    Top = 112
  end
  object DataSource1: TDataSource
    DataSet = ReturningTableQuery1
    Left = 456
    Top = 480
  end
  object ReaderTableQuery3: TQuery
    Active = True
    DatabaseName = 'MyCBuilderOdbc'
    SQL.Strings = (
      'Select * from ReaderTable')
    Left = 416
    Top = 480
  end
end
