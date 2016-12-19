object Form1: TForm1
  Left = 848
  Top = 100
  Width = 532
  Height = 465
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
  object Shape1: TShape
    Left = 160
    Top = 56
    Width = 153
    Height = 73
    Brush.Color = clAqua
    Pen.Color = clTeal
  end
  object GroupBox1: TGroupBox
    Left = 112
    Top = 184
    Width = 249
    Height = 153
    Caption = #24418#29366#30340#22806#35266
    TabOrder = 0
    object RadioButton1: TRadioButton
      Left = 8
      Top = 32
      Width = 113
      Height = 17
      Caption = #22278#24418
      TabOrder = 0
      OnClick = RadioButton1Click
    end
    object RadioButton2: TRadioButton
      Left = 8
      Top = 64
      Width = 113
      Height = 17
      Caption = #26925#22278#24418
      TabOrder = 1
      OnClick = RadioButton2Click
    end
    object RadioButton3: TRadioButton
      Left = 8
      Top = 96
      Width = 113
      Height = 17
      Caption = #30697#24418
      TabOrder = 2
      OnClick = RadioButton3Click
    end
    object RadioButton4: TRadioButton
      Left = 144
      Top = 32
      Width = 113
      Height = 17
      Caption = #22278#35282#30697#24418
      TabOrder = 3
      OnClick = RadioButton4Click
    end
    object RadioButton5: TRadioButton
      Left = 144
      Top = 64
      Width = 113
      Height = 17
      Caption = #22278#35282#27491#26041#24418
      TabOrder = 4
      OnClick = RadioButton5Click
    end
    object RadioButton6: TRadioButton
      Left = 144
      Top = 96
      Width = 113
      Height = 17
      Caption = #27491#26041#24418
      TabOrder = 5
      OnClick = RadioButton6Click
    end
  end
end
