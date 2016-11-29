#pragma once

namespace AutoMix_UI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
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

	protected:


	protected:

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























	protected:

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
			this->_principalPanel->Location = System::Drawing::Point(0, 28);
			this->_principalPanel->Name = L"_principalPanel";
			// 
			// _principalPanel.Panel1
			// 
			this->_principalPanel->Panel1->AccessibleName = L"_musicPanel";
			this->_principalPanel->Panel1->Controls->Add(this->_musicListBox);
			// 
			// _principalPanel.Panel2
			// 
			this->_principalPanel->Panel2->Controls->Add(this->_featuresGroupBox);
			this->_principalPanel->Size = System::Drawing::Size(866, 610);
			this->_principalPanel->SplitterDistance = 398;
			this->_principalPanel->TabIndex = 1;
			// 
			// _musicListBox
			// 
			this->_musicListBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_musicListBox->FormattingEnabled = true;
			this->_musicListBox->ItemHeight = 16;
			this->_musicListBox->Location = System::Drawing::Point(72, 107);
			this->_musicListBox->Name = L"_musicListBox";
			this->_musicListBox->Size = System::Drawing::Size(268, 356);
			this->_musicListBox->TabIndex = 0;
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
			this->_featuresGroupBox->Location = System::Drawing::Point(62, 191);
			this->_featuresGroupBox->Name = L"_featuresGroupBox";
			this->_featuresGroupBox->Size = System::Drawing::Size(305, 176);
			this->_featuresGroupBox->TabIndex = 0;
			this->_featuresGroupBox->TabStop = false;
			this->_featuresGroupBox->Text = L"Features";
			// 
			// _durationValueTextArea
			// 
			this->_durationValueTextArea->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_durationValueTextArea->BackColor = System::Drawing::SystemColors::Control;
			this->_durationValueTextArea->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->_durationValueTextArea->Location = System::Drawing::Point(96, 106);
			this->_durationValueTextArea->Name = L"_durationValueTextArea";
			this->_durationValueTextArea->Size = System::Drawing::Size(87, 15);
			this->_durationValueTextArea->TabIndex = 3;
			// 
			// _durationTextArea
			// 
			this->_durationTextArea->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_durationTextArea->BackColor = System::Drawing::SystemColors::Control;
			this->_durationTextArea->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->_durationTextArea->Location = System::Drawing::Point(24, 106);
			this->_durationTextArea->Name = L"_durationTextArea";
			this->_durationTextArea->Size = System::Drawing::Size(67, 15);
			this->_durationTextArea->TabIndex = 2;
			this->_durationTextArea->Text = L"Duration :";
			// 
			// _bpmValueTextArea
			// 
			this->_bpmValueTextArea->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_bpmValueTextArea->BackColor = System::Drawing::SystemColors::Control;
			this->_bpmValueTextArea->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->_bpmValueTextArea->Location = System::Drawing::Point(96, 54);
			this->_bpmValueTextArea->Name = L"_bpmValueTextArea";
			this->_bpmValueTextArea->Size = System::Drawing::Size(87, 15);
			this->_bpmValueTextArea->TabIndex = 1;
			// 
			// _bpmTextArea
			// 
			this->_bpmTextArea->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_bpmTextArea->BackColor = System::Drawing::SystemColors::Control;
			this->_bpmTextArea->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->_bpmTextArea->Location = System::Drawing::Point(24, 54);
			this->_bpmTextArea->Name = L"_bpmTextArea";
			this->_bpmTextArea->Size = System::Drawing::Size(67, 15);
			this->_bpmTextArea->TabIndex = 0;
			this->_bpmTextArea->Text = L"BPM :";
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->_fileToolStripMenuItem,
					this->_helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(866, 28);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// _fileToolStripMenuItem
			// 
			this->_fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->_openToolStripMenuItem,
					this->toolStripSeparator, this->_quitToolStripMenuItem
			});
			this->_fileToolStripMenuItem->Name = L"_fileToolStripMenuItem";
			this->_fileToolStripMenuItem->Size = System::Drawing::Size(44, 24);
			this->_fileToolStripMenuItem->Text = L"&File";
			this->_fileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::_fileToolStripMenuItem_Click);
			// 
			// _openToolStripMenuItem
			// 
			this->_openToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"_openToolStripMenuItem.Image")));
			this->_openToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->_openToolStripMenuItem->Name = L"_openToolStripMenuItem";
			this->_openToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->_openToolStripMenuItem->Size = System::Drawing::Size(181, 26);
			this->_openToolStripMenuItem->Text = L"&Open";
			this->_openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::_openToolStripMenuItem_Click);
			// 
			// toolStripSeparator
			// 
			this->toolStripSeparator->Name = L"toolStripSeparator";
			this->toolStripSeparator->Size = System::Drawing::Size(178, 6);
			// 
			// _quitToolStripMenuItem
			// 
			this->_quitToolStripMenuItem->Name = L"_quitToolStripMenuItem";
			this->_quitToolStripMenuItem->Size = System::Drawing::Size(181, 26);
			this->_quitToolStripMenuItem->Text = L"&Quit";
			this->_quitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::_quitToolStripMenuItem_Click);
			// 
			// _helpToolStripMenuItem
			// 
			this->_helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->_aboutToolStripMenuItem });
			this->_helpToolStripMenuItem->Name = L"_helpToolStripMenuItem";
			this->_helpToolStripMenuItem->Size = System::Drawing::Size(53, 24);
			this->_helpToolStripMenuItem->Text = L"&Help";
			// 
			// _aboutToolStripMenuItem
			// 
			this->_aboutToolStripMenuItem->Name = L"_aboutToolStripMenuItem";
			this->_aboutToolStripMenuItem->Size = System::Drawing::Size(125, 26);
			this->_aboutToolStripMenuItem->Text = L"&About";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(866, 638);
			this->Controls->Add(this->_principalPanel);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MinimumSize = System::Drawing::Size(884, 685);
			this->Name = L"MyForm";
			this->Text = L"AutoMix";
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
private: System::Void _openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	_inputMusicFolderBrowserDialog->ShowDialog();
}
private: System::Void _fileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void _quitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}
};
}
