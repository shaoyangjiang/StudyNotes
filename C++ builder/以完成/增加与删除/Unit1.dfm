object Form1: TForm1
  Left = 518
  Top = 127
  Width = 928
  Height = 480
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
    Left = 104
    Top = 192
    Width = 45
    Height = 13
    Caption = #21517#31216#65306'   '
  end
  object Label2: TLabel
    Left = 104
    Top = 232
    Width = 45
    Height = 13
    Caption = #39318#37117#65306'   '
  end
  object Label3: TLabel
    Left = 104
    Top = 272
    Width = 57
    Height = 13
    Caption = #25152#22312#24030#65306'   '
  end
  object Label4: TLabel
    Left = 320
    Top = 192
    Width = 42
    Height = 13
    Caption = #38754#31215#65306'  '
  end
  object Label5: TLabel
    Left = 320
    Top = 232
    Width = 39
    Height = 13
    Caption = #20154#21475#65306' '
  end
  object DBGrid1: TDBGrid
    Left = 160
    Top = 16
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
  object Button1: TButton
    Left = 144
    Top = 352
    Width = 75
    Height = 25
    Caption = #22686#21152
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 360
    Top = 352
    Width = 75
    Height = 25
    Caption = #21024#38500
    TabOrder = 2
    OnClick = Button2Click
  end
  object Edit1: TEdit
    Left = 160
    Top = 192
    Width = 121
    Height = 21
    TabOrder = 3
  end
  object Edit2: TEdit
    Left = 160
    Top = 224
    Width = 121
    Height = 21
    TabOrder = 4
  end
  object Edit3: TEdit
    Left = 160
    Top = 264
    Width = 121
    Height = 21
    TabOrder = 5
  end
  object Edit4: TEdit
    Left = 384
    Top = 192
    Width = 121
    Height = 21
    TabOrder = 6
  end
  object Edit5: TEdit
    Left = 384
    Top = 224
    Width = 121
    Height = 21
    TabOrder = 7
  end
  object DataSource1: TDataSource
    DataSet = Table1
    Left = 48
    Top = 24
  end
  object Table1: TTable
    Active = True
    DatabaseName = 'BCDEMOS'
    TableName = 'COUNTRY.DB'
    Left = 48
    Top = 88
  end
end
