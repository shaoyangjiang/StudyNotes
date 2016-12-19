object Form1: TForm1
  Left = 521
  Top = 111
  Width = 668
  Height = 528
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
  object DBGrid1: TDBGrid
    Left = 0
    Top = 0
    Width = 401
    Height = 201
    DataSource = DataSource1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
  object GroupBox1: TGroupBox
    Left = 0
    Top = 200
    Width = 553
    Height = 177
    Caption = #28155#21152#35760#24405' '
    TabOrder = 1
    object Label1: TLabel
      Left = 16
      Top = 24
      Width = 30
      Height = 13
      Caption = #23398#21495'  '
    end
    object Label2: TLabel
      Left = 288
      Top = 32
      Width = 27
      Height = 13
      Caption = #22995#21517' '
    end
    object Label3: TLabel
      Left = 16
      Top = 64
      Width = 30
      Height = 13
      Caption = #24615#21035'  '
    end
    object Label4: TLabel
      Left = 288
      Top = 72
      Width = 30
      Height = 13
      Caption = #29983#26085'  '
    end
    object Label5: TLabel
      Left = 16
      Top = 96
      Width = 30
      Height = 13
      Caption = #22320#22336'  '
    end
    object Label6: TLabel
      Left = 16
      Top = 128
      Width = 30
      Height = 13
      Caption = #22791#27880'  '
    end
    object StuIdEdit: TEdit
      Left = 72
      Top = 24
      Width = 121
      Height = 21
      TabOrder = 0
    end
    object NameEdit: TEdit
      Left = 344
      Top = 24
      Width = 121
      Height = 21
      TabOrder = 1
    end
    object GenderEdit: TEdit
      Left = 72
      Top = 64
      Width = 121
      Height = 21
      TabOrder = 2
    end
    object BirthdayEdit: TEdit
      Left = 344
      Top = 64
      Width = 121
      Height = 21
      TabOrder = 3
    end
    object AddressEdit: TEdit
      Left = 72
      Top = 96
      Width = 377
      Height = 21
      TabOrder = 4
    end
    object RemarkEdit: TEdit
      Left = 72
      Top = 128
      Width = 377
      Height = 41
      TabOrder = 5
    end
    object Add: TButton
      Left = 464
      Top = 136
      Width = 75
      Height = 25
      Caption = #25554#20837#25968#25454
      TabOrder = 6
      OnClick = AddClick
    end
  end
  object GroupBox2: TGroupBox
    Left = 0
    Top = 368
    Width = 297
    Height = 113
    Caption = #26597#25214#25968#25454' '
    TabOrder = 2
    object Label7: TLabel
      Left = 8
      Top = 24
      Width = 54
      Height = 13
      Caption = #26597#25214#23383#27573'  '
    end
    object Label8: TLabel
      Left = 8
      Top = 64
      Width = 54
      Height = 13
      Caption = #26597#25214#20869#23481'  '
    end
    object FindNameComboBox: TComboBox
      Left = 72
      Top = 24
      Width = 121
      Height = 21
      ItemHeight = 13
      TabOrder = 0
    end
    object FindEdit: TEdit
      Left = 72
      Top = 56
      Width = 121
      Height = 21
      TabOrder = 1
    end
    object Button1: TButton
      Left = 216
      Top = 24
      Width = 75
      Height = 25
      Caption = #26174#31034#20840#37096'  '
      TabOrder = 2
    end
    object Find: TButton
      Left = 216
      Top = 64
      Width = 75
      Height = 25
      Caption = #26597#25214
      TabOrder = 3
      OnClick = FindClick
    end
  end
  object GroupBox3: TGroupBox
    Left = 296
    Top = 376
    Width = 257
    Height = 105
    Caption = #25968#25454#21024#38500'  '
    TabOrder = 3
    object Label9: TLabel
      Left = 16
      Top = 24
      Width = 99
      Height = 13
      Caption = #35201#21024#38500#21516#23398#30340#23398#21495' '
    end
    object Button2: TButton
      Left = 152
      Top = 24
      Width = 75
      Height = 25
      Caption = #21024#38500#24403#21069#25968#25454' '
      TabOrder = 0
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 160
      Top = 56
      Width = 75
      Height = 25
      Caption = #28165#31354#25968#25454#24211'  '
      TabOrder = 1
    end
    object Edit1: TEdit
      Left = 16
      Top = 48
      Width = 121
      Height = 21
      TabOrder = 2
    end
  end
  object Panel1: TPanel
    Left = 400
    Top = 0
    Width = 153
    Height = 201
    Caption = 'Panel1'
    TabOrder = 4
    object Image1: TImage
      Left = -8
      Top = 0
      Width = 161
      Height = 201
    end
  end
  object Button4: TButton
    Left = 568
    Top = 168
    Width = 75
    Height = 25
    Caption = 'Button4'
    TabOrder = 5
    OnClick = Button4Click
  end
  object DataSource1: TDataSource
    DataSet = ADOQuery1
    Left = 368
    Top = 32
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security In' +
      'fo=False;Initial Catalog=MyCBilderDB;Data Source=DADI-20111010XB' +
      '\ZZJ'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    Left = 368
    Top = 64
  end
  object ADOQuery1: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    SQL.Strings = (
      'select * from test')
    Left = 368
  end
  object OpenPictureDialog1: TOpenPictureDialog
    Left = 368
    Top = 96
  end
end
