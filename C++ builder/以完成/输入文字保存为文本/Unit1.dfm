object Form1: TForm1
  Left = 429
  Top = 135
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
    Left = 88
    Top = 80
    Width = 185
    Height = 89
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
  end
  object Button1: TButton
    Left = 352
    Top = 128
    Width = 75
    Height = 25
    Caption = #20445#23384
    TabOrder = 1
    OnClick = Button1Click
  end
  object SaveDialog1: TSaveDialog
    Left = 352
    Top = 72
  end
end
