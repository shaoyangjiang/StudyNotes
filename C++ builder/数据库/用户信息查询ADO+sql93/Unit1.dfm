object Form1: TForm1
  Left = 799
  Top = 106
  Width = 572
  Height = 483
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label3: TLabel
    Left = 8
    Top = 96
    Width = 48
    Height = 13
    Caption = #29992#25143#21517#31216
    FocusControl = DBEdit1
  end
  object Label4: TLabel
    Left = 136
    Top = 96
    Width = 36
    Height = 13
    Caption = #32852#32476#20154
    FocusControl = DBEdit2
  end
  object Label5: TLabel
    Left = 8
    Top = 152
    Width = 24
    Height = 13
    Caption = #22320#22336
    FocusControl = DBEdit3
  end
  object Label6: TLabel
    Left = 8
    Top = 216
    Width = 24
    Height = 13
    Caption = #30005#35805
    FocusControl = DBEdit4
  end
  object Label7: TLabel
    Left = 112
    Top = 216
    Width = 24
    Height = 13
    Caption = #20256#30495
    FocusControl = DBEdit5
  end
  object Label8: TLabel
    Left = 256
    Top = 208
    Width = 48
    Height = 13
    Caption = #32479#19968#32534#21495
    FocusControl = DBEdit6
  end
  object GroupBox1: TGroupBox
    Left = 384
    Top = 56
    Width = 161
    Height = 217
    Caption = #26597#35810#21151#33021
    Color = clInfoBk
    ParentColor = False
    TabOrder = 0
    object Label1: TLabel
      Left = 24
      Top = 32
      Width = 48
      Height = 13
      Caption = #26597#35810#23383#27573
    end
    object Label2: TLabel
      Left = 24
      Top = 88
      Width = 36
      Height = 13
      Caption = #26597#35810#20540
    end
    object search_value: TEdit
      Left = 24
      Top = 112
      Width = 121
      Height = 21
      TabOrder = 0
    end
    object search_field: TComboBox
      Left = 24
      Top = 56
      Width = 121
      Height = 21
      ItemHeight = 13
      TabOrder = 1
    end
    object search: TButton
      Left = 24
      Top = 160
      Width = 75
      Height = 25
      Caption = #26597#35810
      TabOrder = 2
      OnClick = searchClick
    end
  end
  object DBNavigator1: TDBNavigator
    Left = 16
    Top = 328
    Width = 240
    Height = 25
    DataSource = DataSource1
    TabOrder = 1
  end
  object DBEdit1: TDBEdit
    Left = 8
    Top = 112
    Width = 89
    Height = 21
    DataField = #29992#25143#21517#31216
    DataSource = DataSource1
    TabOrder = 2
  end
  object DBEdit2: TDBEdit
    Left = 136
    Top = 112
    Width = 134
    Height = 21
    DataField = #32852#32476#20154
    DataSource = DataSource1
    TabOrder = 3
  end
  object DBEdit3: TDBEdit
    Left = 8
    Top = 168
    Width = 137
    Height = 21
    DataField = #22320#22336
    DataSource = DataSource1
    TabOrder = 4
  end
  object DBEdit4: TDBEdit
    Left = 8
    Top = 232
    Width = 81
    Height = 21
    DataField = #30005#35805
    DataSource = DataSource1
    TabOrder = 5
  end
  object DBEdit5: TDBEdit
    Left = 112
    Top = 232
    Width = 97
    Height = 21
    DataField = #20256#30495
    DataSource = DataSource1
    TabOrder = 6
  end
  object DBEdit6: TDBEdit
    Left = 256
    Top = 232
    Width = 97
    Height = 21
    DataField = #32479#19968#32534#21495
    DataSource = DataSource1
    TabOrder = 7
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=SQLOLEDB;Integrated Security=SSPI;Persist Security Info' +
      '=False;Initial Catalog=custominfo;Data Source=DADI-20111010XB\ZZ' +
      'J'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    Left = 40
    Top = 40
  end
  object ADOQuery1: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'select * from TABLE1')
    Left = 96
    Top = 40
    object ADOQuery1DSDesigner: TStringField
      FieldName = #29992#25143#21517#31216
      Size = 25
    end
    object ADOQuery1DSDesigner2: TStringField
      FieldName = #32852#32476#20154
      Size = 10
    end
    object ADOQuery1DSDesigner3: TStringField
      FieldName = #22320#22336
      Size = 50
    end
    object ADOQuery1DSDesigner4: TStringField
      FieldName = #30005#35805
      Size = 15
    end
    object ADOQuery1DSDesigner5: TStringField
      FieldName = #20256#30495
      Size = 18
    end
    object ADOQuery1DSDesigner6: TStringField
      FieldName = #32479#19968#32534#21495
      Size = 10
    end
  end
  object DataSource1: TDataSource
    DataSet = ADOQuery1
    Left = 152
    Top = 32
  end
end
