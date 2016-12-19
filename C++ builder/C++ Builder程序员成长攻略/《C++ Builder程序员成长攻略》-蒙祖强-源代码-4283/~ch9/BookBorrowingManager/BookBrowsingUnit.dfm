object BrowsingBook: TBrowsingBook
  Left = 226
  Top = 182
  Width = 696
  Height = 480
  Caption = #20070#30446#26597#35810
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
  object Label1: TLabel
    Left = 14
    Top = 20
    Width = 105
    Height = 25
    AutoSize = False
    Caption = #26816#32034#35789#31867#22411#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 14
    Top = 51
    Width = 105
    Height = 25
    AutoSize = False
    Caption = #26816'    '#32034'    '#35789#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 354
    Top = 20
    Width = 105
    Height = 25
    AutoSize = False
    Caption = #21305#37197#26041#24335#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object SearchType: TComboBox
    Left = 90
    Top = 16
    Width = 145
    Height = 22
    Style = csOwnerDrawFixed
    Ctl3D = False
    ItemHeight = 16
    ItemIndex = 0
    ParentCtl3D = False
    TabOrder = 0
    Text = #39064#21517
    Items.Strings = (
      #39064#21517
      #20316#32773
      'ISBN'
      #20986#29256#31038
      #32034#20070#21495)
  end
  object MatchType: TComboBox
    Left = 418
    Top = 16
    Width = 145
    Height = 22
    Style = csOwnerDrawFixed
    Ctl3D = False
    ItemHeight = 16
    ItemIndex = 0
    ParentCtl3D = False
    TabOrder = 1
    Text = #27169#31946#21305#37197
    Items.Strings = (
      #27169#31946#21305#37197
      #31934#30830#21305#37197)
  end
  object SearchingText: TEdit
    Left = 90
    Top = 48
    Width = 423
    Height = 19
    Ctl3D = False
    ParentCtl3D = False
    TabOrder = 2
    Text = '11233'
  end
  object SearchingBtn: TButton
    Left = 531
    Top = 47
    Width = 75
    Height = 20
    Caption = #24320#22987#26816#32034
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -8
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = SearchingBtnClick
  end
  object ScrollBox1: TScrollBox
    Left = 0
    Top = 76
    Width = 671
    Height = 632
    Align = alBottom
    Color = clGrayText
    ParentColor = False
    TabOrder = 4
    object DBGrid1: TDBGrid
      Left = 0
      Top = 0
      Width = 667
      Height = 628
      Align = alClient
      DataSource = DataSource1
      Options = [dgEditing, dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgConfirmDelete, dgCancelOnExit, dgMultiSelect]
      ReadOnly = True
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'MS Sans Serif'
      TitleFont.Style = []
      Visible = False
    end
  end
  object BrowsingBookQuery: TQuery
    DatabaseName = 'MyCBuilderOdbc'
    SQL.Strings = (
      '')
    Left = 352
    Top = 280
  end
  object DataSource1: TDataSource
    DataSet = BrowsingBookQuery
    Left = 408
    Top = 280
  end
end
