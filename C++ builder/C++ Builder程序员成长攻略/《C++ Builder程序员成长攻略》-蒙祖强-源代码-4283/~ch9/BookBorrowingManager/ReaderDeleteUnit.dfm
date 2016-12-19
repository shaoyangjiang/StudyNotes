object ReaderDelete: TReaderDelete
  Left = 239
  Top = 190
  Width = 696
  Height = 376
  Caption = #35835#32773#35760#24405#21024#38500
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
  object BitBtn1: TBitBtn
    Left = 576
    Top = 288
    Width = 75
    Height = 25
    Caption = #21024#38500
    TabOrder = 0
    OnClick = BitBtn1Click
    Kind = bkAbort
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 8
    Width = 673
    Height = 249
    DataSource = DataSource1
    Options = [dgEditing, dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgConfirmDelete, dgCancelOnExit, dgMultiSelect]
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
  object ReaderDeleteQuery: TQuery
    Active = True
    DatabaseName = 'MyCBuilderOdbc'
    SQL.Strings = (
      'Select * from ReaderTable;')
    Left = 120
    Top = 176
  end
  object DataSource1: TDataSource
    DataSet = ReaderDeleteQuery
    Left = 168
    Top = 176
  end
end
