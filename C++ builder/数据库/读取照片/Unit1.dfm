object Form1: TForm1
  Left = 1008
  Top = 110
  Width = 665
  Height = 490
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
  object Button1: TButton
    Left = 8
    Top = 168
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 120
    Top = 168
    Width = 75
    Height = 25
    Caption = 'Button2'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Panel1: TPanel
    Left = 8
    Top = 0
    Width = 185
    Height = 153
    Caption = 'Panel1'
    TabOrder = 2
    object Image1: TImage
      Left = 0
      Top = 0
      Width = 185
      Height = 153
    end
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security In' +
      'fo=False;Initial Catalog=MyCBilderDB;Data Source=DADI-20111010XB' +
      '\ZZJ'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    Left = 200
    Top = 8
  end
  object ADOQuery1: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    SQL.Strings = (
      'select *from test1')
    Left = 200
    Top = 48
  end
  object OpenDialog1: TOpenDialog
    Left = 200
    Top = 88
  end
end
