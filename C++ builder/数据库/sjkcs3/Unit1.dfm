object Form1: TForm1
  Left = 189
  Top = 110
  Width = 343
  Height = 557
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
  object Label1: TLabel
    Left = 136
    Top = 48
    Width = 17
    Height = 13
    Caption = 'sno'
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 8
    Width = 321
    Height = 209
    DataSource = DataSource1
    ImeName = #35895#27468#25340#38899#36755#20837#27861' 2'
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 224
    Width = 321
    Height = 145
    Caption = #28155#21152#35760#24405
    TabOrder = 1
    object Label2: TLabel
      Left = 8
      Top = 16
      Width = 27
      Height = 13
      Caption = #23398#21495' '
    end
    object Label3: TLabel
      Left = 152
      Top = 16
      Width = 30
      Height = 13
      Caption = #22995#21517'  '
    end
    object Label4: TLabel
      Left = 8
      Top = 48
      Width = 30
      Height = 13
      Caption = #24615#21035'  '
    end
    object Label5: TLabel
      Left = 152
      Top = 48
      Width = 30
      Height = 13
      Caption = #24180#40836'  '
    end
    object Label6: TLabel
      Left = 8
      Top = 80
      Width = 30
      Height = 13
      Caption = #19987#19994'  '
    end
    object Edit1: TEdit
      Left = 40
      Top = 16
      Width = 97
      Height = 21
      ImeName = #35895#27468#25340#38899#36755#20837#27861' 2'
      TabOrder = 0
    end
    object Edit2: TEdit
      Left = 192
      Top = 16
      Width = 121
      Height = 21
      ImeName = #35895#27468#25340#38899#36755#20837#27861' 2'
      TabOrder = 1
    end
    object Edit3: TEdit
      Left = 40
      Top = 48
      Width = 97
      Height = 21
      ImeName = #35895#27468#25340#38899#36755#20837#27861' 2'
      TabOrder = 2
    end
    object Edit4: TEdit
      Left = 192
      Top = 48
      Width = 121
      Height = 21
      ImeName = #35895#27468#25340#38899#36755#20837#27861' 2'
      TabOrder = 3
    end
    object Edit5: TEdit
      Left = 40
      Top = 80
      Width = 273
      Height = 21
      ImeName = #35895#27468#25340#38899#36755#20837#27861' 2'
      TabOrder = 4
    end
    object Button1: TButton
      Left = 224
      Top = 112
      Width = 75
      Height = 25
      Caption = #28155#21152
      TabOrder = 5
      OnClick = Button1Click
    end
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 376
    Width = 161
    Height = 137
    Caption = #26597#35810
    TabOrder = 2
    object Label7: TLabel
      Left = 8
      Top = 16
      Width = 54
      Height = 13
      Caption = #26597#35810#23383#27573'  '
    end
    object Label8: TLabel
      Left = 8
      Top = 56
      Width = 18
      Height = 13
      Caption = #20540'  '
    end
    object ComboBox1: TComboBox
      Left = 8
      Top = 32
      Width = 145
      Height = 21
      ImeName = #35895#27468#25340#38899#36755#20837#27861' 2'
      ItemHeight = 13
      TabOrder = 0
    end
    object Edit6: TEdit
      Left = 8
      Top = 72
      Width = 145
      Height = 21
      ImeName = #35895#27468#25340#38899#36755#20837#27861' 2'
      TabOrder = 1
    end
    object Button2: TButton
      Left = 80
      Top = 104
      Width = 75
      Height = 25
      Caption = #26597#35810
      TabOrder = 2
    end
    object Button4: TButton
      Left = 8
      Top = 104
      Width = 65
      Height = 25
      Caption = #26174#31034#20840#37096
      TabOrder = 3
      OnClick = Button4Click
    end
  end
  object GroupBox3: TGroupBox
    Left = 176
    Top = 376
    Width = 153
    Height = 137
    Caption = #21024#38500
    TabOrder = 3
    object Label9: TLabel
      Left = 8
      Top = 24
      Width = 114
      Height = 13
      Caption = #36755#20837#21024#38500#23398#29983#30340#23398#21495'  '
    end
    object Edit7: TEdit
      Left = 8
      Top = 48
      Width = 121
      Height = 21
      ImeName = #35895#27468#25340#38899#36755#20837#27861' 2'
      TabOrder = 0
    end
    object Button3: TButton
      Left = 0
      Top = 104
      Width = 75
      Height = 25
      Caption = #21024#38500
      TabOrder = 1
    end
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security In' +
      'fo=False;Initial Catalog=MyCBilderDB;Data Source=DADI-20111010XB' +
      '\ZZJ'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    Left = 64
    Top = 64
  end
  object ADOQuery1: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    SQL.Strings = (
      'select * from stuinfo')
    Left = 144
    Top = 56
    object ADOQuery1sno: TStringField
      FieldName = 'sno'
      FixedChar = True
      Size = 3
    end
    object ADOQuery1sname: TStringField
      FieldName = 'sname'
      Size = 8
    end
    object ADOQuery1ssex: TStringField
      FieldName = 'ssex'
      FixedChar = True
      Size = 2
    end
    object ADOQuery1sage: TIntegerField
      FieldName = 'sage'
    end
    object ADOQuery1sspecial: TStringField
      FieldName = 'sspecial'
    end
  end
  object DataSource1: TDataSource
    DataSet = ADOQuery1
    Left = 216
    Top = 64
  end
end
