object deleteForm: TdeleteForm
  Left = 263
  Top = 220
  Width = 666
  Height = 345
  Caption = #25968#25454#21024#38500#23376#31383#21475
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
    Left = 8
    Top = 8
    Width = 641
    Height = 233
    DataSource = DataSource1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
  object Button1: TButton
    Left = 264
    Top = 264
    Width = 105
    Height = 25
    Caption = #21024#38500#24403#21069#35760#24405
    TabOrder = 1
    OnClick = Button1Click
  end
  object DataSource1: TDataSource
    DataSet = Query1
    Left = 80
    Top = 136
  end
  object Query1: TQuery
    Active = True
    DatabaseName = 'MyCBuilderOdbc'
    SQL.Strings = (
      'select * from StuTable;')
    Left = 40
    Top = 136
  end
end
