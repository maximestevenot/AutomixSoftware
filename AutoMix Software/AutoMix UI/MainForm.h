// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#pragma once

#include "ViewWithTrackCollection.h"
#include "AutoMixColorTable.h"
#include "Presenter.h"

namespace AutoMixUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace AutoMixDataManagement;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form, public ViewWithTrackCollection
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			_menuStrip->RenderMode = ToolStripRenderMode::Professional;
			_menuStrip->Renderer = gcnew ToolStripProfessionalRenderer(gcnew AutoMixColorTable());
			_trackContextMenu->RenderMode = ToolStripRenderMode::Professional;
			_trackContextMenu->Renderer = gcnew ToolStripProfessionalRenderer(gcnew AutoMixColorTable());

			_presenter = gcnew Presenter(this);

			_cancelMenuItem->Enabled = false;
			_generateButton->Enabled = false;
			_sortButton->Enabled = false;
			_playerbutton->Enabled = false;
			_toolStripProgressBar->Visible = false;
			AnOperationRunning = false;

			_insertionLineColor = Color::LightGray;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	public:

		property bool AnOperationRunning
		{
			bool get() { return _anOperationRunning; }
		private:
			void set(bool value) { _anOperationRunning = value; }
		}


	private:
		Presenter^ _presenter;

		bool _isPlayerPlaying = false;
		bool _playerExists = false;
		System::String^ _exportPath = System::IO::Path::GetTempPath() + "AutomixSoftware\\preview.mp3";

		property bool IsRowDragInProgress;
		property bool IsDragImportInProgress;
		bool _anOperationRunning;

		enum class InsertionModeType
		{
			Before,
			After
		};

		int _insertionIndex;
		InsertionModeType _insertionMode;
		Color _insertionLineColor;

	private: System::Windows::Forms::MenuStrip^  _menuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^  _fileToolStripMenuItem;

	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator;
	private: System::Windows::Forms::ToolStripMenuItem^  _quitMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  _helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  _aboutMenuItem;
	private: System::Windows::Forms::StatusStrip^  _statusStrip;
	private: System::Windows::Forms::ListView^  _musicListView;
	private: System::Windows::Forms::ColumnHeader^  collectionDuration;
	private: System::Windows::Forms::ColumnHeader^  collectionBPM;
	private: System::Windows::Forms::ColumnHeader^  collectionName;
	private: System::Windows::Forms::Button^  _importButton;
	private: System::Windows::Forms::Button^  _generateButton;
	private: System::Windows::Forms::PictureBox^  _logo;
	private: System::Windows::Forms::ColumnHeader^  collectionKey;
	private: System::Windows::Forms::Button^  _sortButton;
	private: System::Windows::Forms::ToolStripMenuItem^  _cancelMenuItem;
	private: System::ComponentModel::BackgroundWorker^  _importBackgroundWorker;
	private: System::ComponentModel::BackgroundWorker^  _sortBackgroundWorker;
	private: System::Windows::Forms::ToolStripProgressBar^  _toolStripProgressBar;
	private: System::Windows::Forms::ToolStripStatusLabel^  _toolStripCurrentDir;
	private: System::Windows::Forms::ToolStripMenuItem^  _optionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  _dataBaseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  _clearDBMenuItem;
	private: System::ComponentModel::BackgroundWorker^  _exportBackgroundWorker;
	private: System::Windows::Forms::ToolTip^  _toolTip;
	private: System::Windows::Forms::ContextMenuStrip^  _trackContextMenu;
	private: System::Windows::Forms::ToolStripMenuItem^  _deleteTrackToolStrip;
	private: System::Windows::Forms::ToolStripMenuItem^  _selectAllToolStrip;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutCharacteristicsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;

	private: System::ComponentModel::BackgroundWorker^  _playerBackgroundWorker;
	private: System::Windows::Forms::ToolStripMenuItem^  _importMenuItem;
	private: System::Windows::Forms::Panel^  panel1;
