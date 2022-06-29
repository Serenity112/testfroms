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
	/// ������ ��� PathForm
	/// </summary>
	public ref class PathForm : public System::Windows::Forms::Form
	{
	public:
		PathForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
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
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(89, 36);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(370, 318);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PathForm::pictureBox1_Paint);
			// 
			// PathForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(621, 418);
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
		Graphics^ G = pictureBox1->CreateGraphics();
		G->DrawEllipse(Pens::Black, centX + cX - radius, cY - radius - centY, radius * 2, radius * 2);
		G->DrawLine(Pens::Black, centX + cX, cY - centY, cX + x, cY + y);
		// ���������� ������� ������� ����������
	}

	private: void Paint_Graphic(int cX, int cY, int r2, int x, int y, array<Point>^ p)
	{
		Graphics^ G = pictureBox1->CreateGraphics();
		G->Clear(BackColor);
		Paint_Circle(cX, cY, 0, 0, r2, x, y);
		G->DrawLines(Pens::Red, p); // ����������
	}


	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		double InitT = 0, LastT = 6.3; // ������ � 360 �������� (6,28 ������)
		double Step = 0.1, angle = InitT;
		double x, y, x1, y1;
		int cX = 120, cY = 120; // ����� ������� ����������
		int R2 = 90; // ������ ������� ����������
		int k = 20; // ����� �������� �� ����������
		int R1 = int(R2 / k); // ������ ������� (����������) ����������
		int i = 0; // ���������� ����� ����������
		array<Point>^ p;
		p = gcnew array<Point>(64); // ����� ��� ���������� (LastT/Step)

		while (angle <= LastT)
		{
			x = R1 * (k - 1) * (cos(angle) + cos((k - 1) * angle) / (k - 1));
			y = R1 * (k - 1) * (sin(angle) - sin((k - 1) * angle) / (k - 1));
			p[i] = Drawing::Point(cX + int(x), cY + int(y)); // ������ ��������� ����� ����������
			Paint_Graphic(cX, cY, R2, x, y, p);
			x1 = (R2 - R1) * sin(angle + 1.57);
			y1 = (R2 - R1) * cos(angle + 1.57);
			Paint_Circle(cX, cY, int(x1), int(y1), R1, x, y);
			angle += Step;
			::Sleep(40); //����� ������������ ����������
			i++;
		}
	}
	};
}