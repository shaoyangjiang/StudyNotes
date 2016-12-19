object AlterUserNameForm: TAlterUserNameForm
  Left = 295
  Top = 175
  Width = 553
  Height = 457
  Caption = #26356#25913#30331#24405#29992#25143#21517#21644#23494#30721
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
  object Label6: TLabel
    Left = 56
    Top = 344
    Width = 201
    Height = 17
    AutoSize = False
    Caption = #27880#65306#23398#29983#21487#20197#21516#26102#20462#25913#29992#25143#21517#21644#23494
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label7: TLabel
    Left = 79
    Top = 364
    Width = 297
    Height = 17
    AutoSize = False
    Caption = #35835#20070#39302#24037#20316#20154#21592#21482#33021#20462#25913#23494#30721#65288#29992#25143#21517#19982#32534#21495#30456#21516#65289
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label8: TLabel
    Left = 78
    Top = 384
    Width = 193
    Height = 17
    AutoSize = False
    Caption = #19981#25552#20379#31995#32479#31649#29702#21592#24080#21495#30340#20462#25913#21151#33021
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object GroupBox1: TGroupBox
    Left = 64
    Top = 16
    Width = 425
    Height = 105
    TabOrder = 0
    object Label1: TLabel
      Left = 86
      Top = 27
      Width = 105
      Height = 25
      AutoSize = False
      Caption = #21407#26469#29992#25143#21517#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 103
      Top = 67
      Width = 105
      Height = 25
      AutoSize = False
      Caption = #21407#26469#23494#30721#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object OldUserNameEdit: TEdit
      Left = 191
      Top = 24
      Width = 121
      Height = 19
      Ctl3D = False
      ParentCtl3D = False
      TabOrder = 0
    end
    object OldPassEdit: TEdit
      Left = 191
      Top = 68
      Width = 121
      Height = 19
      Ctl3D = False
      ParentCtl3D = False
      PasswordChar = '*'
      TabOrder = 1
    end
  end
  object GroupBox2: TGroupBox
    Left = 64
    Top = 125
    Width = 425
    Height = 140
    TabOrder = 1
    object Label3: TLabel
      Left = 105
      Top = 23
      Width = 105
      Height = 25
      AutoSize = False
      Caption = #26032#29992#25143#21517#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 119
      Top = 63
      Width = 105
      Height = 25
      AutoSize = False
      Caption = #26032#23494#30721#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 88
      Top = 102
      Width = 120
      Height = 25
      AutoSize = False
      Caption = #30830#35748#26032#23494#30721#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object NewUserNameEdit: TEdit
      Left = 191
      Top = 21
      Width = 121
      Height = 19
      Ctl3D = False
      ParentCtl3D = False
      TabOrder = 0
    end
    object NewPassEdit: TEdit
      Left = 191
      Top = 61
      Width = 121
      Height = 19
      Ctl3D = False
      ParentCtl3D = False
      PasswordChar = '*'
      TabOrder = 1
    end
    object ReNewPassEdit: TEdit
      Left = 191
      Top = 101
      Width = 121
      Height = 19
      Ctl3D = False
      ParentCtl3D = False
      PasswordChar = '*'
      TabOrder = 2
    end
  end
  object ConfirBtn: TBitBtn
    Left = 160
    Top = 297
    Width = 75
    Height = 25
    Caption = ' '#30830'  '#35748' '
    Default = True
    TabOrder = 2
    OnClick = ConfirBtnClick
    Glyph.Data = {
      DE010000424DDE01000000000000760000002800000024000000120000000100
      0400000000006801000000000000000000001000000000000000000000000000
      80000080000000808000800000008000800080800000C0C0C000808080000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
      3333333333333333333333330000333333333333333333333333F33333333333
      00003333344333333333333333388F3333333333000033334224333333333333
      338338F3333333330000333422224333333333333833338F3333333300003342
      222224333333333383333338F3333333000034222A22224333333338F338F333
      8F33333300003222A3A2224333333338F3838F338F33333300003A2A333A2224
      33333338F83338F338F33333000033A33333A222433333338333338F338F3333
      0000333333333A222433333333333338F338F33300003333333333A222433333
      333333338F338F33000033333333333A222433333333333338F338F300003333
      33333333A222433333333333338F338F00003333333333333A22433333333333
      3338F38F000033333333333333A223333333333333338F830000333333333333
      333A333333333333333338330000333333333333333333333333333333333333
      0000}
    NumGlyphs = 2
  end
  object RetryBtn: TBitBtn
    Left = 328
    Top = 296
    Width = 75
    Height = 25
    Caption = ' '#37325'  '#32622
    TabOrder = 3
    OnClick = RetryBtnClick
    Glyph.Data = {
      DE010000424DDE01000000000000760000002800000024000000120000000100
      0400000000006801000000000000000000001000000000000000000000000000
      80000080000000808000800000008000800080800000C0C0C000808080000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333444444
      33333333333F8888883F33330000324334222222443333388F3833333388F333
      000032244222222222433338F8833FFFFF338F3300003222222AAAAA22243338
      F333F88888F338F30000322222A33333A2224338F33F8333338F338F00003222
      223333333A224338F33833333338F38F00003222222333333A444338FFFF8F33
      3338888300003AAAAAAA33333333333888888833333333330000333333333333
      333333333333333333FFFFFF000033333333333344444433FFFF333333888888
      00003A444333333A22222438888F333338F3333800003A2243333333A2222438
      F38F333333833338000033A224333334422224338338FFFFF8833338000033A2
      22444442222224338F3388888333FF380000333A2222222222AA243338FF3333
      33FF88F800003333AA222222AA33A3333388FFFFFF8833830000333333AAAAAA
      3333333333338888883333330000333333333333333333333333333333333333
      0000}
    NumGlyphs = 2
  end
  object ConfirQuery: TQuery
    DatabaseName = 'MyCBuilderOdbc'
    SQL.Strings = (
      '')
    Left = 440
    Top = 40
  end
end
