object Form1: TForm1
  Left = 1096
  Top = 101
  Width = 267
  Height = 165
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
    Left = 32
    Top = 32
    Width = 42
    Height = 13
    Caption = #23494#30721#65306'  '
  end
  object Label2: TLabel
    Left = 32
    Top = 72
    Width = 42
    Height = 13
    Caption = #26126#30721#65306'  '
  end
  object Edit1: TEdit
    Left = 112
    Top = 32
    Width = 121
    Height = 21
    BorderStyle = bsNone
    MaxLength = 6
    PasswordChar = '*'
    TabOrder = 0
    OnChange = Edit1Change
  end
  object Edit2: TEdit
    Left = 112
    Top = 64
    Width = 121
    Height = 21
    ReadOnly = True
    TabOrder = 1
  end
end
