object fmUpDateGroundProp: TfmUpDateGroundProp
  Left = 231
  Top = 166
  BorderStyle = bsNone
  Caption = #26356#26032#22303#22320#38754#31215#20449#24687
  ClientHeight = 244
  ClientWidth = 569
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 569
    Height = 244
    Align = alClient
    TabOrder = 0
    object Panel2: TPanel
      Left = 1
      Top = 33
      Width = 567
      Height = 143
      Align = alClient
      TabOrder = 1
      object Label49: TLabel
        Left = 8
        Top = 50
        Width = 89
        Height = 13
        AutoSize = False
        Caption = #20351#29992#22303#22320#38754#31215
      end
      object Label50: TLabel
        Left = 168
        Top = 50
        Width = 65
        Height = 13
        AutoSize = False
        Caption = #24179#26041#31859#21512
      end
      object Label52: TLabel
        Left = 339
        Top = 42
        Width = 46
        Height = 13
        AutoSize = False
        Caption = #22303#22320#20351
      end
      object Label53: TLabel
        Left = 340
        Top = 58
        Width = 49
        Height = 13
        AutoSize = False
        Caption = #29992#35777#21495
      end
      object Label54: TLabel
        Left = 449
        Top = 50
        Width = 32
        Height = 13
        AutoSize = False
        Caption = #23383#31532
      end
      object Label55: TLabel
        Left = 529
        Top = 50
        Width = 12
        Height = 13
        AutoSize = False
        Caption = #21495
      end
      object Label56: TLabel
        Left = 8
        Top = 116
        Width = 57
        Height = 13
        Caption = #22635' '#21457' '#26085' '#26399
      end
      object edtUsedAreaM2: TEdit
        Left = 104
        Top = 43
        Width = 57
        Height = 19
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 0
      end
      object edtUsedArea: TEdit
        Left = 240
        Top = 43
        Width = 73
        Height = 19
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 1
      end
      object edtFile: TEdit
        Left = 405
        Top = 43
        Width = 41
        Height = 19
        Color = clBtnFace
        Ctl3D = False
        ParentCtl3D = False
        ReadOnly = True
        TabOrder = 2
        Text = #26690#25151#35777
      end
      object edtFileNo: TEdit
        Left = 482
        Top = 43
        Width = 41
        Height = 19
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 3
      end
      object dataSendOutDate: TDateTimePicker
        Left = 96
        Top = 108
        Width = 147
        Height = 21
        BevelOuter = bvNone
        BevelKind = bkFlat
        CalAlignment = dtaLeft
        Date = 38505.9478405208
        Time = 38505.9478405208
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkDate
        ParseInput = False
        TabOrder = 4
      end
    end
    object panPaperNo: TPanel
      Left = 1
      Top = 1
      Width = 567
      Height = 32
      Align = alTop
      Caption = #26690#25151#35777#23383#31532#65306
      Color = clBlue
      Font.Charset = GB2312_CHARSET
      Font.Color = clWhite
      Font.Height = -16
      Font.Name = #23435#20307
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
    end
    object Panel3: TPanel
      Left = 1
      Top = 176
      Width = 567
      Height = 67
      Align = alBottom
      TabOrder = 2
      object BitBtn1: TBitBtn
        Left = 104
        Top = 32
        Width = 121
        Height = 33
        TabOrder = 0
        OnClick = BitBtn1Click
        Kind = bkOK
      end
      object BitBtn2: TBitBtn
        Left = 320
        Top = 24
        Width = 121
        Height = 33
        TabOrder = 1
        Kind = bkCancel
      end
    end
  end
end
