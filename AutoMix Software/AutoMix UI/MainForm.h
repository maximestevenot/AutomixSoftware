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

	public ref class MainForm : public System::Windows::Forms::Form, public ViewWithTrackCollection
	{
	public:
		MainForm(void);

		property bool AnOperationRunning
		{
			bool get() { return _anOperationRunning; }
		private:
			void set(bool value) { _anOperationRunning = value; }
		}

		System::Void update(TrackCollection^) override;

	protected:
		~MainForm();

	private:
		Presenter^ _presenter;

		bool _isPlayerPlaying = false;
		bool _playerExists = false;
		System::String^ _defaultExportPath = System::IO::Path::GetTempPath() + "AutomixSoftware\\preview.mp3";
		System::String^ _exportPath = _defaultExportPath;

		property bool IsRowDragInProgress;
		property bool IsDragImportInProgress;
		bool _anOperationRunning;

		enum class InsertionModeType
		{
			Before,
			After
		};

		property System::Drawing::Bitmap^ PlayIcon { System::Drawing::Bitmap^ get(); }
		property System::Drawing::Bitmap^ PauseIcon { System::Drawing::Bitmap^ get(); }
		property System::Drawing::Bitmap^ SeekIcon { System::Drawing::Bitmap^ get(); }
		System::Drawing::Bitmap^ _playIcon;
		System::Drawing::Bitmap^ _pauseIcon;
		System::Drawing::Bitmap^ _seekIcon;

		int _insertionIndex;
		InsertionModeType _insertionMode;
		System::Drawing::Color _insertionLineColor;

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
	private: System::Windows::Forms::ToolStripMenuItem^  _aboutCharacteristicsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;

	private: System::ComponentModel::BackgroundWorker^  _playerBackgroundWorker;
	private: System::Windows::Forms::ToolStripMenuItem^  _importMenuItem;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  _playerbutton;

	private: System::Windows::Forms::BindingSource^  bindingSource1;
	private: System::Windows::Forms::TrackBar^  _playerTrackBar;
	private: System::Windows::Forms::Timer^  _trackBarTimer;
	private: System::Windows::Forms::Button^  _skipButton;
	private: System::Windows::Forms::ToolStripMenuItem^  _stopMixToolStripMenuItem;

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
			this->_stopMixToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_aboutCharacteristicsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->_playerbutton = (gcnew System::Windows::Forms::Button());
			this->_skipButton = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->_playerTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->_playerBackgroundWorker = (gcnew System::ComponentModel::BackgroundWorker());
			this->bindingSource1 = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->_trackBarTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->_menuStrip->SuspendLayout();
			this->_statusStrip->SuspendLayout();
			this->_trackContextMenu->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->_logo))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->_playerTrackBar))->BeginInit();
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
			resources->ApplyResources(this->_menuStrip, L"_menuStrip");
			this->_menuStrip->Name = L"_menuStrip";
			// 
			// _fileToolStripMenuItem
			// 
			this->_fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->_importMenuItem,
					this->_cancelMenuItem, this->toolStripSeparator, this->_quitMenuItem
			});
			this->_fileToolStripMenuItem->ForeColor = System::Drawing::Color::White;
			this->_fileToolStripMenuItem->Name = L"_fileToolStripMenuItem";
			resources->ApplyResources(this->_fileToolStripMenuItem, L"_fileToolStripMenuItem");
			// 
			// _importMenuItem
			// 
			this->_importMenuItem->ForeColor = System::Drawing::Color::White;
			this->_importMenuItem->Name = L"_importMenuItem";
			resources->ApplyResources(this->_importMenuItem, L"_importMenuItem");
			this->_importMenuItem->Click += gcnew System::EventHandler(this, &MainForm::onImportMenuItemClick);
			// 
			// _cancelMenuItem
			// 
			this->_cancelMenuItem->ForeColor = System::Drawing::Color::White;
			this->_cancelMenuItem->Name = L"_cancelMenuItem";
			resources->ApplyResources(this->_cancelMenuItem, L"_cancelMenuItem");
			this->_cancelMenuItem->Click += gcnew System::EventHandler(this, &MainForm::onCancelMenuItemClick);
			// 
			// toolStripSeparator
			// 
			this->toolStripSeparator->Name = L"toolStripSeparator";
			resources->ApplyResources(this->toolStripSeparator, L"toolStripSeparator");
			// 
			// _quitMenuItem
			// 
			this->_quitMenuItem->ForeColor = System::Drawing::Color::White;
			this->_quitMenuItem->Name = L"_quitMenuItem";
			resources->ApplyResources(this->_quitMenuItem, L"_quitMenuItem");
			this->_quitMenuItem->Click += gcnew System::EventHandler(this, &MainForm::onQuitMenuItemClick);
			// 
			// _optionsToolStripMenuItem
			// 
			this->_optionsToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->_optionsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->_dataBaseToolStripMenuItem,
					this->_stopMixToolStripMenuItem
			});
			this->_optionsToolStripMenuItem->ForeColor = System::Drawing::Color::White;
			this->_optionsToolStripMenuItem->Name = L"_optionsToolStripMenuItem";
			resources->ApplyResources(this->_optionsToolStripMenuItem, L"_optionsToolStripMenuItem");
			this->_optionsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::onClearDBMenuItemClick);
			// 
			// _dataBaseToolStripMenuItem
			// 
			this->_dataBaseToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->_clearDBMenuItem });
			this->_dataBaseToolStripMenuItem->ForeColor = System::Drawing::Color::White;
			this->_dataBaseToolStripMenuItem->Name = L"_dataBaseToolStripMenuItem";
			resources->ApplyResources(this->_dataBaseToolStripMenuItem, L"_dataBaseToolStripMenuItem");
			// 
			// _clearDBMenuItem
			// 
			this->_clearDBMenuItem->ForeColor = System::Drawing::Color::White;
			this->_clearDBMenuItem->Name = L"_clearDBMenuItem";
			resources->ApplyResources(this->_clearDBMenuItem, L"_clearDBMenuItem");
			this->_clearDBMenuItem->Click += gcnew System::EventHandler(this, &MainForm::onClearDBMenuItemClick);
			// 
			// _stopMixToolStripMenuItem
			// 
			this->_stopMixToolStripMenuItem->ForeColor = System::Drawing::Color::White;
			this->_stopMixToolStripMenuItem->Name = L"_stopMixToolStripMenuItem";
			resources->ApplyResources(this->_stopMixToolStripMenuItem, L"_stopMixToolStripMenuItem");
			this->_stopMixToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::onStopMixToolStripMenuItemClick);
			// 
			// _helpToolStripMenuItem
			// 
			this->_helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->_aboutCharacteristicsToolStripMenuItem,
					this->toolStripSeparator1, this->_aboutMenuItem
			});
			this->_helpToolStripMenuItem->ForeColor = System::Drawing::Color::White;
			this->_helpToolStripMenuItem->Name = L"_helpToolStripMenuItem";
			resources->ApplyResources(this->_helpToolStripMenuItem, L"_helpToolStripMenuItem");
			// 
			// _aboutCharacteristicsToolStripMenuItem
			// 
			this->_aboutCharacteristicsToolStripMenuItem->ForeColor = System::Drawing::Color::White;
			this->_aboutCharacteristicsToolStripMenuItem->Name = L"_aboutCharacteristicsToolStripMenuItem";
			resources->ApplyResources(this->_aboutCharacteristicsToolStripMenuItem, L"_aboutCharacteristicsToolStripMenuItem");
			this->_aboutCharacteristicsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::onAboutCharacteristicsMenuItemClick);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			resources->ApplyResources(this->toolStripSeparator1, L"toolStripSeparator1");
			// 
			// _aboutMenuItem
			// 
			this->_aboutMenuItem->ForeColor = System::Drawing::Color::White;
			this->_aboutMenuItem->Name = L"_aboutMenuItem";
			resources->ApplyResources(this->_aboutMenuItem, L"_aboutMenuItem");
			this->_aboutMenuItem->Click += gcnew System::EventHandler(this, &MainForm::onAboutMenuItemClick);
			// 
			// _statusStrip
			// 
			resources->ApplyResources(this->_statusStrip, L"_statusStrip");
			this->_statusStrip->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(19)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)));
			this->_statusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->_toolStripProgressBar,
					this->_toolStripCurrentDir
			});
			this->_statusStrip->Name = L"_statusStrip";
			// 
			// _toolStripProgressBar
			// 
			this->_toolStripProgressBar->Margin = System::Windows::Forms::Padding(3, 3, 1, 3);
			this->_toolStripProgressBar->Maximum = 1000;
			this->_toolStripProgressBar->Name = L"_toolStripProgressBar";
			resources->ApplyResources(this->_toolStripProgressBar, L"_toolStripProgressBar");
			// 
			// _toolStripCurrentDir
			// 
			this->_toolStripCurrentDir->Margin = System::Windows::Forms::Padding(5, 3, 0, 2);
			this->_toolStripCurrentDir->Name = L"_toolStripCurrentDir";
			resources->ApplyResources(this->_toolStripCurrentDir, L"_toolStripCurrentDir");
			// 
			// _musicListView
			// 
			resources->ApplyResources(this->_musicListView, L"_musicListView");
			this->_musicListView->AllowDrop = true;
			this->_musicListView->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(19)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)));
			this->_musicListView->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->_musicListView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->collectionName,
					this->collectionDuration, this->collectionBPM, this->collectionKey
			});
			this->_musicListView->ContextMenuStrip = this->_trackContextMenu;
			this->_musicListView->ForeColor = System::Drawing::Color::White;
			this->_musicListView->FullRowSelect = true;
			this->_musicListView->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->_musicListView->Name = L"_musicListView";
			this->_musicListView->OwnerDraw = true;
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
			resources->ApplyResources(this->collectionName, L"collectionName");
			// 
			// collectionDuration
			// 
			resources->ApplyResources(this->collectionDuration, L"collectionDuration");
			// 
			// collectionBPM
			// 
			resources->ApplyResources(this->collectionBPM, L"collectionBPM");
			// 
			// collectionKey
			// 
			resources->ApplyResources(this->collectionKey, L"collectionKey");
			// 
			// _trackContextMenu
			// 
			this->_trackContextMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->_deleteTrackToolStrip,
					this->_selectAllToolStrip
			});
			this->_trackContextMenu->Name = L"_listViewcontextMenu";
			resources->ApplyResources(this->_trackContextMenu, L"_trackContextMenu");
			this->_trackContextMenu->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &MainForm::onTrackContextMenuOpening);
			// 
			// _deleteTrackToolStrip
			// 
			resources->ApplyResources(this->_deleteTrackToolStrip, L"_deleteTrackToolStrip");
			this->_deleteTrackToolStrip->ForeColor = System::Drawing::Color::White;
			this->_deleteTrackToolStrip->Name = L"_deleteTrackToolStrip";
			this->_deleteTrackToolStrip->Click += gcnew System::EventHandler(this, &MainForm::onDeleteTrackToolStripClick);
			// 
			// _selectAllToolStrip
			// 
			this->_selectAllToolStrip->ForeColor = System::Drawing::Color::White;
			this->_selectAllToolStrip->Name = L"_selectAllToolStrip";
			resources->ApplyResources(this->_selectAllToolStrip, L"_selectAllToolStrip");
			this->_selectAllToolStrip->Click += gcnew System::EventHandler(this, &MainForm::onSelectAllMenuItemClick);
			// 
			// _importButton
			// 
			resources->ApplyResources(this->_importButton, L"_importButton");
			this->_importButton->BackColor = System::Drawing::Color::DarkMagenta;
			this->_importButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->_importButton->FlatAppearance->BorderSize = 0;
			this->_importButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(151)), static_cast<System::Int32>(static_cast<System::Byte>(151)));
			this->_importButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->_importButton->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->_importButton->Name = L"_importButton";
			this->_toolTip->SetToolTip(this->_importButton, resources->GetString(L"_importButton.ToolTip"));
			this->_importButton->UseVisualStyleBackColor = false;
			this->_importButton->EnabledChanged += gcnew System::EventHandler(this, &MainForm::onButtonEnabledChanged);
			this->_importButton->Click += gcnew System::EventHandler(this, &MainForm::onImportButtonClick);
			// 
			// _generateButton
			// 
			resources->ApplyResources(this->_generateButton, L"_generateButton");
			this->_generateButton->BackColor = System::Drawing::Color::DarkMagenta;
			this->_generateButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->_generateButton->FlatAppearance->BorderSize = 0;
			this->_generateButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(151)), static_cast<System::Int32>(static_cast<System::Byte>(151)));
			this->_generateButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->_generateButton->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->_generateButton->Name = L"_generateButton";
			this->_toolTip->SetToolTip(this->_generateButton, resources->GetString(L"_generateButton.ToolTip"));
			this->_generateButton->UseVisualStyleBackColor = false;
			this->_generateButton->EnabledChanged += gcnew System::EventHandler(this, &MainForm::onButtonEnabledChanged);
			this->_generateButton->Click += gcnew System::EventHandler(this, &MainForm::onExportButtonClick);
			// 
			// _logo
			// 
			resources->ApplyResources(this->_logo, L"_logo");
			this->_logo->Name = L"_logo";
			this->_logo->TabStop = false;
			// 
			// _sortButton
			// 
			resources->ApplyResources(this->_sortButton, L"_sortButton");
			this->_sortButton->BackColor = System::Drawing::Color::DarkMagenta;
			this->_sortButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->_sortButton->FlatAppearance->BorderSize = 0;
			this->_sortButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(151)), static_cast<System::Int32>(static_cast<System::Byte>(151)));
			this->_sortButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->_sortButton->ForeColor = System::Drawing::Color::White;
			this->_sortButton->Name = L"_sortButton";
			this->_toolTip->SetToolTip(this->_sortButton, resources->GetString(L"_sortButton.ToolTip"));
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
			// _playerbutton
			// 
			resources->ApplyResources(this->_playerbutton, L"_playerbutton");
			this->_playerbutton->BackColor = System::Drawing::Color::DarkMagenta;
			this->_playerbutton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->_playerbutton->FlatAppearance->BorderSize = 0;
			this->_playerbutton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(151)), static_cast<System::Int32>(static_cast<System::Byte>(151)));
			this->_playerbutton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->_playerbutton->ForeColor = System::Drawing::Color::White;
			this->_playerbutton->Name = L"_playerbutton";
			this->_toolTip->SetToolTip(this->_playerbutton, resources->GetString(L"_playerbutton.ToolTip"));
			this->_playerbutton->UseVisualStyleBackColor = false;
			this->_playerbutton->Click += gcnew System::EventHandler(this, &MainForm::onPlayerButtonClick);
			// 
			// _skipButton
			// 
			resources->ApplyResources(this->_skipButton, L"_skipButton");
			this->_skipButton->BackColor = System::Drawing::Color::DarkMagenta;
			this->_skipButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->_skipButton->FlatAppearance->BorderSize = 0;
			this->_skipButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(151)), static_cast<System::Int32>(static_cast<System::Byte>(151)));
			this->_skipButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->_skipButton->ForeColor = System::Drawing::Color::White;
			this->_skipButton->Name = L"_skipButton";
			this->_toolTip->SetToolTip(this->_skipButton, resources->GetString(L"_skipButton.ToolTip"));
			this->_skipButton->UseVisualStyleBackColor = false;
			this->_skipButton->Click += gcnew System::EventHandler(this, &MainForm::onSkipButtonClick);
			// 
			// panel1
			// 
			resources->ApplyResources(this->panel1, L"panel1");
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(37)));
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->_skipButton);
			this->panel1->Controls->Add(this->_playerTrackBar);
			this->panel1->Controls->Add(this->_playerbutton);
			this->panel1->Name = L"panel1";
			// 
			// _playerTrackBar
			// 
			resources->ApplyResources(this->_playerTrackBar, L"_playerTrackBar");
			this->_playerTrackBar->Maximum = 10000;
			this->_playerTrackBar->Name = L"_playerTrackBar";
			this->_playerTrackBar->TickStyle = System::Windows::Forms::TickStyle::None;
			// 
			// _playerBackgroundWorker
			// 
			this->_playerBackgroundWorker->WorkerReportsProgress = true;
			this->_playerBackgroundWorker->WorkerSupportsCancellation = true;
			this->_playerBackgroundWorker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MainForm::playerBackgroundWorker_DoWork);
			this->_playerBackgroundWorker->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MainForm::playerBackgroundWorker_ProgressChanged);
			this->_playerBackgroundWorker->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MainForm::playerBackgroundWorker_RunWorkerCompleted);
			// 
			// _trackBarTimer
			// 
			this->_trackBarTimer->Interval = 500;
			this->_trackBarTimer->Tick += gcnew System::EventHandler(this, &MainForm::trackBarTimer_Tick);
			// 
			// MainForm
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(19)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)));
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->_sortButton);
			this->Controls->Add(this->_logo);
			this->Controls->Add(this->_importButton);
			this->Controls->Add(this->_musicListView);
			this->Controls->Add(this->_statusStrip);
			this->Controls->Add(this->_menuStrip);
			this->Controls->Add(this->_generateButton);
			this->MainMenuStrip = this->_menuStrip;
			this->Name = L"MainForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::onMainFormClosing);
			this->Load += gcnew System::EventHandler(this, &MainForm::MyForm_Load);
			this->_menuStrip->ResumeLayout(false);
			this->_menuStrip->PerformLayout();
			this->_statusStrip->ResumeLayout(false);
			this->_statusStrip->PerformLayout();
			this->_trackContextMenu->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->_logo))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->_playerTrackBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Void onWorkerStart();
		System::Void onWorkerStop();
		System::Void stopPlayer();
		System::Void onButtonEnabledChanged(System::Object^  sender, System::EventArgs^  e);
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
	private: System::Void onPlayerButtonClick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void onSkipButtonClick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void onStopMixToolStripMenuItemClick(System::Object^  sender, System::EventArgs^  e);

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

	private: System::Void playerBackgroundWorker_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e);
	private: System::Void playerBackgroundWorker_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e);
	private: System::Void playerBackgroundWorker_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e);

	private: System::Void trackBarTimer_Tick(System::Object^  sender, System::EventArgs^  e);

	private: System::Void musicListView_DrawItem(System::Object^  sender, System::Windows::Forms::DrawListViewItemEventArgs^  e);
	private: System::Void musicListView_DrawColumnHeader(System::Object^  sender, System::Windows::Forms::DrawListViewColumnHeaderEventArgs^  e);
	private: System::Void musicListView_DrawSubItem(System::Object^  sender, System::Windows::Forms::DrawListViewSubItemEventArgs^  e);

	};

}
