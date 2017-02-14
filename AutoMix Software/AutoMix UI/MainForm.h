// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#pragma once

#include "ViewWithTrackCollection.h"
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
			_presenter = gcnew Presenter(this);

			_cancelToolStripMenuItem->Enabled = false;
			_outputButton->Enabled = false;
			_sortButton->Enabled = false;
			_toolStripProgressBar->Visible = false;
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

	private:
		Presenter^ _presenter;

	private: System::Windows::Forms::MenuStrip^  menuStrip1;

	private: System::Windows::Forms::ToolStripMenuItem^  _fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  _openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator;
	private: System::Windows::Forms::ToolStripMenuItem^  _quitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  _helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  _aboutToolStripMenuItem;
	private: System::Windows::Forms::StatusStrip^  _statusStrip;
	private: System::Windows::Forms::ListView^  _musicListView;
	private: System::Windows::Forms::ColumnHeader^  collectionDuration;
	private: System::Windows::Forms::ColumnHeader^  collectionBPM;
	private: System::Windows::Forms::ColumnHeader^  collectionName;
	private: System::Windows::Forms::Button^  _imputButton;
	private: System::Windows::Forms::Button^  _outputButton;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::ColumnHeader^  collectionKey;
	private: System::Windows::Forms::Button^  _sortButton;
	private: System::Windows::Forms::ToolStripMenuItem^  _cancelToolStripMenuItem;
	private: System::ComponentModel::BackgroundWorker^  _backgroundWorker1;
	private: System::ComponentModel::BackgroundWorker^  _backgroundWorker2;
	private: System::Windows::Forms::ToolStripProgressBar^  _toolStripProgressBar;


	private: System::Windows::Forms::ToolStripStatusLabel^  _toolStripCurrentDir;
	private: System::Windows::Forms::ToolStripMenuItem^  optionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  dataBaseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  _clearDBToolStripMenuItem;
	private: System::ComponentModel::BackgroundWorker^  _backgroundWorker3;
	private: System::Windows::Forms::ToolTip^  _toolTip;
	private: System::Windows::Forms::ContextMenuStrip^  _listViewcontextMenu;
	private: System::Windows::Forms::ToolStripMenuItem^  _toolStripDeleteTrack;


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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->_fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_cancelToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->_quitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->optionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dataBaseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_clearDBToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_statusStrip = (gcnew System::Windows::Forms::StatusStrip());
			this->_toolStripProgressBar = (gcnew System::Windows::Forms::ToolStripProgressBar());
			this->_toolStripCurrentDir = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->_musicListView = (gcnew System::Windows::Forms::ListView());
			this->collectionName = (gcnew System::Windows::Forms::ColumnHeader());
			this->collectionDuration = (gcnew System::Windows::Forms::ColumnHeader());
			this->collectionBPM = (gcnew System::Windows::Forms::ColumnHeader());
			this->collectionKey = (gcnew System::Windows::Forms::ColumnHeader());
			this->_listViewcontextMenu = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->_toolStripDeleteTrack = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_imputButton = (gcnew System::Windows::Forms::Button());
			this->_outputButton = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->_sortButton = (gcnew System::Windows::Forms::Button());
			this->_backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->_backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			this->_backgroundWorker3 = (gcnew System::ComponentModel::BackgroundWorker());
			this->_toolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->menuStrip1->SuspendLayout();
			this->_statusStrip->SuspendLayout();
			this->_listViewcontextMenu->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->_fileToolStripMenuItem,
					this->optionsToolStripMenuItem, this->_helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(1264, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// _fileToolStripMenuItem
			// 
			this->_fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->_openToolStripMenuItem,
					this->_cancelToolStripMenuItem, this->toolStripSeparator, this->_quitToolStripMenuItem
			});
			this->_fileToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ControlText;
			this->_fileToolStripMenuItem->Name = L"_fileToolStripMenuItem";
			this->_fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->_fileToolStripMenuItem->Text = L"&File";
			this->_fileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::_fileToolStripMenuItem_Click);
			// 
			// _openToolStripMenuItem
			// 
			this->_openToolStripMenuItem->Checked = true;
			this->_openToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Indeterminate;
			this->_openToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"_openToolStripMenuItem.Image")));
			this->_openToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->_openToolStripMenuItem->Name = L"_openToolStripMenuItem";
			this->_openToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->_openToolStripMenuItem->Size = System::Drawing::Size(155, 22);
			this->_openToolStripMenuItem->Text = L"&Open...";
			this->_openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::_openToolStripMenuItem_Click);
			// 
			// _cancelToolStripMenuItem
			// 
			this->_cancelToolStripMenuItem->Name = L"_cancelToolStripMenuItem";
			this->_cancelToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C));
			this->_cancelToolStripMenuItem->Size = System::Drawing::Size(155, 22);
			this->_cancelToolStripMenuItem->Text = L"&Cancel";
			this->_cancelToolStripMenuItem->ToolTipText = L"Cancel all operations";
			this->_cancelToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::_cancelToolStripMenuItem_Click);
			// 
			// toolStripSeparator
			// 
			this->toolStripSeparator->Name = L"toolStripSeparator";
			this->toolStripSeparator->Size = System::Drawing::Size(152, 6);
			// 
			// _quitToolStripMenuItem
			// 
			this->_quitToolStripMenuItem->Name = L"_quitToolStripMenuItem";
			this->_quitToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Q));
			this->_quitToolStripMenuItem->Size = System::Drawing::Size(155, 22);
			this->_quitToolStripMenuItem->Text = L"&Quit";
			this->_quitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::_quitToolStripMenuItem_Click);
			// 
			// optionsToolStripMenuItem
			// 
			this->optionsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->dataBaseToolStripMenuItem });
			this->optionsToolStripMenuItem->Name = L"optionsToolStripMenuItem";
			this->optionsToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->optionsToolStripMenuItem->Text = L"&Options";
			this->optionsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::_clearDBToolStripMenuItem_Click);
			// 
			// dataBaseToolStripMenuItem
			// 
			this->dataBaseToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->_clearDBToolStripMenuItem });
			this->dataBaseToolStripMenuItem->Name = L"dataBaseToolStripMenuItem";
			this->dataBaseToolStripMenuItem->Size = System::Drawing::Size(122, 22);
			this->dataBaseToolStripMenuItem->Text = L"&Database";
			// 
			// _clearDBToolStripMenuItem
			// 
			this->_clearDBToolStripMenuItem->Name = L"_clearDBToolStripMenuItem";
			this->_clearDBToolStripMenuItem->Size = System::Drawing::Size(101, 22);
			this->_clearDBToolStripMenuItem->Text = L"&Clear";
			this->_clearDBToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::_clearDBToolStripMenuItem_Click);
			// 
			// _helpToolStripMenuItem
			// 
			this->_helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->_aboutToolStripMenuItem });
			this->_helpToolStripMenuItem->Name = L"_helpToolStripMenuItem";
			this->_helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->_helpToolStripMenuItem->Text = L"&Help";
			// 
			// _aboutToolStripMenuItem
			// 
			this->_aboutToolStripMenuItem->Name = L"_aboutToolStripMenuItem";
			this->_aboutToolStripMenuItem->Size = System::Drawing::Size(116, 22);
			this->_aboutToolStripMenuItem->Text = L"&About...";
			this->_aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::_aboutToolStripMenuItem_Click);
			// 
			// _statusStrip
			// 
			this->_statusStrip->AccessibleName = L"_statusStrip";
			this->_statusStrip->BackColor = System::Drawing::SystemColors::GrayText;
			this->_statusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->_toolStripProgressBar,
					this->_toolStripCurrentDir
			});
			this->_statusStrip->Location = System::Drawing::Point(0, 660);
			this->_statusStrip->Name = L"_statusStrip";
			this->_statusStrip->Size = System::Drawing::Size(1264, 22);
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
			this->_musicListView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_musicListView->BackColor = System::Drawing::SystemColors::ControlDark;
			this->_musicListView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->collectionName,
					this->collectionDuration, this->collectionBPM, this->collectionKey
			});
			this->_musicListView->ContextMenuStrip = this->_listViewcontextMenu;
			this->_musicListView->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->_musicListView->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->_musicListView->FullRowSelect = true;
			this->_musicListView->Location = System::Drawing::Point(0, 275);
			this->_musicListView->Name = L"_musicListView";
			this->_musicListView->Size = System::Drawing::Size(1264, 381);
			this->_musicListView->TabIndex = 4;
			this->_musicListView->UseCompatibleStateImageBehavior = false;
			this->_musicListView->View = System::Windows::Forms::View::Details;
			this->_musicListView->ColumnClick += gcnew System::Windows::Forms::ColumnClickEventHandler(this, &MainForm::_musicListView_ColumnClick);
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
			// _listViewcontextMenu
			// 
			this->_listViewcontextMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->_toolStripDeleteTrack });
			this->_listViewcontextMenu->Name = L"_listViewcontextMenu";
			this->_listViewcontextMenu->Size = System::Drawing::Size(153, 48);
			this->_listViewcontextMenu->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &MainForm::_listViewcontextMenu_Opening);
			// 
			// _toolStripDeleteTrack
			// 
			this->_toolStripDeleteTrack->Enabled = false;
			this->_toolStripDeleteTrack->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"_toolStripDeleteTrack.Image")));
			this->_toolStripDeleteTrack->Name = L"_toolStripDeleteTrack";
			this->_toolStripDeleteTrack->Size = System::Drawing::Size(152, 22);
			this->_toolStripDeleteTrack->Text = L"&Remove";
			this->_toolStripDeleteTrack->Click += gcnew System::EventHandler(this, &MainForm::toolStripDeleteTrack_Click);
			// 
			// _imputButton
			// 
			this->_imputButton->AccessibleName = L"_inputButton";
			this->_imputButton->BackColor = System::Drawing::SystemColors::ControlDark;
			this->_imputButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->_imputButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->_imputButton->Location = System::Drawing::Point(70, 114);
			this->_imputButton->Name = L"_imputButton";
			this->_imputButton->Size = System::Drawing::Size(147, 78);
			this->_imputButton->TabIndex = 5;
			this->_imputButton->Text = L"Import Tracks";
			this->_toolTip->SetToolTip(this->_imputButton, L"Click to import new tracks");
			this->_imputButton->UseVisualStyleBackColor = false;
			this->_imputButton->Click += gcnew System::EventHandler(this, &MainForm::_imputButton_Click);
			// 
			// _outputButton
			// 
			this->_outputButton->AccessibleName = L"_outputButton";
			this->_outputButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->_outputButton->BackColor = System::Drawing::SystemColors::ControlDark;
			this->_outputButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->_outputButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->_outputButton->Location = System::Drawing::Point(1054, 67);
			this->_outputButton->Name = L"_outputButton";
			this->_outputButton->Size = System::Drawing::Size(147, 78);
			this->_outputButton->TabIndex = 6;
			this->_outputButton->Text = L"Generate Mix";
			this->_toolTip->SetToolTip(this->_outputButton, L"Click to export an mp3 file");
			this->_outputButton->UseVisualStyleBackColor = false;
			this->_outputButton->Click += gcnew System::EventHandler(this, &MainForm::_outputButton_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(311, 38);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(653, 226);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			// 
			// _sortButton
			// 
			this->_sortButton->AccessibleName = L"_sortButton";
			this->_sortButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->_sortButton->BackColor = System::Drawing::SystemColors::ControlDark;
			this->_sortButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->_sortButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->_sortButton->Location = System::Drawing::Point(1054, 174);
			this->_sortButton->Name = L"_sortButton";
			this->_sortButton->Size = System::Drawing::Size(147, 78);
			this->_sortButton->TabIndex = 8;
			this->_sortButton->Text = L"Sort";
			this->_toolTip->SetToolTip(this->_sortButton, L"Click to sort tracks using AutoMix AI");
			this->_sortButton->UseVisualStyleBackColor = false;
			this->_sortButton->Click += gcnew System::EventHandler(this, &MainForm::_sortButton_click);
			// 
			// _backgroundWorker1
			// 
			this->_backgroundWorker1->WorkerReportsProgress = true;
			this->_backgroundWorker1->WorkerSupportsCancellation = true;
			this->_backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MainForm::_backgroundWorker1_DoWork);
			this->_backgroundWorker1->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MainForm::_backgroundWorker1_ProgressChanged);
			this->_backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MainForm::_backgroundWorker1_RunWorkerCompleted);
			// 
			// _backgroundWorker2
			// 
			this->_backgroundWorker2->WorkerReportsProgress = true;
			this->_backgroundWorker2->WorkerSupportsCancellation = true;
			this->_backgroundWorker2->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MainForm::_backgroundWorker2_DoWork);
			this->_backgroundWorker2->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MainForm::_backgroundWorker2_ProgressChanged);
			this->_backgroundWorker2->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MainForm::_backgroundWorker2_RunWorkerCompleted);
			// 
			// _backgroundWorker3
			// 
			this->_backgroundWorker3->WorkerReportsProgress = true;
			this->_backgroundWorker3->WorkerSupportsCancellation = true;
			this->_backgroundWorker3->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MainForm::_backgroundWorker3_DoWork);
			this->_backgroundWorker3->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MainForm::_backgroundWorker3_ProgressChanged);
			this->_backgroundWorker3->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MainForm::_backgroundWorker3_RunWorkerCompleted);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ClientSize = System::Drawing::Size(1264, 682);
			this->Controls->Add(this->_sortButton);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->_outputButton);
			this->Controls->Add(this->_imputButton);
			this->Controls->Add(this->_musicListView);
			this->Controls->Add(this->_statusStrip);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MinimumSize = System::Drawing::Size(1280, 720);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AutoMix Software";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MainForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->_statusStrip->ResumeLayout(false);
			this->_statusStrip->PerformLayout();
			this->_listViewcontextMenu->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
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

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {}
	private: System::Void _fileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {}
	private: System::Void _quitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void _openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void loadTracks(System::Object^  sender, System::EventArgs^  e);
	private: System::Void exportTrackList(System::Object^  sender, System::EventArgs^  e);
	private: System::Void sortTracksWithGeneticAlgorithm(System::Object^ sender, System::EventArgs^ e);
	private: System::Void _imputButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void _outputButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void _musicListView_ColumnClick(System::Object^ sender, ColumnClickEventArgs^ e);
	private: System::Void _sortButton_click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);
	private: System::Void _backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e);
	private: System::Void _backgroundWorker1_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e);
	private: System::Void _cancelToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void _backgroundWorker2_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e);
	private: System::Void _backgroundWorker2_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e);
	private: System::Void _aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void _clearDBToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void _backgroundWorker1_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e);
	private: System::Void _backgroundWorker2_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e);
	private: System::Void _backgroundWorker3_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e);
	private: System::Void _backgroundWorker3_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e);
	private: System::Void _backgroundWorker3_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e);
	private: System::Void toolStripDeleteTrack_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void _listViewcontextMenu_Opening(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e);
};

}
