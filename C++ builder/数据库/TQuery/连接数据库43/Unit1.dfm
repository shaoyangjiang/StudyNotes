object Form1: TForm1
  Left = 800
  Top = 103
  Width = 526
  Height = 329
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 16
    Width = 30
    Height = 13
    Caption = #32534#21495'  '
  end
  object Edit1: TEdit
    Left = 88
    Top = 16
    Width = 121
    Height = 21
    TabOrder = 0
  end
  object Button1: TButton
    Left = 232
    Top = 16
    Width = 75
    Height = 25
    Caption = #26597#35810'  '
    TabOrder = 1
    OnClick = Button1Click
  end
  object DBGrid1: TDBGrid
    Left = 0
    Top = 64
    Width = 518
    Height = 231
    Align = alBottom
    DataSource = DataSource1
    TabOrder = 2
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
  object Query1: TQuery
    DatabaseName = 'BCDEMOS'
    Left = 344
    Top = 16
  end
  object DataSource1: TDataSource
    DataSet = Query1
    Left = 408
    Top = 16
  end
end
