#pragma once
#include "msclr/marshal_cppstd.h"
#include "string_parser.h"
#include <regex>
#include <sstream> // For std::
bool isHistory = true;

namespace coursach {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms::DataVisualization::Charting;


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
			GLOBALS.saveToFile();
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ expression;


	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button5;


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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->expression = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button5 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chart1->Legends->Add(legend2);
			this->chart1->Location = System::Drawing::Point(12, 12);
			this->chart1->Name = L"chart1";
			series2->ChartArea = L"ChartArea1";
			series2->Legend = L"Legend1";
			series2->Name = L"Series1";
			series2->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Int64;
			series2->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Int64;
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(575, 551);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			this->chart1->Click += gcnew System::EventHandler(this, &MyForm::chart1_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::DodgerBlue;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(16, 648);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(191, 78);
			this->button1->TabIndex = 1;
			this->button1->Text = L"calculate";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(17, 609);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(190, 26);
			this->textBox1->TabIndex = 2;
			// 
			// expression
			// 
			this->expression->AutoSize = true;
			this->expression->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->expression->Location = System::Drawing::Point(64, 577);
			this->expression->Name = L"expression";
			this->expression->Size = System::Drawing::Size(100, 25);
			this->expression->TabIndex = 3;
			this->expression->Text = L"expression:";
			this->expression->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(485, 616);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 26);
			this->textBox4->TabIndex = 6;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(485, 648);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 26);
			this->textBox5->TabIndex = 7;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->label1->Location = System::Drawing::Point(528, 587);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(20, 25);
			this->label1->TabIndex = 8;
			this->label1->Text = L"x";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click_1);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->label2->Location = System::Drawing::Point(421, 616);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 25);
			this->label2->TabIndex = 9;
			this->label2->Text = L"min:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->label3->Location = System::Drawing::Point(418, 648);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 25);
			this->label3->TabIndex = 10;
			this->label3->Text = L"max:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->label4->Location = System::Drawing::Point(390, 679);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(77, 25);
			this->label4->TabIndex = 11;
			this->label4->Text = L"tangent:";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(485, 680);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 26);
			this->textBox2->TabIndex = 12;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::DodgerBlue;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(213, 692);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(92, 34);
			this->button2->TabIndex = 13;
			this->button2->Text = L"style";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::DodgerBlue;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->ForeColor = System::Drawing::Color::White;
			this->button3->Location = System::Drawing::Point(213, 648);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(92, 38);
			this->button3->TabIndex = 14;
			this->button3->Text = L"language";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::DodgerBlue;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->ForeColor = System::Drawing::Color::White;
			this->button4->Location = System::Drawing::Point(213, 603);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(92, 38);
			this->button4->TabIndex = 15;
			this->button4->Text = L"history";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->Location = System::Drawing::Point(593, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(626, 714);
			this->panel1->TabIndex = 16;
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::DodgerBlue;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->ForeColor = System::Drawing::Color::White;
			this->button5->Location = System::Drawing::Point(311, 603);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(83, 38);
			this->button5->TabIndex = 17;
			this->button5->Text = L"log in";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1231, 738);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->expression);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->chart1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->HelpButton = true;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
			render_size_form();
			GLOBALS.readFromFile();
		}
private: System::Void render_saves() {
	// Assuming 'saves' is accessible here and contains your data
	SaveType saves = GLOBALS.getSaves();
	int yOffset = 10;

	for (size_t i = 0; i < saves.size(); i++) {
		// Create a container panel for each set of controls
		Panel^ savePanel = gcnew Panel();
		savePanel->TabIndex = i;
		savePanel->Size = System::Drawing::Size(300, 100); // Adjust size as needed
		savePanel->Location = System::Drawing::Point(10, yOffset);
		yOffset += 110; // Increment y-offset for the next set of controls

		// Create a button
		Button^ myButton = gcnew Button();
		myButton->Text = "insert";
		myButton->Size = System::Drawing::Size(60, 20); // Adjust size as needed
		myButton->Location = System::Drawing::Point(10, 20);

		// Add a Click event handler to the button
		myButton->Click += gcnew System::EventHandler(this, &MyForm::MyButton_Click);

		savePanel->Controls->Add(myButton);

		// Create labels for other data in the map
		Label^ labelMax = gcnew Label();
		labelMax->Text = "Max: " + gcnew String(saves[i]["max"].c_str());
		labelMax->Location = System::Drawing::Point(100, 10);
		savePanel->Controls->Add(labelMax);

		Label^ labelMin = gcnew Label();
		labelMin->Text = "Min: " + gcnew String(saves[i]["min"].c_str());
		labelMin->Location = System::Drawing::Point(100, 33);
		savePanel->Controls->Add(labelMin);

		Label^ labelX = gcnew Label();
		labelX->Text = "X: " + gcnew String(saves[i]["x"].c_str());
		labelX->Location = System::Drawing::Point(100, 56);
		savePanel->Controls->Add(labelX);

		Label^ labelExpression = gcnew Label();
		labelExpression->Text = gcnew String(saves[i]["expression"].c_str());
		labelExpression->Location = System::Drawing::Point(100, 79);
		savePanel->Controls->Add(labelExpression);

		// Add the container panel to the main panel
		panel1->Controls->Add(savePanel);

		// Add a separator (thin line) between panels
		Panel^ separatorPanel = gcnew Panel();
		separatorPanel->BackColor = System::Drawing::Color::Gray; // Choose a color for the separator
		separatorPanel->Size = System::Drawing::Size(300, 1); // Adjust width and height as needed
		separatorPanel->Location = System::Drawing::Point(10, yOffset - 5);
		panel1->Controls->Add(separatorPanel);
	}
}

