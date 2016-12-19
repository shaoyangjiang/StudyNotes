object ParentForm: TParentForm
  Left = 314
  Top = 181
  Width = 634
  Height = 417
  Caption = #25105#30340'Word'#32534#36753#36719#20214
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIForm
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object MainMenu1: TMainMenu
    Left = 72
    Top = 48
    object NFile: TMenuItem
      Caption = #25991#20214'(&F)'
      object NNew: TMenuItem
        Caption = #26032#24314'(&N)...'
        OnClick = NNewClick
      end
      object NOpen: TMenuItem
        Caption = #25171#24320'(&O)...'
        Enabled = False
        ShortCut = 16463
      end
      object NClose: TMenuItem
        Caption = #20851#38381'(&C)...'
        Enabled = False
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object NSave: TMenuItem
        Caption = #20445#23384'(&S)'
        Enabled = False
        ShortCut = 16467
      end
      object NSaveas: TMenuItem
        Caption = #21478#23384#20026'(&A)...'
        Enabled = False
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object NExit: TMenuItem
        Caption = #36864#20986'(&X)'
        OnClick = NExitClick
      end
    end
    object NHelp: TMenuItem
      Caption = #24110#21161'(&H)'
      GroupIndex = 3
      object Word1: TMenuItem
        Caption = #20851#20110'"'#25105#30340'Word'#32534#36753#36719#20214'"'
        OnClick = Word1Click
      end
    end
  end
end