private: System::Windows::Forms::Button^  _playerbutton;

private: System::Windows::Forms::BindingSource^  bindingSource1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->_menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->_fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_importMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_cancelMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->_quitMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_optionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_dataBaseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_clearDBMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutCharacteristicsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->_aboutMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_statusStrip = (gcnew System::Windows::Forms::StatusStrip());
			this->_toolStripProgressBar = (gcnew System::Windows::Forms::ToolStripProgressBar());
			this->_toolStripCurrentDir = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->_musicListView = (gcnew System::Windows::Forms::ListView());
			this->collectionName = (gcnew System::Windows::Forms::ColumnHeader());
			this->collectionDuration = (gcnew System::Windows::Forms::ColumnHeader());
			this->collectionBPM = (gcnew System::Windows::Forms::ColumnHeader());
			this->collectionKey = (gcnew System::Windows::Forms::ColumnHeader());
			this->_trackContextMenu = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->_deleteTrackToolStrip = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_selectAllToolStrip = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_importButton = (gcnew System::Windows::Forms::Button());
			this->_generateButton = (gcnew System::Windows::Forms::Button());
			this->_logo = (gcnew System::Windows::Forms::PictureBox());
			this->_sortButton = (gcnew System::Windows::Forms::Button());
			this->_importBackgroundWorker = (gcnew System::ComponentModel::BackgroundWorker());
			this->_sortBackgroundWorker = (gcnew System::ComponentModel::BackgroundWorker());
			this->_exportBackgroundWorker = (gcnew System::ComponentModel::BackgroundWorker());
			this->_toolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->_playerBackgroundWorker = (gcnew System::ComponentModel::BackgroundWorker());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->bindingSource1 = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->_playerbutton = (gcnew System::Windows::Forms::Button());
			this->_menuStrip->SuspendLayout();
			this->_statusStrip->SuspendLayout();
			this->_trackContextMenu->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->_logo))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->BeginInit();
			this->SuspendLayout();
			// 
			// _menuStrip
			// 
			this->_menuStrip->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(19)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)));
			this->_menuStrip->ImageScalingSize = System::Drawing::Size(20, 20);
			this->_menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->_fileToolStripMenuItem,
					this->_optionsToolStripMenuItem, this->_helpToolStripMenuItem
			});
			this->_menuStrip->Location = System::Drawing::Point(0, 0);
			this->_menuStrip->Name = L"_menuStrip";
			this->_menuStrip->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			this->_menuStrip->Size = System::Drawing::Size(1064, 24);
			this->_menuStrip->TabIndex = 2;
			this->_menuStrip->Text = L"menuStrip1";
			// 
			// _fileToolStripMenuItem
			// 
			this->_fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->_importMenuItem,
					this->_cancelMenuItem, this->toolStripSeparator, this->_quitMenuItem
			});
			this->_fileToolStripMenuItem->ForeColor = System::Drawing::Color::White;
			this->_fileToolStripMenuItem->Name = L"_fileToolStripMenuItem";
			this->_fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->_fileToolStripMenuItem->Text = L"&File";
			// 
			// _importMenuItem
			// 
			this->_importMenuItem->ForeColor = System::Drawing::Color::White;
			this->_importMenuItem->Name = L"_importMenuItem";
			this->_importMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->_importMenuItem->Size = System::Drawing::Size(162, 22);
			this->_importMenuItem->Text = L"&Import...";
			this->_importMenuItem->Click += gcnew System::EventHandler(this, &MainForm::onImportMenuItemClick);
			// 
			// _cancelMenuItem
			// 
			this->_cancelMenuItem->ForeColor = System::Drawing::Color::White;
			this->_cancelMenuItem->Name = L"_cancelMenuItem";
			this->_cancelMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Z));
			this->_cancelMenuItem->Size = System::Drawing::Size(162, 22);
			this->_cancelMenuItem->Text = L"&Cancel";
			this->_cancelMenuItem->ToolTipText = L"Cancel all operations";
			this->_cancelMenuItem->Click += gcnew System::EventHandler(this, &MainForm::onCancelMenuItemClick);
			// 
			// toolStripSeparator
			// 
			this->toolStripSeparator->Name = L"toolStripSeparator";
			this->toolStripSeparator->Size = System::Drawing::Size(159, 6);
			// 
			// _quitMenuItem
			// 
			this->_quitMenuItem->ForeColor = System::Drawing::Color::White;
			this->_quitMenuItem->Name = L"_quitMenuItem";
			this->_quitMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Q));
			this->_quitMenuItem->Size = System::Drawing::Size(162, 22);
			this->_quitMenuItem->Text = L"&Quit";
			this->_quitMenuItem->Click += gcnew System::EventHandler(this, &MainForm::onQuitMenuItemClick);
			// 
			// _optionsToolStripMenuItem
			// 
			this->_optionsToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->_optionsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->_dataBaseToolStripMenuItem });
			this->_optionsToolStripMenuItem->ForeColor = System::Drawing::Color::White;
			this->_optionsToolStripMenuItem->Name = L"_optionsToolStripMenuItem";
			this->_optionsToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->_optionsToolStripMenuItem->Text = L"&Options";
			this->_optionsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::onClearDBMenuItemClick);
			// 
			// _dataBaseToolStripMenuItem
			// 
			this->_dataBaseToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->_clearDBMenuItem });
			this->_dataBaseToolStripMenuItem->ForeColor = System::Drawing::Color::White;
			this->_dataBaseToolStripMenuItem->Name = L"_dataBaseToolStripMenuItem";
			this->_dataBaseToolStripMenuItem->Size = System::Drawing::Size(122, 22);
			this->_dataBaseToolStripMenuItem->Text = L"&Database";
			// 
			// _clearDBMenuItem
			// 
			this->_clearDBMenuItem->ForeColor = System::Drawing::Color::White;
			this->_clearDBMenuItem->Name = L"_clearDBMenuItem";
			this->_clearDBMenuItem->Size = System::Drawing::Size(101, 22);
			this->_clearDBMenuItem->Text = L"&Clear";
			this->_clearDBMenuItem->Click += gcnew System::EventHandler(this, &MainForm::onClearDBMenuItemClick);
			// 
			// _helpToolStripMenuItem
			// 
			this->_helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->aboutCharacteristicsToolStripMenuItem,
					this->toolStripSeparator1, this->_aboutMenuItem
			});
			this->_helpToolStripMenuItem->ForeColor = System::Drawing::Color::White;
			this->_helpToolStripMenuItem->Name = L"_helpToolStripMenuItem";
			this->_helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->_helpToolStripMenuItem->Text = L"&Help";
			// 
			// aboutCharacteristicsToolStripMenuItem
			// 
			this->aboutCharacteristicsToolStripMenuItem->ForeColor = System::Drawing::Color::White;
			this->aboutCharacteristicsToolStripMenuItem->Name = L"aboutCharacteristicsToolStripMenuItem";
			this->aboutCharacteristicsToolStripMenuItem->Size = System::Drawing::Size(194, 22);
			this->aboutCharacteristicsToolStripMenuItem->Text = L"About &characteristics...";
			this->aboutCharacteristicsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::onAboutCharacteristicsMenuItemClick);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(191, 6);
			// 
			// _aboutMenuItem
			// 
			this->_aboutMenuItem->ForeColor = System::Drawing::Color::White;
			this->_aboutMenuItem->Name = L"_aboutMenuItem";
			this->_aboutMenuItem->Size = System::Drawing::Size(194, 22);
			this->_aboutMenuItem->Text = L"About &application...";
			this->_aboutMenuItem->Click += gcnew System::EventHandler(this, &MainForm::onAboutMenuItemClick);
			// 
			// _statusStrip
			// 
			this->_statusStrip->AccessibleName = L"_statusStrip";
			this->_statusStrip->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(19)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)));
			this->_statusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->_toolStripProgressBar,
					this->_toolStripCurrentDir
			});
			this->_statusStrip->Location = System::Drawing::Point(0, 626);
			this->_statusStrip->Name = L"_statusStrip";
			this->_statusStrip->Size = System::Drawing::Size(1064, 22);
			this->_statusStrip->TabIndex = 3;
			this->_statusStrip->Text = L"statusStrip1";
			// 
			// _toolStripProgressBar
			// 
			this->_toolStripProgressBar->Margin = System::Windows::Forms::Padding(3, 3, 1, 3);
			this->_toolStripProgressBar->Maximum = 1000;
			this->_toolStripProgressBar->Name = L"_toolStripProgressBar";
			this->_toolStripProgressBar->Size = System::Drawing::Size(150, 16);
			// 
			// _toolStripCurrentDir
			// 
			this->_toolStripCurrentDir->Margin = System::Windows::Forms::Padding(5, 3, 0, 2);
			this->_toolStripCurrentDir->Name = L"_toolStripCurrentDir";
			this->_toolStripCurrentDir->Size = System::Drawing::Size(0, 17);
			// 
			// _musicListView
			// 
			this->_musicListView->AccessibleName = L"_musicListView";
			this->_musicListView->AllowDrop = true;
			this->_musicListView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_musicListView->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(19)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)));
			this->_musicListView->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->_musicListView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->collectionName,
					this->collectionDuration, this->collectionBPM, this->collectionKey
			});
			this->_musicListView->ContextMenuStrip = this->_trackContextMenu;
			this->_musicListView->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->_musicListView->ForeColor = System::Drawing::Color::White;
			this->_musicListView->FullRowSelect = true;
			this->_musicListView->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->_musicListView->Location = System::Drawing::Point(0, 275);
			this->_musicListView->Name = L"_musicListView";
			this->_musicListView->OwnerDraw = true;
			this->_musicListView->Size = System::Drawing::Size(1064, 348);
			this->_musicListView->TabIndex = 4;
			this->_musicListView->UseCompatibleStateImageBehavior = false;
			this->_musicListView->View = System::Windows::Forms::View::Details;
			this->_musicListView->DrawColumnHeader += gcnew System::Windows::Forms::DrawListViewColumnHeaderEventHandler(this, &MainForm::musicListView_DrawColumnHeader);
			this->_musicListView->DrawItem += gcnew System::Windows::Forms::DrawListViewItemEventHandler(this, &MainForm::musicListView_DrawItem);
			this->_musicListView->DrawSubItem += gcnew System::Windows::Forms::DrawListViewSubItemEventHandler(this, &MainForm::musicListView_DrawSubItem);
			this->_musicListView->ItemDrag += gcnew System::Windows::Forms::ItemDragEventHandler(this, &MainForm::musicListView_ItemDrag);
			this->_musicListView->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::musicListView_DragDrop);
			this->_musicListView->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::musicListView_DragEnter);
			this->_musicListView->DragOver += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::musicListView_DragOver);
			// 
			// collectionName
			// 
			this->collectionName->Text = L"Name";
			this->collectionName->Width = 681;
			// 
			// collectionDuration
			// 
			this->collectionDuration->Text = L"Duration";
			this->collectionDuration->Width = 162;
			// 
			// collectionBPM
			// 
			this->collectionBPM->Text = L"BPM";
			this->collectionBPM->Width = 72;
			// 
			// collectionKey
			// 
			this->collectionKey->Text = L"Key";
			this->collectionKey->Width = 71;
			// 
			// _trackContextMenu
			// 
			this->_trackContextMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->_deleteTrackToolStrip,
					this->_selectAllToolStrip
			});
			this->_trackContextMenu->Name = L"_listViewcontextMenu";
			this->_trackContextMenu->Size = System::Drawing::Size(165, 48);
			this->_trackContextMenu->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &MainForm::onTrackContextMenuOpening);
			// 
			// _deleteTrackToolStrip
			// 
			this->_deleteTrackToolStrip->Enabled = false;
			this->_deleteTrackToolStrip->ForeColor = System::Drawing::Color::White;
			this->_deleteTrackToolStrip->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"_deleteTrackToolStrip.Image")));
			this->_deleteTrackToolStrip->Name = L"_deleteTrackToolStrip";
			this->_deleteTrackToolStrip->ShortcutKeys = System::Windows::Forms::Keys::Delete;
			this->_deleteTrackToolStrip->Size = System::Drawing::Size(164, 22);
			this->_deleteTrackToolStrip->Text = L"&Remove";
			this->_deleteTrackToolStrip->Click += gcnew System::EventHandler(this, &MainForm::onDeleteTrackToolStripClick);
			// 
			// _selectAllToolStrip
			// 
			this->_selectAllToolStrip->ForeColor = System::Drawing::Color::White;
			this->_selectAllToolStrip->Name = L"_selectAllToolStrip";
			this->_selectAllToolStrip->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::A));
			this->_selectAllToolStrip->Size = System::Drawing::Size(164, 22);
			this->_selectAllToolStrip->Text = L"Select All";
			this->_selectAllToolStrip->Click += gcnew System::EventHandler(this, &MainForm::onSelectAllMenuItemClick);
			// 
			// _importButton
			// 
			this->_importButton->AccessibleName = L"_importButton";
			this->_importButton->BackColor = System::Drawing::Color::DarkMagenta;
			this->_importButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->_importButton->FlatAppearance->BorderSize = 0;
			this->_importButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(151)), static_cast<System::Int32>(static_cast<System::Byte>(151)));
			this->_importButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->_importButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_importButton->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->_importButton->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->_importButton->Location = System::Drawing::Point(12, 188);
			this->_importButton->MinimumSize = System::Drawing::Size(200, 0);
			this->_importButton->Name = L"_importButton";
			this->_importButton->Size = System::Drawing::Size(348, 78);
			this->_importButton->TabIndex = 5;
			this->_importButton->Text = L"Import Tracks";
			this->_toolTip->SetToolTip(this->_importButton, L"Click to import new tracks");
			this->_importButton->UseVisualStyleBackColor = false;
			this->_importButton->EnabledChanged += gcnew System::EventHandler(this, &MainForm::onButtonEnabledChanged);
			this->_importButton->Click += gcnew System::EventHandler(this, &MainForm::onImportButtonClick);
			// 
			// _generateButton
			// 
			this->_generateButton->AccessibleName = L"_generateButton";
			this->_generateButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->_generateButton->BackColor = System::Drawing::Color::DarkMagenta;
			this->_generateButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->_generateButton->FlatAppearance->BorderSize = 0;
			this->_generateButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(151)), static_cast<System::Int32>(static_cast<System::Byte>(151)));
			this->_generateButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->_generateButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_generateButton->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->_generateButton->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->_generateButton->Location = System::Drawing::Point(742, 188);
			this->_generateButton->MinimumSize = System::Drawing::Size(200, 0);
			this->_generateButton->Name = L"_generateButton";
			this->_generateButton->Size = System::Drawing::Size(310, 78);
			this->_generateButton->TabIndex = 6;
			this->_generateButton->Text = L"Generate Mix";
			this->_toolTip->SetToolTip(this->_generateButton, L"Click to export an mp3 file");
			this->_generateButton->UseVisualStyleBackColor = false;
			this->_generateButton->EnabledChanged += gcnew System::EventHandler(this, &MainForm::onButtonEnabledChanged);
			this->_generateButton->Click += gcnew System::EventHandler(this, &MainForm::onExportButtonClick);
			// 
			// _logo
			// 
			this->_logo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"_logo.Image")));
			this->_logo->Location = System::Drawing::Point(12, 37);
			this->_logo->Name = L"_logo";
			this->_logo->Size = System::Drawing::Size(387, 134);
			this->_logo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->_logo->TabIndex = 7;
			this->_logo->TabStop = false;
			// 
			// _sortButton
			// 
			this->_sortButton->AccessibleName = L"_sortButton";
			this->_sortButton->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->_sortButton->BackColor = System::Drawing::Color::DarkMagenta;
			this->_sortButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->_sortButton->FlatAppearance->BorderSize = 0;
			this->_sortButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(151)), static_cast<System::Int32>(static_cast<System::Byte>(151)));
			this->_sortButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->_sortButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_sortButton->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->_sortButton->ForeColor = System::Drawing::Color::White;
			this->_sortButton->Location = System::Drawing::Point(386, 188);
			this->_sortButton->MinimumSize = System::Drawing::Size(200, 0);
			this->_sortButton->Name = L"_sortButton";
			this->_sortButton->Size = System::Drawing::Size(330, 78);
			this->_sortButton->TabIndex = 8;
			this->_sortButton->Text = L"Sort";
			this->_toolTip->SetToolTip(this->_sortButton, L"Click to sort tracks using AutoMix AI");
			this->_sortButton->UseVisualStyleBackColor = false;
			this->_sortButton->EnabledChanged += gcnew System::EventHandler(this, &MainForm::onButtonEnabledChanged);
			this->_sortButton->Click += gcnew System::EventHandler(this, &MainForm::onSortButtonClick);
			// 
			// _importBackgroundWorker
			// 
			this->_importBackgroundWorker->WorkerReportsProgress = true;
			this->_importBackgroundWorker->WorkerSupportsCancellation = true;
			this->_importBackgroundWorker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MainForm::importBW_DoWork);
			this->_importBackgroundWorker->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MainForm::importBW_ProgressChanged);
			this->_importBackgroundWorker->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MainForm::importBW_RunWorkerCompleted);
			// 
			// _sortBackgroundWorker
			// 
			this->_sortBackgroundWorker->WorkerReportsProgress = true;
			this->_sortBackgroundWorker->WorkerSupportsCancellation = true;
			this->_sortBackgroundWorker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MainForm::sortBW_DoWork);
			this->_sortBackgroundWorker->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MainForm::sortBW_ProgressChanged);
			this->_sortBackgroundWorker->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MainForm::sortBW_RunWorkerCompleted);
			// 
			// _exportBackgroundWorker
			// 
			this->_exportBackgroundWorker->WorkerReportsProgress = true;
			this->_exportBackgroundWorker->WorkerSupportsCancellation = true;
			this->_exportBackgroundWorker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MainForm::exportBW_DoWork);
			this->_exportBackgroundWorker->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MainForm::exportBW_ProgressChanged);
			this->_exportBackgroundWorker->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MainForm::exportBW_RunWorkerCompleted);
			// 
			// _playerBackgroundWorker
			// 
			this->_playerBackgroundWorker->WorkerReportsProgress = true;
			this->_playerBackgroundWorker->WorkerSupportsCancellation = true;
			this->_playerBackgroundWorker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MainForm::playerBackgroundWorker_DoWork);
			this->_playerBackgroundWorker->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MainForm::playerBackgroundWorker_ProgressChanged);
			this->_playerBackgroundWorker->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MainForm::playerBackgroundWorker_RunWorkerCompleted);
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(37)));
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->_playerbutton);
			this->panel1->Location = System::Drawing::Point(417, 37);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(635, 134);
			this->panel1->TabIndex = 10;
			// 
			// _playerbutton
			// 
			this->_playerbutton->AccessibleName = L"_playerbutton";
			this->_playerbutton->BackColor = System::Drawing::Color::DarkMagenta;
			this->_playerbutton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->_playerbutton->FlatAppearance->BorderSize = 0;
			this->_playerbutton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(151)), static_cast<System::Int32>(static_cast<System::Byte>(151)));
			this->_playerbutton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->_playerbutton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_playerbutton->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->_playerbutton->ForeColor = System::Drawing::Color::White;
			this->_playerbutton->Location = System::Drawing::Point(20, 30);
			this->_playerbutton->MinimumSize = System::Drawing::Size(200, 0);
			this->_playerbutton->Name = L"_playerbutton";
			this->_playerbutton->Size = System::Drawing::Size(200, 78);
			this->_playerbutton->TabIndex = 11;
			this->_playerbutton->Text = L"Play Mix";
			this->_toolTip->SetToolTip(this->_playerbutton, L"Click to preview the music mix");
			this->_playerbutton->UseVisualStyleBackColor = false;
			this->_playerbutton->Click += gcnew System::EventHandler(this, &MainForm::onPlayerButtonClick);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(19)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)));
			this->ClientSize = System::Drawing::Size(1064, 648);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->_sortButton);
			this->Controls->Add(this->_logo);
			this->Controls->Add(this->_importButton);
			this->Controls->Add(this->_musicListView);
			this->Controls->Add(this->_statusStrip);
			this->Controls->Add(this->_menuStrip);
			this->Controls->Add(this->_generateButton);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->_menuStrip;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MinimumSize = System::Drawing::Size(1080, 687);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Automix Software";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::onMainFormClosing);
			this->Load += gcnew System::EventHandler(this, &MainForm::MyForm_Load);
			this->_menuStrip->ResumeLayout(false);
			this->_menuStrip->PerformLayout();
			this->_statusStrip->ResumeLayout(false);
			this->_statusStrip->PerformLayout();
			this->_trackContextMenu->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->_logo))->EndInit();
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		System::Void update(TrackCollection^) override;

	private:
		System::Void onWorkerStart();
		System::Void onWorkerStop();

		System::Void showCancelDialog();
		System::Void showErrorDialog(System::String^);
		bool showExitDialog();

		System::Void exitApplication();

		System::Void loadTracks(System::Object^  sender, System::EventArgs^  e);
		System::Void exportTrackList(System::Object^  sender, System::EventArgs^  e);
		System::Void sortTrackList(System::Object^ sender, System::EventArgs^ e);

		System::Void MainForm::drawInsertionLine();
		System::Void MainForm::drawInsertionLine(int x1, int y, int width);

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {}

	private: System::Void onQuitMenuItemClick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void onImportMenuItemClick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void onImportButtonClick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void onExportButtonClick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void onSortButtonClick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void onCancelMenuItemClick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void onAboutMenuItemClick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void onAboutCharacteristicsMenuItemClick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void onClearDBMenuItemClick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void onDeleteTrackToolStripClick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void onSelectAllMenuItemClick(System::Object^  sender, System::EventArgs^  e);

	private: System::Void importBW_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e);
	private: System::Void importBW_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e);
	private: System::Void importBW_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e);

	private: System::Void sortBW_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e);
	private: System::Void sortBW_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e);
	private: System::Void sortBW_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e);

	private: System::Void exportBW_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e);
	private: System::Void exportBW_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e);
	private: System::Void exportBW_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e);

	private: System::Void onTrackContextMenuOpening(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e);
	private: System::Void onMainFormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);

	private: System::Void musicListView_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e);
	private: System::Void musicListView_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e);
	private: System::Void musicListView_ItemDrag(System::Object^  sender, System::Windows::Forms::ItemDragEventArgs^  e);
	private: System::Void musicListView_DragOver(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e);

	private: System::Void onPlayerButtonClick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void playerBackgroundWorker_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e);
	private: System::Void playerBackgroundWorker_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e);
	private: System::Void playerBackgroundWorker_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e);

	private: System::Void stopPlayer();
	private: System::Void onButtonEnabledChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void musicListView_DrawItem(System::Object^  sender, System::Windows::Forms::DrawListViewItemEventArgs^  e);
	private: System::Void musicListView_DrawColumnHeader(System::Object^  sender, System::Windows::Forms::DrawListViewColumnHeaderEventArgs^  e);

	private: System::Void musicListView_DrawSubItem(System::Object^  sender, System::Windows::Forms::DrawListViewSubItemEventArgs^  e);
};

}
