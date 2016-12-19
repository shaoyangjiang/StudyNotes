object fmUpdateProp: TfmUpdateProp
  Left = 330
  Top = 171
  BorderStyle = bsNone
  Caption = #26356#26032#25152#26377#26435#20449#24687
  ClientHeight = 364
  ClientWidth = 641
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
    Width = 641
    Height = 281
    Align = alTop
    TabOrder = 0
    object Label11: TLabel
      Left = 24
      Top = 72
      Width = 73
      Height = 13
      AutoSize = False
      Caption = #25152' '#26377' '#26435' '#20154
    end
    object Label14: TLabel
      Left = 19
      Top = 108
      Width = 70
      Height = 13
      AutoSize = False
      Caption = #25151' '#23627' '#22352' '#33853
    end
    object Label15: TLabel
      Left = 460
      Top = 108
      Width = 27
      Height = 13
      AutoSize = False
      Caption = #22320' '#21495
    end
    object Label22: TLabel
      Left = 72
      Top = 142
      Width = 12
      Height = 13
      AutoSize = False
      Caption = #38468
    end
    object Label23: TLabel
      Left = 72
      Top = 158
      Width = 12
      Height = 13
      AutoSize = False
      Caption = #35760
    end
    object Label60: TLabel
      Left = 22
      Top = 253
      Width = 59
      Height = 13
      AutoSize = False
      Caption = #22635#21457#26426#20851
    end
    object Label20: TLabel
      Left = 26
      Top = 213
      Width = 55
      Height = 13
      AutoSize = False
      Caption = #32558' '#35777' '#20154
    end
    object Label21: TLabel
      Left = 313
      Top = 213
      Width = 56
      Height = 13
      AutoSize = False
      Caption = #26657' '#23545' '#20154
    end
    object edtOwner: TEdit
      Left = 106
      Top = 67
      Width = 463
      Height = 19
      Ctl3D = False
      ParentCtl3D = False
      TabOrder = 1
    end
    object edtPosition: TEdit
      Left = 104
      Top = 104
      Width = 345
      Height = 19
      Ctl3D = False
      ParentCtl3D = False
      TabOrder = 2
    end
    object edtGround_No: TEdit
      Left = 504
      Top = 104
      Width = 67
      Height = 19
      Ctl3D = False
      ParentCtl3D = False
      TabOrder = 3
    end
    object memRemark: TMemo
      Left = 101
      Top = 135
      Width = 471
      Height = 55
      Ctl3D = False
      MaxLength = 50
      ParentCtl3D = False
      TabOrder = 4
    end
    object panPaperNo: TPanel
      Left = 1
      Top = 1
      Width = 639
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
    object cmbManageUnit: TComboBox
      Left = 98
      Top = 249
      Width = 169
      Height = 21
      BevelKind = bkFlat
      Ctl3D = False
      ItemHeight = 13
      ParentCtl3D = False
      TabOrder = 7
      OnKeyPress = cmbManageUnitKeyPress
    end
    object cmbMaker: TComboBox
      Left = 100
      Top = 204
      Width = 169
      Height = 21
      BevelKind = bkFlat
      Ctl3D = False
      ItemHeight = 13
      ParentCtl3D = False
      TabOrder = 5
      OnKeyPress = cmbMakerKeyPress
    end
    object cmbChecker: TComboBox
      Left = 375
      Top = 204
      Width = 194
      Height = 21
      BevelKind = bkFlat
      Ctl3D = False
      ItemHeight = 13
      ParentCtl3D = False
      TabOrder = 6
      OnKeyPress = cmbCheckerKeyPress
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 281
    Width = 641
    Height = 83
    Align = alClient
    TabOrder = 1
    object BitBtn1: TBitBtn
      Left = 112
      Top = 40
      Width = 153
      Height = 33
      TabOrder = 0
      OnClick = BitBtn1Click
      Kind = bkOK
    end
    object BitBtn2: TBitBtn
      Left = 344
      Top = 40
      Width = 177
      Height = 33
      TabOrder = 1
      Kind = bkCancel
    end
  end
end
