#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "DocList.h"

namespace DSAproj {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
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
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^ listView1;
	protected:

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
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->SuspendLayout();
			// 
			// listView1
			// 
			this->listView1->BackColor = System::Drawing::Color::Black;
			this->listView1->ForeColor = System::Drawing::Color::White;
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(12, 12);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(598, 367);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			// 
			// MyForm1
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(622, 391);
			this->Controls->Add(this->listView1);
			this->Name = L"MyForm1";
			this->Text = L"Output";
			this->ResumeLayout(false);

		}

	public: void setoutputs(vector<pair<string, int>> resultss)
	{
		listView1->Items->Clear();

		for (const auto& result : resultss)
		{
			string displayString = "Document: " + result.first + " - Frequency: " + to_string(result.second);

			System::String^ displayStringManaged = gcnew System::String(displayString.c_str());

			System::Windows::Forms::ListViewItem^ item = gcnew System::Windows::Forms::ListViewItem(displayStringManaged);

			listView1->Items->Add(item);
		}
	}
#pragma endregion
	};
}
