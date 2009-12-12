///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 29 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "dialog_layers_setup_base2.h"

///////////////////////////////////////////////////////////////////////////

DIALOG_LAYERS_SETUP_BASE2::DIALOG_LAYERS_SETUP_BASE2( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 600,600 ), wxDefaultSize );
	
	wxBoxSizer* bMainSizer;
	bMainSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bChoicesSizer;
	bChoicesSizer = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbPresetsSizer;
	sbPresetsSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Preset Layer Groupings") ), wxVERTICAL );
	
	wxString m_PresetsChoiceChoices[] = { _("Custom"), _("Two layers, parts on Front only"), _("Two layers, parts on Back only"), _("Two layers, parts on Front and Back"), _("Four layers, parts on Front only"), _("Four layers, parts on Front and Back"), _("All layers on") };
	int m_PresetsChoiceNChoices = sizeof( m_PresetsChoiceChoices ) / sizeof( wxString );
	m_PresetsChoice = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_PresetsChoiceNChoices, m_PresetsChoiceChoices, 0 );
	m_PresetsChoice->SetSelection( 0 );
	sbPresetsSizer->Add( m_PresetsChoice, 0, wxEXPAND, 5 );
	
	bChoicesSizer->Add( sbPresetsSizer, 2, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbCopperLayersSizer;
	sbCopperLayersSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Copper Layers") ), wxVERTICAL );
	
	wxString m_CopperLayersChoiceChoices[] = { _("2"), _("4"), _("6"), _("8"), _("10"), _("12"), _("14"), _("16") };
	int m_CopperLayersChoiceNChoices = sizeof( m_CopperLayersChoiceChoices ) / sizeof( wxString );
	m_CopperLayersChoice = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_CopperLayersChoiceNChoices, m_CopperLayersChoiceChoices, 0 );
	m_CopperLayersChoice->SetSelection( 0 );
	sbCopperLayersSizer->Add( m_CopperLayersChoice, 0, wxEXPAND, 5 );
	
	bChoicesSizer->Add( sbCopperLayersSizer, 1, wxALL|wxEXPAND, 5 );
	
	bMainSizer->Add( bChoicesSizer, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbLayersSizer;
	sbLayersSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Layers") ), wxVERTICAL );
	
	wxBoxSizer* bCaptionsSizer;
	bCaptionsSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_LayerNameCaption = new wxStaticText( this, wxID_ANY, _("Name"), wxDefaultPosition, wxSize( -1,-1 ), wxALIGN_CENTRE );
	m_LayerNameCaption->Wrap( -1 );
	m_LayerNameCaption->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	bCaptionsSizer->Add( m_LayerNameCaption, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_LayerEnabledCaption = new wxStaticText( this, wxID_ANY, _("Enabled"), wxDefaultPosition, wxSize( -1,-1 ), wxALIGN_CENTRE );
	m_LayerEnabledCaption->Wrap( -1 );
	m_LayerEnabledCaption->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	bCaptionsSizer->Add( m_LayerEnabledCaption, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );
	
	m_LayerTypeCaption = new wxStaticText( this, wxID_ANY, _("Type"), wxDefaultPosition, wxSize( -1,-1 ), wxALIGN_CENTRE );
	m_LayerTypeCaption->Wrap( -1 );
	m_LayerTypeCaption->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	bCaptionsSizer->Add( m_LayerTypeCaption, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	sbLayersSizer->Add( bCaptionsSizer, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	
	m_LayersListPanel = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxALWAYS_SHOW_SB|wxRAISED_BORDER|wxTAB_TRAVERSAL|wxVSCROLL );
	m_LayersListPanel->SetScrollRate( 0, 5 );
	m_LayerListFlexGridSizer = new wxFlexGridSizer( 0, 3, 0, 0 );
	m_LayerListFlexGridSizer->AddGrowableCol( 0 );
	m_LayerListFlexGridSizer->AddGrowableCol( 1 );
	m_LayerListFlexGridSizer->SetFlexibleDirection( wxHORIZONTAL );
	m_LayerListFlexGridSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_AdhesFrontName = new wxStaticText( m_LayersListPanel, ID_ADHESFRONTNAME, _("Adhes_Front_later"), wxDefaultPosition, wxDefaultSize, 0 );
	m_AdhesFrontName->Wrap( -1 );
	m_LayerListFlexGridSizer->Add( m_AdhesFrontName, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT|wxRIGHT, 5 );
	
	m_AdhesFrontPanel = new wxPanel( m_LayersListPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_AdhesFrontPanel->SetBackgroundColour( wxColour( 236, 233, 236 ) );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	m_AdhesFrontCheckBox = new wxCheckBox( m_AdhesFrontPanel, ID_ADHESFRONTCHECKBOX, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	
	m_AdhesFrontCheckBox->SetToolTip( _("If you want an adhesive template for the front side of the board") );
	
	bSizer6->Add( m_AdhesFrontCheckBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_AdhesFrontPanel->SetSizer( bSizer6 );
	m_AdhesFrontPanel->Layout();
	bSizer6->Fit( m_AdhesFrontPanel );
	m_LayerListFlexGridSizer->Add( m_AdhesFrontPanel, 1, wxEXPAND, 5 );
	
	m_AdhesFrontStaticText = new wxStaticText( m_LayersListPanel, ID_ADHESFRONTCHOICE, _("Off-board, manufacturing"), wxDefaultPosition, wxDefaultSize, 0 );
	m_AdhesFrontStaticText->Wrap( -1 );
	m_LayerListFlexGridSizer->Add( m_AdhesFrontStaticText, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT|wxRIGHT, 5 );
	
	m_SoldPFrontName = new wxStaticText( m_LayersListPanel, ID_SOLDPFRONTNAME, _("SoldP_Front_later"), wxDefaultPosition, wxDefaultSize, 0 );
	m_SoldPFrontName->Wrap( -1 );
	m_LayerListFlexGridSizer->Add( m_SoldPFrontName, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT|wxRIGHT, 5 );
	
	m_SoldPFrontPanel = new wxPanel( m_LayersListPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_SoldPFrontPanel->SetBackgroundColour( wxColour( 236, 233, 236 ) );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	m_SoldPFrontCheckBox = new wxCheckBox( m_SoldPFrontPanel, ID_SOLDPFRONTCHECKBOX, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	
	m_SoldPFrontCheckBox->SetToolTip( _("If you want a solder paster layer for front side of the board") );
	
	bSizer7->Add( m_SoldPFrontCheckBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_SoldPFrontPanel->SetSizer( bSizer7 );
	m_SoldPFrontPanel->Layout();
	bSizer7->Fit( m_SoldPFrontPanel );
	m_LayerListFlexGridSizer->Add( m_SoldPFrontPanel, 1, wxEXPAND, 5 );
	
	m_SoldPFrontStaticText = new wxStaticText( m_LayersListPanel, ID_SOLDPFRONTCHOICE, _("Off-board, manufacturing"), wxDefaultPosition, wxDefaultSize, 0 );
	m_SoldPFrontStaticText->Wrap( -1 );
	m_LayerListFlexGridSizer->Add( m_SoldPFrontStaticText, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT|wxRIGHT, 5 );
	
	m_SilkSFrontName = new wxStaticText( m_LayersListPanel, ID_SILKSFRONTNAME, _("SilkS_Front_later"), wxDefaultPosition, wxDefaultSize, 0 );
	m_SilkSFrontName->Wrap( -1 );
	m_LayerListFlexGridSizer->Add( m_SilkSFrontName, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT|wxRIGHT, 5 );
	
	m_SilkSFrontPanel = new wxPanel( m_LayersListPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_SilkSFrontPanel->SetBackgroundColour( wxColour( 255, 252, 235 ) );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	m_SilkSFrontCheckBox = new wxCheckBox( m_SilkSFrontPanel, ID_SILKSFRONTCHECKBOX, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	
	bSizer5->Add( m_SilkSFrontCheckBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_SilkSFrontPanel->SetSizer( bSizer5 );
	m_SilkSFrontPanel->Layout();
	bSizer5->Fit( m_SilkSFrontPanel );
	m_LayerListFlexGridSizer->Add( m_SilkSFrontPanel, 1, wxEXPAND, 5 );
	
	m_SilkSFrontStaticText = new wxStaticText( m_LayersListPanel, ID_SILKSFRONTCHOICE, _("On-board, non-copper"), wxDefaultPosition, wxDefaultSize, 0 );
	m_SilkSFrontStaticText->Wrap( -1 );
	m_LayerListFlexGridSizer->Add( m_SilkSFrontStaticText, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT|wxRIGHT, 5 );
	
	m_MaskFrontName = new wxStaticText( m_LayersListPanel, ID_MASKFRONTNAME, _("Mask_Front_later"), wxDefaultPosition, wxDefaultSize, 0 );
	m_MaskFrontName->Wrap( -1 );
	m_LayerListFlexGridSizer->Add( m_MaskFrontName, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT|wxRIGHT, 5 );
	
	m_MaskFrontPanel = new wxPanel( m_LayersListPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_MaskFrontPanel->SetBackgroundColour( wxColour( 255, 252, 235 ) );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );
	
	m_MaskFrontCheckBox = new wxCheckBox( m_MaskFrontPanel, ID_MASKFRONTCHECKBOX, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	
	bSizer8->Add( m_MaskFrontCheckBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_MaskFrontPanel->SetSizer( bSizer8 );
	m_MaskFrontPanel->Layout();
	bSizer8->Fit( m_MaskFrontPanel );
	m_LayerListFlexGridSizer->Add( m_MaskFrontPanel, 1, wxEXPAND, 5 );
	
	m_MaskFrontStaticText = new wxStaticText( m_LayersListPanel, ID_MASKFRONTCHOICE, _("On-board, non-copper"), wxDefaultPosition, wxDefaultSize, 0 );
	m_MaskFrontStaticText->Wrap( -1 );
	m_LayerListFlexGridSizer->Add( m_MaskFrontStaticText, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT|wxRIGHT, 5 );
	
	m_FrontName = new wxTextCtrl( m_LayersListPanel, ID_FRONTNAME, _("Front_later"), wxDefaultPosition, wxDefaultSize, 0 );
	m_FrontName->SetMaxLength( 20 ); 
	m_LayerListFlexGridSizer->Add( m_FrontName, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5 );
	
	m_FrontPanel = new wxPanel( m_LayersListPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_FrontPanel->SetBackgroundColour( wxColour( 236, 253, 216 ) );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	m_FrontCheckBox = new wxCheckBox( m_FrontPanel, ID_FRONTCHECKBOX, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	
	bSizer9->Add( m_FrontCheckBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_FrontPanel->SetSizer( bSizer9 );
	m_FrontPanel->Layout();
	bSizer9->Fit( m_FrontPanel );
	m_LayerListFlexGridSizer->Add( m_FrontPanel, 1, wxEXPAND, 5 );
	
	wxString m_FrontChoiceChoices[] = { _("signal"), _("power"), _("mixed"), _("jumper") };
	int m_FrontChoiceNChoices = sizeof( m_FrontChoiceChoices ) / sizeof( wxString );
	m_FrontChoice = new wxChoice( m_LayersListPanel, ID_FRONTCHOICE, wxDefaultPosition, wxDefaultSize, m_FrontChoiceNChoices, m_FrontChoiceChoices, 0 );
	m_FrontChoice->SetSelection( 0 );
	m_LayerListFlexGridSizer->Add( m_FrontChoice, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	m_Inner2Name = new wxTextCtrl( m_LayersListPanel, ID_INNER2NAME, _("Inner2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_LayerListFlexGridSizer->Add( m_Inner2Name, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5 );
	
	m_Inner2Panel = new wxPanel( m_LayersListPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_Inner2Panel->SetBackgroundColour( wxColour( 236, 253, 216 ) );
	
	wxBoxSizer* bInner2Sizer;
	bInner2Sizer = new wxBoxSizer( wxVERTICAL );
	
	m_Inner2CheckBox = new wxCheckBox( m_Inner2Panel, ID_INNER2CHECKBOX, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	
	bInner2Sizer->Add( m_Inner2CheckBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_Inner2Panel->SetSizer( bInner2Sizer );
	m_Inner2Panel->Layout();
	bInner2Sizer->Fit( m_Inner2Panel );
	m_LayerListFlexGridSizer->Add( m_Inner2Panel, 1, wxEXPAND, 5 );
	
	wxString m_Inner2ChoiceChoices[] = { _("signal"), _("power"), _("mixed"), _("jumper") };
	int m_Inner2ChoiceNChoices = sizeof( m_Inner2ChoiceChoices ) / sizeof( wxString );
	m_Inner2Choice = new wxChoice( m_LayersListPanel, ID_INNER2CHOICE, wxDefaultPosition, wxDefaultSize, m_Inner2ChoiceNChoices, m_Inner2ChoiceChoices, 0 );
	m_Inner2Choice->SetSelection( 0 );
	m_LayerListFlexGridSizer->Add( m_Inner2Choice, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5 );
	
	m_Inner3Name = new wxTextCtrl( m_LayersListPanel, ID_INNER3NAME, _("Inner3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_LayerListFlexGridSizer->Add( m_Inner3Name, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5 );
	
	m_Inner3Panel = new wxPanel( m_LayersListPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_Inner3Panel->SetBackgroundColour( wxColour( 236, 253, 216 ) );
	
	wxBoxSizer* bInner3Sizer;
	bInner3Sizer = new wxBoxSizer( wxVERTICAL );
	
	m_Inner3CheckBox = new wxCheckBox( m_Inner3Panel, ID_INNER3CHECKBOX, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	
	bInner3Sizer->Add( m_Inner3CheckBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_Inner3Panel->SetSizer( bInner3Sizer );
	m_Inner3Panel->Layout();
	bInner3Sizer->Fit( m_Inner3Panel );
	m_LayerListFlexGridSizer->Add( m_Inner3Panel, 1, wxEXPAND, 5 );
	
	wxString m_Inner3ChoiceChoices[] = { _("signal"), _("power"), _("mixed"), _("jumper") };
	int m_Inner3ChoiceNChoices = sizeof( m_Inner3ChoiceChoices ) / sizeof( wxString );
	m_Inner3Choice = new wxChoice( m_LayersListPanel, ID_INNER3CHOICE, wxDefaultPosition, wxDefaultSize, m_Inner3ChoiceNChoices, m_Inner3ChoiceChoices, 0 );
	m_Inner3Choice->SetSelection( 0 );
	m_LayerListFlexGridSizer->Add( m_Inner3Choice, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5 );
	
	m_Inner4Name = new wxTextCtrl( m_LayersListPanel, ID_INNER4NAME, _("Inner4"), wxDefaultPosition, wxDefaultSize, 0 );
	m_LayerListFlexGridSizer->Add( m_Inner4Name, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5 );
	
	m_Inner4Panel = new wxPanel( m_LayersListPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_Inner4Panel->SetBackgroundColour( wxColour( 236, 253, 216 ) );
	
	wxBoxSizer* bInner4Sizer;
	bInner4Sizer = new wxBoxSizer( wxVERTICAL );
	
	m_Inner4CheckBox = new wxCheckBox( m_Inner4Panel, ID_INNER4CHECKBOX, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	
	bInner4Sizer->Add( m_Inner4CheckBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_Inner4Panel->SetSizer( bInner4Sizer );
	m_Inner4Panel->Layout();
	bInner4Sizer->Fit( m_Inner4Panel );
	m_LayerListFlexGridSizer->Add( m_Inner4Panel, 1, wxEXPAND, 5 );
	
	wxString m_Inner4ChoiceChoices[] = { _("signal"), _("power"), _("mixed"), _("jumper") };
	int m_Inner4ChoiceNChoices = sizeof( m_Inner4ChoiceChoices ) / sizeof( wxString );
	m_Inner4Choice = new wxChoice( m_LayersListPanel, ID_INNER4CHOICE, wxDefaultPosition, wxDefaultSize, m_Inner4ChoiceNChoices, m_Inner4ChoiceChoices, 0 );
	m_Inner4Choice->SetSelection( 0 );
	m_LayerListFlexGridSizer->Add( m_Inner4Choice, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5 );
	
	m_Inner5Name = new wxTextCtrl( m_LayersListPanel, ID_INNER5NAME, _("Inner5"), wxDefaultPosition, wxDefaultSize, 0 );
	m_LayerListFlexGridSizer->Add( m_Inner5Name, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5 );
	
	m_Inner5Panel = new wxPanel( m_LayersListPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_Inner5Panel->SetBackgroundColour( wxColour( 236, 253, 216 ) );
	
	wxBoxSizer* bInner5Sizer;
	bInner5Sizer = new wxBoxSizer( wxVERTICAL );
	
	m_Inner5CheckBox = new wxCheckBox( m_Inner5Panel, ID_INNER5CHECKBOX, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	
	bInner5Sizer->Add( m_Inner5CheckBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_Inner5Panel->SetSizer( bInner5Sizer );
	m_Inner5Panel->Layout();
	bInner5Sizer->Fit( m_Inner5Panel );
	m_LayerListFlexGridSizer->Add( m_Inner5Panel, 1, wxEXPAND, 5 );
	
	wxString m_Inner5ChoiceChoices[] = { _("signal"), _("power"), _("mixed"), _("jumper") };
	int m_Inner5ChoiceNChoices = sizeof( m_Inner5ChoiceChoices ) / sizeof( wxString );
	m_Inner5Choice = new wxChoice( m_LayersListPanel, ID_INNER5CHOICE, wxDefaultPosition, wxDefaultSize, m_Inner5ChoiceNChoices, m_Inner5ChoiceChoices, 0 );
	m_Inner5Choice->SetSelection( 3 );
	m_LayerListFlexGridSizer->Add( m_Inner5Choice, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5 );
	
	m_Inner6Name = new wxTextCtrl( m_LayersListPanel, ID_INNER6NAME, _("Inner6"), wxDefaultPosition, wxDefaultSize, 0 );
	m_LayerListFlexGridSizer->Add( m_Inner6Name, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5 );
	
	m_Inner6Panel = new wxPanel( m_LayersListPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_Inner6Panel->SetBackgroundColour( wxColour( 236, 253, 216 ) );
	
	wxBoxSizer* bInner6Sizer;
	bInner6Sizer = new wxBoxSizer( wxVERTICAL );
	
	m_Inner6CheckBox = new wxCheckBox( m_Inner6Panel, ID_INNER6CHECKBOX, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	
	bInner6Sizer->Add( m_Inner6CheckBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_Inner6Panel->SetSizer( bInner6Sizer );
	m_Inner6Panel->Layout();
	bInner6Sizer->Fit( m_Inner6Panel );
	m_LayerListFlexGridSizer->Add( m_Inner6Panel, 1, wxEXPAND, 5 );
	
	wxString m_Inner6ChoiceChoices[] = { _("signal"), _("power"), _("mixed"), _("jumper") };
	int m_Inner6ChoiceNChoices = sizeof( m_Inner6ChoiceChoices ) / sizeof( wxString );
	m_Inner6Choice = new wxChoice( m_LayersListPanel, ID_INNER6CHOICE, wxDefaultPosition, wxDefaultSize, m_Inner6ChoiceNChoices, m_Inner6ChoiceChoices, 0 );
	m_Inner6Choice->SetSelection( 0 );
	m_LayerListFlexGridSizer->Add( m_Inner6Choice, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5 );
	
	m_Inner7Name = new wxTextCtrl( m_LayersListPanel, ID_INNER7NAME, _("Inner7"), wxDefaultPosition, wxDefaultSize, 0 );
	m_LayerListFlexGridSizer->Add( m_Inner7Name, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5 );
	
	m_Inner7Panel = new wxPanel( m_LayersListPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_Inner7Panel->SetBackgroundColour( wxColour( 236, 253, 216 ) );
	
	wxBoxSizer* bInner7Sizer;
	bInner7Sizer = new wxBoxSizer( wxVERTICAL );
	
	m_Inner7CheckBox = new wxCheckBox( m_Inner7Panel, ID_INNER7CHECKBOX, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	
	bInner7Sizer->Add( m_Inner7CheckBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_Inner7Panel->SetSizer( bInner7Sizer );
	m_Inner7Panel->Layout();
	bInner7Sizer->Fit( m_Inner7Panel );
	m_LayerListFlexGridSizer->Add( m_Inner7Panel, 1, wxEXPAND, 5 );
	
	wxString m_Inner7ChoiceChoices[] = { _("signal"), _("power"), _("mixed"), _("jumper") };
	int m_Inner7ChoiceNChoices = sizeof( m_Inner7ChoiceChoices ) / sizeof( wxString );
	m_Inner7Choice = new wxChoice( m_LayersListPanel, ID_INNER7CHOICE, wxDefaultPosition, wxDefaultSize, m_Inner7ChoiceNChoices, m_Inner7ChoiceChoices, 0 );
	m_Inner7Choice->SetSelection( 0 );
	m_LayerListFlexGridSizer->Add( m_Inner7Choice, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5 );
	
	m_Inner8Name = new wxTextCtrl( m_LayersListPanel, ID_INNER8NAME, _("Inner8"), wxDefaultPosition, wxDefaultSize, 0 );
	m_LayerListFlexGridSizer->Add( m_Inner8Name, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5 );
	
	m_Inner8Panel = new wxPanel( m_LayersListPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_Inner8Panel->SetBackgroundColour( wxColour( 236, 253, 216 ) );
	
	wxBoxSizer* bInner8Sizer;
	bInner8Sizer = new wxBoxSizer( wxVERTICAL );
	
	m_Inner8CheckBox = new wxCheckBox( m_Inner8Panel, ID_INNER8CHECKBOX, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	
	bInner8Sizer->Add( m_Inner8CheckBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_Inner8Panel->SetSizer( bInner8Sizer );
	m_Inner8Panel->Layout();
	bInner8Sizer->Fit( m_Inner8Panel );
	m_LayerListFlexGridSizer->Add( m_Inner8Panel, 1, wxEXPAND, 5 );
	
	wxString m_Inner8ChoiceChoices[] = { _("signal"), _("power"), _("mixed"), _("jumper") };
	int m_Inner8ChoiceNChoices = sizeof( m_Inner8ChoiceChoices ) / sizeof( wxString );
	m_Inner8Choice = new wxChoice( m_LayersListPanel, ID_INNER8CHOICE, wxDefaultPosition, wxDefaultSize, m_Inner8ChoiceNChoices, m_Inner8ChoiceChoices, 0 );
	m_Inner8Choice->SetSelection( 0 );
	m_LayerListFlexGridSizer->Add( m_Inner8Choice, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5 );
	
	m_Inner9Name = new wxTextCtrl( m_LayersListPanel, ID_INNER9NAME, _("Inner9"), wxDefaultPosition, wxDefaultSize, 0 );
	m_LayerListFlexGridSizer->Add( m_Inner9Name, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5 );
	
	m_Inner9Panel = new wxPanel( m_LayersListPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_Inner9Panel->SetBackgroundColour( wxColour( 236, 253, 216 ) );
	
	wxBoxSizer* bInner9Sizer;
	bInner9Sizer = new wxBoxSizer( wxVERTICAL );
	
	m_Inner9CheckBox = new wxCheckBox( m_Inner9Panel, ID_INNER9CHECKBOX, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	
	bInner9Sizer->Add( m_Inner9CheckBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_Inner9Panel->SetSizer( bInner9Sizer );
	m_Inner9Panel->Layout();
	bInner9Sizer->Fit( m_Inner9Panel );
	m_LayerListFlexGridSizer->Add( m_Inner9Panel, 1, wxEXPAND, 5 );
	
	wxString m_Inner9ChoiceChoices[] = { _("signal"), _("power"), _("mixed"), _("jumper") };
	int m_Inner9ChoiceNChoices = sizeof( m_Inner9ChoiceChoices ) / sizeof( wxString );
	m_Inner9Choice = new wxChoice( m_LayersListPanel, ID_INNER9CHOICE, wxDefaultPosition, wxDefaultSize, m_Inner9ChoiceNChoices, m_Inner9ChoiceChoices, 0 );
	m_Inner9Choice->SetSelection( 0 );
	m_LayerListFlexGridSizer->Add( m_Inner9Choice, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5 );
	
	m_Inner10Name = new wxTextCtrl( m_LayersListPanel, ID_INNER10NAME, _("Inner10"), wxDefaultPosition, wxDefaultSize, 0 );
	m_LayerListFlexGridSizer->Add( m_Inner10Name, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5 );
	
	m_Inner10Panel = new wxPanel( m_LayersListPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_Inner10Panel->SetBackgroundColour( wxColour( 236, 253, 216 ) );
	
	wxBoxSizer* bInner10Sizer;
	bInner10Sizer = new wxBoxSizer( wxVERTICAL );
	
	m_Inner10CheckBox = new wxCheckBox( m_Inner10Panel, ID_INNER10CHECKBOX, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	
	bInner10Sizer->Add( m_Inner10CheckBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_Inner10Panel->SetSizer( bInner10Sizer );
	m_Inner10Panel->Layout();
	bInner10Sizer->Fit( m_Inner10Panel );
	m_LayerListFlexGridSizer->Add( m_Inner10Panel, 1, wxEXPAND, 5 );
	
	wxString m_Inner10ChoiceChoices[] = { _("signal"), _("power"), _("mixed"), _("jumper") };
	int m_Inner10ChoiceNChoices = sizeof( m_Inner10ChoiceChoices ) / sizeof( wxString );
	m_Inner10Choice = new wxChoice( m_LayersListPanel, ID_INNER10CHOICE, wxDefaultPosition, wxDefaultSize, m_Inner10ChoiceNChoices, m_Inner10ChoiceChoices, 0 );
	m_Inner10Choice->SetSelection( 0 );
	m_LayerListFlexGridSizer->Add( m_Inner10Choice, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5 );
	
	m_Inner11Name = new wxTextCtrl( m_LayersListPanel, ID_INNER11NAME, _("Inner11"), wxDefaultPosition, wxDefaultSize, 0 );
	m_LayerListFlexGridSizer->Add( m_Inner11Name, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5 );
	
	m_Inner11Panel = new wxPanel( m_LayersListPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_Inner11Panel->SetBackgroundColour( wxColour( 236, 253, 216 ) );
	
	wxBoxSizer* bInner11Sizer;
	bInner11Sizer = new wxBoxSizer( wxVERTICAL );
	
	m_Inner11CheckBox = new wxCheckBox( m_Inner11Panel, ID_INNER11CHECKBOX, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	
	bInner11Sizer->Add( m_Inner11CheckBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_Inner11Panel->SetSizer( bInner11Sizer );
	m_Inner11Panel->Layout();
	bInner11Sizer->Fit( m_Inner11Panel );
	m_LayerListFlexGridSizer->Add( m_Inner11Panel, 1, wxEXPAND, 5 );
	
	wxString m_Inner11ChoiceChoices[] = { _("signal"), _("power"), _("mixed"), _("jumper") };
	int m_Inner11ChoiceNChoices = sizeof( m_Inner11ChoiceChoices ) / sizeof( wxString );
	m_Inner11Choice = new wxChoice( m_LayersListPanel, ID_INNER11CHOICE, wxDefaultPosition, wxDefaultSize, m_Inner11ChoiceNChoices, m_Inner11ChoiceChoices, 0 );
	m_Inner11Choice->SetSelection( 0 );
	m_LayerListFlexGridSizer->Add( m_Inner11Choice, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5 );
	
	m_Inner12Name = new wxTextCtrl( m_LayersListPanel, ID_INNER12NAME, _("Inner12"), wxDefaultPosition, wxDefaultSize, 0 );
	m_LayerListFlexGridSizer->Add( m_Inner12Name, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5 );
	
	m_Inner12Panel = new wxPanel( m_LayersListPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_Inner12Panel->SetBackgroundColour( wxColour( 236, 253, 216 ) );
	
	wxBoxSizer* bInner12Sizer;
	bInner12Sizer = new wxBoxSizer( wxVERTICAL );
	
	m_Inner12CheckBox = new wxCheckBox( m_Inner12Panel, ID_INNER12CHECKBOX, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	
	bInner12Sizer->Add( m_Inner12CheckBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_Inner12Panel->SetSizer( bInner12Sizer );
	m_Inner12Panel->Layout();
	bInner12Sizer->Fit( m_Inner12Panel );
	m_LayerListFlexGridSizer->Add( m_Inner12Panel, 1, wxEXPAND, 5 );
	
	wxString m_Inner12ChoiceChoices[] = { _("signal"), _("power"), _("mixed"), _("jumper") };
	int m_Inner12ChoiceNChoices = sizeof( m_Inner12ChoiceChoices ) / sizeof( wxString );
	m_Inner12Choice = new wxChoice( m_LayersListPanel, ID_INNER12CHOICE, wxDefaultPosition, wxDefaultSize, m_Inner12ChoiceNChoices, m_Inner12ChoiceChoices, 0 );
	m_Inner12Choice->SetSelection( 0 );
	m_LayerListFlexGridSizer->Add( m_Inner12Choice, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5 );
	
	m_Inner13Name = new wxTextCtrl( m_LayersListPanel, ID_INNER13NAME, _("Inner13"), wxDefaultPosition, wxDefaultSize, 0 );
	m_LayerListFlexGridSizer->Add( m_Inner13Name, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5 );
	
	m_Inner13Panel = new wxPanel( m_LayersListPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_Inner13Panel->SetBackgroundColour( wxColour( 236, 253, 216 ) );
	
	wxBoxSizer* bInner13Sizer;
	bInner13Sizer = new wxBoxSizer( wxVERTICAL );
	
	m_Inner13CheckBox = new wxCheckBox( m_Inner13Panel, ID_INNER13CHECKBOX, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	
	bInner13Sizer->Add( m_Inner13CheckBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_Inner13Panel->SetSizer( bInner13Sizer );
	m_Inner13Panel->Layout();
	bInner13Sizer->Fit( m_Inner13Panel );
	m_LayerListFlexGridSizer->Add( m_Inner13Panel, 1, wxEXPAND, 5 );
	
	wxString m_Inner13ChoiceChoices[] = { _("signal"), _("power"), _("mixed"), _("jumper") };
	int m_Inner13ChoiceNChoices = sizeof( m_Inner13ChoiceChoices ) / sizeof( wxString );
	m_Inner13Choice = new wxChoice( m_LayersListPanel, ID_INNER13CHOICE, wxDefaultPosition, wxDefaultSize, m_Inner13ChoiceNChoices, m_Inner13ChoiceChoices, 0 );
	m_Inner13Choice->SetSelection( 0 );
	m_LayerListFlexGridSizer->Add( m_Inner13Choice, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5 );
	
	m_Inner14Name = new wxTextCtrl( m_LayersListPanel, ID_INNER14NAME, _("Inner14"), wxDefaultPosition, wxDefaultSize, 0 );
	m_LayerListFlexGridSizer->Add( m_Inner14Name, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5 );
	
	m_Inner14Panel = new wxPanel( m_LayersListPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_Inner14Panel->SetBackgroundColour( wxColour( 236, 253, 216 ) );
	
	wxBoxSizer* bInner14Sizer;
	bInner14Sizer = new wxBoxSizer( wxVERTICAL );
	
	m_Inner14CheckBox = new wxCheckBox( m_Inner14Panel, ID_INNER14CHECKBOX, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	
	bInner14Sizer->Add( m_Inner14CheckBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_Inner14Panel->SetSizer( bInner14Sizer );
	m_Inner14Panel->Layout();
	bInner14Sizer->Fit( m_Inner14Panel );
	m_LayerListFlexGridSizer->Add( m_Inner14Panel, 1, wxEXPAND, 5 );
	
	wxString m_Inner14ChoiceChoices[] = { _("signal"), _("power"), _("mixed"), _("jumper") };
	int m_Inner14ChoiceNChoices = sizeof( m_Inner14ChoiceChoices ) / sizeof( wxString );
	m_Inner14Choice = new wxChoice( m_LayersListPanel, ID_INNER14CHOICE, wxDefaultPosition, wxDefaultSize, m_Inner14ChoiceNChoices, m_Inner14ChoiceChoices, 0 );
	m_Inner14Choice->SetSelection( 0 );
	m_LayerListFlexGridSizer->Add( m_Inner14Choice, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5 );
	
	m_Inner15Name = new wxTextCtrl( m_LayersListPanel, ID_INNER15NAME, _("Inner15"), wxDefaultPosition, wxDefaultSize, 0 );
	m_LayerListFlexGridSizer->Add( m_Inner15Name, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5 );
	
	m_Inner15Panel = new wxPanel( m_LayersListPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_Inner15Panel->SetBackgroundColour( wxColour( 236, 253, 216 ) );
	
	wxBoxSizer* bInner15Sizer;
	bInner15Sizer = new wxBoxSizer( wxVERTICAL );
	
	m_Inner15CheckBox = new wxCheckBox( m_Inner15Panel, ID_INNER15CHECKBOX, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	
	bInner15Sizer->Add( m_Inner15CheckBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_Inner15Panel->SetSizer( bInner15Sizer );
	m_Inner15Panel->Layout();
	bInner15Sizer->Fit( m_Inner15Panel );
	m_LayerListFlexGridSizer->Add( m_Inner15Panel, 1, wxEXPAND, 5 );
	
	wxString m_Inner15ChoiceChoices[] = { _("signal"), _("power"), _("mixed"), _("jumper") };
	int m_Inner15ChoiceNChoices = sizeof( m_Inner15ChoiceChoices ) / sizeof( wxString );
	m_Inner15Choice = new wxChoice( m_LayersListPanel, ID_INNER15CHOICE, wxDefaultPosition, wxDefaultSize, m_Inner15ChoiceNChoices, m_Inner15ChoiceChoices, 0 );
	m_Inner15Choice->SetSelection( 0 );
	m_LayerListFlexGridSizer->Add( m_Inner15Choice, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5 );
	
	m_BackName = new wxTextCtrl( m_LayersListPanel, ID_BACKNAME, _("Back"), wxDefaultPosition, wxDefaultSize, 0 );
	m_LayerListFlexGridSizer->Add( m_BackName, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5 );
	
	m_BackPanel = new wxPanel( m_LayersListPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_BackPanel->SetBackgroundColour( wxColour( 236, 253, 216 ) );
	
	wxBoxSizer* bBackSizer;
	bBackSizer = new wxBoxSizer( wxVERTICAL );
	
	m_BackCheckBox = new wxCheckBox( m_BackPanel, ID_BACKCHECKBOX, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	
	bBackSizer->Add( m_BackCheckBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_BackPanel->SetSizer( bBackSizer );
	m_BackPanel->Layout();
	bBackSizer->Fit( m_BackPanel );
	m_LayerListFlexGridSizer->Add( m_BackPanel, 1, wxEXPAND, 5 );
	
	wxString m_BackChoiceChoices[] = { _("signal"), _("power"), _("mixed"), _("jumper") };
	int m_BackChoiceNChoices = sizeof( m_BackChoiceChoices ) / sizeof( wxString );
	m_BackChoice = new wxChoice( m_LayersListPanel, ID_BACKCHOICE, wxDefaultPosition, wxDefaultSize, m_BackChoiceNChoices, m_BackChoiceChoices, 0 );
	m_BackChoice->SetSelection( 0 );
	m_LayerListFlexGridSizer->Add( m_BackChoice, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5 );
	
	m_MaskBackName = new wxStaticText( m_LayersListPanel, ID_MASKBACKNAME, _("Mask_Back_later"), wxDefaultPosition, wxDefaultSize, 0 );
	m_MaskBackName->Wrap( -1 );
	m_LayerListFlexGridSizer->Add( m_MaskBackName, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT|wxRIGHT, 5 );
	
	m_panel21 = new wxPanel( m_LayersListPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel21->SetBackgroundColour( wxColour( 255, 252, 235 ) );
	
	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxVERTICAL );
	
	m_MaskBackCheckBox = new wxCheckBox( m_panel21, ID_MASKBACKCHECKBOX, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	
	bSizer24->Add( m_MaskBackCheckBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_panel21->SetSizer( bSizer24 );
	m_panel21->Layout();
	bSizer24->Fit( m_panel21 );
	m_LayerListFlexGridSizer->Add( m_panel21, 1, wxEXPAND, 5 );
	
	m_MaskBackStaticText = new wxStaticText( m_LayersListPanel, ID_MASKBACKCHOICE, _("On-board, non-copper"), wxDefaultPosition, wxDefaultSize, 0 );
	m_MaskBackStaticText->Wrap( -1 );
	m_LayerListFlexGridSizer->Add( m_MaskBackStaticText, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT|wxRIGHT, 5 );
	
	m_SilkSBackName = new wxStaticText( m_LayersListPanel, ID_SILKSBACKNAME, _("SilkS_Back_later"), wxDefaultPosition, wxDefaultSize, 0 );
	m_SilkSBackName->Wrap( -1 );
	m_LayerListFlexGridSizer->Add( m_SilkSBackName, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT|wxRIGHT, 5 );
	
	m_panel22 = new wxPanel( m_LayersListPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel22->SetBackgroundColour( wxColour( 255, 252, 235 ) );
	
	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxVERTICAL );
	
	m_SilkSBackCheckBox = new wxCheckBox( m_panel22, ID_SILKSBACKCHECKBOX, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	
	bSizer25->Add( m_SilkSBackCheckBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_panel22->SetSizer( bSizer25 );
	m_panel22->Layout();
	bSizer25->Fit( m_panel22 );
	m_LayerListFlexGridSizer->Add( m_panel22, 1, wxEXPAND, 5 );
	
	m_SilkSBackStaticText = new wxStaticText( m_LayersListPanel, ID_SILKSBACKCHOICE, _("On-board, non-copper"), wxDefaultPosition, wxDefaultSize, 0 );
	m_SilkSBackStaticText->Wrap( -1 );
	m_LayerListFlexGridSizer->Add( m_SilkSBackStaticText, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT|wxRIGHT, 5 );
	
	m_SoldPBackName = new wxStaticText( m_LayersListPanel, ID_SOLDPBACKNAME, _("SoldP_Back_later"), wxDefaultPosition, wxDefaultSize, 0 );
	m_SoldPBackName->Wrap( -1 );
	m_LayerListFlexGridSizer->Add( m_SoldPBackName, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT|wxRIGHT, 5 );
	
	m_panel23 = new wxPanel( m_LayersListPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel23->SetBackgroundColour( wxColour( 236, 233, 236 ) );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxVERTICAL );
	
	m_SoldPBackCheckBox = new wxCheckBox( m_panel23, ID_SOLDPBACKCHECKBOX, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	
	bSizer26->Add( m_SoldPBackCheckBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_panel23->SetSizer( bSizer26 );
	m_panel23->Layout();
	bSizer26->Fit( m_panel23 );
	m_LayerListFlexGridSizer->Add( m_panel23, 1, wxEXPAND, 5 );
	
	m_SoldPBackStaticText = new wxStaticText( m_LayersListPanel, ID_SOLDPBACKCHOICE, _("Off-board, manufacturing"), wxDefaultPosition, wxDefaultSize, 0 );
	m_SoldPBackStaticText->Wrap( -1 );
	m_LayerListFlexGridSizer->Add( m_SoldPBackStaticText, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT|wxRIGHT, 5 );
	
	m_AdhesBackName = new wxStaticText( m_LayersListPanel, ID_ADHESBACKNAME, _("Adhes_Back_later"), wxDefaultPosition, wxDefaultSize, 0 );
	m_AdhesBackName->Wrap( -1 );
	m_LayerListFlexGridSizer->Add( m_AdhesBackName, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT|wxRIGHT, 5 );
	
	m_panel24 = new wxPanel( m_LayersListPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel24->SetBackgroundColour( wxColour( 236, 233, 236 ) );
	
	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer( wxVERTICAL );
	
	m_AdhesBackCheckBox = new wxCheckBox( m_panel24, ID_ADHESBACKCHECKBOX, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	
	bSizer27->Add( m_AdhesBackCheckBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_panel24->SetSizer( bSizer27 );
	m_panel24->Layout();
	bSizer27->Fit( m_panel24 );
	m_LayerListFlexGridSizer->Add( m_panel24, 1, wxEXPAND, 5 );
	
	m_AdhesBackStaticText = new wxStaticText( m_LayersListPanel, ID_ADHESBACKCHOICE, _("Off-board, manufacturing"), wxDefaultPosition, wxDefaultSize, 0 );
	m_AdhesBackStaticText->Wrap( -1 );
	m_LayerListFlexGridSizer->Add( m_AdhesBackStaticText, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT|wxRIGHT, 5 );
	
	m_PCBEdgesName = new wxStaticText( m_LayersListPanel, ID_PCBEDGESNAME, _("PCB_Edges_later"), wxDefaultPosition, wxDefaultSize, 0 );
	m_PCBEdgesName->Wrap( -1 );
	m_LayerListFlexGridSizer->Add( m_PCBEdgesName, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT|wxRIGHT, 5 );
	
	m_panel25 = new wxPanel( m_LayersListPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel25->SetBackgroundColour( wxColour( 255, 253, 216 ) );
	
	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxVERTICAL );
	
	m_PCBEdgesCheckBox = new wxCheckBox( m_panel25, ID_PCBEDGESCHECKBOX, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	
	bSizer28->Add( m_PCBEdgesCheckBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_panel25->SetSizer( bSizer28 );
	m_panel25->Layout();
	bSizer28->Fit( m_panel25 );
	m_LayerListFlexGridSizer->Add( m_panel25, 1, wxEXPAND, 5 );
	
	m_PCBEdgesStaticText = new wxStaticText( m_LayersListPanel, ID_PCBEDGESCHOICE, _("Board contour"), wxDefaultPosition, wxDefaultSize, 0 );
	m_PCBEdgesStaticText->Wrap( -1 );
	m_LayerListFlexGridSizer->Add( m_PCBEdgesStaticText, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT|wxRIGHT, 5 );
	
	m_Eco2Name = new wxStaticText( m_LayersListPanel, ID_ECO2NAME, _("Eco2_later"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Eco2Name->Wrap( -1 );
	m_LayerListFlexGridSizer->Add( m_Eco2Name, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT|wxRIGHT, 5 );
	
	m_panel26 = new wxPanel( m_LayersListPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel26->SetBackgroundColour( wxColour( 236, 233, 255 ) );
	
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxVERTICAL );
	
	m_Eco2CheckBox = new wxCheckBox( m_panel26, ID_ECO2CHECKBOX, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	
	bSizer29->Add( m_Eco2CheckBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_panel26->SetSizer( bSizer29 );
	m_panel26->Layout();
	bSizer29->Fit( m_panel26 );
	m_LayerListFlexGridSizer->Add( m_panel26, 1, wxEXPAND, 5 );
	
	m_Eco2StaticText = new wxStaticText( m_LayersListPanel, ID_ECO2CHOICE, _("Auxiliary"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Eco2StaticText->Wrap( -1 );
	m_LayerListFlexGridSizer->Add( m_Eco2StaticText, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT|wxRIGHT, 5 );
	
	m_Eco1Name = new wxStaticText( m_LayersListPanel, ID_ECO1NAME, _("Eco1_later"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Eco1Name->Wrap( -1 );
	m_LayerListFlexGridSizer->Add( m_Eco1Name, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT|wxRIGHT, 5 );
	
	m_panel27 = new wxPanel( m_LayersListPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel27->SetBackgroundColour( wxColour( 236, 233, 255 ) );
	
	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxVERTICAL );
	
	m_Eco1CheckBox = new wxCheckBox( m_panel27, ID_ECO1CHECKBOX, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	
	bSizer30->Add( m_Eco1CheckBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_panel27->SetSizer( bSizer30 );
	m_panel27->Layout();
	bSizer30->Fit( m_panel27 );
	m_LayerListFlexGridSizer->Add( m_panel27, 1, wxEXPAND, 5 );
	
	m_Eco1StaticText = new wxStaticText( m_LayersListPanel, ID_ECO1CHOICE, _("Auxiliary"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Eco1StaticText->Wrap( -1 );
	m_LayerListFlexGridSizer->Add( m_Eco1StaticText, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT|wxRIGHT, 5 );
	
	m_CommentsName = new wxStaticText( m_LayersListPanel, ID_COMMENTSNAME, _("Comments_later"), wxDefaultPosition, wxDefaultSize, 0 );
	m_CommentsName->Wrap( -1 );
	m_LayerListFlexGridSizer->Add( m_CommentsName, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT|wxRIGHT, 5 );
	
	m_panel28 = new wxPanel( m_LayersListPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel28->SetBackgroundColour( wxColour( 236, 233, 255 ) );
	
	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxVERTICAL );
	
	m_CommentsCheckBox = new wxCheckBox( m_panel28, ID_COMMENTSCHECKBOX, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	
	bSizer31->Add( m_CommentsCheckBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_panel28->SetSizer( bSizer31 );
	m_panel28->Layout();
	bSizer31->Fit( m_panel28 );
	m_LayerListFlexGridSizer->Add( m_panel28, 1, wxEXPAND, 5 );
	
	m_CommentsStaticText = new wxStaticText( m_LayersListPanel, ID_COMMENTSCHOICE, _("Auxiliary"), wxDefaultPosition, wxDefaultSize, 0 );
	m_CommentsStaticText->Wrap( -1 );
	m_LayerListFlexGridSizer->Add( m_CommentsStaticText, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT|wxRIGHT, 5 );
	
	m_DrawingsName = new wxStaticText( m_LayersListPanel, ID_DRAWINGSNAME, _("Drawings_later"), wxDefaultPosition, wxDefaultSize, 0 );
	m_DrawingsName->Wrap( -1 );
	m_LayerListFlexGridSizer->Add( m_DrawingsName, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT|wxRIGHT, 5 );
	
	m_panel29 = new wxPanel( m_LayersListPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel29->SetBackgroundColour( wxColour( 236, 233, 255 ) );
	
	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxVERTICAL );
	
	m_DrawingsCheckBox = new wxCheckBox( m_panel29, ID_DRAWINGSCHECKBOX, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	
	bSizer32->Add( m_DrawingsCheckBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_panel29->SetSizer( bSizer32 );
	m_panel29->Layout();
	bSizer32->Fit( m_panel29 );
	m_LayerListFlexGridSizer->Add( m_panel29, 1, wxEXPAND, 5 );
	
	m_DrawingsStaticText = new wxStaticText( m_LayersListPanel, ID_DRAWINGSCHOICE, _("Auxiliary"), wxDefaultPosition, wxDefaultSize, 0 );
	m_DrawingsStaticText->Wrap( -1 );
	m_LayerListFlexGridSizer->Add( m_DrawingsStaticText, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_LayersListPanel->SetSizer( m_LayerListFlexGridSizer );
	m_LayersListPanel->Layout();
	m_LayerListFlexGridSizer->Fit( m_LayersListPanel );
	sbLayersSizer->Add( m_LayersListPanel, 1, wxALL|wxEXPAND, 5 );
	
	bMainSizer->Add( sbLayersSizer, 1, wxALIGN_CENTER_HORIZONTAL|wxALL|wxEXPAND, 5 );
	
	m_sdbSizer2 = new wxStdDialogButtonSizer();
	m_sdbSizer2OK = new wxButton( this, wxID_OK );
	m_sdbSizer2->AddButton( m_sdbSizer2OK );
	m_sdbSizer2Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer2->AddButton( m_sdbSizer2Cancel );
	m_sdbSizer2->Realize();
	bMainSizer->Add( m_sdbSizer2, 0, wxALL|wxEXPAND, 5 );
	
	this->SetSizer( bMainSizer );
	this->Layout();
	bMainSizer->Fit( this );
	
	// Connect Events
	m_PresetsChoice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::OnPresetsChoice ), NULL, this );
	m_CopperLayersChoice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::OnCopperLayersChoice ), NULL, this );
	m_AdhesFrontCheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::OnCheckBox ), NULL, this );
	m_SoldPFrontCheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::OnCheckBox ), NULL, this );
	m_SilkSFrontCheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::OnCheckBox ), NULL, this );
	m_MaskFrontCheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::OnCheckBox ), NULL, this );
	m_FrontCheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::DenyChangeCheckBox ), NULL, this );
	m_Inner2CheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::DenyChangeCheckBox ), NULL, this );
	m_Inner3CheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::DenyChangeCheckBox ), NULL, this );
	m_Inner4CheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::DenyChangeCheckBox ), NULL, this );
	m_Inner5CheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::DenyChangeCheckBox ), NULL, this );
	m_Inner6CheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::DenyChangeCheckBox ), NULL, this );
	m_Inner7CheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::DenyChangeCheckBox ), NULL, this );
	m_Inner8CheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::DenyChangeCheckBox ), NULL, this );
	m_Inner9CheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::DenyChangeCheckBox ), NULL, this );
	m_Inner10CheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::DenyChangeCheckBox ), NULL, this );
	m_Inner11CheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::DenyChangeCheckBox ), NULL, this );
	m_Inner12CheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::DenyChangeCheckBox ), NULL, this );
	m_Inner13CheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::DenyChangeCheckBox ), NULL, this );
	m_Inner14CheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::DenyChangeCheckBox ), NULL, this );
	m_Inner15CheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::DenyChangeCheckBox ), NULL, this );
	m_BackCheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::DenyChangeCheckBox ), NULL, this );
	m_MaskBackCheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::OnCheckBox ), NULL, this );
	m_SilkSBackCheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::OnCheckBox ), NULL, this );
	m_SoldPBackCheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::OnCheckBox ), NULL, this );
	m_AdhesBackCheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::OnCheckBox ), NULL, this );
	m_PCBEdgesCheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::OnCheckBox ), NULL, this );
	m_Eco2CheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::OnCheckBox ), NULL, this );
	m_Eco1CheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::OnCheckBox ), NULL, this );
	m_CommentsCheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::OnCheckBox ), NULL, this );
	m_DrawingsCheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::OnCheckBox ), NULL, this );
	m_sdbSizer2Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::OnCancelButtonClick ), NULL, this );
	m_sdbSizer2OK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::OnOkButtonClick ), NULL, this );
}

DIALOG_LAYERS_SETUP_BASE2::~DIALOG_LAYERS_SETUP_BASE2()
{
	// Disconnect Events
	m_PresetsChoice->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::OnPresetsChoice ), NULL, this );
	m_CopperLayersChoice->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::OnCopperLayersChoice ), NULL, this );
	m_AdhesFrontCheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::OnCheckBox ), NULL, this );
	m_SoldPFrontCheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::OnCheckBox ), NULL, this );
	m_SilkSFrontCheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::OnCheckBox ), NULL, this );
	m_MaskFrontCheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::OnCheckBox ), NULL, this );
	m_FrontCheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::DenyChangeCheckBox ), NULL, this );
	m_Inner2CheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::DenyChangeCheckBox ), NULL, this );
	m_Inner3CheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::DenyChangeCheckBox ), NULL, this );
	m_Inner4CheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::DenyChangeCheckBox ), NULL, this );
	m_Inner5CheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::DenyChangeCheckBox ), NULL, this );
	m_Inner6CheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::DenyChangeCheckBox ), NULL, this );
	m_Inner7CheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::DenyChangeCheckBox ), NULL, this );
	m_Inner8CheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::DenyChangeCheckBox ), NULL, this );
	m_Inner9CheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::DenyChangeCheckBox ), NULL, this );
	m_Inner10CheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::DenyChangeCheckBox ), NULL, this );
	m_Inner11CheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::DenyChangeCheckBox ), NULL, this );
	m_Inner12CheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::DenyChangeCheckBox ), NULL, this );
	m_Inner13CheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::DenyChangeCheckBox ), NULL, this );
	m_Inner14CheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::DenyChangeCheckBox ), NULL, this );
	m_Inner15CheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::DenyChangeCheckBox ), NULL, this );
	m_BackCheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::DenyChangeCheckBox ), NULL, this );
	m_MaskBackCheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::OnCheckBox ), NULL, this );
	m_SilkSBackCheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::OnCheckBox ), NULL, this );
	m_SoldPBackCheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::OnCheckBox ), NULL, this );
	m_AdhesBackCheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::OnCheckBox ), NULL, this );
	m_PCBEdgesCheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::OnCheckBox ), NULL, this );
	m_Eco2CheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::OnCheckBox ), NULL, this );
	m_Eco1CheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::OnCheckBox ), NULL, this );
	m_CommentsCheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::OnCheckBox ), NULL, this );
	m_DrawingsCheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::OnCheckBox ), NULL, this );
	m_sdbSizer2Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::OnCancelButtonClick ), NULL, this );
	m_sdbSizer2OK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_LAYERS_SETUP_BASE2::OnOkButtonClick ), NULL, this );
}
