object Form1: TForm1
  Left = 849
  Top = 113
  Width = 515
  Height = 349
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 507
    Height = 249
    Align = alTop
    TabOrder = 0
    object Label1: TLabel
      Left = 48
      Top = 48
      Width = 33
      Height = 13
      Caption = #23398#21495'   '
    end
    object Label2: TLabel
      Left = 48
      Top = 104
      Width = 36
      Height = 13
      Caption = #21517#26063'    '
    end
    object Label3: TLabel
      Left = 48
      Top = 168
      Width = 60
      Height = 13
      Caption = #20986#29983#26085#26399'    '
    end
    object Label4: TLabel
      Left = 320
      Top = 40
      Width = 39
      Height = 13
      Caption = #22995#21517'     '
    end
    object Label5: TLabel
      Left = 320
      Top = 112
      Width = 33
      Height = 13
      Caption = #24615#21035'   '
    end
    object Label6: TLabel
      Left = 320
      Top = 176
      Width = 36
      Height = 13
      Caption = #29677#21495'    '
    end
    object Edit1: TEdit
      Left = 104
      Top = 48
      Width = 121
      Height = 21
      TabOrder = 0
    end
    object Edit2: TEdit
      Left = 368
      Top = 40
      Width = 121
      Height = 21
      TabOrder = 1
    end
    object Edit3: TEdit
      Left = 120
      Top = 160
      Width = 121
      Height = 21
      ImeName = #20013#25991' - QQ'#25340#38899#36755#20837#27861
      TabOrder = 2
    end
    object Edit4: TEdit
      Left = 368
      Top = 176
      Width = 121
      Height = 21
      TabOrder = 3
    end
    object RadioButton1: TRadioButton
      Left = 368
      Top = 112
      Width = 73
      Height = 17
      Caption = #30007'  '
      TabOrder = 4
    end
    object RadioButton2: TRadioButton
      Left = 416
      Top = 112
      Width = 73
      Height = 17
      Caption = #22899'  '
      TabOrder = 5
    end
    object ComboBox1: TComboBox
      Left = 112
      Top = 104
      Width = 105
      Height = 21
      ItemHeight = 13
      TabOrder = 6
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 249
    Width = 507
    Height = 66
    Align = alClient
    TabOrder = 1
    object First: TButton
      Left = 16
      Top = 24
      Width = 49
      Height = 25
      Caption = '| <----'
      TabOrder = 0
      OnClick = FirstClick
    end
    object Prior: TButton
      Left = 88
      Top = 24
      Width = 41
      Height = 25
      Caption = '<----'
      TabOrder = 1
      OnClick = PriorClick
    end
    object Next: TButton
      Left = 152
      Top = 24
      Width = 49
      Height = 25
      Caption = '---->'
      TabOrder = 2
      OnClick = NextClick
    end
    object Last: TButton
      Left = 224
      Top = 24
      Width = 49
      Height = 25
      Caption = '---->|'
      TabOrder = 3
      OnClick = LastClick
    end
    object Add: TButton
      Left = 304
      Top = 24
      Width = 41
      Height = 25
      Caption = #22686#21152'  '
      TabOrder = 4
      OnClick = AddClick
    end
    object Edit: TButton
      Left = 360
      Top = 24
      Width = 57
      Height = 25
      Caption = #20462#25913'  '
      TabOrder = 5
      OnClick = EditClick
    end
    object Delete: TButton
      Left = 440
      Top = 24
      Width = 49
      Height = 25
      Caption = #21024#38500'   '
      TabOrder = 6
      OnClick = DeleteClick
    end
  end
end
