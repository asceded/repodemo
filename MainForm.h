#pragma once
#include "TrafficLight.h"

namespace TrafficLightProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			trafficLight = gcnew TrafficLight(redLight, greenLight, labelElapsedTime);
			trafficLight->Start();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
			if (trafficLight != nullptr)
				trafficLight->Stop();
		}

	private: System::Windows::Forms::Panel^ redLight;
	private: System::Windows::Forms::Panel^ greenLight;
	private: System::Windows::Forms::Button^ buttonRequest;
	private: TrafficLight^ trafficLight;
	private: System::Windows::Forms::Label^ labelElapsedTime;

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->redLight = (gcnew System::Windows::Forms::Panel());
			this->greenLight = (gcnew System::Windows::Forms::Panel());
			this->buttonRequest = (gcnew System::Windows::Forms::Button());
			this->labelElapsedTime = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// redLight
			// 
			this->redLight->BackColor = System::Drawing::Color::Red;
			this->redLight->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->redLight->Location = System::Drawing::Point(64, 26);
			this->redLight->Name = L"redLight";
			this->redLight->Size = System::Drawing::Size(78, 74);
			this->redLight->TabIndex = 0;
			// 
			// greenLight
			// 
			this->greenLight->BackColor = System::Drawing::Color::Lime;
			this->greenLight->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->greenLight->Location = System::Drawing::Point(64, 119);
			this->greenLight->Name = L"greenLight";
			this->greenLight->Size = System::Drawing::Size(78, 76);
			this->greenLight->TabIndex = 1;
			// 
			// buttonRequest
			// 
			this->buttonRequest->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonRequest->Location = System::Drawing::Point(170, 136);
			this->buttonRequest->Name = L"buttonRequest";
			this->buttonRequest->Size = System::Drawing::Size(61, 59);
			this->buttonRequest->TabIndex = 2;
			this->buttonRequest->Text = L"PRESS";
			this->buttonRequest->UseVisualStyleBackColor = true;
			this->buttonRequest->Click += gcnew System::EventHandler(this, &MainForm::buttonRequest_Click);
			// 
			// labelElapsedTime
			// 
			this->labelElapsedTime->AutoSize = true;
			this->labelElapsedTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->labelElapsedTime->Location = System::Drawing::Point(170, 61);
			this->labelElapsedTime->Name = L"labelElapsedTime";
			this->labelElapsedTime->Size = System::Drawing::Size(31, 33);
			this->labelElapsedTime->TabIndex = 3;
			this->labelElapsedTime->Text = L"0";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(418, 337);
			this->Controls->Add(this->labelElapsedTime);
			this->Controls->Add(this->buttonRequest);
			this->Controls->Add(this->greenLight);
			this->Controls->Add(this->redLight);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonRequest_Click(System::Object^ sender, System::EventArgs^ e) {
		trafficLight->onButtonPressed();
	}
	};
}
