object Form1: TForm1
  Left = 972
  Top = 114
  Width = 407
  Height = 375
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
    Left = 80
    Top = 72
    Width = 45
    Height = 13
    Caption = #24038#33756#21333'   '
  end
  object Label2: TLabel
    Left = 296
    Top = 72
    Width = 42
    Height = 13
    Caption = #21491#33756#21333'  '
  end
  object ListBox1: TListBox
    Left = 40
    Top = 104
    Width = 121
    Height = 97
    ItemHeight = 13
    Items.Strings = (
      #27993#27743#19975#37324#23398#38498
      #27993#27743#21307#33647
      #29702#24037
      #23425#27874#22823#23398)
    MultiSelect = True
    TabOrder = 0
  end
  object ListBox2: TListBox
    Left = 256
    Top = 104
    Width = 121
    Height = 97
    ItemHeight = 13
    MultiSelect = True
    TabOrder = 1
  end
  object Button1: TButton
    Left = 192
    Top = 112
    Width = 33
    Height = 25
    Caption = '>>'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 192
    Top = 160
    Width = 33
    Height = 25
    Caption = '<<'
    TabOrder = 3
    OnClick = Button2Click
  end
end
