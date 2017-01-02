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
	private: System::Windows::Forms::FolderBrowserDialog^  _inputMusicFolderBrowserDialog;

	private: System::Windows::Forms::StatusStrip^  _statusStrip;

	private: System::Windows::Forms::FolderBrowserDialog^  _outputMusicFolderBrowserDialog;
	private: System::Windows::Forms::ListView^  _musicListView;
	private: System::Windows::Forms::ColumnHeader^  collectionDuration;
	private: System::Windows::Forms::ColumnHeader^  collectionBPM;




	private: System::Windows::Forms::ColumnHeader^  collectionName;


	private: System::Windows::Forms::Button^  _imputButton;
	private: System::Windows::Forms::Button^  _outputButton;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::ColumnHeader^  collectionKey;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->_fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->_quitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_inputMusicFolderBrowserDialog = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->_statusStrip = (gcnew System::Windows::Forms::StatusStrip());
			this->_outputMusicFolderBrowserDialog = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->_musicListView = (gcnew System::Windows::Forms::ListView());
			this->collectionName = (gcnew System::Windows::Forms::ColumnHeader());
			this->collectionDuration = (gcnew System::Windows::Forms::ColumnHeader());
			this->collectionBPM = (gcnew System::Windows::Forms::ColumnHeader());
			this->_imputButton = (gcnew System::Windows::Forms::Button());
			this->_outputButton = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->collectionKey = (gcnew System::Windows::Forms::ColumnHeader());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->_fileToolStripMenuItem,
					this->_helpToolStripMenuItem
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
			this->_fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->_openToolStripMenuItem,
					this->toolStripSeparator, this->_quitToolStripMenuItem
			});
			this->_fileToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ControlText;
			this->_fileToolStripMenuItem->Name = L"_fileToolStripMenuItem";
			this->_fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->_fileToolStripMenuItem->Text = L"&File";
			this->_fileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::_fileToolStripMenuItem_Click);
			// 
			// _openToolStripMenuItem
			// 
			this->_openToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"_openToolStripMenuItem.Image")));
			this->_openToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->_openToolStripMenuItem->Name = L"_openToolStripMenuItem";
			this->_openToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->_openToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->_openToolStripMenuItem->Text = L"&Open";
			this->_openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::_openToolStripMenuItem_Click);
			// 
			// toolStripSeparator
			// 
			this->toolStripSeparator->Name = L"toolStripSeparator";
			this->toolStripSeparator->Size = System::Drawing::Size(143, 6);
			// 
			// _quitToolStripMenuItem
			// 
			this->_quitToolStripMenuItem->Name = L"_quitToolStripMenuItem";
			this->_quitToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->_quitToolStripMenuItem->Text = L"&Quit";
			this->_quitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::_quitToolStripMenuItem_Click);
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
			this->_aboutToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->_aboutToolStripMenuItem->Text = L"&About";
			// 
			// _statusStrip
			// 
			this->_statusStrip->AccessibleName = L"_statusStrip";
			this->_statusStrip->BackColor = System::Drawing::SystemColors::GrayText;
			this->_statusStrip->Location = System::Drawing::Point(0, 659);
			this->_statusStrip->Name = L"_statusStrip";
			this->_statusStrip->Size = System::Drawing::Size(1264, 22);
			this->_statusStrip->TabIndex = 3;
			this->_statusStrip->Text = L"statusStrip1";
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
			// _imputButton
			// 
			this->_imputButton->AccessibleName = L"_inputButton";
			this->_imputButton->BackColor = System::Drawing::SystemColors::ControlDark;
			this->_imputButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->_imputButton->Location = System::Drawing::Point(70, 114);
			this->_imputButton->Name = L"_imputButton";
			this->_imputButton->Size = System::Drawing::Size(147, 78);
			this->_imputButton->TabIndex = 5;
			this->_imputButton->Text = L"Import Tracks";
			this->_imputButton->UseVisualStyleBackColor = false;
			this->_imputButton->Click += gcnew System::EventHandler(this, &MainForm::_imputButton_Click);
			// 
			// _outputButton
			// 
			this->_outputButton->AccessibleName = L"_outputButton";
			this->_outputButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->_outputButton->BackColor = System::Drawing::SystemColors::ControlDark;
			this->_outputButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->_outputButton->Location = System::Drawing::Point(1050, 114);
			this->_outputButton->Name = L"_outputButton";
			this->_outputButton->Size = System::Drawing::Size(147, 78);
			this->_outputButton->TabIndex = 6;
			this->_outputButton->Text = L"Generate Mix";
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
			// collectionKey
			// 
			this->collectionKey->Text = L"Key";
			this->collectionKey->Width = 71;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ClientSize = System::Drawing::Size(1264, 681);
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
			this->Load += gcnew System::EventHandler(this, &MainForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: System::Void update(TrackCollection^) override;


	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {}
	private: System::Void _fileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {}

	private: System::Void _quitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void _openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void loadTracksFromDirectory(System::Object^  sender, System::EventArgs^  e);
	private: System::Void exportTrackList(System::Object^  sender, System::EventArgs^  e);
	private: System::Void _imputButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void _outputButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void _musicListView_ColumnClick(System::Object^ sender, ColumnClickEventArgs^ e);
	};

}
