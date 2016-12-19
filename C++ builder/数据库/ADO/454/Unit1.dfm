object Form1: TForm1
  Left = 730
  Top = 113
  Width = 614
  Height = 480
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
  object DBGrid1: TDBGrid
    Left = 120
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
  object DBNavigator1: TDBNavigator
    Left = 96
    Top = 264
    Width = 240
    Height = 25
    DataSource = DataSource1
    TabOrder = 1
  end
  object ADOConnection1: TADOConnection
    LoginPrompt = False
    Left = 40
    Top = 32
  end
  object ADOTable1: TADOTable
    Connection = ADOConnection1
    TableName = 'StuTable'
    Left = 40
    Top = 88
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
    Left = 48
    Top = 160
  end
end
