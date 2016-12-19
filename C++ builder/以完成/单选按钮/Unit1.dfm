object Form1: TForm1
  Left = 839
  Top = 121
  Width = 543
  Height = 318
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
    Left = 64
    Top = 176
    Width = 147
    Height = 13
    Caption = #35831#36873#25321#25805#20316#31995#32479#26159#65306'             '
  end
  object RadioButton1: TRadioButton
    Left = 72
    Top = 48
    Width = 65
    Height = 17
    Caption = 'DOS                 '
    TabOrder = 0
    OnClick = RadioButton1Click
  end
  object RadioButton2: TRadioButton
    Left = 72
    Top = 88
    Width = 73
    Height = 17
    Caption = 'Windows'
    TabOrder = 1
    OnClick = RadioButton2Click
  end
  object RadioButton3: TRadioButton
    Left = 72
    Top = 120
    Width = 65
    Height = 17
    Caption = 'Linux'
    TabOrder = 2
    OnClick = RadioButton3Click
  end
end
