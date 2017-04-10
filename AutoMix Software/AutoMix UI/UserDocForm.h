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
			resources->ApplyResources(this->tableLayoutPanel1, L"tableLayoutPanel1");
			this->tableLayoutPanel1->Controls->Add(this->tabControl1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->okButton, 1, 1);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			// 
			// tabControl1
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->tabControl1, 2);
			this->tabControl1->Controls->Add(this->_bpmTab);
			this->tabControl1->Controls->Add(this->_keyPage);
			resources->ApplyResources(this->tabControl1, L"tabControl1");
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->SizeMode = System::Windows::Forms::TabSizeMode::FillToRight;
			// 
			// _bpmTab
			// 
			this->_bpmTab->Controls->Add(this->richTextBox1);
			resources->ApplyResources(this->_bpmTab, L"_bpmTab");
			this->_bpmTab->Name = L"_bpmTab";
			this->_bpmTab->UseVisualStyleBackColor = true;
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::SystemColors::Window;
			this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			resources->ApplyResources(this->richTextBox1, L"richTextBox1");
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->ShortcutsEnabled = false;
			// 
			// _keyPage
			// 
			resources->ApplyResources(this->_keyPage, L"_keyPage");
			this->_keyPage->Controls->Add(this->tableLayoutPanel2);
			this->_keyPage->Name = L"_keyPage";
			this->_keyPage->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel2
			// 
			resources->ApplyResources(this->tableLayoutPanel2, L"tableLayoutPanel2");
			this->tableLayoutPanel2->Controls->Add(this->pictureBox1, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->_keyDescription, 1, 0);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			// 
			// pictureBox1
			// 
			resources->ApplyResources(this->pictureBox1, L"pictureBox1");
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->TabStop = false;
			// 
			// _keyDescription
			// 
			this->_keyDescription->BackColor = System::Drawing::SystemColors::Window;
			this->_keyDescription->BorderStyle = System::Windows::Forms::BorderStyle::None;
			resources->ApplyResources(this->_keyDescription, L"_keyDescription");
			this->_keyDescription->Name = L"_keyDescription";
			this->_keyDescription->ReadOnly = true;
			this->_keyDescription->ShortcutsEnabled = false;
			// 
			// okButton
			// 
			resources->ApplyResources(this->okButton, L"okButton");
			this->okButton->Name = L"okButton";
			this->okButton->UseVisualStyleBackColor = true;
			this->okButton->Click += gcnew System::EventHandler(this, &UserDocForm::onOkButtonClick);
			// 
			// UserDocForm
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->tableLayoutPanel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"UserDocForm";
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