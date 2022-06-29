#pragma once

#include <windows.h>
#include <math.h>
# define M_PI 3.14159265358979323846

namespace testfroms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	enum class FigureAnchores { Center, LeftBottomAngle, LeftTopAngle, RightTopAngle, RightBottomAngle};

	FigureAnchores anchore;
	double side1 = 0, side2 = 0, angle = 0;
	

	public ref class PathForm : public System::Windows::Forms::Form
	{
	public:
		PathForm(void)
		{
			InitializeComponent();
		}

	protected:
		~PathForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ label11;
	protected:

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PathForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(-1, 1);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(648, 715);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PathForm::pictureBox1_Paint);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(666, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(228, 25);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Trajectory parameters:\r\n";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(666, 357);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(286, 50);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Paralellogramm parametees:\r\n\r\n";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(666, 399);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(46, 16);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Sides:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(668, 426);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(86, 16);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Figure angle:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(718, 398);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(77, 20);
			this->textBox1->TabIndex = 5;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &PathForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(836, 398);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(77, 20);
			this->textBox2->TabIndex = 6;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &PathForm::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(757, 425);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(67, 20);
			this->textBox3->TabIndex = 7;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &PathForm::textBox3_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(828, 428);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(62, 16);
			this->label5->TabIndex = 8;
			this->label5->Text = L"degrees.";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(801, 399);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(31, 16);
			this->label6->TabIndex = 9;
			this->label6->Text = L"and";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->ForeColor = System::Drawing::Color::DarkRed;
			this->label7->Location = System::Drawing::Point(668, 481);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(45, 16);
			this->label7->TabIndex = 10;
			this->label7->Text = L"label7";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(668, 502);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(86, 15);
			this->label8->TabIndex = 11;
			this->label8->Text = L"Figure anchor:\r\n";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Center", L"LeftBottomAngle", L"LeftTopAngle",
					L"RightTopAngle", L"RightBottomAngle"
			});
			this->comboBox1->Location = System::Drawing::Point(757, 501);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 12;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &PathForm::comboBox1_SelectedIndexChanged);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(835, 456);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(62, 16);
			this->label9->TabIndex = 15;
			this->label9->Text = L"degrees.";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(764, 453);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(67, 20);
			this->textBox4->TabIndex = 14;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(668, 454);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(98, 16);
			this->label10->TabIndex = 13;
			this->label10->Text = L"Rotation angle:";
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->Location = System::Drawing::Point(933, 398);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(167, 130);
			this->pictureBox2->TabIndex = 16;
			this->pictureBox2->TabStop = false;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(1016, 502);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(58, 16);
			this->label11->TabIndex = 17;
			this->label11->Text = L"Rotation";
			this->label11->Click += gcnew System::EventHandler(this, &PathForm::label11_Click);
			// 
			// PathForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1112, 728);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"PathForm";
			this->Text = L"PathForm";
			this->Load += gcnew System::EventHandler(this, &PathForm::PathForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void PathForm_Load(System::Object^ sender, System::EventArgs^ e) {
		label7->Text = "";
		
		comboBox1->Text = "Center";
		anchore = FigureAnchores::Center;
	}

	private: void Paint_Parallelogram(Point point, double side1, double side2, double angle, FigureAnchores anchore, Pens pen)
	{
		double x = point.X;
		double y = point.Y;
		double h = side2 * sin(angle);

		Graphics^ G = pictureBox1->CreateGraphics();
		
		Point point1 = Point();
		Point point2 = Point();
		Point point3 = Point();
		Point point4 = Point();

		switch (anchore) {
			case FigureAnchores::Center:
				point1 = Point(x - side1/2, y - h/2);
				point2 = Point(x - side1 / 2, y - h / 2);
				point3 = Point(x - side1 / 2, y - h / 2);
				point4 = Point(x - side1 / 2, y - h / 2);
				break;

			case FigureAnchores::LeftBottomAngle:
				break;

			case FigureAnchores::LeftTopAngle:
				break;

			case FigureAnchores::RightTopAngle:
				break;

			case FigureAnchores::RightBottomAngle:
				break;
		}

		G->DrawLine(Pens::Red, point1, point2);
		G->DrawLine(Pens::Red, point2, point3);
		G->DrawLine(Pens::Red, point3, point4);
		G->DrawLine(Pens::Red, point4, point1);
	}

	private: void Paint_Graphic(array<Point>^ points, int count)
	{
		Graphics^ G = pictureBox1->CreateGraphics();
		G->Clear(BackColor);

		while (count != 0) {
			G->DrawLine(Pens::Red, points[count], points[count - 1]);
			count--;
		}	
	}



	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		double InitT = 0, LastT = 6.28; // оборот в 360 градусов (6,28 радиан)
		double Step = 0.01, angle = InitT;
		double x, y;
		int cX =300, cY = 300; // центр большой окружности
		int i = 0; // количество точек прорисовки
		
		int radiusMuliplier = 3;

		array<Point>^ points = gcnew array<Point>(629);

		Graphics^ G = pictureBox1->CreateGraphics();

		while (angle <= LastT)
		{
			double radius = radiusMuliplier*(30 + 15 * sin(60 * angle) * sin(2.5 *angle));

			x = radius * cos(angle);
			y = radius * sin(angle);

			points[i] = Point(cX +x, cY + y);


			//G->Clear(BackColor);

			//Paint_Graphic(points, i);			
			//Sleep(1);





			angle += Step;
			i++;
		}

		
		
		
		//G->DrawLines(Pens::Red, points);


		//Sleep(40000000);
		while (angle <= LastT)
		{
			//x = R1 * (k - 1) * (cos(angle) + cos((k - 1) * angle) / (k - 1));
			//y = R1 * (k - 1) * (sin(angle) - sin((k - 1) * angle) / (k - 1));
			//p[i] = Drawing::Point(cX + int(x), cY + int(y)); // расчет очередной точки траектории
			//Paint_Graphic(cX, cY, R2, x, y, p);




			//x1 = (R2 - R1) * sin(angle + 1.57);
			//y1 = (R2 - R1) * cos(angle + 1.57);
			//Paint_Circle(cX, cY, int(x1), int(y1), R1, x, y);





			angle += Step;
			//Sleep(40);
			i++;
		}
	}

	private: void RecalculateParallelogram() {
		
		try {
			side1 = Convert::ToDouble(textBox1->Text);
			side2 = Convert::ToDouble(textBox2->Text);
			angle = Convert::ToDouble(textBox3->Text);

			if (side1 <= 0 || side2 <= 0 || angle <= 0) {
				label7->Text = "Wrong params!";
			}
			else
			{
				label7->Text = "";
			}
		}
		catch (...) {
			label7->Text = "Wrong params!";				
		}
	}

	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		RecalculateParallelogram();
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		RecalculateParallelogram();
	}
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		RecalculateParallelogram();
	}

	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		switch (comboBox1->SelectedIndex)
		{
		case 0:
			anchore = FigureAnchores::Center;
			break;
		case 1:
			anchore = FigureAnchores::LeftBottomAngle;
			break;
		case 2:
			anchore = FigureAnchores::LeftTopAngle;
			break;
		case 3:
			anchore = FigureAnchores::RightTopAngle;
			break;
		case 4:
			anchore = FigureAnchores::RightBottomAngle;
			break;
		}
	}
private: System::Void label11_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
