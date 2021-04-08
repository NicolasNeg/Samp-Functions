#pragma once
#using <System.DLL>
#using <System.Drawing.DLL>
#using <System.Windows.Forms.DLL>

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System;
	using namespace System::Windows::Forms;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ inputtext;
	protected:

	private: System::Windows::Forms::Label^ DG_TITLE;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ BTN_1;
	private: System::Windows::Forms::Button^ BTN_2;
	private: System::Windows::Forms::Label^ exit;
	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->inputtext = (gcnew System::Windows::Forms::TextBox());
			this->DG_TITLE = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->BTN_1 = (gcnew System::Windows::Forms::Button());
			this->BTN_2 = (gcnew System::Windows::Forms::Button());
			this->exit = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// inputtext
			// 
			this->inputtext->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->inputtext->Font = (gcnew System::Drawing::Font(L"Calibri", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->inputtext->ForeColor = System::Drawing::SystemColors::InfoText;
			this->inputtext->Location = System::Drawing::Point(27, 94);
			this->inputtext->Multiline = true;
			this->inputtext->Name = L"inputtext";
			this->inputtext->Size = System::Drawing::Size(265, 33);
			this->inputtext->TabIndex = 0;
			this->inputtext->WordWrap = false;
			this->inputtext->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// DG_TITLE
			// 
			this->DG_TITLE->AutoSize = true;
			this->DG_TITLE->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->DG_TITLE->CausesValidation = false;
			this->DG_TITLE->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->DG_TITLE->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DG_TITLE->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->DG_TITLE->Location = System::Drawing::Point(12, 9);
			this->DG_TITLE->Name = L"DG_TITLE";
			this->DG_TITLE->Size = System::Drawing::Size(190, 19);
			this->DG_TITLE->TabIndex = 1;
			this->DG_TITLE->Text = L"Insert your caption here";
			this->DG_TITLE->Click += gcnew System::EventHandler(this, &Form1::DG_TITLE_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Location = System::Drawing::Point(23, 54);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(139, 19);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Insert your info here";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// BTN_1
			// 
			this->BTN_1->Location = System::Drawing::Point(67, 150);
			this->BTN_1->Name = L"BTN_1";
			this->BTN_1->Size = System::Drawing::Size(85, 29);
			this->BTN_1->TabIndex = 3;
			this->BTN_1->Text = L"Button1";
			this->BTN_1->UseVisualStyleBackColor = true;
			this->BTN_1->Click += gcnew System::EventHandler(this, &Form1::BTN_1_Click);
			// 
			// BTN_2
			// 
			this->BTN_2->Location = System::Drawing::Point(168, 150);
			this->BTN_2->Name = L"BTN_2";
			this->BTN_2->Size = System::Drawing::Size(82, 29);
			this->BTN_2->TabIndex = 4;
			this->BTN_2->Text = L"Button 2";
			this->BTN_2->UseVisualStyleBackColor = true;
			this->BTN_2->Click += gcnew System::EventHandler(this, &Form1::BTN_2_Click);
			// 
			// exit
			// 
			this->exit->AutoSize = true;
			this->exit->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->exit->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->exit->Location = System::Drawing::Point(313, -1);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(14, 13);
			this->exit->TabIndex = 5;
			this->exit->Text = L"X";
			this->exit->Click += gcnew System::EventHandler(this, &Form1::exit_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(324, 191);
			this->ControlBox = false;
			this->Controls->Add(this->exit);
			this->Controls->Add(this->BTN_2);
			this->Controls->Add(this->BTN_1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->DG_TITLE);
			this->Controls->Add(this->inputtext);
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L".";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		/*public: System::Void CreateDG(int DG_STYLE, int DG_ID, char DG_TITLE, char DG_INFO, char DG_BTN1, char DG_BTN2)
		{
			
		}*/
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void DG_TITLE_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void BTN_1_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Debug - response: 1");
}
private: System::Void BTN_2_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Debug - response: 2");
}
private: System::Void exit_Click(System::Object^ sender, System::EventArgs^ e) {
	System::Windows::Forms::DialogResult result;
	result = MessageBox::Show("Debug - saliendo...", "Seguro?", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
	if (result == System::Windows::Forms::DialogResult::Yes)
	{
		MessageBox::Show("Debug - Ha escojido salir...", "Exito", MessageBoxButtons::OK, MessageBoxIcon::Information);
		exit;
	}
	else if(result == System::Windows::Forms::DialogResult::No)
	{
		MessageBox::Show("Debug - No se ha escojido nada...");
	}
}
};
}
