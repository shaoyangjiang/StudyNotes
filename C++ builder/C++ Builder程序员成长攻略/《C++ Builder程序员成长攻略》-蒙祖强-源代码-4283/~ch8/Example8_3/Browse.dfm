object BrowseForm: TBrowseForm
  Left = 306
  Top = 132
  Width = 498
  Height = 399
  Caption = #27983#35272#12289#26597#35810#23376#31383#21475
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
    Left = 16
    Top = 299
    Width = 145
    Height = 17
    AutoSize = False
    Caption = #36873#25321#24453#26597#25214#30340#23383#27573#21517#65306
  end
  object Label2: TLabel
    Left = 224
    Top = 299
    Width = 121
    Height = 17
    AutoSize = False
    Caption = #35201#26597#25214#30340#23383#27573#20540#65306
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 8
    Width = 473
    Height = 217
    Ctl3D = False
    DataSource = DataSource1
    ParentCtl3D = False
    ReadOnly = True
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
  object Edit1: TEdit
    Left = 224
    Top = 325
    Width = 121
    Height = 21
    TabOrder = 1
  end
  object ComboBox1: TComboBox
    Left = 16
    Top = 325
    Width = 145
    Height = 21
    ItemHeight = 13
    TabOrder = 2
    Text = 'ComboBox1'
  end
  object Button1: TButton
    Left = 14
    Top = 248
    Width = 75
    Height = 25
    Caption = #21152#36733#25968#25454
    TabOrder = 3
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 109
    Top = 248
    Width = 75
    Height = 25
    Caption = #31532#19968#26465#35760#24405
    TabOrder = 4
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 206
    Top = 248
    Width = 75
    Height = 25
    Caption = #19979#19968#26465#35760#24405
    TabOrder = 5
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 302
    Top = 248
    Width = 75
    Height = 25
    Caption = #19978#19968#26465#35760#24405
    TabOrder = 6
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 395
    Top = 248
    Width = 75
    Height = 25
    Caption = #26368#21518#19968#26465#35760#24405
    TabOrder = 7
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 395
    Top = 322
    Width = 75
    Height = 25
    Caption = #26597'  '#25214
    TabOrder = 8
    OnClick = Button6Click
  end
  object DataSource1: TDataSource
    DataSet = Query1
    Left = 136
    Top = 40
  end
  object Query1: TQuery
    DatabaseName = 'MyCBuilderOdbc'
    SQL.Strings = (
      '')
    Left = 80
    Top = 40
  end
end
