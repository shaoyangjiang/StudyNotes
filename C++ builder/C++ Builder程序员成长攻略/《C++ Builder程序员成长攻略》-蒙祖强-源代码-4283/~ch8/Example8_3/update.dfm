object updateForm: TupdateForm
  Left = 271
  Top = 114
  Width = 615
  Height = 564
  Caption = #25968#25454#26356#26032#23376#31383#21475
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
    Left = 53
    Top = 252
    Width = 65
    Height = 17
    AutoSize = False
    Caption = #23398#21495#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 53
    Top = 292
    Width = 65
    Height = 17
    AutoSize = False
    Caption = #22995#21517#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 53
    Top = 334
    Width = 65
    Height = 17
    AutoSize = False
    Caption = #24615#21035#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 28
    Top = 375
    Width = 65
    Height = 17
    AutoSize = False
    Caption = #20986#29983#26085#26399#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 285
    Top = 252
    Width = 65
    Height = 17
    AutoSize = False
    Caption = #31821#36143#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label6: TLabel
    Left = 285
    Top = 294
    Width = 65
    Height = 17
    AutoSize = False
    Caption = #19987#19994#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label7: TLabel
    Left = 285
    Top = 331
    Width = 65
    Height = 17
    AutoSize = False
    Caption = #25104#32489#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label8: TLabel
    Left = 106
    Top = 407
    Width = 65
    Height = 17
    AutoSize = False
    Caption = #35780#35821#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label9: TLabel
    Left = 8
    Top = 216
    Width = 170
    Height = 16
    Caption = #22312#20197#19979#25991#26412#26694#20013#20462#25913#65306
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #38582#20070
    Font.Style = [fsBold]
    ParentFont = False
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 8
    Width = 585
    Height = 185
    DataSource = DataSource1
    ReadOnly = True
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'StuId'
        Title.Caption = #23398#21495
        Width = 43
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'name'
        Title.Caption = #22995#21517
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'gender'
        Title.Caption = #24615#21035
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'birthday'
        Title.Caption = #20986#29983#26085#26399
        Width = 88
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'native'
        Title.Caption = #31821#36143
        Width = 84
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'speciality'
        Title.Caption = #19987#19994
        Width = 96
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'grade'
        Title.Caption = #25104#32489
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'remark'
        Title.Caption = #35780#35821
        Visible = True
      end>
  end
  object DBEdit1: TDBEdit
    Left = 109
    Top = 249
    Width = 121
    Height = 21
    DataField = 'StuId'
    DataSource = DataSource1
    TabOrder = 1
  end
  object DBEdit2: TDBEdit
    Left = 109
    Top = 289
    Width = 121
    Height = 21
    DataField = 'name'
    DataSource = DataSource1
    TabOrder = 2
  end
  object DBEdit3: TDBEdit
    Left = 108
    Top = 330
    Width = 121
    Height = 21
    DataField = 'gender'
    DataSource = DataSource1
    TabOrder = 3
  end
  object DBEdit4: TDBEdit
    Left = 107
    Top = 372
    Width = 121
    Height = 21
    DataField = 'birthday'
    DataSource = DataSource1
    TabOrder = 4
  end
  object DBEdit5: TDBEdit
    Left = 349
    Top = 248
    Width = 121
    Height = 21
    DataField = 'native'
    DataSource = DataSource1
    TabOrder = 5
  end
  object DBEdit6: TDBEdit
    Left = 349
    Top = 289
    Width = 121
    Height = 21
    DataField = 'speciality'
    DataSource = DataSource1
    TabOrder = 6
  end
  object DBEdit7: TDBEdit
    Left = 347
    Top = 329
    Width = 121
    Height = 21
    DataField = 'grade'
    DataSource = DataSource1
    TabOrder = 7
  end
  object DBMemo1: TDBMemo
    Left = 101
    Top = 426
    Width = 393
    Height = 75
    DataField = 'remark'
    DataSource = DataSource1
    TabOrder = 8
  end
  object Button1: TButton
    Left = 510
    Top = 478
    Width = 75
    Height = 25
    Caption = #20445'    '#23384
    TabOrder = 9
    OnClick = Button1Click
  end
  object DataSource1: TDataSource
    DataSet = Table1
    Left = 80
    Top = 128
  end
  object Table1: TTable
    Active = True
    DatabaseName = 'MyCBuilderOdbc'
    TableName = 'dbo.StuTable'
    Left = 40
    Top = 128
  end
end
