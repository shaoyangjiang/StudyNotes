object Form1: TForm1
  Left = 338
  Top = 132
  Width = 396
  Height = 397
  Caption = 'RichEdit'#32452#20214
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object SpeedButton1: TSpeedButton
    Left = 277
    Top = 8
    Width = 23
    Height = 22
    Caption = 'B'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNone
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Pitch = fpVariable
    Font.Style = [fsBold]
    ParentFont = False
    OnClick = SpeedButton1Click
  end
  object SpeedButton2: TSpeedButton
    Left = 300
    Top = 8
    Width = 23
    Height = 22
    Caption = 'I'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Pitch = fpVariable
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    OnClick = SpeedButton2Click
  end
  object SpeedButton3: TSpeedButton
    Left = 323
    Top = 8
    Width = 23
    Height = 22
    Caption = 'U'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Pitch = fpVariable
    Font.Style = [fsBold, fsUnderline]
    ParentFont = False
    OnClick = SpeedButton3Click
  end
  object RichEdit1: TRichEdit
    Left = 8
    Top = 40
    Width = 249
    Height = 313
    Font.Charset = GB2312_CHARSET
    Font.Color = clBlack
    Font.Height = -16
    Font.Name = #23435#20307
    Font.Style = []
    HideSelection = False
    Lines.Strings = (
      #36171#24471#21476#21407#33609#36865#21035
      '    '#8212#8212#30333#23621#26131
      #31163#31163#21407#19978#33609#65292
      #19968#23681#19968#26543#33635#12290
      #37326#28779#28903#19981#23613#65292
      #26149#39118#21561#21448#29983#12290
      #36828#33459#20405#21476#36947#65292
      #26228#32736#25509#33618#22478#12290
      #21448#36865#29579#23385#21435#65292
      #33803#33803#28385#21035#24773#12290)
    ParentFont = False
    TabOrder = 0
    OnMouseUp = RichEdit1MouseUp
  end
  object GroupBox1: TGroupBox
    Left = 272
    Top = 40
    Width = 105
    Height = 113
    Caption = #23383#20307
    TabOrder = 1
    object RadioButton1: TRadioButton
      Left = 8
      Top = 16
      Width = 73
      Height = 17
      Caption = #23435#20307
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      TabStop = True
      OnClick = RadioButton1Click
    end
    object RadioButton2: TRadioButton
      Left = 9
      Top = 40
      Width = 72
      Height = 17
      Caption = #26999#20307
      TabOrder = 1
      OnClick = RadioButton2Click
    end
    object RadioButton3: TRadioButton
      Left = 9
      Top = 66
      Width = 80
      Height = 17
      Caption = #21326#25991#24425#20113
      TabOrder = 2
      OnClick = RadioButton3Click
    end
    object RadioButton4: TRadioButton
      Left = 10
      Top = 90
      Width = 71
      Height = 17
      Caption = #38582#20070
      TabOrder = 3
      OnClick = RadioButton4Click
    end
  end
  object GroupBox2: TGroupBox
    Left = 272
    Top = 160
    Width = 105
    Height = 113
    Caption = #39068#33394
    TabOrder = 2
    object RadioButton5: TRadioButton
      Left = 8
      Top = 16
      Width = 73
      Height = 17
      Caption = #40657#33394
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = RadioButton5Click
    end
    object RadioButton6: TRadioButton
      Left = 9
      Top = 40
      Width = 72
      Height = 17
      Caption = #32418#33394
      TabOrder = 1
      OnClick = RadioButton6Click
    end
    object RadioButton7: TRadioButton
      Left = 9
      Top = 66
      Width = 80
      Height = 17
      Caption = #32511#33394
      TabOrder = 2
      OnClick = RadioButton7Click
    end
    object RadioButton8: TRadioButton
      Left = 10
      Top = 90
      Width = 71
      Height = 17
      Caption = #34013#33394
      TabOrder = 3
      OnClick = RadioButton8Click
    end
  end
  object GroupBox3: TGroupBox
    Left = 272
    Top = 280
    Width = 105
    Height = 73
    Caption = #23383#21495
    TabOrder = 3
    object RadioButton9: TRadioButton
      Left = 8
      Top = 24
      Width = 57
      Height = 17
      Caption = '12'#21495
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = RadioButton9Click
    end
    object RadioButton10: TRadioButton
      Left = 8
      Top = 48
      Width = 65
      Height = 17
      Caption = '18'#21495
      TabOrder = 1
      OnClick = RadioButton10Click
    end
  end
end
