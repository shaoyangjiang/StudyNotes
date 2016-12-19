object fmInitFileNo: TfmInitFileNo
  Left = 249
  Top = 188
  BorderStyle = bsNone
  Caption = #25151#20135#35777#21495#32500#25252#31383#20307
  ClientHeight = 184
  ClientWidth = 581
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 581
    Height = 184
    Align = alClient
    Color = clSilver
    TabOrder = 0
    object Label1: TLabel
      Left = 8
      Top = 36
      Width = 57
      Height = 13
      AutoSize = False
      Caption = #21021#22987#21495#30721
    end
    object Label2: TLabel
      Left = 8
      Top = 99
      Width = 57
      Height = 13
      AutoSize = False
      Caption = #21495#30721#38271#24230
    end
    object edtFileNo: TEdit
      Left = 80
      Top = 36
      Width = 177
      Height = 21
      MaxLength = 10
      TabOrder = 1
      OnKeyPress = edtFileNoKeyPress
    end
    object edtFileLength: TEdit
      Left = 80
      Top = 91
      Width = 177
      Height = 21
      TabOrder = 2
      OnKeyPress = edtFileLengthKeyPress
    end
    object btnYes: TButton
      Left = 48
      Top = 139
      Width = 81
      Height = 25
      Caption = #30830#23450
      TabOrder = 3
      OnClick = btnYesClick
    end
    object btnNo: TButton
      Left = 168
      Top = 139
      Width = 81
      Height = 25
      Caption = #21462#28040
      TabOrder = 4
      OnClick = btnNoClick
    end
    object GroupBox1: TGroupBox
      Left = 304
      Top = 1
      Width = 276
      Height = 182
      Align = alRight
      TabOrder = 0
      object Label4: TLabel
        Left = 9
        Top = 16
        Width = 36
        Height = 13
        Caption = #35828#26126#65306
      end
      object Label6: TLabel
        Left = 17
        Top = 35
        Width = 224
        Height = 118
        AutoSize = False
        Caption = 
          '    '#24405#20837#31995#32479#20869#30340#25151#23627#25152#26377#26435#35777#21495#20250#20197#21021#22987#21495#30721#20026#22522#25968#33258#21160#22686#21152'1'#36827#34892#32534#21495', '#20363#22914#21021#22987#21495#30721#20026'"00",'#24405#20837#31995#32479#30340#31532#19968#26465#25151#23627#25152#26377#26435#35777#21495 +
          #23601#20250#32534#21495#20026'"01".'#13#10'    '#21495#30721#38271#24230#23601#26159#32534#21495#30340#26368#22823#38271#24230'.'#13#10
        Font.Charset = GB2312_CHARSET
        Font.Color = clWindowText
        Font.Height = -14
        Font.Name = #21326#25991#20013#23435
        Font.Style = []
        ParentFont = False
        WordWrap = True
      end
    end
  end
end
