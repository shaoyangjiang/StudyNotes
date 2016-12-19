object Form1: TForm1
  Left = 814
  Top = 112
  Width = 643
  Height = 459
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  HelpFile = 
    'D:\C++ builder\Borland_C++_Builder_V6.0_99D.COM\Borland C++ Buil' +
    'der V6.0'#20013#33521#25991#22823#20225#19994#29256'_99D.COM\BCB6EN\PROGRAM FILES\BORLAND\CBUILDER6\H' +
    'ELP\BCB6.HLP'
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object MainMenu1: TMainMenu
    Left = 48
    Top = 56
    object HELP: TMenuItem
      Caption = #24110#21161
      object CONTENT: TMenuItem
        Caption = #20869#23481
        OnClick = CONTENTClick
      end
      object INDEX: TMenuItem
        Caption = #32034#24341
        OnClick = INDEXClick
      end
      object HELPONHELP: TMenuItem
        Caption = #20056#27861
        OnClick = HELPONHELPClick
      end
    end
  end
end
