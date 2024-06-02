#pragma once
#include <string>
#include <iostream>
#include <msclr/marshal_cppstd.h>
#include "MyForm1.h"
#include "DocList.h"

using namespace msclr::interop;
using namespace std;

namespace DSAproj {

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
    private: System::Windows::Forms::TextBox^ textBox1;
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Label^ label1;
    protected:

    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // textBox1
            // 
            this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBox1->Location = System::Drawing::Point(293, 491);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(752, 56);
            this->textBox1->TabIndex = 0;
            this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox1_KeyDown);
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(1031, 491);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(75, 31);
            this->button1->TabIndex = 1;
            this->button1->Text = L"search";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->BackColor = System::Drawing::Color::Transparent;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->ForeColor = System::Drawing::Color::White;
            this->label1->Location = System::Drawing::Point(553, 375);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(472, 147);
            this->label1->TabIndex = 2;
            this->label1->Text = L"Doodle";
            // 
            // MyForm
            // 
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->ClientSize = System::Drawing::Size(1920, 1200);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->textBox1);
            this->Name = L"MyForm";
            this->Text = L"DOC BROWSER";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }

    public: void Run(string query)
    {
        DocList docList;
        string directoryPath = "C:\\Users\\osaid\\Documents\\doc 2.txt";
        docList.loadDocuments(directoryPath);

        vector<pair<string, int>> results = docList.searchDocuments(query);

        DSAproj::MyForm1^ form1 = gcnew DSAproj::MyForm1();
        form1->setoutputs(results);
        form1->ShowDialog();
    }


#pragma endregion
    private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e)
    {

    }
   private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
   {
       try
       {
           System::String^ managedString1 = textBox1->Text;
           std::string s = marshal_as<std::string>(managedString1);

           Run(s);
       }
       catch (const std::exception& ex)
       {
           MessageBox::Show(gcnew System::String(ex.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
       }
   }

private: System::Void textBox1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
    if (e->KeyValue == (int)Keys::Enter)
    {
        try
        {
            System::String^ managedString1 = textBox1->Text;
            std::string s = marshal_as<std::string>(managedString1);

            Run(s);
        }
        catch (const std::exception& ex)
        {
            MessageBox::Show(gcnew System::String(ex.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
}

};
}
