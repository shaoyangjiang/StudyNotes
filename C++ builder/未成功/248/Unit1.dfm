object Form1: TForm1
  Left = 723
  Top = 117
  Width = 623
  Height = 375
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
    Left = 192
    Top = 80
    Width = 320
    Height = 120
    DataSource = DataSource1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
  object Button1: TButton
    Left = 272
    Top = 304
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Table1: TTable
    Active = True
    DatabaseName = 'BCDEMOS'
    TableName = 'COUNTRY.DB'
    Left = 104
    Top = 152
    object Table1Name: TStringField
      FieldName = 'Name'
      Size = 24
    end
    object Table1Capital: TStringField
      FieldName = 'Capital'
      Size = 24
    end
    object Table1Continent: TStringField
      FieldName = 'Continent'
      Size = 24
    end
    object Table1Area: TFloatField
      FieldName = 'Area'
    end
    object Table1Population: TFloatField
      FieldName = 'Population'
    end
  end
  object DataSource1: TDataSource
    DataSet = Table1
    Left = 96
    Top = 72
  end
end
