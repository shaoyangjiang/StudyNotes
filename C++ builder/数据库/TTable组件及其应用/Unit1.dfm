object Form1: TForm1
  Left = 681
  Top = 105
  Width = 642
  Height = 442
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 80
    Top = 216
    Width = 42
    Height = 13
    Caption = #21517#31216#65306'  '
  end
  object Label2: TLabel
    Left = 80
    Top = 264
    Width = 45
    Height = 13
    Caption = #39318#37117#65306'   '
  end
  object Label3: TLabel
    Left = 80
    Top = 304
    Width = 57
    Height = 13
    Caption = #25152#22312#24030#65306'   '
  end
  object Label4: TLabel
    Left = 320
    Top = 216
    Width = 45
    Height = 13
    Caption = #38754#31215#65306'   '
  end
  object Label5: TLabel
    Left = 320
    Top = 264
    Width = 45
    Height = 13
    Caption = #20154#21475#65306'   '
  end
  object DBGrid1: TDBGrid
    Left = 128
    Top = 64
    Width = 320
    Height = 120
    DataSource = DataSource1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
  object Insert: TButton
    Left = 72
    Top = 352
    Width = 75
    Height = 25
    Caption = #22686#21152'   '
    TabOrder = 1
    OnClick = InsertClick
  end
  object Delete: TButton
    Left = 160
    Top = 352
    Width = 75
    Height = 25
    Caption = #21024#38500'   '
    TabOrder = 2
    OnClick = DeleteClick
  end
  object Edit1: TEdit
    Left = 136
    Top = 216
    Width = 121
    Height = 21
    TabOrder = 3
  end
  object Edit2: TEdit
    Left = 136
    Top = 264
    Width = 121
    Height = 21
    TabOrder = 4
  end
  object Edit3: TEdit
    Left = 136
    Top = 304
    Width = 121
    Height = 21
    TabOrder = 5
  end
  object Edit4: TEdit
    Left = 368
    Top = 216
    Width = 121
    Height = 21
    TabOrder = 6
  end
  object Edit5: TEdit
    Left = 368
    Top = 264
    Width = 121
    Height = 21
    TabOrder = 7
  end
  object Button1: TButton
    Left = 256
    Top = 352
    Width = 105
    Height = 25
    Caption = #24403#21069#35760#24405#20462#25913'    '
    TabOrder = 8
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 392
    Top = 352
    Width = 75
    Height = 25
    Caption = #26597#35810
    TabOrder = 9
    OnClick = Button2Click
  end
  object Edit6: TEdit
    Left = 488
    Top = 352
    Width = 121
    Height = 21
    TabOrder = 10
    OnKeyDown = Edit6KeyDown
  end
  object DataSource1: TDataSource
    DataSet = Table1
    Left = 64
    Top = 64
  end
  object Table1: TTable
    Active = True
    DatabaseName = 'BCDEMOS'
    TableName = 'country.db'
    Left = 64
    Top = 128
  end
end
