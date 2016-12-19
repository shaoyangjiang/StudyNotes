object Form1: TForm1
  Left = 772
  Top = 110
  Width = 584
  Height = 439
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIForm
  Menu = MainMenu1
  OldCreateOrder = False
  WindowMenu = Window
  PixelsPerInch = 96
  TextHeight = 13
  object MainMenu1: TMainMenu
    Left = 32
    Top = 48
    object File: TMenuItem
      Caption = #25991#20214
      object New: TMenuItem
        Caption = #26032#24314
        OnClick = NewClick
      end
      object CLOSE: TMenuItem
        Caption = #20851#38381
        OnClick = CLOSEClick
      end
      object CloseAll: TMenuItem
        Caption = #20851#38381#25152#26377#23376#31383#21475'   '
        OnClick = CloseAllClick
      end
      object N1: TMenuItem
      end
      object Exit: TMenuItem
        Caption = #36864#20986
        OnClick = ExitClick
      end
    end
    object Window: TMenuItem
      Caption = #31383#21475
      object CASCADE: TMenuItem
        Caption = #23618#21472
        OnClick = CASCADEClick
      end
      object TILE: TMenuItem
        Caption = #24179#38138
        OnClick = TILEClick
      end
      object ARRANGEICONS: TMenuItem
        Caption = #25490#21015
        OnClick = ARRANGEICONSClick
      end
    end
  end
end
