object Form1: TForm1
  Left = 311
  Top = 115
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
  object Memo1: TMemo
    Left = 40
    Top = 32
    Width = 265
    Height = 297
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
  end
  object Button1: TButton
    Left = 376
    Top = 120
    Width = 75
    Height = 25
    Caption = #25171#24320#25991#20214
    TabOrder = 1
    OnClick = Button1Click
  end
  object OpenDialog1: TOpenDialog
    Filter = #25991#26412#25991#20214'(*.txt)|*.txt'
    Left = 376
    Top = 64
  end
end
