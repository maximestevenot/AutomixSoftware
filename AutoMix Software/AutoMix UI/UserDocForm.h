// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#pragma once

namespace AutoMixUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for UserDocForm
	/// </summary>
	public ref class UserDocForm : public System::Windows::Forms::Form
	{
	public:
		UserDocForm(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UserDocForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected:
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  _bpmTab;
	private: System::Windows::Forms::TabPage^  _keyPage;


	private: System::Windows::Forms::Button^  okButton;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::RichTextBox^  _keyDescription;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;



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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(UserDocForm::typeid));
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->_bpmTab = (gcnew System::Windows::Forms::TabPage());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->_keyPage = (gcnew System::Windows::Forms::TabPage());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->_keyDescription = (gcnew System::Windows::Forms::RichTextBox());
			this->okButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->_bpmTab->SuspendLayout();
			this->_keyPage->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->AutoSize = true;
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				107)));
			this->tableLayoutPanel1->Controls->Add(this->tabControl1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->okButton, 1, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1136, 609);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tabControl1
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->tabControl1, 2);
			this->tabControl1->Controls->Add(this->_bpmTab);
			this->tabControl1->Controls->Add(this->_keyPage);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(3, 3);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1130, 567);
			this->tabControl1->SizeMode = System::Windows::Forms::TabSizeMode::FillToRight;
			this->tabControl1->TabIndex = 0;
			// 
			// _bpmTab
			// 
			this->_bpmTab->Controls->Add(this->richTextBox1);
			this->_bpmTab->Location = System::Drawing::Point(4, 22);
			this->_bpmTab->Name = L"_bpmTab";
			this->_bpmTab->Padding = System::Windows::Forms::Padding(3);
			this->_bpmTab->Size = System::Drawing::Size(1122, 541);
			this->_bpmTab->TabIndex = 0;
			this->_bpmTab->Text = L"BPM";
			this->_bpmTab->UseVisualStyleBackColor = true;
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::SystemColors::Window;
			this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->Location = System::Drawing::Point(3, 3);
			this->richTextBox1->Margin = System::Windows::Forms::Padding(10);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->ShortcutsEnabled = false;
			this->richTextBox1->Size = System::Drawing::Size(1116, 535);
			this->richTextBox1->TabIndex = 2;
			this->richTextBox1->Text = resources->GetString(L"richTextBox1.Text");
			// 
			// _keyPage
			// 
			this->_keyPage->AutoScroll = true;
			this->_keyPage->Controls->Add(this->tableLayoutPanel2);
			this->_keyPage->Location = System::Drawing::Point(4, 22);
			this->_keyPage->Name = L"_keyPage";
			this->_keyPage->Padding = System::Windows::Forms::Padding(3);
			this->_keyPage->Size = System::Drawing::Size(1122, 541);
			this->_keyPage->TabIndex = 1;
			this->_keyPage->Text = L"Key";
			this->_keyPage->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->AutoScroll = true;
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->pictureBox1, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->_keyDescription, 1, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(1116, 535);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(3, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(552, 529);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// _keyDescription
			// 
			this->_keyDescription->BackColor = System::Drawing::SystemColors::Window;
			this->_keyDescription->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->_keyDescription->Dock = System::Windows::Forms::DockStyle::Fill;
			this->_keyDescription->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->_keyDescription->Location = System::Drawing::Point(568, 10);
			this->_keyDescription->Margin = System::Windows::Forms::Padding(10);
			this->_keyDescription->Name = L"_keyDescription";
			this->_keyDescription->ReadOnly = true;
			this->_keyDescription->ShortcutsEnabled = false;
			this->_keyDescription->Size = System::Drawing::Size(538, 515);
			this->_keyDescription->TabIndex = 1;
			this->_keyDescription->Text = resources->GetString(L"_keyDescription.Text");
			// 
			// okButton
			// 
			this->okButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->okButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->okButton->Location = System::Drawing::Point(1040, 576);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(84, 30);
			this->okButton->TabIndex = 1;
			this->okButton->Text = L"Ok";
			this->okButton->UseVisualStyleBackColor = true;
			this->okButton->Click += gcnew System::EventHandler(this, &UserDocForm::onOkButtonClick);
			// 
			// UserDocForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1136, 609);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"UserDocForm";
			this->Text = L"AutoMix Software";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tabControl1->ResumeLayout(false);
			this->_bpmTab->ResumeLayout(false);
			this->_keyPage->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion
	private: System::Void onOkButtonClick(System::Object^  sender, System::EventArgs^  e)
	{
		this->Close();
	}
};
}