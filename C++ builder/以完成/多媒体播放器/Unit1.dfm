object Form1: TForm1
  Left = 758
  Top = 108
  Width = 539
  Height = 451
  Caption = #37045#27915#27743#25773#25918#22120
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object PanelAVI: TPanel
    Left = 0
    Top = 336
    Width = 569
    Height = 41
    Caption = 'PanelAVI'
    TabOrder = 0
    object mprMain: TMediaPlayer
      Left = 120
      Top = 8
      Width = 253
      Height = 30
      TabOrder = 0
    end
  end
  object Display: TPanel
    Left = 0
    Top = 0
    Width = 569
    Height = 337
    Align = alTop
    Caption = 'Display'
    Color = clBtnText
    TabOrder = 1
  end
  object MainMenu1: TMainMenu
    Left = 224
    Top = 32
    object N1: TMenuItem
      Caption = #25991#20214
      object miFileOpen: TMenuItem
        Caption = #25171#24320
        OnClick = miFileOpenClick
      end
      object miFileClose: TMenuItem
        Caption = #20851#38381
      end
      object miFileEjectCD: TMenuItem
        Caption = #24377#20986'CD'
        OnClick = miFileEjectCDClick
      end
      object miFileExit: TMenuItem
        Caption = #36864#20986
        OnClick = miFileExitClick
      end
    end
    object N6: TMenuItem
      Caption = #21151#33021
      object miFunctionCD: TMenuItem
        Caption = #25773#25918'CD'
        OnClick = miFunctionCDClick
      end
      object miFunctionAVI: TMenuItem
        Caption = #25773#25918'AVI'
        OnClick = miFunctionAVIClick
      end
      object miFunctionmp3: TMenuItem
        Caption = #25773#25918'mp3'
        OnClick = miFunctionmp3Click
      end
      object miFunctionOthers: TMenuItem
        Caption = #20854#20182
        OnClick = miFunctionOthersClick
      end
    end
    object C1: TMenuItem
      Caption = #25511#21046
      object miControlPlay: TMenuItem
        Caption = #25773#25918'/'#32487#32493
        OnClick = miControlPlayClick
      end
      object miControlPause: TMenuItem
        Caption = #26242#20572
        OnClick = miControlPauseClick
      end
      object miControlStop: TMenuItem
        Caption = #20572#27490
        OnClick = miControlStopClick
      end
      object miControlStep: TMenuItem
        Caption = #24555#36827
        OnClick = miControlStepClick
      end
      object miControlBack: TMenuItem
        Caption = #21518#36864
        OnClick = miControlBackClick
      end
      object miControlHome: TMenuItem
        Caption = #22238#21040#39318
        OnClick = miControlHomeClick
      end
    end
    object H1: TMenuItem
      Caption = #24110#32452
      object miHelpAbout: TMenuItem
        Caption = #20851#20110
      end
    end
  end
  object OpenFile: TOpenDialog
    Left = 160
    Top = 24
  end
end
