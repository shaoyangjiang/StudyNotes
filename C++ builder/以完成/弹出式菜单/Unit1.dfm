object Form1: TForm1
  Left = 982
  Top = 114
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Form1'
  ClientHeight = 409
  ClientWidth = 420
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 136
    Top = 104
    Width = 57
    Height = 13
    Caption = #36816#31639#25968#19968'   '
  end
  object Label2: TLabel
    Left = 136
    Top = 152
    Width = 60
    Height = 13
    Caption = #36816#31639#25968#20108'    '
  end
  object Label3: TLabel
    Left = 136
    Top = 208
    Width = 54
    Height = 13
    Caption = #35745#31639#32467#26524'  '
  end
  object Edit1: TEdit
    Left = 224
    Top = 104
    Width = 121
    Height = 21
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 224
    Top = 152
    Width = 121
    Height = 21
    TabOrder = 1
  end
  object Edit3: TEdit
    Left = 224
    Top = 200
    Width = 121
    Height = 21
    TabOrder = 2
  end
  object PopupMenu1: TPopupMenu
    OnPopup = PopupMenu1Popup
    Left = 16
    Top = 48
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
end
