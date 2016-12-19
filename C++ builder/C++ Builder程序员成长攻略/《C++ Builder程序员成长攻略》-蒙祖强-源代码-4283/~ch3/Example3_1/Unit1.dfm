object Form1: TForm1
  Left = 317
  Top = 239
  Width = 421
  Height = 313
  Caption = #27979#35797'CheckBox'#32452#20214#30340#29366#24577
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
    Left = 48
    Top = 39
    Width = 161
    Height = 16
    AutoSize = False
    Caption = 'Checked'#23646#24615#30340#24403#21069#20540#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 68
    Top = 95
    Width = 141
    Height = 16
    AutoSize = False
    Caption = 'State'#23646#24615#30340#24403#21069#20540#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 174
    Top = 152
    Width = 219
    Height = 25
    AutoSize = False
    Caption = #65288#32452#20214#30340#24403#21069#29366#24577#65306#20108#29366#24577#65289
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 216
    Top = 37
    Width = 121
    Height = 21
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 216
    Top = 95
    Width = 121
    Height = 21
    TabOrder = 1
  end
  object CheckBox1: TCheckBox
    Left = 24
    Top = 152
    Width = 145
    Height = 17
    Alignment = taLeftJustify
    Caption = #34987#27979#35797#30340'CheckBox'#32452#20214
    TabOrder = 2
    OnClick = CheckBox1Click
  end
  object Button1: TButton
    Left = 32
    Top = 216
    Width = 161
    Height = 25
    Caption = #35774#32622#20026#20108#29366#24577'('#40664#35748')'
    TabOrder = 3
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 216
    Top = 216
    Width = 161
    Height = 25
    Caption = #35774#32622#20026#19977#29366#24577
    TabOrder = 4
    OnClick = Button2Click
  end
end
