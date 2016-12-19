object Form1: TForm1
  Left = 954
  Top = 105
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Form1'
  ClientHeight = 324
  ClientWidth = 427
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
  object Label1: TLabel
    Left = 120
    Top = 88
    Width = 60
    Height = 13
    Caption = #36816#31639#25968#19968'    '
  end
  object Label2: TLabel
    Left = 120
    Top = 136
    Width = 60
    Height = 13
    Caption = #36816#31639#25968#20108'    '
  end
  object Label3: TLabel
    Left = 120
    Top = 200
    Width = 66
    Height = 13
    Caption = #36816#31639#25968#19977'      '
  end
  object Edit1: TEdit
    Left = 232
    Top = 88
    Width = 121
    Height = 21
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 232
    Top = 136
    Width = 121
    Height = 21
    TabOrder = 1
  end
  object Edit3: TEdit
    Left = 232
    Top = 192
    Width = 121
    Height = 21
    TabOrder = 2
  end
  object MainMenu1: TMainMenu
    Left = 8
    Top = 24
    object Oper: TMenuItem
      Caption = #36816#31639
      OnClick = OperClick
      object Add: TMenuItem
        Caption = #21152#27861
        OnClick = AddClick
      end
      object Sub: TMenuItem
        Caption = #20943#27861
        OnClick = SubClick
      end
      object Mul: TMenuItem
        Caption = #20056#27861
        OnClick = MulClick
      end
      object Div: TMenuItem
        Caption = #38500#27861
        OnClick = DivClick
      end
    end
    object Exit: TMenuItem
      Caption = #36864#20986
      OnClick = ExitClick
    end
  end
end
