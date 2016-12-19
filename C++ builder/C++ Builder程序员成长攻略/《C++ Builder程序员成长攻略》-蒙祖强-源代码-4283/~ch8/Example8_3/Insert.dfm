object InsertForm: TInsertForm
  Left = 295
  Top = 172
  Width = 519
  Height = 442
  Caption = #25968#25454#28155#21152#25554#20837#23376#31383#21475
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
    Left = 40
    Top = 24
    Width = 57
    Height = 13
    AutoSize = False
    Caption = #23398#21495#65306
  end
  object Label2: TLabel
    Left = 40
    Top = 64
    Width = 57
    Height = 13
    AutoSize = False
    Caption = #22995#21517#65306
  end
  object Label3: TLabel
    Left = 40
    Top = 106
    Width = 57
    Height = 13
    AutoSize = False
    Caption = #24615#21035#65306
  end
  object Label4: TLabel
    Left = 13
    Top = 144
    Width = 73
    Height = 13
    AutoSize = False
    Caption = #20986#29983#26085#26399#65306
  end
  object Label5: TLabel
    Left = 293
    Top = 24
    Width = 57
    Height = 13
    AutoSize = False
    Caption = #31821#36143#65306
  end
  object Label6: TLabel
    Left = 293
    Top = 65
    Width = 57
    Height = 13
    AutoSize = False
    Caption = #19987#19994#65306
  end
  object Label7: TLabel
    Left = 293
    Top = 106
    Width = 57
    Height = 13
    AutoSize = False
    Caption = #25104#32489#65306
  end
  object Label8: TLabel
    Left = 39
    Top = 184
    Width = 57
    Height = 13
    AutoSize = False
    Caption = #35780#35821#65306
  end
  object Edit1: TEdit
    Left = 94
    Top = 21
    Width = 121
    Height = 21
    TabOrder = 0
    Text = 'Edit1'
  end
  object Edit2: TEdit
    Left = 94
    Top = 62
    Width = 121
    Height = 21
    TabOrder = 1
    Text = 'Edit2'
  end
  object Edit3: TEdit
    Left = 93
    Top = 103
    Width = 121
    Height = 21
    TabOrder = 2
    Text = 'Edit3'
  end
  object Edit4: TEdit
    Left = 354
    Top = 21
    Width = 121
    Height = 21
    TabOrder = 3
    Text = 'Edit4'
  end
  object Edit5: TEdit
    Left = 354
    Top = 61
    Width = 121
    Height = 21
    TabOrder = 4
    Text = 'Edit5'
  end
  object Edit6: TEdit
    Left = 353
    Top = 102
    Width = 121
    Height = 21
    TabOrder = 5
    Text = 'Edit6'
  end
  object Memo1: TMemo
    Left = 40
    Top = 208
    Width = 441
    Height = 129
    Lines.Strings = (
      'Memo1')
    TabOrder = 6
  end
  object MaskEdit1: TMaskEdit
    Left = 91
    Top = 142
    Width = 120
    Height = 21
    EditMask = '!9999/99/00;1;_'
    MaxLength = 10
    TabOrder = 7
    Text = '    -  -  '
  end
  object BitBtn1: TBitBtn
    Left = 216
    Top = 368
    Width = 75
    Height = 25
    Caption = #25554'    '#20837
    TabOrder = 8
    OnClick = BitBtn1Click
  end
  object Table1: TTable
    Active = True
    DatabaseName = 'MyCBuilderOdbc'
    TableName = 'dbo.StuTable'
    Left = 312
    Top = 152
  end
  object DataSource1: TDataSource
    DataSet = Table1
    Left = 384
    Top = 152
  end
end
