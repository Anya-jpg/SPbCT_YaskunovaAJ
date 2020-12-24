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
	private: System::Windows::Forms::Button^ File1CreateButton;

	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ SortFileButton;
	private: System::Windows::Forms::Button^ ClearFilesButton;
	private: System::Windows::Forms::Button^ File1ShowButton;







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
			this->File1CreateButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SortFileButton = (gcnew System::Windows::Forms::Button());
			this->ClearFilesButton = (gcnew System::Windows::Forms::Button());
			this->File1ShowButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 44);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(378, 189);
			this->textBox1->TabIndex = 0;
			// 
			// File1CreateButton
			// 
			this->File1CreateButton->Location = System::Drawing::Point(396, 95);
			this->File1CreateButton->Name = L"File1CreateButton";
			this->File1CreateButton->Size = System::Drawing::Size(243, 42);
			this->File1CreateButton->TabIndex = 1;
			this->File1CreateButton->Text = L"Заполнить файл буквами";
			this->File1CreateButton->UseVisualStyleBackColor = true;
			this->File1CreateButton->Click += gcnew System::EventHandler(this, &MyForm::File1CreateButton_Click);
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
			this->label2->Location = System::Drawing::Point(9, 255);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(168, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Отсортированный файл";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 284);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(378, 207);
			this->textBox2->TabIndex = 4;
			// 
			// SortFileButton
			// 
			this->SortFileButton->Location = System::Drawing::Point(396, 193);
			this->SortFileButton->Name = L"SortFileButton";
			this->SortFileButton->Size = System::Drawing::Size(243, 40);
			this->SortFileButton->TabIndex = 5;
			this->SortFileButton->Text = L"Отсортировать файл";
			this->SortFileButton->UseVisualStyleBackColor = true;
			// 
			// ClearFilesButton
			// 
			this->ClearFilesButton->Location = System::Drawing::Point(396, 44);
			this->ClearFilesButton->Name = L"ClearFilesButton";
			this->ClearFilesButton->Size = System::Drawing::Size(243, 45);
			this->ClearFilesButton->TabIndex = 6;
			this->ClearFilesButton->Text = L"Очистить файлы";
			this->ClearFilesButton->UseVisualStyleBackColor = true;
			this->ClearFilesButton->Click += gcnew System::EventHandler(this, &MyForm::ClearFilesButton_Click);
			// 
			// File1ShowButton
			// 
			this->File1ShowButton->Location = System::Drawing::Point(396, 143);
			this->File1ShowButton->Name = L"File1ShowButton";
			this->File1ShowButton->Size = System::Drawing::Size(243, 44);
			this->File1ShowButton->TabIndex = 7;
			this->File1ShowButton->Text = L"Отобразить исходный файл";
			this->File1ShowButton->UseVisualStyleBackColor = true;
			this->File1ShowButton->Click += gcnew System::EventHandler(this, &MyForm::File1ShowButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(808, 538);
			this->Controls->Add(this->File1ShowButton);
			this->Controls->Add(this->ClearFilesButton);
			this->Controls->Add(this->SortFileButton);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->File1CreateButton);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void File1CreateButton_Click(System::Object^ sender, System::EventArgs^ e) {
		srand(time(NULL));
		char letters[100];
		fstream file1; // создание объекта класса fstream 
		file1.open("1.txt"); // связывание объекта класса fstream с файлом, который будет использоваться для операций ввода-вывода
		for (int i = 0; i < 100; i++)
		{
			letters[i] = (rand() % ('z' - 'a' + 1)) + 'a';
			file1 << letters[i];
		}
		file1 << endl;
		file1.close();
	}
	private: System::Void ClearFilesButton_Click(System::Object^ sender, System::EventArgs^ e) {
		ofstream file1, file2;
		file1.open("1.txt", ofstream::out, ofstream::trunc);
		file2.open("2.txt", ofstream::out, ofstream::trunc);
		file1.close();
		file2.close();
	}
private: System::Void File1ShowButton_Click(System::Object^ sender, System::EventArgs^ e) {
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
	char letter[100];
	vector<char> v1;
	vector<char> v2;
	vector<char> v3;
	vector<char> v4;
	vector<char> v5;
	vector<char> v6;
	vector<char> v7;
	vector<char> v8;
	vector<char> v9;
	vector<char> v10;
	fstream file1; // создание объекта класса fstream 
	file1.open("1.txt");
	for (int i = 0; i < 10; i++)
	{
		file1 >> letter[i];
		v1.push_back(letter[i]);
	}
	for (int i = 10; i < 20; i++)
	{
		file1 >> letter[i];
		v2.push_back(letter[i]);
	}
	for (int i = 20; i < 30; i++)
	{
		file1 >> letter[i];
		v3.push_back(letter[i]);
	}
	for (int i = 30; i < 40; i++)
	{
		file1 >> letter[i];
		v4.push_back(letter[i]);
	}
	for (int i = 40; i < 50; i++)
	{
		file1 >> letter[i];
		v5.push_back(letter[i]);
	}
	for (int i = 50; i < 60; i++)
	{
		file1 >> letter[i];
		v6.push_back(letter[i]);
	}
	for (int i = 60; i < 70; i++)
	{
		file1 >> letter[i];
		v7.push_back(letter[i]);
	}
	for (int i = 70; i < 80; i++)
	{
		file1 >> letter[i];
		v8.push_back(letter[i]);
	}
	for (int i = 80; i < 90; i++)
	{
		file1 >> letter[i];
		v9.push_back(letter[i]);
	}
	for (int i = 90; i < 100; i++)
	{
		file1 >> letter[i];
		v10.push_back(letter[i]);
	}
	file1.close();
}

};
}