private: System::Void MyButton_Click(System::Object^ sender, System::EventArgs^ e) {
	SaveType saves = GLOBALS.getSaves();
	Button^ clickedButton = safe_cast<Button^>(sender);
	int index = clickedButton->Parent->TabIndex; // Ensure TabIndex is set correctly

	// Check if index is within the range of saves
	if (index < 0 || index >= saves.size()) {
		// Handle error: index out of range
		return;
	}

	// Check if the keys exist before accessing them
	if (saves[index].find("min") != saves[index].end() &&
		saves[index].find("x") != saves[index].end() &&
		saves[index].find("max") != saves[index].end() &&
		saves[index].find("expression") != saves[index].end()) {

		this->textBox4->Text = gcnew String(saves[index]["min"].c_str());
		this->textBox2->Text = gcnew String(saves[index]["x"].c_str());
		this->textBox5->Text = gcnew String(saves[index]["max"].c_str());
		this->textBox1->Text = gcnew String(saves[index]["expression"].c_str());
	}
	else {
		// Handle error: key not found
	}
}
		void render_size_form() {
			if (isHistory) {
				this->Size = System::Drawing::Size(420, 515);
			}
			else {
				this->Size = System::Drawing::Size(800, 515);
			}
		}
		void render_style() {
			switch (GLOBALS.getStyle())
			{
			case 0: // Black style
				this->BackColor = System::Drawing::Color::White;
				this->ForeColor = System::Drawing::Color::Black; // Text color
				this->button1->BackColor = System::Drawing::Color::Silver;
				this->textBox1->BackColor = System::Drawing::Color::Silver;
				this->textBox4->BackColor = System::Drawing::Color::Silver;
				this->textBox5->BackColor = System::Drawing::Color::Silver;
				this->textBox2->BackColor = System::Drawing::Color::Silver;
				break;
			case 1: // White style
				this->BackColor = System::Drawing::Color::Black;
				this->ForeColor = System::Drawing::Color::White; // Text color
				this->button1->BackColor = System::Drawing::Color::Silver;
				this->textBox1->BackColor = System::Drawing::Color::Silver;
				this->textBox4->BackColor = System::Drawing::Color::Silver;
				this->textBox5->BackColor = System::Drawing::Color::Silver;
				this->textBox2->BackColor = System::Drawing::Color::Silver;
				break;
			case 2: // Green style
				this->BackColor = System::Drawing::Color::Green;
				this->ForeColor = System::Drawing::Color::Black; // Text color
				this->button1->BackColor = System::Drawing::Color::DarkGreen;
				this->textBox1->BackColor = System::Drawing::Color::DarkGreen;
				this->textBox4->BackColor = System::Drawing::Color::DarkGreen;
				this->textBox5->BackColor = System::Drawing::Color::DarkGreen;
				this->textBox2->BackColor = System::Drawing::Color::DarkGreen;
				break;
			}
		}

		void render_language() {
			switch (GLOBALS.getLanguage())
			{
			case 0:
				this->button1->Text = L"calculate";
				this->expression->Text = L"expression:";
				this->label2->Text = L"min:";
				this->label3->Text = L"max:";
				this->label4->Text = L"tangent:";
				this->button2->Text = L"style";
				this->button3->Text = L"language";
				break;

			case 1:
				this->button1->Text = L"рассчитать";
				this->expression->Text = L"выражение:";
				this->label2->Text = L"мин:";
				this->label3->Text = L"макс:";
				this->label4->Text = L"тангенс:";
				this->button2->Text = L"стиль";
				this->button3->Text = L"язык";
				break;

			case 2:
				this->button1->Text = L"вылічыць";
				this->expression->Text = L"выраз:";
				this->label2->Text = L"мін:";
				this->label3->Text = L"макс:";
				this->label4->Text = L"тангенс:";
				this->button2->Text = L"стыль";
				this->button3->Text = L"мова";
				break;
			}
		}

