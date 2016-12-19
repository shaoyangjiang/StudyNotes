object BookDelete: TBookDelete
  Left = 247
  Top = 190
  Width = 758
  Height = 362
  Caption = #26087#20070#28120#27760
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  PixelsPerInch = 96
  TextHeight = 13
  object DBGrid1: TDBGrid
    Left = 0
    Top = 0
    Width = 750
    Height = 249
    Align = alTop
    DataSource = DataSource1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
  object BitBtn1: TBitBtn
    Left = 640
    Top = 280
    Width = 75
    Height = 25
    Caption = #21024#38500
    TabOrder = 1
    OnClick = BitBtn1Click
    Kind = bkAbort
  end
  object DataSource1: TDataSource
    DataSet = BookDeleteQuery
    Left = 96
    Top = 200
  end
  object BookDeleteQuery: TQuery
    Active = True
    DatabaseName = 'MyCBuilderOdbc'
    SQL.Strings = (
      'Select * from BookTable;')
    Left = 48
    Top = 200
  end
end
