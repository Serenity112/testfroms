#pragma once

#include <windows.h>
#include <math.h>
namespace testfroms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для PathForm
	/// </summary>
	public ref class PathForm : public System::Windows::Forms::Form
	{
	public:
		PathForm(void)
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
		~PathForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:

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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(25, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(498, 529);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PathForm::pictureBox1_Paint);
			// 
			// PathForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(579, 581);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"PathForm";
			this->Text = L"PathForm";
			this->Load += gcnew System::EventHandler(this, &PathForm::PathForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void PathForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: void Paint_Circle(int cX, int cY, int centX, int centY, int radius, int x, int y)
	{
		Graphics^ Графика = pictureBox1->CreateGraphics();
		Графика->DrawEllipse(Pens::Black, centX + cX - radius, cY - radius - centY, radius * 2, radius * 2);
		Графика->DrawLine(Pens::Black, centX + cX, cY - centY, cX + x, cY + y);
		// прорисовка радиуса большей окружности
	}
	private: void Paint_Graphic(int cX, int cY, int r2, int x, int y, array<Point>^ p)
	{
		Graphics^ Графика = pictureBox1->CreateGraphics();
		Графика->Clear(BackColor);
		Paint_Circle(cX, cY, 0, 0, r2, x, y);
		Графика->DrawLines(Pens::Red, p); // траектория
	}

	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		double InitT = 0, LastT = 6.3; // оборот в 360 градусов (6,28 радиан)
		double Step = 0.1, angle = InitT;
		double x, y, x1, y1;
		int cX = 120, cY = 120; // центр большой окружности
		int R2 = 90; // радиус большой окружности
		int k = 20; // число областей на траектории
		int R1 = int(R2 / k); // радиус меньшей (движущейся) окружности
		int i = 0; // количество точек прорисовки
		array<Point>^ p;
		p = gcnew array<Point>(64); // точки для прорисовки (LastT/Step)
		while (angle <= LastT)
		{
			x = R1 * (k - 1) * (cos(angle) + cos((k - 1) * angle) / (k - 1));
			y = R1 * (k - 1) * (sin(angle) - sin((k - 1) * angle) / (k - 1));
			p[i] = Drawing::Point(cX + int(x), cY + int(y)); // расчет очередной точки траектории
			Paint_Graphic(cX, cY, R2, x, y, p);
			x1 = (R2 - R1) * sin(angle + 1.57);
			y1 = (R2 - R1) * cos(angle + 1.57);
			Paint_Circle(cX, cY, int(x1), int(y1), R1, x, y);
			angle += Step;
			Sleep(40); //время приостановки прорисовки
			i++;
		}
	}
	};
}
