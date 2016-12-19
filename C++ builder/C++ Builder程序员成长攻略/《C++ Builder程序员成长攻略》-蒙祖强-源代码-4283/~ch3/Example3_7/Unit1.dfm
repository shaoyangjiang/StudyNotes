object Form1: TForm1
  Left = 297
  Top = 221
  Width = 504
  Height = 324
  Caption = #26597#25214#19982#26367#25442
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 392
    Top = 56
    Width = 83
    Height = 25
    Caption = #26597'      '#25214
    TabOrder = 0
    OnClick = Button1Click
  end
  object RichEdit1: TRichEdit
    Left = 0
    Top = 0
    Width = 369
    Height = 289
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    HideSelection = False
    Lines.Strings = (
      'Borland Software Corporation (NASDAQ NM: '
      'BORL, www.borland.com) today introduced a '
      'complete, personalized IT management and '
      'governance solution to help organizations '
      'achieve IT business alignment, increase '
      'visibility and control over IT projects and '
      'investments, improve execution with more '
      'effective resource utilization and manage '
      'regulatory compliance. The solution combines '
      'Borland'#8217's process improvement and skills '
      'training services with a new version of '
      'Borland? Tempo?, packaged and delivered in an '
      'integrated way that can help IT organizations '
      'manage their investments, projects and '
      'resources more efficiently and cost '
      'effectively')
    ParentFont = False
    TabOrder = 1
  end
  object Button2: TButton
    Left = 392
    Top = 184
    Width = 83
    Height = 25
    Caption = #26597#25214#19982#26367#25442
    TabOrder = 2
    OnClick = Button2Click
  end
  object FindDialog1: TFindDialog
    OnFind = FindDialog1Find
    Left = 400
    Top = 120
  end
  object ReplaceDialog1: TReplaceDialog
    OnFind = ReplaceDialog1Find
    OnReplace = ReplaceDialog1Replace
    Left = 448
    Top = 120
  end
end
