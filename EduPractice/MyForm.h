#pragma once
#include "DLL.h"
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
			DateTime datetime = DateTime::Now;
			this->label4->Text = "Дата: " + datetime.ToString();
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
	private: System::Windows::Forms::Button^ File1ShowButton;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

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
			this->File1ShowButton = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::LemonChiffon;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(14, 298);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(425, 234);
			this->textBox1->TabIndex = 0;
			// 
			// File1CreateButton
			// 
			this->File1CreateButton->BackColor = System::Drawing::Color::BurlyWood;
			this->File1CreateButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->File1CreateButton->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->File1CreateButton->Location = System::Drawing::Point(75, 55);
			this->File1CreateButton->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->File1CreateButton->Name = L"File1CreateButton";
			this->File1CreateButton->Size = System::Drawing::Size(412, 43);
			this->File1CreateButton->TabIndex = 1;
			this->File1CreateButton->Text = L"Заполнить исходный файл (1.txt) буквами";
			this->File1CreateButton->UseVisualStyleBackColor = false;
			this->File1CreateButton->Click += gcnew System::EventHandler(this, &MyForm::File1CreateButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Verdana", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(10, 262);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(220, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Исходный файл (1.txt):";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Verdana", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(486, 262);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(289, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Отсортированный файл (2.txt):";
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::LemonChiffon;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(490, 298);
			this->textBox2->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(425, 234);
			this->textBox2->TabIndex = 4;
			// 
			// SortFileButton
			// 
			this->SortFileButton->BackColor = System::Drawing::Color::BurlyWood;
			this->SortFileButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SortFileButton->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SortFileButton->Location = System::Drawing::Point(75, 153);
			this->SortFileButton->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->SortFileButton->Name = L"SortFileButton";
			this->SortFileButton->Size = System::Drawing::Size(412, 43);
			this->SortFileButton->TabIndex = 5;
			this->SortFileButton->Text = L"Показать отсортированный файл (2.txt)";
			this->SortFileButton->UseVisualStyleBackColor = false;
			this->SortFileButton->Click += gcnew System::EventHandler(this, &MyForm::SortFileButton_Click);
			// 
			// File1ShowButton
			// 
			this->File1ShowButton->BackColor = System::Drawing::Color::BurlyWood;
			this->File1ShowButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->File1ShowButton->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->File1ShowButton->Location = System::Drawing::Point(75, 104);
			this->File1ShowButton->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->File1ShowButton->Name = L"File1ShowButton";
			this->File1ShowButton->Size = System::Drawing::Size(412, 43);
			this->File1ShowButton->TabIndex = 7;
			this->File1ShowButton->Text = L"Показать исходный файл (1.txt)";
			this->File1ShowButton->UseVisualStyleBackColor = false;
			this->File1ShowButton->Click += gcnew System::EventHandler(this, &MyForm::File1ShowButton_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::LemonChiffon;
			this->groupBox1->Controls->Add(this->File1CreateButton);
			this->groupBox1->Controls->Add(this->SortFileButton);
			this->groupBox1->Controls->Add(this->File1ShowButton);
			this->groupBox1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Verdana", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(14, 14);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->groupBox1->Size = System::Drawing::Size(566, 235);
			this->groupBox1->TabIndex = 8;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Что вы хотите сделать\?";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(588, 14);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(327, 25);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Яскунова Анна, группа 590";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(588, 63);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(77, 25);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Дата: ";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackColor = System::Drawing::Color::BurlyWood;
			this->ClientSize = System::Drawing::Size(928, 548);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->Name = L"MyForm";
			this->Text = L"Учебная практика_Яскунова Анна_гр590";
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void File1CreateButton_Click(System::Object^ sender, System::EventArgs^ e) { //кнопка для автоматического заполнения файла буквами
		srand(time(NULL));
		char letters[100];
		fstream file1; // создание объекта класса fstream 
		file1.open("1.txt"); // связывание объекта класса fstream с файлом, который будет использоваться для операций ввода-вывода
		for (int i = 0; i < 100; i++)
		{
			letters[i] = (rand() % ('z' - 'a' + 1)) + 'a'; // присваивание букве значение от "a" до "z"
			file1 << letters[i]; // добавление буквы в файл
		}
		file1.close();
	}
	private: System::Void File1ShowButton_Click(System::Object^ sender, System::EventArgs^ e) { //кнопка для отображения исходного файла 1.txt, также здесь создание векторов и сортировка файла
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
		fstream file1, file2; // создание объекта класса fstream 
		file1.open("1.txt");
		file2.open("2.txt");
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
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		sort(v3.begin(), v3.end());
		sort(v4.begin(), v4.end());
		sort(v5.begin(), v5.end());
		sort(v6.begin(), v6.end());
		sort(v7.begin(), v7.end());
		sort(v8.begin(), v8.end());
		sort(v9.begin(), v9.end());
		sort(v10.begin(), v10.end());
		v1[0] = '*';
		v2[1] = '*';
		v3[2] = '*';
		v4[3] = '*';
		v5[4] = '*';
		v6[5] = '*';
		v7[6] = '*';
		v8[7] = '*';
		v9[8] = '*';
		v10[9] = '*';
		for (int i = 0; i < 10; i++)
		{
			file2 << v1[i];
		}
		file2 << endl;
		for (int i = 0; i < 10; i++)
		{
			file2 << v2[i];

		}
		file2 << endl;
		for (int i = 0; i < 10; i++)
		{
			file2 << v3[i];

		}
		file2 << endl;
		for (int i = 0; i < 10; i++)
		{
			file2 << v4[i];

		}
		file2 << endl;
		for (int i = 0; i < 10; i++)
		{
			file2 << v5[i];

		}
		file2 << endl;
		for (int i = 0; i < 10; i++)
		{
			file2 << v6[i];

		}
		file2 << endl;
		for (int i = 0; i < 10; i++)
		{
			file2 << v7[i];

		}
		file2 << endl;
		for (int i = 0; i < 10; i++)
		{
			file2 << v8[i];

		}
		file2 << endl;
		for (int i = 0; i < 10; i++)
		{
			file2 << v9[i];

		}
		file2 << endl;
		for (int i = 0; i < 10; i++)
		{
			file2 << v10[i];

		}
		file2 << endl;
		file1.close();
		file2.close();
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
	private: System::Void SortFileButton_Click(System::Object^ sender, System::EventArgs^ e) { //кнопка для отображения отсортированного файла 2.txt
		String^ file2Path = "2.txt"; // создаем переменную для хранения пути к файлу
		try
		{
			StreamReader^ file = File::OpenText(file2Path); //открываем файл
			textBox2->Text = file->ReadToEnd(); //записываем содержимое файла в TextBox
		}
		catch (Exception^ e)
		{
			MessageBox::Show(this, "Файл не был открыт", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);

		}
	}
};
}
