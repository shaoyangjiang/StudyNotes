object Form1: TForm1
  Left = 899
  Top = 119
  Width = 403
  Height = 289
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClick = FormClick
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 120
    Top = 200
    Width = 189
    Height = 13
    Caption = '                                                               '
  end
  object Panel1: TPanel
    Left = 16
    Top = 16
    Width = 185
    Height = 153
    BevelInner = bvRaised
    Caption = 'Panel1'
    TabOrder = 0
    object RadioButton1: TRadioButton
      Left = 32
      Top = 24
      Width = 113
      Height = 17
      Caption = 'Dos'
      TabOrder = 0
      OnClick = RadioButton1Click
    end
    object RadioButton2: TRadioButton
      Left = 32
      Top = 64
      Width = 113
      Height = 17
      Caption = 'Windows'
      TabOrder = 1
      OnClick = RadioButton2Click
    end
    object RadioButton3: TRadioButton
      Left = 32
      Top = 112
      Width = 113
      Height = 17
      Caption = 'Linux'
      TabOrder = 2
      OnClick = RadioButton3Click
    end
  end
  object Panel2: TPanel
    Left = 200
    Top = 16
    Width = 185
    Height = 153
    BevelInner = bvRaised
    Caption = 'Panel2'
    TabOrder = 1
    object RadioButton4: TRadioButton
      Left = 40
      Top = 24
      Width = 113
      Height = 17
      Caption = #33521#25991
      TabOrder = 0
      OnClick = RadioButton4Click
    end
    object RadioButton5: TRadioButton
      Left = 40
      Top = 64
      Width = 113
      Height = 17
      Caption = #20013#25991
      TabOrder = 1
      OnClick = RadioButton5Click
    end
    object RadioButton6: TRadioButton
      Left = 40
      Top = 112
      Width = 113
      Height = 17
      Caption = #26085#25991
      TabOrder = 2
      OnClick = RadioButton6Click
    end
  end
end
