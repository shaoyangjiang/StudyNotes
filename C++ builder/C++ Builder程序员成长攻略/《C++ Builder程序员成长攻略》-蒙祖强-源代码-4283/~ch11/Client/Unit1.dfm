object Form1: TForm1
  Left = 278
  Top = 247
  Width = 666
  Height = 286
  Caption = #23458#25143#31471#31243#24207
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
    Width = 658
    Height = 170
    Align = alTop
    DataSource = DataSource1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
  object Button1: TButton
    Left = 504
    Top = 200
    Width = 75
    Height = 25
    Caption = #20445#23384#20462#25913
    TabOrder = 1
    OnClick = Button1Click
  end
  object DBNavigator1: TDBNavigator
    Left = 104
    Top = 200
    Width = 240
    Height = 25
    DataSource = DataSource1
    TabOrder = 2
  end
  object DCOMConnection1: TDCOMConnection
    Connected = True
    ServerGUID = '{60A01E5C-6FD4-4F18-8E99-D2FE2296156F}'
    ServerName = 'AppServer.AppServer1'
    ComputerName = 'mzq'
    Left = 24
    Top = 120
  end
  object ClientDataSet1: TClientDataSet
    Active = True
    Aggregates = <>
    Params = <>
    ProviderName = 'DataSetProvider1'
    RemoteServer = DCOMConnection1
    Left = 80
    Top = 120
  end
  object DataSource1: TDataSource
    DataSet = ClientDataSet1
    Left = 136
    Top = 120
  end
end
