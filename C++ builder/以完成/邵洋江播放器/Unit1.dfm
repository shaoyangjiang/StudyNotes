object Form1: TForm1
  Left = 810
  Top = 115
  Width = 524
  Height = 328
  Caption = #37045#27915#27743#25773#25918#22120
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
    Left = 152
    Top = 40
    Width = 69
    Height = 13
    Caption = #25991#20214#21517#31216#65306'   '
  end
  object Label2: TLabel
    Left = 152
    Top = 88
    Width = 66
    Height = 13
    Caption = #25773#25918#38271#24230#65306'  '
  end
  object Label3: TLabel
    Left = 152
    Top = 128
    Width = 78
    Height = 13
    Caption = #24038#22768#36947#38899#37327#65306'  '
  end
  object Label4: TLabel
    Left = 152
    Top = 168
    Width = 81
    Height = 13
    Caption = #21491#22768#36947#38899#37327#65306'   '
  end
  object Mp3Play1: TMp3Play
    Left = 416
    Top = 24
    Width = 65
    Height = 50
    TabOrder = 0
    ControlData = {00000100B80600002B05000000000000}
  end
  object Button1: TButton
    Left = 40
    Top = 32
    Width = 75
    Height = 25
    Caption = #25171#24320#25991#20214
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 40
    Top = 80
    Width = 75
    Height = 25
    Caption = #25773#25918#25991#20214
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 40
    Top = 128
    Width = 75
    Height = 25
    Caption = #26242#20572#38899#20048
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 40
    Top = 176
    Width = 75
    Height = 25
    Caption = #20572#27490#25773#25918
    TabOrder = 4
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 40
    Top = 216
    Width = 75
    Height = 25
    Caption = #20851#38381#25991#20214
    TabOrder = 5
    OnClick = Button5Click
  end
  object RadioButton1: TRadioButton
    Left = 160
    Top = 224
    Width = 113
    Height = 17
    Caption = #35835#21462#25773#25918#20449#24687
    TabOrder = 6
    OnClick = RadioButton1Click
  end
  object RadioButton2: TRadioButton
    Left = 304
    Top = 224
    Width = 113
    Height = 17
    Caption = #35774#32622#25773#25918#20449#24687
    TabOrder = 7
    OnClick = RadioButton2Click
  end
  object Edit1: TEdit
    Left = 232
    Top = 40
    Width = 121
    Height = 21
    TabOrder = 8
  end
  object Edit2: TEdit
    Left = 232
    Top = 88
    Width = 121
    Height = 21
    TabOrder = 9
  end
  object Edit3: TEdit
    Left = 232
    Top = 128
    Width = 121
    Height = 21
    TabOrder = 10
    OnKeyPress = Edit3KeyPress
  end
  object Edit4: TEdit
    Left = 232
    Top = 168
    Width = 121
    Height = 21
    TabOrder = 11
    OnKeyPress = Edit4KeyPress
  end
  object OpenDialog1: TOpenDialog
    Left = 424
    Top = 136
  end
end
