object Form1: TForm1
  Left = 265
  Top = 118
  Width = 532
  Height = 399
  Caption = 'ListBox'#32452#20214
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 223
    Top = 21
    Width = 282
    Height = 284
  end
  object Label1: TLabel
    Left = 15
    Top = 7
    Width = 73
    Height = 17
    AutoSize = False
    Caption = #24403#21069#30446#24405#65306
  end
  object Label2: TLabel
    Left = 17
    Top = 60
    Width = 191
    Height = 17
    AutoSize = False
    Caption = 'D:\pic'#30446#24405#19979#30340#25152#26377'jpg'#25991#20214#65306
  end
  object ListBox1: TListBox
    Left = 15
    Top = 77
    Width = 193
    Height = 233
    ItemHeight = 13
    TabOrder = 0
  end
  object Edit1: TEdit
    Left = 15
    Top = 26
    Width = 193
    Height = 21
    TabOrder = 1
    Text = 'D:\pic'
  end
  object Button1: TButton
    Left = 20
    Top = 325
    Width = 89
    Height = 25
    Caption = #21152#36733'jpg'#25991#20214
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 116
    Top = 325
    Width = 89
    Height = 25
    Caption = #26174#31034#34987#36873#25991#20214
    TabOrder = 3
    OnClick = Button2Click
  end
end
