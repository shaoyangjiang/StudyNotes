object Form1: TForm1
  Left = 887
  Top = 137
  Width = 430
  Height = 326
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object DBGrid1: TDBGrid
    Left = 0
    Top = 0
    Width = 422
    Height = 271
    Align = alClient
    DataSource = DataSource1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
  object TabSet1: TTabSet
    Left = 0
    Top = 271
    Width = 422
    Height = 21
    Align = alBottom
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Tabs.Strings = (
      'A'
      'B'
      'C'
      'D'
      'E'
      'F'
      'G'
      'H'
      'I'
      'J'
      'K'
      'L'
      'M'
      'N'
      'O'
      'P'
      'Q'
      'I'
      'S'
      'T'
      'U'
      'V'
      'W'
      'X'
      'Y'
      'Z')
    TabIndex = 0
    OnChange = TabSet1Change
  end
  object Query1: TQuery
    DatabaseName = 'BCDEMOS'
    SQL.Strings = (
      'Select * from Country where Name like : NameStr')
    Left = 32
    Top = 64
    ParamData = <
      item
        DataType = ftString
        Name = 'TheArea'
        ParamType = ptUnknown
      end>
  end
  object DataSource1: TDataSource
    DataSet = Query1
    Left = 32
    Top = 120
  end
end
