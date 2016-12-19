object fmUpdateTax: TfmUpdateTax
  Left = 233
  Top = 190
  BorderStyle = bsNone
  Caption = #26356#26032#22865#31246#25688#35201
  ClientHeight = 294
  ClientWidth = 547
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 547
    Height = 294
    Align = alClient
    TabOrder = 0
    object panPaperNo: TPanel
      Left = 1
      Top = 1
      Width = 545
      Height = 41
      Align = alTop
      Caption = #26690#25151#35777#23383#31532#65306
      Color = clBlue
      Font.Charset = ANSI_CHARSET
      Font.Color = clWhite
      Font.Height = -16
      Font.Name = #23435#20307
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
    end
    object Panel3: TPanel
      Left = 1
      Top = 42
      Width = 545
      Height = 183
      Align = alTop
      TabOrder = 1
      object Label3: TLabel
        Left = 20
        Top = 59
        Width = 61
        Height = 13
        AutoSize = False
        Caption = #31435#22865#26085#26399
      end
      object Label4: TLabel
        Left = 208
        Top = 59
        Width = 33
        Height = 13
        AutoSize = False
        Caption = #22865'  '#20215
      end
      object Label5: TLabel
        Left = 328
        Top = 59
        Width = 73
        Height = 13
        AutoSize = False
        Caption = #22865' '#31246' '#31181' '#31867
      end
      object Label6: TLabel
        Left = 12
        Top = 99
        Width = 69
        Height = 13
        AutoSize = False
        Caption = #22865' '#31246' '#31246' '#29575
      end
      object Label8: TLabel
        Left = 176
        Top = 93
        Width = 65
        Height = 13
        AutoSize = False
        Caption = #32435' '#31246' '#37329' '#39069
      end
      object Label24: TLabel
        Left = 44
        Top = 139
        Width = 27
        Height = 13
        AutoSize = False
        Caption = #22791' '#27880
      end
      object Label2: TLabel
        Left = 172
        Top = 15
        Width = 185
        Height = 16
        Caption = #22865'    '#31246'     '#25688'    '#35201
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #23435#20307
        Font.Style = [fsBold]
        ParentFont = False
      end
      object dataStartData: TDateTimePicker
        Left = 83
        Top = 51
        Width = 89
        Height = 20
        BevelOuter = bvNone
        BevelKind = bkFlat
        CalAlignment = dtaLeft
        Date = 38505.9478405208
        Time = 38505.9478405208
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkDate
        ParseInput = False
        TabOrder = 1
      end
      object EdtPrice: TEdit
        Left = 248
        Top = 52
        Width = 73
        Height = 19
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 2
      end
      object cmbTaxType: TComboBox
        Left = 407
        Top = 50
        Width = 74
        Height = 21
        BevelKind = bkFlat
        Ctl3D = False
        ItemHeight = 13
        ParentCtl3D = False
        TabOrder = 0
        OnKeyPress = cmbTaxTypeKeyPress
      end
      object cmbTaxRace: TComboBox
        Left = 82
        Top = 90
        Width = 90
        Height = 21
        BevelKind = bkFlat
        Ctl3D = False
        ItemHeight = 13
        ParentCtl3D = False
        TabOrder = 4
        OnKeyPress = cmbTaxRaceKeyPress
      end
      object edtTax: TEdit
        Left = 248
        Top = 89
        Width = 73
        Height = 19
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 3
      end
      object edtNote: TEdit
        Left = 80
        Top = 136
        Width = 401
        Height = 19
        Ctl3D = False
        MaxLength = 50
        ParentCtl3D = False
        TabOrder = 5
      end
    end
    object Panel4: TPanel
      Left = 1
      Top = 225
      Width = 545
      Height = 68
      Align = alClient
      TabOrder = 2
      object BitBtn1: TBitBtn
        Left = 128
        Top = 16
        Width = 97
        Height = 33
        TabOrder = 0
        OnClick = BitBtn1Click
        Kind = bkOK
      end
      object BitBtn2: TBitBtn
        Left = 312
        Top = 16
        Width = 105
        Height = 33
        TabOrder = 1
        Kind = bkCancel
      end
    end
  end
end
