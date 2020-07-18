object F2: TF2
  Left = 311
  Top = 161
  Width = 400
  Height = 300
  BorderIcons = [biSystemMenu]
  Caption = ' '#1060#1091#1085#1082#1094#1080#1103' '#1080#1085#1090#1077#1085#1089#1080#1074#1085#1086#1089#1090#1080' '#1074#1099#1095#1080#1089#1083#1077#1085#1080#1081
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnResize = On_Resize
  PixelsPerInch = 96
  TextHeight = 13
  object Chart_IC: TChart
    Left = 0
    Top = 0
    Width = 384
    Height = 261
    Hint = 
      #1044#1080#1072#1075#1086#1085#1072#1083#1100#1085#1099#1077' '#1076#1074#1080#1078#1077#1085#1080#1103' '#1084#1099#1096#1100#1102' '#1089' '#1085#1072#1078#1072#1090#1099#1084#1080' '#13#10#1082#1085#1086#1087#1082#1072#1084#1080'  '#1087#1086' '#1080#1079#1086#1073#1088#1072#1078#1077#1085#1080 +
      #1102' - '#1084#1072#1089#1096#1090#1072#1073' '#1075#1088#1072#1092#1080#1082#1072
    BackWall.Brush.Color = clWhite
    BackWall.Brush.Style = bsClear
    BottomWall.Color = clGray
    Foot.Font.Charset = RUSSIAN_CHARSET
    Foot.Font.Color = clBlack
    Foot.Font.Height = -11
    Foot.Font.Name = 'System'
    Foot.Font.Style = [fsBold]
    Gradient.Direction = gdLeftRight
    LeftWall.Brush.Color = clWhite
    Title.Font.Charset = RUSSIAN_CHARSET
    Title.Font.Color = clBlack
    Title.Font.Height = -11
    Title.Font.Name = 'System'
    Title.Font.Style = [fsBold]
    Title.Text.Strings = (
      
        #1047#1072#1074#1080#1089#1080#1084#1086#1089#1090#1100' '#1095#1080#1089#1083#1072' '#1086#1076#1085#1086#1074#1088#1077#1084#1077#1085#1085#1086' '#1074#1099#1087#1086#1083#1085#1103#1102#1097#1080#1093#1089#1103' '#1086#1087#1077#1088#1072#1090#1086#1088#1086#1074' '#1086#1090' '#1074#1088#1077#1084#1077 +
        #1085#1080' '#1074#1099#1087#1086#1083#1085#1077#1085#1080#1103' '#1087#1088#1086#1075#1088#1072#1084#1084#1099)
    BottomAxis.Title.Font.Charset = RUSSIAN_CHARSET
    BottomAxis.Title.Font.Color = clBlack
    BottomAxis.Title.Font.Height = -11
    BottomAxis.Title.Font.Name = 'System'
    BottomAxis.Title.Font.Style = [fsBold]
    Legend.Visible = False
    RightAxis.Automatic = False
    RightAxis.AutomaticMinimum = False
    View3D = False
    Align = alClient
    BevelWidth = 0
    Color = clWhite
    ParentShowHint = False
    ShowHint = True
    TabOrder = 0
    object Series1: TAreaSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = clRed
      DrawArea = True
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      Stairs = True
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
  end
end
