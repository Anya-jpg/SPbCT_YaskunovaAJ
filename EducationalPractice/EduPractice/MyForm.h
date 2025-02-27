﻿#pragma once
#include "DLL.h" // подключение созданной DLL-библиотеки
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
	using namespace System::Threading;
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
			this->label4->Text = "Дата: " + datetime.ToString(); // запись времени и даты в label 4 на форму
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
	private: Thread^ t1;
	private: Thread^ t2; // создание потоков
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
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(342, 147);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(378, 153);
			this->textBox1->TabIndex = 0;
			// 
			// File1CreateButton
			// 
			this->File1CreateButton->BackColor = System::Drawing::Color::BurlyWood;
			this->File1CreateButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->File1CreateButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->File1CreateButton->Location = System::Drawing::Point(17, 83);
			this->File1CreateButton->Name = L"File1CreateButton";
			this->File1CreateButton->Size = System::Drawing::Size(273, 54);
			this->File1CreateButton->TabIndex = 1;
			this->File1CreateButton->Text = L"Заполнить исходный файл буквами (если он пустой)";
			this->File1CreateButton->UseVisualStyleBackColor = false;
			this->File1CreateButton->Click += gcnew System::EventHandler(this, &MyForm::File1CreateButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(339, 124);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(217, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Исходный файл (1.txt):";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(338, 313);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(296, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Отсортированный файл (2.txt):";
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::LemonChiffon;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(342, 337);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox2->Size = System::Drawing::Size(378, 254);
			this->textBox2->TabIndex = 4;
			// 
			// SortFileButton
			// 
			this->SortFileButton->BackColor = System::Drawing::Color::BurlyWood;
			this->SortFileButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SortFileButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SortFileButton->Location = System::Drawing::Point(17, 331);
			this->SortFileButton->Name = L"SortFileButton";
			this->SortFileButton->Size = System::Drawing::Size(273, 54);
			this->SortFileButton->TabIndex = 5;
			this->SortFileButton->Text = L"Отобразить отсортированный файл";
			this->SortFileButton->UseVisualStyleBackColor = false;
			this->SortFileButton->Click += gcnew System::EventHandler(this, &MyForm::SortFileButton_Click);
			// 
			// File1ShowButton
			// 
			this->File1ShowButton->BackColor = System::Drawing::Color::BurlyWood;
			this->File1ShowButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->File1ShowButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->File1ShowButton->Location = System::Drawing::Point(17, 210);
			this->File1ShowButton->Name = L"File1ShowButton";
			this->File1ShowButton->Size = System::Drawing::Size(273, 54);
			this->File1ShowButton->TabIndex = 7;
			this->File1ShowButton->Text = L"Отобразить исходный файл";
			this->File1ShowButton->UseVisualStyleBackColor = false;
			this->File1ShowButton->Click += gcnew System::EventHandler(this, &MyForm::File1ShowButton_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::LemonChiffon;
			this->groupBox1->Controls->Add(this->File1CreateButton);
			this->groupBox1->Controls->Add(this->SortFileButton);
			this->groupBox1->Controls->Add(this->File1ShowButton);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(12, 127);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(310, 464);
			this->groupBox1->TabIndex = 8;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Что вы хотите сделать\?";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(12, 30);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(279, 25);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Яскунова Анна, группа 590";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(337, 30);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(67, 25);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Дата:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackColor = System::Drawing::Color::BurlyWood;
			this->ClientSize = System::Drawing::Size(732, 603);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"Учебная практика_ЯскуноваАнна_гр590";
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void File1CreateButton_Click(System::Object^ sender, System::EventArgs^ e) { // кнопка для заполнения файла 100 буквами, если это не было сделано вручную
		srand(time(NULL));
		char letters[100];
		fstream file1; // создание объекта класса fstream 
		file1.open("1.txt"); // связывание объекта класса fstream с файлом, который будет использоваться для операций ввода-вывода
		for (int i = 0; i < 100; i++)
		{
			letters[i] = (rand() % ('z' - 'a' + 1)) + 'a'; //присваиваем букве рандомное значение из алфавита
			file1 << letters[i]; // добавляем букву в файл
		}
		file1.close(); //закрываем файл
	}
	public: void T1() { //функция для передачи 1-му потоку
		char letter[100];
		ifstream file1;
		std::vector<char> v1, v2, v3, v4, v5; //инициализация векторов
		file1.open("1.txt");
		for (int i = 0; i < 10; i++)
		{
			file1 >> letter[i]; //присваиваем переменной списка значение буквы из файла
			v1.push_back(letter[i]); //добавляем эту букву в вектор
		}
		sort(v1.begin(), v1.end()); // сортировка вектора по алфавиту
		v1[0] = '*'; // замена в 1-ом векторе 1-ой буквы на звездочку
		writeToFile2(v1); //обращение к функции из созданной DLL-библиотеки, которая записывает отсортированный вектор во 2-файл (2.txt)
		for (int i = 10; i < 20; i++)
		{
			file1 >> letter[i];
			v2.push_back(letter[i]);
		}
		sort(v2.begin(), v2.end());
		v2[1] = '*';
		writeToFile2(v2);
		for (int i = 20; i < 30; i++)
		{
			file1 >> letter[i];
			v3.push_back(letter[i]);
		}
		sort(v3.begin(), v3.end());
		v3[2] = '*';
		writeToFile2(v3);
		for (int i = 30; i < 40; i++)
		{
			file1 >> letter[i];
			v4.push_back(letter[i]);
		}
		sort(v4.begin(), v4.end());
		v4[3] = '*';
		writeToFile2(v4);
		for (int i = 40; i < 50; i++)
		{
			file1 >> letter[i];
			v5.push_back(letter[i]);
		}
		sort(v5.begin(), v5.end());
		v5[4] = '*';
		writeToFile2(v5);
		file1.close();
	}
	public: void T2() { //функция для передачи 2-му потоку
		char letter[100];
		ifstream file1;
		std::vector<char> v6, v7, v8, v9, v10;
		file1.open("1.txt");
		for (int i = 50; i < 60; i++)
		{
			file1 >> letter[i];
			v6.push_back(letter[i]);
		}
		sort(v6.begin(), v6.end());
		v6[5] = '*';
		writeToFile2(v6);
		for (int i = 60; i < 70; i++)
		{
			file1 >> letter[i];
			v7.push_back(letter[i]);
		}
		sort(v7.begin(), v7.end());
		v7[6] = '*';
		writeToFile2(v7);
		for (int i = 70; i < 80; i++)
		{
			file1 >> letter[i];
			v8.push_back(letter[i]);
		}
		sort(v8.begin(), v8.end());
		v8[7] = '*';
		writeToFile2(v8);
		for (int i = 80; i < 90; i++)
		{
			file1 >> letter[i];
			v9.push_back(letter[i]);
		}
		sort(v9.begin(), v9.end());
		v9[8] = '*';
		writeToFile2(v9);
		for (int i = 90; i < 100; i++)
		{
			file1 >> letter[i];
			v10.push_back(letter[i]);
		}
		sort(v10.begin(), v10.end());
		v10[9] = '*';
		writeToFile2(v10);
		file1.close();
	}

	private: System::Void File1ShowButton_Click(System::Object^ sender, System::EventArgs^ e) { //кнопка для отображения содержимого 1-го файла (1.txt) в textbox1
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

	private: System::Void SortFileButton_Click(System::Object^ sender, System::EventArgs^ e) { //кнопка для отображения содержимого 2-го отсортированного файла (2.txt) в textbox2
		t1 = gcnew Thread(gcnew ThreadStart(this, &MyForm::T1)); //создаем поток, выполняющий функцию T1
		t2 = gcnew Thread(gcnew ThreadStart(this, &MyForm::T2));
		t1->Start(); // начинаем поток
		t1->Join(); // функция для блокировки вызывающегося потока до тех пор, пока поток выполнения не завершится
		t2->Start();
		t2->Join();
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
