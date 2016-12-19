object Form1: TForm1
  Left = 268
  Top = 209
  Width = 491
  Height = 327
  Caption = #33756#21333#30340#20351#29992
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object RichEdit1: TRichEdit
    Left = 0
    Top = 0
    Width = 483
    Height = 273
    Align = alClient
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Lines.Strings = (
      'RichEdit1')
    ParentFont = False
    TabOrder = 0
  end
  object MainMenu1: TMainMenu
    Left = 40
    Top = 48
    object NFile: TMenuItem
      Caption = '&File'
      object Nnew: TMenuItem
        Caption = 'New'
      end
      object NOpen: TMenuItem
        Caption = 'Open'
        OnClick = NOpenClick
      end
      object NSave: TMenuItem
        Caption = 'Save'
      end
      object open1: TMenuItem
        Caption = '-'
      end
      object NExit: TMenuItem
        Caption = '&Exit'
      end
    end
    object Edit1: TMenuItem
      Caption = 'Edit'
    end
  end
  object OpenDialog1: TOpenDialog
    Filter = #25171#24320#25991#26412#25991#20214'(*.txt)|*.txt'
    Left = 136
    Top = 56
  end
end
