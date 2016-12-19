object Form1: TForm1
  Left = 584
  Top = 112
  Width = 678
  Height = 474
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
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security In' +
      'fo=False;Initial Catalog=MyCBilderDB;Data Source=DADI-20111010XB' +
      '\ZZJ'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    Left = 56
    Top = 40
  end
  object ADOQuery1: TADOQuery
    Parameters = <>
    Left = 112
    Top = 40
  end
  object ADOCommand1: TADOCommand
    Parameters = <>
    Left = 56
    Top = 96
  end
  object ADODataSet1: TADODataSet
    Connection = ADOConnection1
    CommandText = 'select * from test'
    Parameters = <>
    Left = 112
    Top = 96
  end
end
