object Form1: TForm1
  Left = 683
  Top = 104
  Width = 576
  Height = 401
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
    Left = 112
    Top = 152
    Width = 22
    Height = 29
    Caption = '*  '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 216
    Top = 144
    Width = 37
    Height = 37
    Caption = '=  '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object ListBox1: TListBox
    Left = 56
    Top = 88
    Width = 33
    Height = 145
    ItemHeight = 13
    Items.Strings = (
      '1'
      '2'
      '3'
      '4'
      '5'
      '6'
      '7'
      '8'
      '9')
    TabOrder = 0
    OnClick = ListBox1Click
  end
  object ListBox2: TListBox
    Left = 152
    Top = 88
    Width = 41
    Height = 145
    ItemHeight = 13
    Items.Strings = (
      '1'
      '2'
      '3'
      '4'
      '5'
      '6'
      '7'
      '8'
      '9')
    TabOrder = 1
    OnClick = ListBox1Click
  end
  object ListBox3: TListBox
    Left = 272
    Top = 88
    Width = 177
    Height = 153
    ItemHeight = 13
    TabOrder = 2
    OnClick = ListBox3Click
  end
end