#pragma endregion
		private: System::Void chart1_AxisViewChanged(System::Object^ sender, System::Windows::Forms::DataVisualization::Charting::ViewEventArgs^ e) {
			for each (System::Windows::Forms::DataVisualization::Charting::Series ^ series in chart1->Series)
			{
				double roundedValue = Math::Round(series->Points[0]->YValues[0], 2);
				series->LegendText = series->Name + ": " + roundedValue.ToString();
			}
		}


		private: void MyForm::chart1_MouseWheel(Object^ sender, MouseEventArgs^ e)
		{
			Chart^ chart = safe_cast<Chart^>(sender);
			Axis^ xAxis = chart->ChartAreas[0]->AxisX;
			Axis^ yAxis = chart->ChartAreas[0]->AxisY;
			yAxis->LabelStyle->Format = "{0:0.00}";
			xAxis->LabelStyle->Format = "{0:0.00}";

			try
			{
				if (e->Delta < 0) // Scrolled down.
				{
					xAxis->ScaleView->ZoomReset();
					yAxis->ScaleView->ZoomReset();
				}
				else if (e->Delta > 0) // Scrolled up.
				{
					double xMin = xAxis->ScaleView->ViewMinimum;
					double xMax = xAxis->ScaleView->ViewMaximum;
					double yMin = yAxis->ScaleView->ViewMinimum;
					double yMax = yAxis->ScaleView->ViewMaximum;

					double posXStart = xAxis->PixelPositionToValue(e->Location.X) - (xMax - xMin) / 4;
					double posXFinish = xAxis->PixelPositionToValue(e->Location.X) + (xMax - xMin) / 4;

					double posYStart = yAxis->PixelPositionToValue(e->Location.Y) - (yMax - yMin) / 4;
					double posYFinish = yAxis->PixelPositionToValue(e->Location.Y) + (yMax - yMin) / 4;

					xAxis->ScaleView->Zoom(posXStart, posXFinish);
					yAxis->ScaleView->Zoom(posYStart, posYFinish);
				}
			}
			catch (...)
			{
				// Handle or ignore errors.
			}
		}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		render_style();

		std::string mins = msclr::interop::marshal_as<std::string>(this->textBox4->Text);
		double min;
		if (isNumeric(mins)) {
			min = stringToDouble(mins);
		}
		else {
			this->textBox4->BackColor = System::Drawing::Color::Red;
			return;
		}

		std::string xs = msclr::interop::marshal_as<std::string>(this->textBox2->Text);
		double x;
		if (isNumeric(xs)) {
			x = stringToDouble(xs);
		}
		else {
			this->textBox2->BackColor = System::Drawing::Color::Red;
			return;
		}

		std::string maxs = msclr::interop::marshal_as<std::string>(this->textBox5->Text);
		double max;
		if (isNumeric(maxs)) {
			max = stringToDouble(maxs);
		}
		else {
			this->textBox5->BackColor = System::Drawing::Color::Red;
			return;
		}

		if (max < min) {
			this->textBox4->BackColor = System::Drawing::Color::Red;
			this->textBox5->BackColor = System::Drawing::Color::Red;
			return;
		}
		
		this->chart1->Series->Clear();
		this->chart1->Series->Add("Series1");
		this->chart1->Series["Series1"]->ChartType = DataVisualization::Charting::SeriesChartType::Line;
		this->chart1->Series["Series1"]->IsVisibleInLegend = false;


		std::string expression = msclr::interop::marshal_as<std::string>(this->textBox1->Text);
		std::map<std::string, double> variables;
		std::vector<std::string> rpn = infixToRPN(expression);

		if (!isValid(expression)) {
			this->textBox1->BackColor = System::Drawing::Color::Red;
			return;
		}

		this->chart1->Series->Add("Series2");
		this->chart1->Series["Series2"]->ChartType = DataVisualization::Charting::SeriesChartType::Line;
		this->chart1->Series["Series2"]->IsVisibleInLegend = false;

		double h = 0.00001;
		variables["x"] = x;
		double first = evaluateRPN(rpn, variables);
		variables["x"] += h;
		double second = evaluateRPN(rpn, variables);
		double m = (first - second) / h; // Наклон касательной
		double b = first - m * x; // Смещение по оси Y

		for (double x = min; x <= max; x += 0.1) {
			variables["x"] = x;
			double result = evaluateRPN(rpn, variables);
			this->chart1->Series["Series1"]->Points->AddXY(x, result);
			this->chart1->Series["Series2"]->Points->AddXY(x, m * x + b);
		}
		std::map<std::string, std::string> new_save;
		new_save["expression"] = expression;
		new_save["max"] = maxs;
		new_save["min"] = mins;
		new_save["x"] = xs;
		GLOBALS.addSave(new_save);
		render_saves();
	}
	private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	GLOBALS.changeStyle();
	render_style();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	GLOBALS.changeLanguage();
	render_language();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	isHistory = !isHistory;
	this->render_saves();
	this->render_size_form();
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
