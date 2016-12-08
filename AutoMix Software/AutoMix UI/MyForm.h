#pragma once
#include "Track.h"
#include "TrackCollection.h"

namespace AutoMix_UI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace AM_Resources;
	using namespace AM_StringUtils;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			_trackCollection = new TrackCollection();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: TrackCollection* _trackCollection;

	private: System::Windows::Forms::MenuStrip^  menuStrip1;

	private: System::Windows::Forms::GroupBox^  _featuresGroupBox;
	private: System::Windows::Forms::ListBox^  _musicListBox;

	private: System::Windows::Forms::TextBox^  _bpmTextArea;
	private: System::Windows::Forms::TextBox^  _bpmValueTextArea;

	private: System::Windows::Forms::TextBox^  _durationValueTextArea;
	private: System::Windows::Forms::TextBox^  _durationTextArea;
	private: System::Windows::Forms::SplitContainer^  _principalPanel;

	private: System::Windows::Forms::ToolStripMenuItem^  _fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  _openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator;
	private: System::Windows::Forms::ToolStripMenuItem^  _quitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  _helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  _aboutToolStripMenuItem;
	private: System::Windows::Forms::FolderBrowserDialog^  _inputMusicFolderBrowserDialog;


	private: System::Windows::Forms::StatusStrip^  _statusStrip;
	private: System::Windows::Forms::Button^  _extractionButton;
	private: System::Windows::Forms::FolderBrowserDialog^  _outputMusicFolderBrowserDialog;



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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->_principalPanel = (gcnew System::Windows::Forms::SplitContainer());
			this->_musicListBox = (gcnew System::Windows::Forms::ListBox());
			this->_extractionButton = (gcnew System::Windows::Forms::Button());
			this->_featuresGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->_durationValueTextArea = (gcnew System::Windows::Forms::TextBox());
			this->_durationTextArea = (gcnew System::Windows::Forms::TextBox());
			this->_bpmValueTextArea = (gcnew System::Windows::Forms::TextBox());
			this->_bpmTextArea = (gcnew System::Windows::Forms::TextBox());
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->_principalPanel))->BeginInit();
			this->_principalPanel->Panel1->SuspendLayout();
			this->_principalPanel->Panel2->SuspendLayout();
			this->_principalPanel->SuspendLayout();
			this->_featuresGroupBox->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// _principalPanel
			// 
			this->_principalPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->_principalPanel->Location = System::Drawing::Point(0, 24);
			this->_principalPanel->Margin = System::Windows::Forms::Padding(2);
			this->_principalPanel->Name = L"_principalPanel";
			// 
			// _principalPanel.Panel1
			// 
			this->_principalPanel->Panel1->AccessibleName = L"_musicPanel";
			this->_principalPanel->Panel1->Controls->Add(this->_musicListBox);
			// 
			// _principalPanel.Panel2
			// 
			this->_principalPanel->Panel2->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->_principalPanel->Panel2->Controls->Add(this->_extractionButton);
			this->_principalPanel->Panel2->Controls->Add(this->_featuresGroupBox);
			this->_principalPanel->Panel2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->_principalPanel->Size = System::Drawing::Size(1264, 657);
			this->_principalPanel->SplitterDistance = 578;
			this->_principalPanel->SplitterWidth = 3;
			this->_principalPanel->TabIndex = 1;
			// 
			// _musicListBox
			// 
			this->_musicListBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_musicListBox->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->_musicListBox->ForeColor = System::Drawing::SystemColors::ControlLight;
			this->_musicListBox->FormattingEnabled = true;
			this->_musicListBox->Location = System::Drawing::Point(10, 10);
			this->_musicListBox->Margin = System::Windows::Forms::Padding(2);
			this->_musicListBox->Name = L"_musicListBox";
			this->_musicListBox->Size = System::Drawing::Size(556, 615);
			this->_musicListBox->TabIndex = 0;
			this->_musicListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::_musicListBox_SelectedIndexChanged);
			// 
			// _extractionButton
			// 
			this->_extractionButton->AccessibleName = L"_extractionButton";
			this->_extractionButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->_extractionButton->BackColor = System::Drawing::SystemColors::ControlDark;
			this->_extractionButton->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->_extractionButton->Location = System::Drawing::Point(311, 44);
			this->_extractionButton->Name = L"_extractionButton";
			this->_extractionButton->Size = System::Drawing::Size(120, 61);
			this->_extractionButton->TabIndex = 1;
			this->_extractionButton->Text = L"Exporter";
			this->_extractionButton->UseVisualStyleBackColor = false;
			this->_extractionButton->Click += gcnew System::EventHandler(this, &MyForm::_extractionButton_Click);
			// 
			// _featuresGroupBox
			// 
			this->_featuresGroupBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_featuresGroupBox->Controls->Add(this->_durationValueTextArea);
			this->_featuresGroupBox->Controls->Add(this->_durationTextArea);
			this->_featuresGroupBox->Controls->Add(this->_bpmValueTextArea);
			this->_featuresGroupBox->Controls->Add(this->_bpmTextArea);
			this->_featuresGroupBox->ForeColor = System::Drawing::SystemColors::ControlLight;
			this->_featuresGroupBox->Location = System::Drawing::Point(16, 155);
			this->_featuresGroupBox->Margin = System::Windows::Forms::Padding(2);
			this->_featuresGroupBox->Name = L"_featuresGroupBox";
			this->_featuresGroupBox->Padding = System::Windows::Forms::Padding(2);
			this->_featuresGroupBox->Size = System::Drawing::Size(658, 304);
			this->_featuresGroupBox->TabIndex = 0;
			this->_featuresGroupBox->TabStop = false;
			this->_featuresGroupBox->Text = L"Features";
			// 
			// _durationValueTextArea
			// 
			this->_durationValueTextArea->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_durationValueTextArea->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->_durationValueTextArea->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->_durationValueTextArea->ForeColor = System::Drawing::SystemColors::ControlLight;
			this->_durationValueTextArea->Location = System::Drawing::Point(72, 86);
			this->_durationValueTextArea->Margin = System::Windows::Forms::Padding(2);
			this->_durationValueTextArea->Name = L"_durationValueTextArea";
			this->_durationValueTextArea->Size = System::Drawing::Size(494, 13);
			this->_durationValueTextArea->TabIndex = 3;
			// 
			// _durationTextArea
			// 
			this->_durationTextArea->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_durationTextArea->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->_durationTextArea->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->_durationTextArea->ForeColor = System::Drawing::SystemColors::ControlLight;
			this->_durationTextArea->Location = System::Drawing::Point(18, 86);
			this->_durationTextArea->Margin = System::Windows::Forms::Padding(2);
			this->_durationTextArea->Name = L"_durationTextArea";
			this->_durationTextArea->Size = System::Drawing::Size(478, 13);
			this->_durationTextArea->TabIndex = 2;
			this->_durationTextArea->Text = L"Duration :";
			// 
			// _bpmValueTextArea
			// 
			this->_bpmValueTextArea->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_bpmValueTextArea->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->_bpmValueTextArea->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->_bpmValueTextArea->ForeColor = System::Drawing::SystemColors::ControlLight;
			this->_bpmValueTextArea->Location = System::Drawing::Point(72, 44);
			this->_bpmValueTextArea->Margin = System::Windows::Forms::Padding(2);
			this->_bpmValueTextArea->Name = L"_bpmValueTextArea";
			this->_bpmValueTextArea->Size = System::Drawing::Size(494, 13);
			this->_bpmValueTextArea->TabIndex = 1;
			// 
			// _bpmTextArea
			// 
			this->_bpmTextArea->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_bpmTextArea->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->_bpmTextArea->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->_bpmTextArea->ForeColor = System::Drawing::SystemColors::ControlLight;
			this->_bpmTextArea->Location = System::Drawing::Point(18, 44);
			this->_bpmTextArea->Margin = System::Windows::Forms::Padding(2);
			this->_bpmTextArea->Name = L"_bpmTextArea";
			this->_bpmTextArea->Size = System::Drawing::Size(478, 13);
			this->_bpmTextArea->TabIndex = 0;
			this->_bpmTextArea->Text = L"BPM :";
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
			this->_fileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::_fileToolStripMenuItem_Click);
			// 
			// _openToolStripMenuItem
			// 
			this->_openToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"_openToolStripMenuItem.Image")));
			this->_openToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->_openToolStripMenuItem->Name = L"_openToolStripMenuItem";
			this->_openToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->_openToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->_openToolStripMenuItem->Text = L"&Open";
			this->_openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::_openToolStripMenuItem_Click);
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
			this->_quitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::_quitToolStripMenuItem_Click);
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
			this->_statusStrip->BackColor = System::Drawing::SystemColors::ControlDark;
			this->_statusStrip->Location = System::Drawing::Point(0, 659);
			this->_statusStrip->Name = L"_statusStrip";
			this->_statusStrip->Size = System::Drawing::Size(1264, 22);
			this->_statusStrip->TabIndex = 3;
			this->_statusStrip->Text = L"statusStrip1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ClientSize = System::Drawing::Size(1264, 681);
			this->Controls->Add(this->_statusStrip);
			this->Controls->Add(this->_principalPanel);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MinimumSize = System::Drawing::Size(768, 432);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AutoMix";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->_principalPanel->Panel1->ResumeLayout(false);
			this->_principalPanel->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->_principalPanel))->EndInit();
			this->_principalPanel->ResumeLayout(false);
			this->_featuresGroupBox->ResumeLayout(false);
			this->_featuresGroupBox->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {}
	private: System::Void _fileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {}

	private: System::Void _quitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void _musicListBox_SelectedIndexChanged(System::Object ^ sender, System::EventArgs ^ e);
	private: System::Void _openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

	private:
		System::Void loadTracksFromDirectory(System::Object^  sender, System::EventArgs^  e);
	private: System::Void _extractionButton_Click(System::Object^  sender, System::EventArgs^  e);
};

}
