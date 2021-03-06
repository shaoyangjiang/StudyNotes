object ChildForm: TChildForm
  Left = 234
  Top = 221
  Width = 632
  Height = 370
  Caption = #23376#31383#21475
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  PixelsPerInch = 96
  TextHeight = 13
  object RichEdit1: TRichEdit
    Left = 0
    Top = 0
    Width = 624
    Height = 316
    Align = alClient
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = #23435#20307
    Font.Style = []
    HideSelection = False
    ParentFont = False
    PopupMenu = PopupMenu1
    ScrollBars = ssBoth
    TabOrder = 0
    OnChange = RichEdit1Change
    OnMouseDown = RichEdit1MouseDown
  end
  object MainMenu1: TMainMenu
    Left = 160
    Top = 56
    object NFile: TMenuItem
      Caption = #25991#20214'(&F)'
      object NNew: TMenuItem
        Caption = #26032#24314'(&N)...'
        OnClick = NNewClick
      end
      object NOpen: TMenuItem
        Caption = #25171#24320'(&O)...'
        ShortCut = 16463
        OnClick = NOpenClick
      end
      object NClose: TMenuItem
        Caption = #20851#38381'(&C)... '
        OnClick = NCloseClick
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object NSave: TMenuItem
        Caption = #20445#23384'(&S)'
        ShortCut = 16467
        OnClick = NSaveClick
      end
      object NSaveas: TMenuItem
        Caption = #21478#23384#20026'(&A)...'
        OnClick = NSaveasClick
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object NExit: TMenuItem
        Caption = #36864#20986'(&X)'
      end
    end
    object NEdit: TMenuItem
      Caption = #32534#36753'(&E) '
      OnClick = NEditClick
      object NUndo: TMenuItem
        Caption = #25764#38144'(&U) '
        ShortCut = 16474
        OnClick = NUndoClick
      end
      object N4: TMenuItem
        Caption = '-'
      end
      object NCut: TMenuItem
        Caption = #21098#20999'(&T)'
        ShortCut = 16472
        OnClick = NCutClick
      end
      object NCopy: TMenuItem
        Caption = #22797#21046'(&C)'
        ShortCut = 16451
        OnClick = NCopyClick
      end
      object NPaste: TMenuItem
        Caption = #31896#36148'(&P)'
        ShortCut = 16470
        OnClick = NPasteClick
      end
      object N5: TMenuItem
        Caption = '-'
      end
      object NClear: TMenuItem
        Caption = #28165#38500'(&A)'
        OnClick = NClearClick
      end
      object NSelectAll: TMenuItem
        Caption = #20840#36873'(&L)'
        ShortCut = 16449
        OnClick = NSelectAllClick
      end
      object N6: TMenuItem
        Caption = '-'
      end
      object NFind: TMenuItem
        Caption = #26597#25214'(&F)...'
        ShortCut = 16454
        OnClick = NFindClick
      end
      object NReplace: TMenuItem
        Caption = #26367#25442'(&E)...'
        ShortCut = 16456
        OnClick = NReplaceClick
      end
    end
    object NFormat: TMenuItem
      Caption = #26684#24335'(&O)'
      OnClick = NFormatClick
      object NFont: TMenuItem
        Caption = #23383#20307'(&F)...'
        OnClick = NFontClick
      end
      object NBColor: TMenuItem
        Caption = #32972#26223#39068#33394
        OnClick = NBColorClick
      end
      object NFColor: TMenuItem
        Caption = #23383#20307#39068#33394
        OnClick = NFColorClick
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Filter = #25991#26412#25991#26723'(*.txt)|*.txt|Rich Text Format(*.rtf)|*.rtf'
    FilterIndex = 2
    InitialDir = 'C:\Documents and Settings\mengzuqiang\My Documents\MyWord'
    Left = 272
    Top = 48
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = '.rtf'
    Filter = #25991#26412#25991#26723'(*.txt)|*.txt|Rich Text Format(*.rtf)|*.rtf'
    FilterIndex = 2
    InitialDir = 'C:\Documents and Settings\mengzuqiang\My Documents\MyWord'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
    Left = 312
    Top = 48
  end
  object FindDialog1: TFindDialog
    OnFind = FindDialog1Find
    Left = 408
    Top = 48
  end
  object ReplaceDialog1: TReplaceDialog
    OnFind = ReplaceDialog1Find
    OnReplace = ReplaceDialog1Replace
    Left = 448
    Top = 48
  end
  object FontDialog1: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    MinFontSize = 0
    MaxFontSize = 0
    Left = 536
    Top = 48
  end
  object ColorDialog1: TColorDialog
    Ctl3D = True
    Left = 384
    Top = 128
  end
  object PopupMenu1: TPopupMenu
    Left = 192
    Top = 56
    object PUndo: TMenuItem
      Caption = #25764#38144'(&U) '
      OnClick = PUndoClick
    end
    object N3: TMenuItem
      Caption = '-'
    end
    object PCut: TMenuItem
      Caption = #21098#20999'(&T)'
      ShortCut = 49240
      OnClick = PCutClick
    end
    object PCopy: TMenuItem
      Caption = #22797#21046'(&C)'
      ShortCut = 16451
      OnClick = PCopyClick
    end
    object PPaste: TMenuItem
      Caption = #31896#36148'(&P)'
      ShortCut = 16470
      OnClick = PPasteClick
    end
    object N7: TMenuItem
      Caption = '-'
    end
    object PClear: TMenuItem
      Caption = #28165#38500'(&A)'
      OnClick = PClearClick
    end
    object PSelectall: TMenuItem
      Caption = #20840#36873'(&L)'
      ShortCut = 16449
      OnClick = PSelectallClick
    end
  end
end
