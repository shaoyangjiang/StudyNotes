object Form1: TForm1
  Left = 307
  Top = 215
  Width = 626
  Height = 329
  Caption = 'ADO'#31243#24207
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object DBGrid1: TDBGrid
    Left = 0
    Top = 0
    Width = 618
    Height = 209
    Align = alTop
    DataSource = DataSource1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
  object DBNavigator1: TDBNavigator
    Left = 200
    Top = 240
    Width = 240
    Height = 25
    DataSource = DataSource1
    TabOrder = 1
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=SQLOLEDB.1;Password=123;Persist Security Info=True;User' +
      ' ID=sa;Initial Catalog=MyCBuilderDB;Data Source=MZQ'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    Left = 24
    Top = 240
  end
  object ADOTable1: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'StuTable'
    Left = 72
    Top = 240
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
    Left = 128
    Top = 240
  end
end
