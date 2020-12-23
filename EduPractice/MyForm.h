#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <Windows.h>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <mutex>
#include <iterator>
#include <chrono>
#include <iomanip>
namespace EduPractice {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::IO;
	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::Button^ FileCreate_Button;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ SortFile_Button;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->FileCreate_Button = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SortFile_Button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 29);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(375, 93);
			this->textBox1->TabIndex = 0;
			// 
			// FileCreate_Button
			// 
			this->FileCreate_Button->Location = System::Drawing::Point(393, 29);
			this->FileCreate_Button->Name = L"FileCreate_Button";
			this->FileCreate_Button->Size = System::Drawing::Size(243, 52);
			this->FileCreate_Button->TabIndex = 1;
			this->FileCreate_Button->Text = L"Создать новый файл и показать его";
			this->FileCreate_Button->UseVisualStyleBackColor = true;
			this->FileCreate_Button->Click += gcnew System::EventHandler(this, &MyForm::FileCreate_Button_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(116, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Исходный файл:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 147);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(168, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Отсортированный файл";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 186);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(375, 135);
			this->textBox2->TabIndex = 4;
			// 
			// SortFile_Button
			// 
			this->SortFile_Button->Location = System::Drawing::Point(393, 186);
			this->SortFile_Button->Name = L"SortFile_Button";
			this->SortFile_Button->Size = System::Drawing::Size(243, 47);
			this->SortFile_Button->TabIndex = 5;
			this->SortFile_Button->Text = L"Отсортировать файл и показать его";
			this->SortFile_Button->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(662, 368);
			this->Controls->Add(this->SortFile_Button);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->FileCreate_Button);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void FileCreate_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		ofstream file1; // создание объекта класса fstream (<ofstream> — файловый вывод)
		file1.open("1.txt"); // связывание объекта класса fstream с файлом, который будет использоваться для операций ввода-вывода
		file1.clear();
		for (int i = 0; i < 100; i++)
		{
			char letter = (rand() % ('z' - 'a' + 1)) + 'a';
			file1 << letter; // ввод буквы в файл
		}
		file1.close();
		vector <vector <char>> fileVec; // создание вектора, в котором будет файл
		String^ file1Path = "1.txt"; // создаем переменную для хранения пути к файлу
		try
		{
			StreamReader^ file = File::OpenText(file1Path); //открываем файл
			textBox1->Text = file->ReadToEnd(); //записываем содержимое файла в TextBox
		}
		catch (Exception^ e)
		{
			MessageBox::Show(this, "Файл не был открыт", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);

		}

	}
	};
}
